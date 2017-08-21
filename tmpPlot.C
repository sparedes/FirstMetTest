void plotEff()
{
   TCanvas *C = new TCanvas();
   gStyle->SetOptTitle(kFALSE);
   gStyle->SetOptStat(0);

   eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->SetLineColor(kBlue);
   eff_HLT_xe100_L1XE50_wSel_trig_muon->SetLineColor(kRed);
   eff_HLT_xe110_mht_L1XE50_wSel_trig_muon->SetLineColor(kYellow);
   eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon->SetLineColor(kGreen);
   eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon->SetLineColor(kOrange);
   eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->SetLineColor(kBlack);
   eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->SetLineColor(kPink);

   eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon->Draw();
   eff_HLT_xe100_L1XE50_wSel_trig_muon->Draw("SAME");
   eff_HLT_xe110_mht_L1XE50_wSel_trig_muon->Draw("SAME");
   eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon->Draw("SAME");
   eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon->Draw("SAME");
   eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon->Draw("SAME");
   eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon->Draw("SAME");

   gPad->BuildLegend();
   C->Print("/home/paredes/TestArea/athenaMetTest2/plots/trigEff/allTrig.png");
}
//MyWSelMetHist_clone
//MyWSelMetHist_clone
//MyWSelMetHist_clone
//MyWSelMetHist_clone
//MyWSelMetHist_clone
//MyWSelMetHist_clone
//MyWSelMetHist_clone
//eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_wSel_trig_muon
//eff_HLT_xe100_L1XE50_wSel_trig_muon
//eff_HLT_xe110_mht_L1XE50_wSel_trig_muon
//eff_HLT_xe140_pueta_L1XE50_wSel_trig_muon
//eff_HLT_xe140_pufit_L1XE50_wSel_trig_muon
//eff_HLT_xe160_tc_lcw_L1XE50_wSel_trig_muon
//eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_wSel_trig_muon
//MyZSelMetHist_clone
//MyZSelMetHist_clone
//MyZSelMetHist_clone
//MyZSelMetHist_clone
//MyZSelMetHist_clone
//MyZSelMetHist_clone
//MyZSelMetHist_clone
//eff_HLT_xe110_mht_L1XE50_AND_xe70_L1XE50_zSel_trig_muon
//eff_HLT_xe100_L1XE50_zSel_trig_muon
//eff_HLT_xe110_mht_L1XE50_zSel_trig_muon
//eff_HLT_xe140_pueta_L1XE50_zSel_trig_muon
//eff_HLT_xe140_pufit_L1XE50_zSel_trig_muon
//eff_HLT_xe160_tc_lcw_L1XE50_zSel_trig_muon
//eff_HLT_xe160_tc_lcw_wEFMu_L1XE50_zSel_trig_muon
//MyWMetHist_clone
//
