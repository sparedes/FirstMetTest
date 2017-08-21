#ifndef TESTMETMAKER_MYALG_H
#define TESTMETMAKER_MYALG_H 1

#include "AthAnalysisBaseComps/AthAnalysisAlgorithm.h"


#include "AthenaBaseComps/AthAlgorithm.h"
#include "GaudiKernel/ToolHandle.h"
#include "JetCalibTools/IJetCalibrationTool.h"
#include "xAODEgamma/Electron.h"
#include "xAODEgamma/Photon.h"
#include "xAODMuon/Muon.h"
#include "xAODTau/TauJet.h"


#include "TH1D.h"
#include "TH2D.h"
#include "TTree.h"
#include <TEfficiency.h>

#include "TrigDecisionTool/TrigDecisionTool.h"
#include "IsolationSelection/IIsolationSelectionTool.h"



class IMETMaker;
class IAsgElectronLikelihoodTool;
class IAsgPhotonIsEMSelector;
namespace CP {
  class IMuonSelectionTool;
  class IIsolationSelectionTool;
}
namespace TauAnalysisTools {
  class ITauSelectionTool;
}
namespace Trig {
  class TrigDecisionTool;
  //class ChainGroup;
}
//namespace met {
class MyAlg : public AthAlgorithm {
public: 
  /// Constructor with parameters:
  MyAlg(const std::string& name, ISvcLocator* pSvcLocator);
  /// Destructor:
  ~MyAlg(); 
  /// Athena algorithm's Hooks
  StatusCode  initialize();
  StatusCode  execute();
  StatusCode  finalize();
private: 
  /// Default constructor:
  MyAlg();
  bool accept(const xAOD::Electron* el);
  bool accept(const xAOD::Photon* ph);
  bool accept(const xAOD::TauJet* tau);
  bool accept(const xAOD::Muon* muon);
  std::string m_mapname;
  std::string m_corename;
  std::string m_outname;
  std::string m_softclname;
  std::string m_softtrkname;
  std::string m_jetColl;
  std::string m_eleColl;
  std::string m_gammaColl;
  std::string m_tauColl;
  std::string m_muonColl;
  bool m_doTruthLep;

  TH1D* MyWMetHist;
  TH1D* myHist;
  TH1D* h_metHist;
  TH1D* mySuMetHist;
  TTree* myTree;

  TH1D* h_truthMet;
  TH1D* h_l1Met;
  TH2D* h2_OLvsL1Met;
  TH1D* h_HLTMet;
  TH2D* h2_OLvsHLTMet;
  bool m_isData;
  TH1D* h_Met_Wtrig_muon;
  TH1D* h_l1TrigTurnON;
  TH1D* h_muonPT; 
  TH1D* h_muonEta;
  TH1D* h_electronPT; 
  TH1D* h_electronEta;
  TH1D* h_cutQualMuonPT; 
  TH1D* h_cutQualElectronPT; 
  TH1D* h_cutIsoMuonPT; 
  TH1D* h_cutIsoElectronPT; 
  TH1D* h_cut2GoodMuonPT; 
  TH1D* h_wmunuSelectMuonPT; 
  TH1D* h_zmumuSelectMuonPT; 
  TH1D* h_nSelMuons; 
  TH1D* h_mumuInvMass; 
  TH1D* MyWSelMetHist; 
  TH1D* MyZSelMetHist; 
  TH1D* h_l1TrigMet;
  TH1D* h_goodMu1_PtTLV;
  TH1D* h_goodMu1_Pt;
  TEfficiency* eff_HLT_xe35_wSel_trig_muon;
  TEfficiency* eff_HLT_xe35_tc_lcw_wSel_trig_muon;
  TEfficiency* eff_HLT_xe35_tc_em_wSel_trig_muon;
  TEfficiency* eff_HLT_xe35_pueta_wSel_trig_muon;
  TEfficiency* eff_HLT_xe35_pufit_wSel_trig_muon;
  TEfficiency* eff_HLT_xe35_mht_wSel_trig_muon;
  TEfficiency* eff_HLT_xe35_wEFMu_wSel_trig_muon;
  TEfficiency* eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon;

  TEfficiency* eff_HLT_xe100_L1XE50_wSel_trig_muon;
  TEfficiency* eff_HLT_xe110_mht_L1XE50_wSel_trig_muon;
  TEfficiency* eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon;
  TEfficiency* eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon;
  TEfficiency* eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon;
  TEfficiency* eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon;          

  TEfficiency* eff_HLT_xe35_zSel_trig_muon;
  TEfficiency* eff_HLT_xe35_tc_lcw_zSel_trig_muon;
  TEfficiency* eff_HLT_xe35_tc_em_zSel_trig_muon;
  TEfficiency* eff_HLT_xe35_pueta_zSel_trig_muon;
  TEfficiency* eff_HLT_xe35_pufit_zSel_trig_muon;
  TEfficiency* eff_HLT_xe35_mht_zSel_trig_muon;
  TEfficiency* eff_HLT_xe35_wEFMu_zSel_trig_muon;
  TEfficiency* eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon;

