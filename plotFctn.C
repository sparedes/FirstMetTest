//Script to print TEfficiency objects from a .root file containing only TEfficiency objects. 
//run root, .L thisfile.C, use plotEff() or plotAll()
#include "TFile.h"
#include "TKey.h"
#include "TDirectory.h"

template<typename T> T* readKey(TObject* key) {
    TKey* asKey = dynamic_cast<TKey*>(key);
    return dynamic_cast<T*>(asKey->ReadObj());
}

void plotEff(){
  cout<<"I'm ALIIIIVE (before oppening file)"<<endl;
  //Now using new TEffs made after grid TFile *myEffFile = TFile::Open("/home/paredes/TestArea/athenaMetTest2/GridOut/fullTriggerRun/user.saparede.trigEffJETM11p2950.2403AllTrig_EXT0/myEfficiency.root");
  TFile *myEffFile = TFile::Open("/home/paredes/TestArea/athenaMetTest2/myEffAfterGrid.root");
  TCanvas *C = new TCanvas();
  gStyle->SetOptTitle(kTRUE);
  
  for(auto trigEffKey : *(myEffFile->GetListOfKeys())) {
    auto trigEff = readKey<TEfficiency>(trigEffKey);
    if(trigEff == nullptr) break;
    // Retrieving Trigger name from histogram name 
    TString effName = trigEff->GetName();
    TString newName;
    for(int i = 0; i < effName.Sizeof() - 5; ++i) {
      //if (i+4 == effName.Sizeof()) break;
      bool foundEndOfNameW = effName[i] == '_' && effName[i+1] == 'w' && effName[i+2] == 'S' && effName[i+3] == 'e' && effName[i+4] == 'l'; 
      bool foundEndOfNameZ = effName[i] == '_' && effName[i+1] == 'z' && effName[i+2] == 'S' && effName[i+3] == 'e' && effName[i+4] == 'l'; 
      if(i > 3 && !foundEndOfNameZ && !foundEndOfNameW ) newName += effName[i];
      if(foundEndOfNameW) {
        trigEff->SetTitle("Turn on "+newName+", W #rightarrow #mu#nu events;Offline #slash{E}_{T} [GeV], #mu invisible");//cout<<"New name is "<<newName<<endl<<endl;
      }
      if(foundEndOfNameZ) trigEff->SetTitle("Turn on "+newName+", Z #rightarrow #mu#mu events;Offline #slash{E}_{T} [GeV], #mu invisible");//cout<<"New name is "<<newName<<endl<<endl;
    }
    trigEff->SetLineColor(38);
    trigEff->Draw();
    TString nametext = "/home/paredes/TestArea/athenaMetTest2/plots/trigEff/";
    nametext += trigEff->GetName();    
    nametext += ".png";    
    cout<<nametext<<endl;
    C->Print(nametext);
    C->Clear();
    }
  C->Close();
}

