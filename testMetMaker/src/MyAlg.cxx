#include "MyAlg.h"
#include "METInterface/IMETMaker.h"
#include "xAODMissingET/MissingETContainer.h"
#include "xAODMissingET/MissingETAuxContainer.h"
#include "xAODMissingET/MissingETComposition.h"
#include "xAODMissingET/MissingETAssociationMap.h"
#include "xAODJet/JetContainer.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODEgamma/PhotonContainer.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODTau/TauJetContainer.h"
#include "xAODTracking/VertexContainer.h"
#include "MuonSelectorTools/IMuonSelectionTool.h"
#include "ElectronPhotonSelectorTools/IAsgElectronLikelihoodTool.h"
#include "ElectronPhotonSelectorTools/IAsgPhotonIsEMSelector.h"
#include "TauAnalysisTools/ITauSelectionTool.h"

#include "GaudiKernel/ITHistSvc.h"
#include "xAODTrigger/EnergySumRoI.h"
#include "TFile.h"
//CHECK//to do L1 Trigger emulation
//CHECK#include "TrigT1Interfaces/L1METvalue.h"
//CHECK#include <cmath>
//CHECK
#include "xAODTrigMissingET/TrigMissingETContainer.h"
#include "TrigDecisionTool/TrigDecisionTool.h"

#include "TrigDecisionTool/ChainGroup.h"

#include "TEfficiency.h"


using std::string;
using namespace xAOD;
//namespace met {
typedef ElementLink<xAOD::IParticleContainer> iplink_t;
static const SG::AuxElement::ConstAccessor< std::vector<iplink_t > > acc_constitObjLinks("ConstitObjectLinks");
//    For TrigDecisionTool
//**********************************************************************
MyAlg::MyAlg(const std::string& name,
                         ISvcLocator* pSvcLocator )
  : ::AthAlgorithm( name, pSvcLocator ),
  m_muonSelTool(""),
  m_elecSelLHTool(""),
  m_photonSelIsEMTool(""),
  m_tauSelTool(""),
  //m_all( 0 ), m_allL1( 0 ), m_allHLT( 0 )
