//Script to print TEfficiency objects from a .root file containing only TEfficiency objects. 
//run root, .L thisfile.C, makeEff()
#include "TFile.h"
#include "TKey.h"
#include "TDirectory.h"
#include "TEfficiency.h"

template<typename T> T* readKey(TObject* key) {
    TKey* asKey = dynamic_cast<TKey*>(key);
    return dynamic_cast<T*>(asKey->ReadObj());
}

void makeEff(){

  TFile *myHistoFile = TFile::Open("/home/paredes/TestArea/athenaMetTest2/GridOut/fullTriggerRun/user.saparede.trigEffJETM11p2950.2403AllTrig_MYSTREAM/myHisotFile.root");
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


  //Re Binning histograms
  MyWMetHist->Rebin(5);
  h_metHist->Rebin(5);
  L1Met->Rebin(5);
  HLTMet->Rebin(5);
  h_Met_Wtrig_muon->Rebin(5);
  l1TrigTurnON->Rebin(5);
  h_HLT_xe35->Rebin(5);
  h_HLT_xe35_tc_lcw->Rebin(5);
  h_HLT_xe35_tc_em->Rebin(5);
  h_HLT_xe35_pueta->Rebin(5);
  h_HLT_xe35_pufit->Rebin(5);
  h_HLT_xe35_mht->Rebin(5);
  h_HLT_xe35_wEFMu->Rebin(5);
  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50->Rebin(5);
  h_HLT_xe100_L1XE50->Rebin(5);
  h_HLT_xe110_mht_L1XE50->Rebin(5);
  h_HLT_xe140_pueta_L1XE50->Rebin(5);
  h_HLT_xe140_pufit_L1XE50->Rebin(5);
  h_HLT_xe160_tc_lcw_L1XE50->Rebin(5);
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50->Rebin(5);
  h_HLT_xe35_wSel_trig_muon->Rebin(5);
  h_HLT_xe35_tc_lcw_wSel_trig_muon->Rebin(5);
  h_HLT_xe35_tc_em_wSel_trig_muon->Rebin(5);
  h_HLT_xe35_pueta_wSel_trig_muon->Rebin(5);
  h_HLT_xe35_pufit_wSel_trig_muon->Rebin(5);
  h_HLT_xe35_mht_wSel_trig_muon->Rebin(5);
  h_HLT_xe35_wEFMu_wSel_trig_muon->Rebin(5);
  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->Rebin(5);
  h_HLT_xe100_L1XE50_wSel_trig_muon->Rebin(5);
  h_HLT_xe110_mht_L1XE50_wSel_trig_muon->Rebin(5);
  h_HLT_xe140_pueta_L1XE50_wSel_trig_muon->Rebin(5);
  h_HLT_xe140_pufit_L1XE50_wSel_trig_muon->Rebin(5);
  h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->Rebin(5);
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->Rebin(5);
  h_HLT_xe35_zSel_trig_muon->Rebin(5);
  h_HLT_xe35_tc_lcw_zSel_trig_muon->Rebin(5);
  h_HLT_xe35_tc_em_zSel_trig_muon->Rebin(5);
  h_HLT_xe35_pueta_zSel_trig_muon->Rebin(5);
  h_HLT_xe35_pufit_zSel_trig_muon->Rebin(5);
  h_HLT_xe35_mht_zSel_trig_muon->Rebin(5);
  h_HLT_xe35_wEFMu_zSel_trig_muon->Rebin(5);
  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon->Rebin(5);
  h_HLT_xe100_L1XE50_zSel_trig_muon->Rebin(5);
  h_HLT_xe110_mht_L1XE50_zSel_trig_muon->Rebin(5);
  h_HLT_xe140_pueta_L1XE50_zSel_trig_muon->Rebin(5);
  h_HLT_xe140_pufit_L1XE50_zSel_trig_muon->Rebin(5);
  h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon->Rebin(5);
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon->Rebin(5);
  nSelMuons->Rebin(5);
  mumuInvMass->Rebin(5);
  h_goodMu1_Pt->Rebin(5);
  h_goodMu1_PtTLV->Rebin(5);
  muonPT->Rebin(5);
  cutQualMuonPT->Rebin(5);
  cutIsoMuonPT->Rebin(5);
  cut2GoodMuonPT->Rebin(5);
  electronPT->Rebin(5);
  cutQualElectronPT->Rebin(5);
  cutIsoElectronPT->Rebin(5);
  MyWSelMetHist->Rebin(5);
  MyZSelMetHist->Rebin(5);
  wmunuSelectMuonPT->Rebin(5);
  zmumuSelectMuonPT->Rebin(5);
  
  TFile* myFile = new TFile("myHistoAfterGrid.root","recreate");

  MyWMetHist->Write();
  h_metHist->Write();
  L1Met->Write();
  HLTMet->Write();
  h_Met_Wtrig_muon->Write();
  l1TrigTurnON->Write();
  h_HLT_xe35->Write();
  h_HLT_xe35_tc_lcw->Write();
  h_HLT_xe35_tc_em->Write();
  h_HLT_xe35_pueta->Write();
  h_HLT_xe35_pufit->Write();
  h_HLT_xe35_mht->Write();
  h_HLT_xe35_wEFMu->Write();
  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50->Write();
  h_HLT_xe100_L1XE50->Write();
  h_HLT_xe110_mht_L1XE50->Write();
  h_HLT_xe140_pueta_L1XE50->Write();
  h_HLT_xe140_pufit_L1XE50->Write();
  h_HLT_xe160_tc_lcw_L1XE50->Write();
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50->Write();
  h_HLT_xe35_wSel_trig_muon->Write();
  h_HLT_xe35_tc_lcw_wSel_trig_muon->Write();
  h_HLT_xe35_tc_em_wSel_trig_muon->Write();
  h_HLT_xe35_pueta_wSel_trig_muon->Write();
  h_HLT_xe35_pufit_wSel_trig_muon->Write();
  h_HLT_xe35_mht_wSel_trig_muon->Write();
  h_HLT_xe35_wEFMu_wSel_trig_muon->Write();
  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->Write();
  h_HLT_xe100_L1XE50_wSel_trig_muon->Write();
  h_HLT_xe110_mht_L1XE50_wSel_trig_muon->Write();
  h_HLT_xe140_pueta_L1XE50_wSel_trig_muon->Write();
  h_HLT_xe140_pufit_L1XE50_wSel_trig_muon->Write();
  h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->Write();
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->Write();
  h_HLT_xe35_zSel_trig_muon->Write();
  h_HLT_xe35_tc_lcw_zSel_trig_muon->Write();
  h_HLT_xe35_tc_em_zSel_trig_muon->Write();
  h_HLT_xe35_pueta_zSel_trig_muon->Write();
  h_HLT_xe35_pufit_zSel_trig_muon->Write();
  h_HLT_xe35_mht_zSel_trig_muon->Write();
  h_HLT_xe35_wEFMu_zSel_trig_muon->Write();
  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon->Write();
  h_HLT_xe100_L1XE50_zSel_trig_muon->Write();
  h_HLT_xe110_mht_L1XE50_zSel_trig_muon->Write();
  h_HLT_xe140_pueta_L1XE50_zSel_trig_muon->Write();
  h_HLT_xe140_pufit_L1XE50_zSel_trig_muon->Write();
  h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon->Write();
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon->Write();
  nSelMuons->Write();
  mumuInvMass->Write();
  h_goodMu1_Pt->Write();
  h_goodMu1_PtTLV->Write();
  muonPT->Write();
  cutQualMuonPT->Write();
  cutIsoMuonPT->Write();
  cut2GoodMuonPT->Write();
  electronPT->Write();
  cutQualElectronPT->Write();
  cutIsoElectronPT->Write();
  MyWSelMetHist->Write();
  MyZSelMetHist->Write();
  wmunuSelectMuonPT->Write();
  zmumuSelectMuonPT->Write();

  MyWMetHist->GetCumulative(kFALSE)->Write();
  h_metHist->GetCumulative(kFALSE)->Write();
  L1Met->GetCumulative(kFALSE)->Write();
  HLTMet->GetCumulative(kFALSE)->Write();
  h_Met_Wtrig_muon->GetCumulative(kFALSE)->Write();
  l1TrigTurnON->GetCumulative(kFALSE)->Write();
  h_HLT_xe35->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_tc_lcw->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_tc_em->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_pueta->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_pufit->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_mht->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_wEFMu->GetCumulative(kFALSE)->Write();
  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50->GetCumulative(kFALSE)->Write();
  h_HLT_xe100_L1XE50->GetCumulative(kFALSE)->Write();
  h_HLT_xe110_mht_L1XE50->GetCumulative(kFALSE)->Write();
  h_HLT_xe140_pueta_L1XE50->GetCumulative(kFALSE)->Write();
  h_HLT_xe140_pufit_L1XE50->GetCumulative(kFALSE)->Write();
  h_HLT_xe160_tc_lcw_L1XE50->GetCumulative(kFALSE)->Write();
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_tc_lcw_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_tc_em_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_pueta_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_pufit_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_mht_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_wEFMu_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe100_L1XE50_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe110_mht_L1XE50_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe140_pueta_L1XE50_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe140_pufit_L1XE50_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_tc_lcw_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_tc_em_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_pueta_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_pufit_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_mht_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe35_wEFMu_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe100_L1XE50_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe110_mht_L1XE50_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe140_pueta_L1XE50_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe140_pufit_L1XE50_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  h_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon->GetCumulative(kFALSE)->Write();
  nSelMuons->GetCumulative(kFALSE)->Write();
  mumuInvMass->GetCumulative(kFALSE)->Write();
  h_goodMu1_Pt->GetCumulative(kFALSE)->Write();
  h_goodMu1_PtTLV->GetCumulative(kFALSE)->Write();
  muonPT->GetCumulative(kFALSE)->Write();
  cutQualMuonPT->GetCumulative(kFALSE)->Write();
  cutIsoMuonPT->GetCumulative(kFALSE)->Write();
  cut2GoodMuonPT->GetCumulative(kFALSE)->Write();
  electronPT->GetCumulative(kFALSE)->Write();
  cutQualElectronPT->GetCumulative(kFALSE)->Write();
  cutIsoElectronPT->GetCumulative(kFALSE)->Write();
  MyWSelMetHist->GetCumulative(kFALSE)->Write();
  MyZSelMetHist->GetCumulative(kFALSE)->Write();
  wmunuSelectMuonPT->GetCumulative(kFALSE)->Write();
  zmumuSelectMuonPT->GetCumulative(kFALSE)->Write();

  myFile->Close();

  TFile* pFile = new TFile("myEffAfterGrid.root","recreate");

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
}