  TEfficiency* eff_HLT_xe100_L1XE50_zSel_trig_muon;
  TEfficiency* eff_HLT_xe110_mht_L1XE50_zSel_trig_muon;
  TEfficiency* eff_HLT_xe140_pueta_L1XE50_zSel_trig_muon;
  TEfficiency* eff_HLT_xe140_pufit_L1XE50_zSel_trig_muon;
  TEfficiency* eff_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon;
  TEfficiency* eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon;

  TEfficiency* g_eff_HLT_xe35_wSel_trig_muon;
  TEfficiency* g_eff_HLT_xe35_wSel_trig_muonSel;
  TEfficiency* g_pzEffSel;


  TH1D* h_HLT_xe35             ;  
  TH1D* h_HLT_xe35_tc_lcw      ;
  TH1D* h_HLT_xe35_tc_em       ;
  TH1D* h_HLT_xe35_pueta       ;
  TH1D* h_HLT_xe35_pufit       ;
  TH1D* h_HLT_xe35_mht         ;
  TH1D* h_HLT_xe35_wEFMu       ;
  TH1D* h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50;

  TH1D* h_HLT_xe100_L1XE50 ;
  TH1D* h_HLT_xe110_mht_L1XE50   ;
  TH1D* h_HLT_xe140_pueta_L1XE50 ;
  TH1D* h_HLT_xe140_pufit_L1XE50 ;
  TH1D* h_HLT_xe160_tc_lcw_L1XE50     ;
  TH1D* h_HLT_xe160_tc_lcw_wEFMu_L1XE50        ;

  TH1D* h_HLT_xe35_zSel_trig_muon;  
  TH1D* h_HLT_xe35_tc_lcw_zSel_trig_muon;
  TH1D* h_HLT_xe35_tc_em_zSel_trig_muon;
  TH1D* h_HLT_xe35_pueta_zSel_trig_muon;
  TH1D* h_HLT_xe35_pufit_zSel_trig_muon;
  TH1D* h_HLT_xe35_mht_zSel_trig_muon;
  TH1D* h_HLT_xe35_wEFMu_zSel_trig_muon;
  TH1D* h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon;

  TH1D* h_HLT_xe100_L1XE50_zSel_trig_muon;
  TH1D* h_HLT_xe110_mht_L1XE50_zSel_trig_muon;
  TH1D* h_HLT_xe140_pueta_L1XE50_zSel_trig_muon;
  TH1D* h_HLT_xe140_pufit_L1XE50_zSel_trig_muon;
  TH1D* h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon;
  TH1D* h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon;

  TH1D* h_HLT_xe35_wSel_trig_muon;  
  TH1D* h_HLT_xe35_tc_lcw_wSel_trig_muon;
  TH1D* h_HLT_xe35_tc_em_wSel_trig_muon;
  TH1D* h_HLT_xe35_pueta_wSel_trig_muon;
  TH1D* h_HLT_xe35_pufit_wSel_trig_muon;
  TH1D* h_HLT_xe35_mht_wSel_trig_muon;
  TH1D* h_HLT_xe35_wEFMu_wSel_trig_muon;
  TH1D* h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon;

  TH1D* h_HLT_xe100_L1XE50_wSel_trig_muon;
  TH1D* h_HLT_xe110_mht_L1XE50_wSel_trig_muon;
  TH1D* h_HLT_xe140_pueta_L1XE50_wSel_trig_muon;
  TH1D* h_HLT_xe140_pufit_L1XE50_wSel_trig_muon;
  TH1D* h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon;
  TH1D* h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon;          

 
  /// Athena configured tools
  ToolHandle<IMETMaker> m_metmaker;
  ToolHandle<CP::IMuonSelectionTool> m_muonSelTool;
  ToolHandle<IAsgElectronLikelihoodTool> m_elecSelLHTool;
  ToolHandle<IAsgPhotonIsEMSelector>     m_photonSelIsEMTool;
  ToolHandle<TauAnalysisTools::ITauSelectionTool> m_tauSelTool;
  ToolHandle<IJetCalibrationTool> m_jetCalibration;
  ToolHandle<Trig::TrigDecisionTool> m_trigDecTool;
  ToolHandle<CP::IIsolationSelectionTool> m_muIsoSelTool;
  ToolHandle<CP::IIsolationSelectionTool> m_eleIsoSelTool;
}; 
//}





//Original code from new_jobo

//class MyAlg: public ::AthAnalysisAlgorithm { 
// public: 
//  MyAlg( const std::string& name, ISvcLocator* pSvcLocator );
//  virtual ~MyAlg(); 
//
//  virtual StatusCode  initialize();
//  virtual StatusCode  execute();
//  virtual StatusCode  finalize();
//  
//  virtual StatusCode beginInputFile();
//
// private: 
//
//}; 

#endif //> !TESTMETMAKER_MYALG_H