//  m_trigDecTool( "Trig::TrigDecisionTool/TrigDecisionTool" )
  m_trigDecTool(""),
  m_muIsoSelTool("")
{
  declareProperty( "Maker",          m_metmaker                        );
  declareProperty( "METMapName",     m_mapname   = "METAssoc"          );
  declareProperty( "METCoreName",    m_corename  = "MET_Core"          );
  declareProperty( "METName",        m_outname   = "MET_Reference"     );
  declareProperty( "METSoftClName",  m_softclname  = "SoftClus"        );
  declareProperty( "METSoftTrkName", m_softtrkname = "PVSoftTrk"       );
  declareProperty( "InputJets",      m_jetColl   = "AntiKt4LCTopoJets" );
  declareProperty( "InputElectrons", m_eleColl   = "Electrons"         );
  declareProperty( "InputPhotons",   m_gammaColl = "Photons"           );
  declareProperty( "InputTaus",      m_tauColl   = "TauJets"           );
  declareProperty( "InputMuons",     m_muonColl  = "Muons"             );
  declareProperty( "MuonSelectionTool",        m_muonSelTool           );
  declareProperty( "ElectronLHSelectionTool",  m_elecSelLHTool         );
  declareProperty( "PhotonIsEMSelectionTool" , m_photonSelIsEMTool     );
  declareProperty( "TauSelectionTool",         m_tauSelTool            );
  declareProperty( "DoTruthLeptons", m_doTruthLep = false              );
  declareProperty( "IsData",         m_isData = true                   );
  declareProperty( "TrigDecTool",    m_trigDecTool                     );
  declareProperty( "MuonIsoSelTool",    m_muIsoSelTool                     );
  declareProperty( "ElectronIsoSelTool",    m_eleIsoSelTool                     );
   //ATH_MSG_INFO ("debug: end constructor ");
}
//**********************************************************************
MyAlg::~MyAlg() { }
//**********************************************************************
StatusCode MyAlg::initialize() {
  ATH_MSG_INFO ("start initialize ");
  MyWMetHist = new TH1D("MyWMetHist","Offline MET",400,0,400);
  ServiceHandle<ITHistSvc> histSvc("THistSvc",name()); 
  CHECK( histSvc.retrieve() );
  // myHist = new TH1D("myHist","myHist",10,0,10);
  mySuMetHist = new TH1D("mySuMetHist","mySuMetHist",400, 0, 400);
  histSvc->regHist("/MYSTREAM/MyWMetHist",MyWMetHist).ignore(); //or check the statuscode
  ATH_CHECK( histSvc->regHist("/MYSTREAM/MyDirectory/mySuMetHist",mySuMetHist) ); //will put mySuMetHist in a TDirectory called MyDirectory

  h_metHist = new TH1D("h_metHist","Offline MET",400, 0, 400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_metHist",h_metHist) ); //will put h_metHist in a TDirectory called MyDirectory

  //TRUTH ONLY ON MC SAMPLE    h_truthMet = new TH1D("TruthMET", "Truth MET;E_{T}^{miss} (Truth) [GeV]", 400, 0, 400);
  //TRUTH ONLY ON MC SAMPLE    ATH_CHECK( histSvc->regHist("/MYSTREAM/truthMET", h_truthMet) );

  h_l1Met = new TH1D("L1Met", "L1 Trigger MET;E_{T}^{miss}  [GeV]", 400, 0, 400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/l1Met", h_l1Met) );

  h2_OLvsL1Met = new TH2D("OffLineVSl1Met", "Offline vs L1  MET;OffLine E_{T}^{miss}  [GeV];l1 E_{T}^{miss}  [GeV]", 400,0,400,400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/OLvsL1Met", h2_OLvsL1Met) );


  h_HLTMet = new TH1D("HLTMet", "HLT Trigger MET;E_{T}^{miss}  [GeV]", 400, 0, 400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/HLTMet", h_HLTMet) );

  h2_OLvsHLTMet = new TH2D("OffLineVSHLTMet", "Offline vs HLT  MET;OffLine E_{T}^{miss}  [GeV];HLT E_{T}^{miss}  [GeV]", 400,0,400,400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/OLvsHLTMet", h2_OLvsHLTMet) );

  h_Met_Wtrig_muon = new TH1D("h_Met_Wtrig_muon", "MET, muon trigger;E_{T}^{miss}  [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_Met_Wtrig_muon", h_Met_Wtrig_muon) );

  h_l1TrigTurnON = new TH1D("l1TrigTurnON", "()Turn On MET, l1ton trigger;E_{T}^{miss}  [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/l1TrigTurnON", h_l1TrigTurnON) );

  // creating all the met trigger histos

  // MET
  h_HLT_xe35 = new TH1D("h_HLT_xe35", "HLT_xe35             , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_tc_lcw = new TH1D("h_HLT_xe35_tc_lcw", "HLT_xe35_tc_lcw      , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_tc_em = new TH1D("h_HLT_xe35_tc_em", "HLT_xe35_tc_em       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_pueta = new TH1D("h_HLT_xe35_pueta", "HLT_xe35_pueta       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_pufit = new TH1D("h_HLT_xe35_pufit", "HLT_xe35_pufit       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_mht = new TH1D("h_HLT_xe35_mht", "HLT_xe35_mht         , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_wEFMu = new TH1D("h_HLT_xe35_wEFMu", "HLT_xe35_wEFMu       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);

  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50 = new TH1D("h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50", "HLT_xe110_mht_L1XE50_AND_xe70_L1XE50, muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe100_L1XE50 = new TH1D("h_HLT_xe100_L1XE50", "HLT_xe100_L1XE50 , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe110_mht_L1XE50 = new TH1D("h_HLT_xe110_mht_L1XE50", "HLT_xe110_mht_L1XE50   , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe140_pueta_L1XE50 = new TH1D("h_HLT_xe140_pueta_L1XE50", "HLT_xe140_pueta_L1XE50 , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe140_pufit_L1XE50 = new TH1D("h_HLT_xe140_pufit_L1XE50", "HLT_xe140_pufit_L1XE50 , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe160_tc_lcw_L1XE50 = new TH1D("h_HLT_xe160_tc_lcw_L1XE50", "HLT_xe160_tc_lcw_L1XE50     , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50 = new TH1D("h_HLT_xe160_tc_lcw_wEFMu_L1XE50", "HLT_xe160_tc_lcw_wEFMu_L1XE50        , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);

  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35", h_HLT_xe35) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_tc_lcw", h_HLT_xe35_tc_lcw) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_tc_em", h_HLT_xe35_tc_em) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_pueta", h_HLT_xe35_pueta) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_pufit", h_HLT_xe35_pufit) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_mht", h_HLT_xe35_mht) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_wEFMu", h_HLT_xe35_wEFMu) );

  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50", h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe100_L1XE50", h_HLT_xe100_L1XE50) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe110_mht_L1XE50", h_HLT_xe110_mht_L1XE50) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe140_pueta_L1XE50", h_HLT_xe140_pueta_L1XE50) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe140_pufit_L1XE50", h_HLT_xe140_pufit_L1XE50) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe160_tc_lcw_L1XE50", h_HLT_xe160_tc_lcw_L1XE50) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe160_tc_lcw_wEFMu_L1XE50", h_HLT_xe160_tc_lcw_wEFMu_L1XE50) );

  // MET W to mu nu events
  h_HLT_xe35_wSel_trig_muon = new TH1D("h_HLT_xe35_wSel_trig_muon", "HLT_xe35             , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_tc_lcw_wSel_trig_muon = new TH1D("h_HLT_xe35_tc_lcw_wSel_trig_muon", "HLT_xe35_tc_lcw      , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_tc_em_wSel_trig_muon = new TH1D("h_HLT_xe35_tc_em_wSel_trig_muon", "HLT_xe35_tc_em       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_pueta_wSel_trig_muon = new TH1D("h_HLT_xe35_pueta_wSel_trig_muon", "HLT_xe35_pueta       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_pufit_wSel_trig_muon = new TH1D("h_HLT_xe35_pufit_wSel_trig_muon", "HLT_xe35_pufit       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_mht_wSel_trig_muon = new TH1D("h_HLT_xe35_mht_wSel_trig_muon", "HLT_xe35_mht         , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_wEFMu_wSel_trig_muon = new TH1D("h_HLT_xe35_wEFMu_wSel_trig_muon", "HLT_xe35_wEFMu       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);

  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon = new TH1D("h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon", "HLT_xe110_mht_L1XE50_AND_xe70_L1XE50, muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe100_L1XE50_wSel_trig_muon = new TH1D("h_HLT_xe100_L1XE50_wSel_trig_muon", "HLT_xe100_L1XE50 , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe110_mht_L1XE50_wSel_trig_muon = new TH1D("h_HLT_xe110_mht_L1XE50_wSel_trig_muon", "HLT_xe110_mht_L1XE50   , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe140_pueta_L1XE50_wSel_trig_muon = new TH1D("h_HLT_xe140_pueta_L1XE50_wSel_trig_muon", "HLT_xe140_pueta_L1XE50 , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe140_pufit_L1XE50_wSel_trig_muon = new TH1D("h_HLT_xe140_pufit_L1XE50_wSel_trig_muon", "HLT_xe140_pufit_L1XE50 , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon = new TH1D("h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon", "HLT_xe160_tc_lcw_L1XE50     , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon = new TH1D("h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon", "HLT_xe160_tc_lcw_wEFMu_L1XE50        , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);

  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_wSel_trig_muon", h_HLT_xe35_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_tc_lcw_wSel_trig_muon", h_HLT_xe35_tc_lcw_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_tc_em_wSel_trig_muon", h_HLT_xe35_tc_em_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_pueta_wSel_trig_muon", h_HLT_xe35_pueta_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_pufit_wSel_trig_muon", h_HLT_xe35_pufit_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_mht_wSel_trig_muon", h_HLT_xe35_mht_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_wEFMu_wSel_trig_muon", h_HLT_xe35_wEFMu_wSel_trig_muon) );

  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon", h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe100_L1XE50_wSel_trig_muon", h_HLT_xe100_L1XE50_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe110_mht_L1XE50_wSel_trig_muon", h_HLT_xe110_mht_L1XE50_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe140_pueta_L1XE50_wSel_trig_muon", h_HLT_xe140_pueta_L1XE50_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe140_pufit_L1XE50_wSel_trig_muon", h_HLT_xe140_pufit_L1XE50_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon", h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon", h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon) );

  // MET Z to mu mu events
  h_HLT_xe35_zSel_trig_muon = new TH1D("h_HLT_xe35_zSel_trig_muon", "HLT_xe35             , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_tc_lcw_zSel_trig_muon = new TH1D("h_HLT_xe35_tc_lcw_zSel_trig_muon", "HLT_xe35_tc_lcw      , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_tc_em_zSel_trig_muon = new TH1D("h_HLT_xe35_tc_em_zSel_trig_muon", "HLT_xe35_tc_em       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_pueta_zSel_trig_muon = new TH1D("h_HLT_xe35_pueta_zSel_trig_muon", "HLT_xe35_pueta       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_pufit_zSel_trig_muon = new TH1D("h_HLT_xe35_pufit_zSel_trig_muon", "HLT_xe35_pufit       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_mht_zSel_trig_muon = new TH1D("h_HLT_xe35_mht_zSel_trig_muon", "HLT_xe35_mht         , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe35_wEFMu_zSel_trig_muon = new TH1D("h_HLT_xe35_wEFMu_zSel_trig_muon", "HLT_xe35_wEFMu       , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);

  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon = new TH1D("h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon", "HLT_xe110_mht_L1XE50_AND_xe70_L1XE50, muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe100_L1XE50_zSel_trig_muon = new TH1D("h_HLT_xe100_L1XE50_zSel_trig_muon", "HLT_xe100_L1XE50 , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe110_mht_L1XE50_zSel_trig_muon = new TH1D("h_HLT_xe110_mht_L1XE50_zSel_trig_muon", "HLT_xe110_mht_L1XE50   , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe140_pueta_L1XE50_zSel_trig_muon = new TH1D("h_HLT_xe140_pueta_L1XE50_zSel_trig_muon", "HLT_xe140_pueta_L1XE50 , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe140_pufit_L1XE50_zSel_trig_muon = new TH1D("h_HLT_xe140_pufit_L1XE50_zSel_trig_muon", "HLT_xe140_pufit_L1XE50 , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon = new TH1D("h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon", "HLT_xe160_tc_lcw_L1XE50     , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon = new TH1D("h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon", "HLT_xe160_tc_lcw_wEFMu_L1XE50        , muon triggers. Sel W events;E_{T}^{miss}  [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_zSel_trig_muon", h_HLT_xe35_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_tc_lcw_zSel_trig_muon", h_HLT_xe35_tc_lcw_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_tc_em_zSel_trig_muon", h_HLT_xe35_tc_em_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_pueta_zSel_trig_muon", h_HLT_xe35_pueta_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_pufit_zSel_trig_muon", h_HLT_xe35_pufit_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_mht_zSel_trig_muon", h_HLT_xe35_mht_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe35_wEFMu_zSel_trig_muon", h_HLT_xe35_wEFMu_zSel_trig_muon) );

  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon", h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe100_L1XE50_zSel_trig_muon", h_HLT_xe100_L1XE50_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe110_mht_L1XE50_zSel_trig_muon", h_HLT_xe110_mht_L1XE50_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe140_pueta_L1XE50_zSel_trig_muon", h_HLT_xe140_pueta_L1XE50_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe140_pufit_L1XE50_zSel_trig_muon", h_HLT_xe140_pufit_L1XE50_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon", h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon) );
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon", h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon) );


  // Object Histograms^^^^^^^^^


  h_nSelMuons = new TH1D("nSelMuons", "Number of muons selected per event ;num. Mu", 20,0,20);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/nSelMuons", h_nSelMuons) );

  h_mumuInvMass = new TH1D("mumuInvMass", "MuMu inv. Mass ;M_{inv} [GeV]", 50,0,200);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/mumuInvMass", h_mumuInvMass) );

  //testing TLV object
  h_goodMu1_Pt = new TH1D("h_goodMu1_Pt", "Good Muon 1 PT ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_goodMu1_Pt", h_goodMu1_Pt) );

  h_goodMu1_PtTLV = new TH1D("h_goodMu1_PtTLV", "Good Muon 1 PT ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/h_goodMu1_PtTLV", h_goodMu1_PtTLV) );

  h_muonPT = new TH1D("muonPT", "Muon PT ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/muonPT", h_muonPT) );

  h_cutQualMuonPT = new TH1D("cutQualMuonPT", "Muon PT, quality cut ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/cutQualMuonPT", h_cutQualMuonPT) );

  h_cutIsoMuonPT = new TH1D("cutIsoMuonPT", "Muon PT, iso cut ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/cutIsoMuonPT", h_cutIsoMuonPT) );

  h_cut2GoodMuonPT = new TH1D("cut2GoodMuonPT", "Muon PT, 2 good mu cut ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/cut2GoodMuonPT", h_cut2GoodMuonPT) );

  h_muonEta = new TH1D("muonEta", "Muon Eta ; eta", 100,-4,4);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/muonEta", h_muonEta) );

  h_electronPT = new TH1D("electronPT", "Electron PT ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/electronPT", h_electronPT) );

  h_cutQualElectronPT = new TH1D("cutQualElectronPT", "Electron PT, quality cut ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/cutQualElectronPT", h_cutQualElectronPT) );

  h_cutIsoElectronPT = new TH1D("cutIsoElectronPT", "Electron PT, iso cut ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/cutIsoElectronPT", h_cutIsoElectronPT) );

  h_electronEta = new TH1D("electronEta", "Electron Eta ; eta", 100,-4,4);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/electronEta", h_electronEta) );

  // Selected event histo
  MyWSelMetHist = new TH1D("MyWSelMetHist","Offline MET, W to mu nu events",400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/MyWSelMetHist",MyWSelMetHist) ); 

  MyZSelMetHist = new TH1D("MyZSelMetHist","Offline MET, Z to mu mu events",400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/MyZSelMetHist",MyZSelMetHist) ); 

  h_wmunuSelectMuonPT = new TH1D("wmunuSelectMuonPT", "Muon PT,  W mu nu selection cut ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/wmunuSelectMuonPT", h_wmunuSelectMuonPT) );

  h_zmumuSelectMuonPT = new TH1D("zmumuSelectMuonPT", "Muon PT,  Z mu mu selection cut ;P_{T} [GeV]", 400,0,400);
  ATH_CHECK( histSvc->regHist("/MYSTREAM/zmumuSelectMuonPT", h_zmumuSelectMuonPT) );

  // Booking tefficiency objects
  //g_eff_HLT_xe35_wSel_trig_muon = new TEfficiency("g_eff_HLT_xe35_wSel_trig_muon", "Turn on curve of muon, W munu ;MET_{T} [GeV]", 400,0,400);
  //ATH_CHECK( histSvc->regGraph("/MYSTREAM/g_eff_HLT_xe35_wSel_trig_muon", reinterpret_cast<TGraph*>(g_eff_HLT_xe35_wSel_trig_muon)) );

  //g_eff_HLT_xe35_wSel_trig_muonSel = new TEfficiency("effSelWevnts", "Turn on curve of muon, W munu selected ;MET_{T} [GeV]", 400,0,400);
  //ATH_CHECK( histSvc->regGraph("/MYSTREAM/effSelWevnts", reinterpret_cast<TGraph*>(g_eff_HLT_xe35_wSel_trig_muonSel)) );

  //g_eff_HLT_xe35_zSel_trig_muonSel = new TEfficiency("effSelzevnts", "Turn on curve of muon, Z mumu selected ;MET_{T} [GeV]", 400,0,400);
  //ATH_CHECK( histSvc->regGraph("/MYSTREAM/effSelZevnts", reinterpret_cast<TGraph*>(g_eff_HLT_xe35_zSel_trig_muonSel)) );

  //if(TEfficiency::CheckConsistency(*h_HLT_xe35_wSel_trig_muon,*MyWSelMetHist))
  //{
  //  eff_HLT_xe35_wSel_trig_muon = new TEfficiency(*h_HLT_xe35_wSel_trig_muon,*MyWSelMetHist);
  //  eff_HLT_xe35_wSel_trig_muon->SetTitle("");
  //  // this will write the TEfficiency object to "myfile.root"
  //  // AND eff_HLT_xe35_wSel_trig_muon will be attached to the current directory
  //  eff_HLT_xe35_wSel_trig_muon->Write();
  //}
  //if(TEfficiency::CheckConsistency(*h_Met_Wtrig_muon,*MyWMetHist))
  //{
  //  eff_HLT_xe35_wSel_trig_muon2 = new TEfficiency(*h_Met_Wtrig_muon,*MyWMetHist);
  //  // this will write the TEfficiency object to "myfile.root"
  //  // AND eff_HLT_xe35_wSel_trig_muon will be attached to the current directory
  //  eff_HLT_xe35_wSel_trig_muon2->SetTitle("Turn on curve of muon");
  //  eff_HLT_xe35_wSel_trig_muon2->Write();
  //}
  //if(TEfficiency::CheckConsistency(*h_HLT_xe35_zSel_trig_muon,*MyZSelMetHist))
  //{
  //  eff_HLT_xe35_zSel_trig_muon = new TEfficiency(*h_HLT_xe35_zSel_trig_muon,*MyZSelMetHist);
  //  eff_HLT_xe35_zSel_trig_muon->SetTitle("Turn on curve of muon, Z mumu selected");
  //  // this will write the TEfficiency object to "myfile.root"
  //  // AND eff_HLT_xe35_zSel_trig_muon will be attached to the current directory
  //  eff_HLT_xe35_zSel_trig_muon->Write();
  //}


  ATH_MSG_INFO("Initializing " << name() << "...");
  ATH_MSG_INFO("Retrieving tools...");
  // retrieve tools
  if( m_metmaker.retrieve().isFailure() ) {
    ATH_MSG_ERROR("Failed to retrieve tool: " << m_metmaker->name());
    return StatusCode::FAILURE;
  };
  if( m_muonSelTool.retrieve().isFailure() ) {
    ATH_MSG_ERROR("Failed to retrieve tool: " << m_muonSelTool->name());
    return StatusCode::FAILURE;
  };
  if( m_elecSelLHTool.retrieve().isFailure() ) {
    ATH_MSG_ERROR("Failed to retrieve tool: " << m_elecSelLHTool->name());
    return StatusCode::FAILURE;
  };
  if( m_photonSelIsEMTool.retrieve().isFailure() ) {
    ATH_MSG_ERROR("Failed to retrieve tool: " << m_photonSelIsEMTool->name());
    return StatusCode::FAILURE;
  };
  if( m_tauSelTool.retrieve().isFailure() ) {
    ATH_MSG_ERROR("Failed to retrieve tool: " << m_tauSelTool->name());
    return StatusCode::FAILURE;
  };

  m_jetCalibration.setTypeAndName("JetCalibrationTool/myJESTool");
  //ATH_CHECK( m_jetCalibration.retrieve() ); //optional, just forces initializing the tool here instead of at first use

  if( m_jetCalibration.retrieve().isFailure() ) {
    ATH_MSG_ERROR("Failed to retrieve tool: " << m_jetCalibration->name());
    return StatusCode::FAILURE;
  };

  ATH_CHECK( m_trigDecTool.retrieve() );


  // Setup IsolationSelectionTool
  if( m_eleIsoSelTool.retrieve().isFailure() ) {
    ATH_MSG_ERROR("Failed to retrieve tool: " << m_eleIsoSelTool->name());
    return StatusCode::FAILURE;
  };
  
  if( m_muIsoSelTool.retrieve().isFailure() ) {
    ATH_MSG_ERROR("Failed to retrieve tool: " << m_muIsoSelTool->name());
    return StatusCode::FAILURE;
  };


  //  ServiceHandle<ITHistSvc> histSvc("THistSvc",name());
  //  ATH_CHECK( histSvc.retrieve() );
  //  ATH_CHECK( histSvc->regHist("/MYSTREAM/myHist",MyWMetHist) );


   //ATH_MSG_INFO ("debug: end initialize ");
    return StatusCode::SUCCESS;
  }
//**********************************************************************
StatusCode MyAlg::finalize() {
   //ATH_MSG_INFO ("debug:start finalize ");

  //write histos in jobOptions TFile f1("myfile.root","RECREATE");
  //write histos in jobOptions MyWMetHist->Write();
  //write histos in jobOptions h_l1Met->Write();  
  //write histos in jobOptions h2_OLvsL1Met->Write(); 
  //write histos in jobOptions h2_OLvsHLTMet->Write(); 
  //write histos in jobOptions h_Met_Wtrig_muon->Write();  
  //write histos in jobOptions h_l1TrigTurnON->Write();

  //write histos in jobOptions ATH_MSG_INFO ("Histogram written to file ");
  //write histos in jobOptions f1.Close();
  
  TEfficiency* eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon = new TEfficiency("eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon", "HLT_xe110_mht_L1XE50_AND_xe70_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe100_L1XE50_wSel_trig_muon = new TEfficiency("eff_HLT_xe100_L1XE50_wSel_trig_muon", "HLT_xe100_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe110_mht_L1XE50_wSel_trig_muon = new TEfficiency("eff_HLT_xe110_mht_L1XE50_wSel_trig_muon", "HLT_xe110_mht_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon = new TEfficiency("eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon", "HLT_xe140_pueta_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon = new TEfficiency("eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon", "HLT_xe140_pufit_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon = new TEfficiency("eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon", "HLT_xe160_tc_lcw_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon = new TEfficiency("eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon", "HLT_xe160_tc_lcw_wEFMu_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);

  TEfficiency* eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon = new TEfficiency("eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon", "HLT_xe110_mht_L1XE50_AND_xe70_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe100_L1XE50_zSel_trig_muon = new TEfficiency("eff_HLT_xe100_L1XE50_zSel_trig_muon", "HLT_xe100_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe110_mht_L1XE50_zSel_trig_muon = new TEfficiency("eff_HLT_xe110_mht_L1XE50_zSel_trig_muon", "HLT_xe110_mht_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe140_pueta_L1XE50_zSel_trig_muon = new TEfficiency("eff_HLT_xe140_pueta_L1XE50_zSel_trig_muon", "HLT_xe140_pueta_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe140_pufit_L1XE50_zSel_trig_muon = new TEfficiency("eff_HLT_xe140_pufit_L1XE50_zSel_trig_muon", "HLT_xe140_pufit_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon = new TEfficiency("eff_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon", "HLT_xe160_tc_lcw_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);
  TEfficiency* eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon = new TEfficiency("eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon", "HLT_xe160_tc_lcw_wEFMu_L1XE50g;E_{T}^{miss}  [GeV]", 400,0,400);

  TEfficiency* eff_HLT_xe35_wSel_trig_muon2 = 0;
  ////TEfficiency* eff_HLT_xe35_zSel_trig_muon2 = 0;

  TFile* pFile = new TFile("myEfffile.root","recreate");

  //test turn on without selection
  if(TEfficiency::CheckConsistency(*h_Met_Wtrig_muon,*MyWMetHist))
  {
    eff_HLT_xe35_wSel_trig_muon2 = new TEfficiency(*h_Met_Wtrig_muon,*MyWMetHist);
    eff_HLT_xe35_wSel_trig_muon2->SetTitle("Turn on curve of HLT_xe100_L1XE50,#mu trigger, no selection;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe35_wSel_trig_muon2->Write();
  }

  //W events Turn on 
  if(TEfficiency::CheckConsistency(*h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon = new TEfficiency(*h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->SetName("eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon");
    eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->SetTitle("h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon, Wmunu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe100_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe100_L1XE50_wSel_trig_muon = new TEfficiency(*h_HLT_xe100_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe100_L1XE50_wSel_trig_muon->SetName("eff_HLT_xe100_L1XE50_wSel_trig_muon");
    eff_HLT_xe100_L1XE50_wSel_trig_muon->SetTitle("h_HLT_xe100_L1XE50_wSel_trig_muon, Wmunu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe100_L1XE50_wSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe110_mht_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe110_mht_L1XE50_wSel_trig_muon = new TEfficiency(*h_HLT_xe110_mht_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe110_mht_L1XE50_wSel_trig_muon->SetName("eff_HLT_xe110_mht_L1XE50_wSel_trig_muon");
    eff_HLT_xe110_mht_L1XE50_wSel_trig_muon->SetTitle("h_HLT_xe110_mht_L1XE50_wSel_trig_muon, Wmunu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe110_mht_L1XE50_wSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe140_pueta_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon = new TEfficiency(*h_HLT_xe140_pueta_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon->SetName("eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon");
    eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon->SetTitle("h_HLT_xe140_pueta_L1XE50_wSel_trig_muon, Wmunu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe140_pufit_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon = new TEfficiency(*h_HLT_xe140_pufit_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon->SetName("eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon");
    eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon->SetTitle("h_HLT_xe140_pufit_L1XE50_wSel_trig_muon, Wmunu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon = new TEfficiency(*h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->SetName("eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon");
    eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->SetTitle("h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon, Wmunu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon = new TEfficiency(*h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->GetCumulative(kFALSE),*MyWSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->SetName("eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon");
    eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->SetTitle("h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon, Wmunu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->Write();
  }

  // z selection turn on curves
  if(TEfficiency::CheckConsistency(*h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon = new TEfficiency(*h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon->SetName("eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon");
    eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon->SetTitle("h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon, Zmumu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe100_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe100_L1XE50_zSel_trig_muon = new TEfficiency(*h_HLT_xe100_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe100_L1XE50_zSel_trig_muon->SetName("eff_HLT_xe100_L1XE50_zSel_trig_muon");
    eff_HLT_xe100_L1XE50_zSel_trig_muon->SetTitle("h_HLT_xe100_L1XE50_zSel_trig_muon, Zmumu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe100_L1XE50_zSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe110_mht_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe110_mht_L1XE50_zSel_trig_muon = new TEfficiency(*h_HLT_xe110_mht_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe110_mht_L1XE50_zSel_trig_muon->SetName("eff_HLT_xe110_mht_L1XE50_zSel_trig_muon");
    eff_HLT_xe110_mht_L1XE50_zSel_trig_muon->SetTitle("h_HLT_xe110_mht_L1XE50_zSel_trig_muon, Zmumu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe110_mht_L1XE50_zSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe140_pueta_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe140_pueta_L1XE50_zSel_trig_muon = new TEfficiency(*h_HLT_xe140_pueta_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe140_pueta_L1XE50_zSel_trig_muon->SetName("eff_HLT_xe140_pueta_L1XE50_zSel_trig_muon");
    eff_HLT_xe140_pueta_L1XE50_zSel_trig_muon->SetTitle("h_HLT_xe140_pueta_L1XE50_zSel_trig_muon, Zmumu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe140_pueta_L1XE50_zSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe140_pufit_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe140_pufit_L1XE50_zSel_trig_muon = new TEfficiency(*h_HLT_xe140_pufit_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe140_pufit_L1XE50_zSel_trig_muon->SetName("eff_HLT_xe140_pufit_L1XE50_zSel_trig_muon");
    eff_HLT_xe140_pufit_L1XE50_zSel_trig_muon->SetTitle("h_HLT_xe140_pufit_L1XE50_zSel_trig_muon, Zmumu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe140_pufit_L1XE50_zSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon = new TEfficiency(*h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon->SetName("eff_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon");
    eff_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon->SetTitle("h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon, Zmumu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon->Write();
  }
  if(TEfficiency::CheckConsistency(*h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE)))
  {
    eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon = new TEfficiency(*h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon->GetCumulative(kFALSE),*MyZSelMetHist->GetCumulative(kFALSE));
    eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon->SetName("eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon");
    eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon->SetTitle("h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon, Zmumu selected;E_{Tmiss} [GeV], #mu invisible");
    eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon->Write();
  }



  ////h_l1TrigTurnON->Divide(h_HLT_xe35_zSel_trig_muon,MyZSelMetHist);
  //h_l1TrigTurnON->Divide(h_HLT_xe35_wSel_trig_muon,MyWSelMetHist);
  /////if(TEfficiency::CheckConsistency(*h_Met_Wtrig_muon,*MyWMetHist))
  /////{
  /////  eff_HLT_xe35_zSel_trig_muon2 = new TEfficiency(*h_Met_Wtrig_muon,*MyWMetHist);
  /////  // this will write the TEfficiency object to "myfile.root"
  /////  // AND eff_HLT_xe35_zSel_trig_muon will be attached to the current directory
  /////  eff_HLT_xe35_zSel_trig_muon2->SetTitle("Turn on curve of muon");
  /////  eff_HLT_xe35_zSel_trig_muon2->Write();
  /////}
  pFile->Close();


  ATH_MSG_INFO ("Finalizing " << name() << "...");

   //ATH_MSG_INFO ("debug: end finalize ");
  return StatusCode::SUCCESS;
}
//**********************************************************************

StatusCode MyAlg::execute() {
   //ATH_MSG_INFO ("debug: start execute ");
  ATH_MSG_VERBOSE("Executing " << name() << "...");
  // Test of TDT

  // Test for primary vertex
  const xAOD::VertexContainer* vtcs(0);
  ATH_CHECK(evtStore()->retrieve(vtcs, "PrimaryVertices") );
  bool hasPrimary(false);
  for (const xAOD::Vertex* vtx : *vtcs) {
    if (vtx->vertexType() == xAOD::VxType::PriVtx) {
      hasPrimary = true;
      break;
    }
  }
  if (!hasPrimary) return StatusCode::SUCCESS;

  // Create a MissingETContainer with its aux store
  MissingETContainer* newMet = new MissingETContainer();
  if( evtStore()->record(newMet, m_outname).isFailure() ) {
    ATH_MSG_WARNING("Unable to record MissingETContainer: " << m_outname);
    return StatusCode::SUCCESS;
  }
  MissingETAuxContainer* metAuxCont = new MissingETAuxContainer();
  if( evtStore()->record(metAuxCont, m_outname+"Aux.").isFailure() ) {
    ATH_MSG_WARNING("Unable to record MissingETAuxContainer: " << m_outname+"Aux.");
    return StatusCode::SUCCESS;
  }
  newMet->setStore(metAuxCont);
  const MissingETAssociationMap* metMap = 0;
  if( evtStore()->retrieve(metMap, m_mapname).isFailure() ) {
    ATH_MSG_WARNING("Unable to retrieve MissingETAssociationMap: " << m_mapname);
    return StatusCode::SUCCESS;
  }
  metMap->resetObjSelectionFlags();
  // Retrieve containers ***********************************************
  /// MET
  const MissingETContainer* coreMet(0);
  if( evtStore()->retrieve(coreMet, m_corename).isFailure() ) {
    ATH_MSG_WARNING("Unable to retrieve MissingETContainer: " << m_corename);
    return StatusCode::SUCCESS;
  }
  /// Jets
  const JetContainer* jetCont(0);
  if( evtStore()->retrieve(jetCont, m_jetColl).isFailure() ) {
    ATH_MSG_WARNING("Unable to retrieve input jet container: " << m_jetColl);
    return StatusCode::SUCCESS;
  }
   ATH_MSG_DEBUG("Successfully retrieved jet collection");
  /// Electrons
  const ElectronContainer* elCont(0);
  if(!m_eleColl.empty()) {
    if( evtStore()->retrieve(elCont, m_eleColl).isFailure() ) {
      ATH_MSG_WARNING("Unable to retrieve input electron container: " << m_eleColl);
      return StatusCode::SUCCESS;
    }
     ATH_MSG_DEBUG("Successfully retrieved electron collection");
  }
  /// Photons
  const PhotonContainer* phCont(0);
  if(!m_gammaColl.empty()) {
    if( evtStore()->retrieve(phCont, m_gammaColl).isFailure() ) {
      ATH_MSG_WARNING("Unable to retrieve input photon container: " << m_gammaColl);
      return StatusCode::SUCCESS;
    }
     ATH_MSG_DEBUG("Successfully retrieved photon collection");
  }
  /// Taus
  const TauJetContainer* tauCont(0);
  if(!m_tauColl.empty()) {
    if( evtStore()->retrieve(tauCont, m_tauColl).isFailure() ) {
      ATH_MSG_WARNING("Unable to retrieve input tau container: " << m_tauColl);
      return StatusCode::SUCCESS;
    }
     ATH_MSG_DEBUG("Successfully retrieved tau collection");
  }
  /// Muons
  const MuonContainer* muonCont(0);
  if(!m_muonColl.empty()) {
    if( evtStore()->retrieve(muonCont, m_muonColl).isFailure() ) {
      ATH_MSG_WARNING("Unable to retrieve input muon container: " << m_muonColl);
      return StatusCode::SUCCESS;
    }
     ATH_MSG_DEBUG("Successfully retrieved muon collection");
  }
  // Select and flag objects for final MET building ***************************
  MissingETBase::UsageHandler::Policy objScale = MissingETBase::UsageHandler::PhysicsObject;
  if(m_doTruthLep) objScale = MissingETBase::UsageHandler::TruthParticle;
  // Electrons
  //bool elPass = false; //test for seleciton
  if(!m_eleColl.empty()) {
    ConstDataVector<ElectronContainer> metElectrons(SG::VIEW_ELEMENTS);
    for(const auto& el : *elCont) {
      if(accept(el)) {
        metElectrons.push_back(el);
        //elPass = true;
      }
    }
    if( m_metmaker->rebuildMET("RefEle", xAOD::Type::Electron, newMet,
                               metElectrons.asDataVector(),
                               metMap, objScale).isFailure() ) {
      ATH_MSG_WARNING("Failed to build electron term.");
    }
     ATH_MSG_DEBUG("Selected " << metElectrons.size() << " MET electrons. "
                  << acc_constitObjLinks(*(*newMet)["RefEle"]).size() << " are non-overlapping.");
  }
  // Photons
  if(!m_gammaColl.empty()) {
    ConstDataVector<PhotonContainer> metPhotons(SG::VIEW_ELEMENTS);
    for(const auto& ph : *phCont) {
      if(accept(ph)) {
        metPhotons.push_back(ph);
      }
    }
    if( m_metmaker->rebuildMET("RefGamma", xAOD::Type::Photon, newMet,
                               metPhotons.asDataVector(),
                               metMap, objScale).isFailure() ) {
      ATH_MSG_WARNING("Failed to build photon term.");
    }
     ATH_MSG_DEBUG("Selected " << metPhotons.size() << " MET photons. "
                  << acc_constitObjLinks(*(*newMet)["RefGamma"]).size() << " are non-overlapping.");
  }
  // Taus
  if(!m_tauColl.empty()) {
    ConstDataVector<TauJetContainer> metTaus(SG::VIEW_ELEMENTS);
    for(const auto& tau : *tauCont) {
      if(accept(tau)) {
        metTaus.push_back(tau);
      }
    }
    if( m_metmaker->rebuildMET("RefTau", xAOD::Type::Tau, newMet,
                               metTaus.asDataVector(),
                               metMap, objScale).isFailure() ){
      ATH_MSG_WARNING("Failed to build tau term.");
    }
     ATH_MSG_DEBUG("Selected " << metTaus.size() << " MET taus. "
                  << acc_constitObjLinks(*(*newMet)["RefTau"]).size() << " are non-overlapping.");
  }
  // Muons
  if(!m_muonColl.empty()) {
    ConstDataVector<MuonContainer> metMuons(SG::VIEW_ELEMENTS);
    for(const auto& mu : *muonCont) {
      if(accept(mu)) {
        metMuons.push_back(mu);
      }
    }
    ATH_CHECK( m_metmaker->markInvisible(metMuons.asDataVector(), metMap, newMet) ); //Treat muons as invisible

    // Treat muons as invisible
    //
    //if(m_doTruthLep) objScale = MissingETBase::UsageHandler::OnlyTrack;
    //if( m_metmaker->rebuildMET("Muons", xAOD::Type::Muon, newMet,
    //                           metMuons.asDataVector(),
    //                           metMap, objScale).isFailure() ) {
    //  ATH_MSG_WARNING("Failed to build muon term.");
    //}
    // ATH_MSG_DEBUG("Selected " << metMuons.size() << " MET muons. "
    //              << acc_constitObjLinks(*(*newMet)["Muons"]).size() << " are non-overlapping.");

  }
  if( m_metmaker->rebuildJetMET("RefJet", m_softclname, m_softtrkname, newMet,
                                jetCont, coreMet, metMap, false ).isFailure() ) {
    ATH_MSG_WARNING("Failed to build jet and soft terms.");
  }
   ATH_MSG_DEBUG("Of " << jetCont->size() << " jets, "
                << acc_constitObjLinks(*(*newMet)["RefJet"]).size() << " are non-overlapping, "
                << acc_constitObjLinks(*(*newMet)[m_softtrkname]).size() << " are soft");
  MissingETBase::Types::bitmask_t trksource = MissingETBase::Source::Track;
  if((*newMet)[m_softtrkname]) trksource = (*newMet)[m_softtrkname]->source();
  if( m_metmaker->buildMETSum("FinalTrk", newMet, trksource).isFailure() ){
    ATH_MSG_WARNING("Building MET FinalTrk sum failed.");
  }
  MissingETBase::Types::bitmask_t clsource = MissingETBase::Source::LCTopo;
  if((*newMet)[m_softclname]) clsource = (*newMet)[m_softclname]->source();
  if( m_metmaker->buildMETSum("FinalClus", newMet, clsource).isFailure() ) {
    ATH_MSG_WARNING("Building MET FinalClus sum failed.");
  }
  auto metItr = newMet->find("FinalTrk");
  if (metItr == newMet->end() ) {
    ATH_MSG_ERROR( "Failed to find " << "FinalTrk" << " term in rebuilt MET!" );
    return StatusCode::FAILURE;
  }
  
  //------------Getting MET info---------------------

  const xAOD::MissingET& finalMet = **metItr;
  //ATH_MSG_INFO( "Rebuilt MET is: ");
  //ATH_MSG_INFO( "  met_x: " << finalMet.mpx () );
  //ATH_MSG_INFO( "  met_y: " << finalMet.mpy () );
  //ATH_MSG_INFO( "  met  : " << finalMet.met () );
  //ATH_MSG_INFO( "  phi  : " << finalMet.phi () );
  //ATH_MSG_INFO( "  sumet: " << finalMet.sumet () );
  mySuMetHist->Fill(finalMet.sumet ()*0.001);
  h_metHist->Fill(finalMet.met ()*0.001);

  int goodMuCount = 0;
  int goodElCount = 0;
  
  bool metCut_Wmunu = finalMet.met ()*0.001 > 25;
  float goodMu1_Pt = 0;
  float goodMu1_Mt = 0;
  float goodMu1_Ch = 100;  //make sure original charge is different
  float mumuInvMass = 0;
  TLorentzVector goodMu1;
  TLorentzVector goodMu2;
  TLorentzVector testMu;
  //TLorentzVector goodMu3;

  for(const auto& mu : *muonCont) {

    bool mediumMuon = m_muonSelTool->getQuality(*mu) > 0; 
    bool gradientIsoMuon = m_muIsoSelTool->accept(*mu); 
    //if (m_muIsoSelTool->accept(*mu) > 0)ATH_MSG_INFO( " muon passes isolation "); 
    bool muSelected = (mu->pt()*0.001 > 25 && fabs(mu->eta()) < 2.4 && mediumMuon && gradientIsoMuon);
    bool secondZmuFound = false;
    if (muSelected) {
      goodMuCount++;
      if (goodMuCount == 1) {
        goodMu1_Ch = mu->charge();
        goodMu1_Pt = mu->pt()*0.001;
        goodMu1_Mt = sqrt(2*mu->pt()*finalMet.met()*(1-cos(finalMet.phi()- mu->phi())))*0.001;
        goodMu1.SetPtEtaPhiM(mu->pt(),mu->eta(),mu->phi(),mu->m());
        h_goodMu1_Pt->Fill(mu->pt()*0.001);
        h_goodMu1_PtTLV->Fill(goodMu1.Pt()*0.001);
      }
      // Check if second mu is good for Z to mumu
      // invariant mass cut done later if (goodMuCount > 1) testMu.SetPtEtaPhiM(mu->pt(),mu->eta(),mu->phi(),mu->m());
      if (goodMuCount > 1 && (goodMu1_Ch != mu->charge()) && !secondZmuFound /* && 66 <(goodMu1+testMu).Mag()*0.001 && (goodMu1+testMu).Mag()*0.001 < 116*/) {
        goodMu2.SetPtEtaPhiM(mu->pt(),mu->eta(),mu->phi(),mu->m());
        mumuInvMass = (goodMu1+goodMu2).Mag()*0.001;
        h_mumuInvMass->Fill(mumuInvMass);
        secondZmuFound = true;
        //ATH_MSG_INFO( " Inv Mass "<<(goodMu1+goodMu2).Mag()*0.001<<" Pt1  "<<goodMu1.Pt()*0.001<<" Pt1 "<<goodMu2.Pt()*0.001 );
      }
    }
    // Cut Flow plot for muon selection 
    h_muonPT->Fill(mu->pt()*0.001);
    h_muonEta->Fill(mu->eta());
    if (mediumMuon) {
      h_cutQualMuonPT->Fill(mu->pt()*0.001); 
      if (gradientIsoMuon) h_cutIsoMuonPT->Fill(mu->pt()*0.001); 
        if (goodMuCount > 1) h_cut2GoodMuonPT->Fill(mu->pt()*0.001);
    }
  }
  
  h_nSelMuons->Fill(goodMuCount);

  for(const auto& el : *elCont) {
    h_electronPT->Fill(el->pt()*0.001);
    h_electronEta->Fill(el->eta());

    bool gradientIsoElectron = m_eleIsoSelTool->accept(*el); 
    if (gradientIsoElectron) h_cutIsoElectronPT->Fill(el->pt()*0.001); 

  //if (m_eleIsoSelTool->accept(*el) > 0)ATH_MSG_INFO( " electron passes isolation "); 
    bool elSelected = (el->pt()*0.001 > 25 && fabs(el->eta()) < 2.4 && m_eleIsoSelTool->accept(*el) );
    if (elSelected) goodElCount++;
    //if (elSelected) break;
  }

  //ATH_MSG_INFO ("***execute: before trigDecTool ");
  bool HLT_xe35 = m_trigDecTool->isPassed("HLT_xe35");
  bool HLT_xe35_tc_lcw = m_trigDecTool->isPassed("HLT_xe35_tc_lcw");
  bool HLT_xe35_tc_em = m_trigDecTool->isPassed("HLT_xe35_tc_em");
  bool HLT_xe35_pueta = m_trigDecTool->isPassed("HLT_xe35_pueta");
  bool HLT_xe35_pufit = m_trigDecTool->isPassed("HLT_xe35_pufit");
  bool HLT_xe35_mht = m_trigDecTool->isPassed("HLT_xe35_mht");
  bool HLT_xe35_wEFMu = m_trigDecTool->isPassed("HLT_xe35_wEFMu");

  bool HLT_xe110_mht_L1XE50_AND_xe70_L1XE50 = m_trigDecTool->isPassed("HLT_xe110_mht_L1XE50_AND_xe70_L1XE50");
  bool HLT_xe100_L1XE50 = m_trigDecTool->isPassed("HLT_xe100_L1XE50");
  bool HLT_xe110_mht_L1XE50 = m_trigDecTool->isPassed("HLT_xe110_mht_L1XE50");
  bool HLT_xe140_pueta_L1XE50 = m_trigDecTool->isPassed("HLT_xe140_pueta_L1XE50");
  bool HLT_xe140_pufit_L1XE50 = m_trigDecTool->isPassed("HLT_xe140_pufit_L1XE50");
  bool HLT_xe160_tc_lcw_L1XE50 = m_trigDecTool->isPassed("HLT_xe160_tc_lcw_L1XE50");
  bool HLT_xe160_tc_lcw_wEFMu_L1XE50 = m_trigDecTool->isPassed("HLT_xe160_tc_lcw_wEFMu_L1XE50");
  // checking muon trigger
  bool muon_trigger_Wmunu = (m_trigDecTool->isPassed("HLT_mu26_imedium") || m_trigDecTool->isPassed("HLT_mu24_imedium") || m_trigDecTool->isPassed("HLT_mu40") || m_trigDecTool->isPassed("HLT_mu24_ivarloose") || m_trigDecTool->isPassed("HLT_mu40") || m_trigDecTool->isPassed("HLT_mu50") /**/); 
  bool muon_trigger_Zmumu = muon_trigger_Wmunu ||m_trigDecTool->isPassed("HLT_mu22_mu8noL1") ||m_trigDecTool->isPassed("HLT_mu20_mu8noL1");    
  //ATH_MSG_INFO ("***execute: after trigDecTool ");
  //if (muon_trigger_Wmunu) ATH_MSG_INFO( " Muon trigger passed " );// check if any events pass muon trigger
    // making event selection
  bool eventSelected_Zmumu = (goodMuCount == 2 && goodElCount == 0 && 66 < mumuInvMass && mumuInvMass < 116/**/);
  bool eventSelected_Wmunu = (goodMuCount == 1 && goodElCount == 0 && metCut_Wmunu && goodMu1_Mt > 50/**/);

  if (muon_trigger_Zmumu){
    if(eventSelected_Zmumu) {
      //ATH_MSG_INFO( " Z to Mu Mu event selected " );
      MyZSelMetHist->Fill(finalMet.met ()*0.001);
      h_zmumuSelectMuonPT->Fill(goodMu1_Pt);
      if (HLT_xe35) h_HLT_xe35_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_tc_lcw) h_HLT_xe35_tc_lcw_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_tc_em) h_HLT_xe35_tc_em_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_pueta) h_HLT_xe35_pueta_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_pufit) h_HLT_xe35_pufit_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_mht) h_HLT_xe35_mht_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_wEFMu) h_HLT_xe35_wEFMu_zSel_trig_muon->Fill(finalMet.met ()*0.001);

      if (HLT_xe110_mht_L1XE50_AND_xe70_L1XE50) h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe100_L1XE50) h_HLT_xe100_L1XE50_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe110_mht_L1XE50) h_HLT_xe110_mht_L1XE50_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe140_pueta_L1XE50) h_HLT_xe140_pueta_L1XE50_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe140_pufit_L1XE50) h_HLT_xe140_pufit_L1XE50_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe160_tc_lcw_L1XE50) h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe160_tc_lcw_wEFMu_L1XE50) h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon->Fill(finalMet.met ()*0.001);
      //ATH_MSG_INFO( " electron pt is " << el->pt()*0.001 );
    }
  }
  if (muon_trigger_Wmunu){
    MyWMetHist->Fill(finalMet.met ()*0.001);
    if (HLT_xe100_L1XE50) h_Met_Wtrig_muon->Fill(finalMet.met ()*0.001);
    //-------------W->Mu Nu selected events---------------
    if(eventSelected_Wmunu) {
      MyWSelMetHist->Fill(finalMet.met ()*0.001);

      if (HLT_xe35) h_HLT_xe35_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_tc_lcw) h_HLT_xe35_tc_lcw_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_tc_em) h_HLT_xe35_tc_em_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_pueta) h_HLT_xe35_pueta_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_pufit) h_HLT_xe35_pufit_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_mht) h_HLT_xe35_mht_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe35_wEFMu) h_HLT_xe35_wEFMu_wSel_trig_muon->Fill(finalMet.met ()*0.001);

      if (HLT_xe110_mht_L1XE50_AND_xe70_L1XE50) h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe100_L1XE50) h_HLT_xe100_L1XE50_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe110_mht_L1XE50) h_HLT_xe110_mht_L1XE50_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe140_pueta_L1XE50) h_HLT_xe140_pueta_L1XE50_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe140_pufit_L1XE50) h_HLT_xe140_pufit_L1XE50_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe160_tc_lcw_L1XE50) h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      if (HLT_xe160_tc_lcw_wEFMu_L1XE50) h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->Fill(finalMet.met ()*0.001);
      //ATH_MSG_INFO( " W to Mu Nu event selected" );

      if (goodMuCount > 1) ATH_MSG_INFO( " What Event has "<<goodMuCount<<" good muons" );

      h_wmunuSelectMuonPT->Fill(goodMu1.Pt()*0.001);

      //ATH_MSG_INFO( " electron pt is " << el->pt()*0.001 );
    }
  }
  
  // for selection test
  //ATH_MSG_INFO( "Event has  " << goodMuCount << " good muons and " << goodElCount << " electrons" );
  //ATH_MSG_INFO ("filling histo");
    //if(m_trigDecTool->isPassed("L1_.*")) ATH_MSG_INFO("L1_.*  is passed!");

  //  Test turn on curve of L1 trigger
  // old test trigger. replaced by muon triggersif(m_trigDecTool->isPassed("muon")) h_Met_Wtrig_muon->Fill(finalMet.met ()*0.001);


  //g_eff_HLT_xe35_wSel_trig_muon->Fill(muon_trigger_Wmunu,finalMet.met ()*0.001);
  //g_eff_HLT_xe35_wSel_trig_muonSel->Fill(eventSelected_Wmunu && muon_trigger_Wmunu,finalMet.met ()*0.001);
  //g_eff_HLT_xe35_zSel_trig_muonSel->Fill(eventSelected_Zmumu && muon_trigger_Wmunu,finalMet.met ()*0.001);

  // Change name of h_Met_Wtrig_muon? something related to muon



  //TRUTH ONLY ON MC SAMPLE    const xAOD::MissingETContainer* truthMet(0);
  //TRUTH ONLY ON MC SAMPLE    CHECK( evtStore()->retrieve(truthMet, "MET_Truth") );
  //TRUTH ONLY ON MC SAMPLE
  //TRUTH ONLY ON MC SAMPLE    auto truthMetItr = truthMet->find("NonInt");
  //TRUTH ONLY ON MC SAMPLE    if (truthMetItr == truthMet->end() ) {
  //TRUTH ONLY ON MC SAMPLE      ATH_MSG_ERROR("No NonInt component found in MET_Truth");
  //TRUTH ONLY ON MC SAMPLE      return StatusCode::FAILURE;
  //TRUTH ONLY ON MC SAMPLE    }
  //TRUTH ONLY ON MC SAMPLE
  //TRUTH ONLY ON MC SAMPLE    h_truthMet->Fill( (*truthMetItr)->met() * 0.001);
  //TRUTH ONLY ON MC SAMPLE

  //ATH_MSG_INFO ("***execute: before met trig emulation ");
  //// Emulatinng MET Trigger
  //const xAOD::EnergySumRoI* l1MetObject(0);
  //CHECK( evtStore()->retrieve(l1MetObject, "LVL1EnergySumRoI") );

  //float l1_mex = l1MetObject->exMiss();
  //float l1_mey = l1MetObject->eyMiss();
  //float l1_met = sqrt(l1_mex*l1_mex + l1_mey*l1_mey);
  //
  //// L1 Trigger emulation
  //// L1 decision emulation const xAOD::EnergySumRoI* l1MetObject(0);
  //// L1 decision emulatio  CHECK( evtStore()->retrieve(l1MetObject, "LVL1EnergySumRoI") );
  //// L1 decision emulatio
  //// L1 decision emulatio  float l1_mex = l1MetObject->exMiss();
  //// L1 decision emulatio  float l1_mey = l1MetObject->eyMiss();
  //// L1 decision emulatio
  //// L1 decision emulatio  float l1_met(0.);
  //// L1 decision emulatio  bool l1_overflow(false);
  //// L1 decision emulatio  static LVL1::L1METvalue l1calc;
  //// L1 decision emulatio  // Note that the L1METvalue object expects and returns values in GeV
  //// L1 decision emulatio  l1calc.calcL1MET(l1_mex/1000, l1_mey/1000, l1_met, l1_overflow);
  //// L1 decision emulatio
  //// L1 decision emulatio  float threshold = 50; // GeV (for L1_XE50) 
  //// L1 decision emulatio
  //// L1 decision emulatio  bool passTrigger = l1_overflow || l1_met > threshold;
  //// L1 decision emulatio
  //
  //h_l1Met->Fill(l1_met*0.001);
  //h2_OLvsL1Met->Fill(finalMet.met ()*0.001,l1_met*0.001);

  //ATH_MSG_INFO ("***execute: l1 trig emulation ");
  //// Emulating HLT
  ////const xAOD::TrigMissingETContainer* hltCont(0);
  ////CHECK( evtStore()->retrieve(hltCont, "HLT_xAOD__TrigMissingETContainer_TrigEFMissingET_topocl") );

  ////float ex = hltCont->front()->ex();
  ////float ey = hltCont->front()->ey();

  ////float hltMet = sqrt(ex*ex + ey*ey);

  ////h_HLTMet->Fill(hltMet*0.001);
  ////h2_OLvsHLTMet->Fill(finalMet.met ()*0.001,hltMet*0.001);
  //ATH_MSG_INFO ("***execute: hlt trig emulation ");
  
//  if ( elPass || muPass) {
//    if (!(elPass && muPass)) h_Met_Wtrig_muon->Fill(finalMet.met ()*0.001);
//  }

   //ATH_MSG_INFO ("debug: end execute ");

  return StatusCode::SUCCESS;
  }
 
//  **********************************************************************
bool MyAlg::accept(const xAOD::Muon* mu)
{
  if( mu->pt()<2.5e3 || mu->pt()/cosh(mu->eta())<4e3 ) return false;
  return m_muonSelTool->accept(*mu);
}
bool MyAlg::accept(const xAOD::Electron* el)
{
  if( fabs(el->eta())>2.47 || el->pt()<10e3 ) return false;
  return m_elecSelLHTool->accept(*el);
}
bool MyAlg::accept(const xAOD::Photon* ph)
{
  if( !(ph->author()&20) || fabs(ph->eta())>2.47 || ph->pt()<10e3 ) return false;
  return m_photonSelIsEMTool->accept(ph);
}
bool MyAlg::accept(const xAOD::TauJet* tau)
{ return m_tauSelTool->accept( *tau ); }
//}