void plotAll()
{
  //Now using new TEffs made after grid TFile *myEffFile = TFile::Open("/home/paredes/TestArea/athenaMetTest2/GridOut/fullTriggerRun/user.saparede.trigEffJETM11p2950.2403AllTrig_EXT0/myEfficiency.root");
  TFile *myEffFile = TFile::Open("/home/paredes/TestArea/athenaMetTest2/myEffAfterGrid.root");
  TCanvas *C = new TCanvas("myCanvas","",1920,1080);
  gStyle->SetOptTitle(kFALSE);
  C->SetTitle("Turn on Curves, various triggers, W #rightarrow #mu #nu");
  gStyle->SetOptStat(0);
  // plotting all triggers for W to mu nu events
  int tcolor = 2;
  bool endOfW = false;
  bool startOfW = false;
  TString skipEffNames[] = {"eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon"};
  for(auto trigEffKey : *(myEffFile->GetListOfKeys())) {
    bool skipEff = false; 
    int i = 0;
    auto trigEff = readKey<TEfficiency>(trigEffKey);
    TString effName = trigEff->GetName();


    // Retrieving Trigger name from histogram name 
    TString newName;
    for(int i = 0; i < effName.Sizeof() - 5; ++i) {
      //if (i+4 == effName.Sizeof()) break;
      bool foundEndOfNameW = effName[i] == '_' && effName[i+1] == 'w' && effName[i+2] == 'S' && effName[i+3] == 'e' && effName[i+4] == 'l'; 
      if(i > 3 && !foundEndOfNameW ) newName += effName[i];
      if(foundEndOfNameW) trigEff->SetTitle(newName+";Offline #slash{E}_{T} [GeV], #mu invisible");//cout<<"New name is "<<newName<<endl<<endl;
    }
    TString firstZName = "eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon";
    TString firstW = "eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon";
    while (i <= sizeof(skipEffNames)/sizeof(*skipEffNames) - 1){
      skipEff = effName == skipEffNames[i];
      i++;
      if (skipEff) i = 10 + sizeof(skipEffNames)/sizeof(*skipEffNames);
    }
    if(!endOfW) endOfW = effName == firstZName;
    if(!startOfW) startOfW = effName == firstW; 
    cout<<effName<<"   "<<endOfW<<endl<<endl;

    if(trigEff == nullptr || endOfW) break;
    
    if (startOfW && !skipEff){
      trigEff->SetLineColor(tcolor);
      trigEff->SetLineWidth(2);
      if (tcolor == 2) trigEff->Draw();
      else trigEff->Draw("SAME");
      tcolor += 10;
    }
  }
  gPad->BuildLegend(0.5,0.13,0.89,0.35);

  TPaveLabel *t = new TPaveLabel(0.12, 0.83, 0.37, 0.89, "W #rightarrow #mu #nu events, Data 2016, #intLdt=6.06 fb^{-1}", "brNDC"); // left-up
  t->Draw();
  C->Print("/home/paredes/TestArea/athenaMetTest2/plots/trigEff/allTrigW.png");
  C->Clear();

  // plotting all triggers for Z to mu mu events
  tcolor = 2;
  bool startOfZ = false;
  C->SetTitle("Turn on Curves, various triggers, Z #rightarrow #mu #mu");
  TString skipEffNamesZ[] = {"eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon"};
  for(auto trigEffKey : *(myEffFile->GetListOfKeys())) {
    bool skipEff = false;
    int i = 0;
    auto trigEff = readKey<TEfficiency>(trigEffKey);
    TString effName = trigEff->GetName();

    // Retrieving Trigger name from histogram name 
    TString newName;
    for(int i = 0; i < effName.Sizeof() - 5; ++i) {
      //if (i+4 == effName.Sizeof()) break;
      bool foundEndOfNameZ = effName[i] == '_' && effName[i+1] == 'z' && effName[i+2] == 'S' && effName[i+3] == 'e' && effName[i+4] == 'l'; 
      if(i > 3 && !foundEndOfNameZ ) newName += effName[i];
      if(foundEndOfNameZ) trigEff->SetTitle(newName+";Offline #slash{E}_{T} [GeV], #mu invisible");//cout<<"New name is "<<newName<<endl<<endl;
    }


    TString firstZName = "eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon";
    while (i <= sizeof(skipEffNamesZ)/sizeof(*skipEffNamesZ) - 1){
      skipEff = effName == skipEffNamesZ[i];
      i++;
      if (skipEff) i = 10 + sizeof(skipEffNamesZ)/sizeof(*skipEffNamesZ);
    }

    if(!startOfZ)startOfZ = effName == firstZName;
    if(trigEff == nullptr) break;
    // mising: stop last histo from printing along with Z
    if(startOfZ && !skipEff){
      trigEff->SetLineColor(tcolor);
      trigEff->SetLineWidth(2);
      if (tcolor == 2) trigEff->Draw();
      else trigEff->Draw("SAME");
      tcolor += 10;
    }
  }
  gPad->BuildLegend(0.5,0.13,0.89,0.35);
  TPaveLabel *t2 = new TPaveLabel(0.12, 0.83, 0.37, 0.89, "Z #rightarrow #mu #mu events, Data 2016, #intLdt=6.06 fb^{-1}", "brNDC"); // left-up
  t2->Draw();
  C->Print("/home/paredes/TestArea/athenaMetTest2/plots/trigEff/allTrigZ.png");
  //C->Clear();
  //C->Close();

  //TFile *_file0 = TFile::Open("/home/paredes/TestArea/athenaMetTest2/GridOut/fullTriggerRun/user.saparede.trigEffJETM11p2950.2403AllTrig_EXT0/myEfficiency.root");
  //TCanvas *C = new TCanvas("myCanvas","",1920,1080);
  //gStyle->SetOptTitle(kFALSE);
  //gStyle->SetOptStat(0);

  //eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->SetLineColor(kBlue);
  //eff_HLT_xe100_L1XE50_wSel_trig_muon->SetLineColor(kRed);
  //eff_HLT_xe110_mht_L1XE50_wSel_trig_muon->SetLineColor(kOrange);
  //eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon->SetLineColor(kGreen);
  //eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon->SetLineColor(kYellow);
  //eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->SetLineColor(kTeal);
  //eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->SetLineColor(kViolet);

  //eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->Draw();
  //eff_HLT_xe100_L1XE50_wSel_trig_muon->Draw("SAME");
  //eff_HLT_xe110_mht_L1XE50_wSel_trig_muon->Draw("SAME");
  //eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon->Draw("SAME");
  //eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon->Draw("SAME");
  //eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->Draw("SAME");
  //eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->Draw("SAME");

  //gPad->BuildLegend(0.6,0.13,0.89,0.3);
  //C->Print("/home/paredes/TestArea/athenaMetTest2/plots/trigEff/allTrig.png");
  //C->Clear();
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
