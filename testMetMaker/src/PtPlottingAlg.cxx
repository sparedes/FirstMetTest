// testMetMaker includes
#include "PtPlottingAlg.h"

//#include "xAODEventInfo/EventInfo.h"

//uncomment the line below to use the HistSvc for outputting trees and histograms
//#include "GaudiKernel/ITHistSvc.h"
//#include "TTree.h"
//#include "TH1D.h"



PtPlottingAlg::PtPlottingAlg( const std::string& name, ISvcLocator* pSvcLocator ) : AthAnalysisAlgorithm( name, pSvcLocator ){

  //declareProperty( "Property", m_nProperty ); //example property declaration
  declareProperty("Input", m_inputCollection = "Electrons");
  declareProperty("HistogramName", m_histogramName = "elePt");
  declareProperty("FileName", m_fileName = "out-hist.root");
  declareProperty("DirName", m_dirName = "");

}


PtPlottingAlg::~PtPlottingAlg() {}


StatusCode PtPlottingAlg::initialize() {
  ATH_MSG_INFO ("Initializing " << name() << "...");
  //
  //This is called once, before the start of the event loop
  //Retrieves of tools you have configured in the joboptions go here
  //

  //HERE IS AN EXAMPLE
  //We will create a histogram and a ttree and register them to the histsvc
  //Remember to uncomment the configuration of the histsvc stream in the joboptions
  //
  //ServiceHandle<ITHistSvc> histSvc("THistSvc",name());
  //TH1D* myHist = new TH1D("myHist","myHist",10,0,10);
  //CHECK( histSvc->regHist("/MYSTREAM/myHist", myHist) ); //registers histogram to output stream (like SetDirectory in EventLoop)
  //TTree* myTree = new TTree("myTree","myTree");
  //CHECK( histSvc->regTree("/MYSTREAM/SubDirectory/myTree", myTree) ); //registers tree to output stream (like SetDirectory in EventLoop) inside a sub-directory


  ATH_CHECK( book( TH1F(m_histogramName.c_str(), ";p_{T} [GeV]", 40, 0, 200) ) );
  m_histoPtr = hist(m_histogramName);


  return StatusCode::SUCCESS;
}

StatusCode PtPlottingAlg::finalize() {
  ATH_MSG_INFO ("Finalizing " << name() << "...");
  //
  //Things that happen once at the end of the event loop go here
  //
  TFile* fout = new TFile(m_fileName.c_str(), "RECREATE");
  if (!m_dirName.empty() ) {
    TDirectory* fdir = fout->mkdir(m_dirName.c_str() );
    fdir->cd();
  }
  m_histoPtr->Write();
  fout->Close();


  return StatusCode::SUCCESS;
}

StatusCode PtPlottingAlg::execute() {  
  ATH_MSG_DEBUG ("Executing " << name() << "...");
  setFilterPassed(false); //optional: start with algorithm not passed

  const xAOD::IParticleContainer* cont(0);
  ATH_CHECK(evtStore()->retrieve(cont, m_inputCollection) );
  for (const xAOD::IParticle* part : *cont) {
    m_histoPtr->Fill(part->pt() * 0.001); // Values stored in MeV but we want to plot in GeV
  }




  //
  //Your main analysis code goes here
  //If you will use this algorithm to perform event skimming, you
  //should ensure the setFilterPassed method is called
  //If never called, the algorithm is assumed to have 'passed' by default
  //


  //HERE IS AN EXAMPLE
  //const xAOD::EventInfo* evtInfo = 0;
  //CHECK( evtStore()->retrieve( evtInfo, "EventInfo" ) );
  //ATH_MSG_INFO("eventNumber=" << evtInfo->eventNumber() );


  setFilterPassed(true); //if got here, assume that means algorithm passed
  return StatusCode::SUCCESS;
}

StatusCode PtPlottingAlg::beginInputFile() { 
  //
  //This method is called at the start of each input file, even if
  //the input file contains no events. Accumulate metadata information here
  //

  //example of retrieval of CutBookkeepers: (remember you will need to include the necessary header files and use statements in requirements file)
  // const xAOD::CutBookkeeperContainer* bks = 0;
  // CHECK( inputMetaStore()->retrieve(bks, "CutBookkeepers") );

  //example of IOVMetaData retrieval (see https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/AthAnalysisBase#How_to_access_file_metadata_in_C)
  //float beamEnergy(0); CHECK( retrieveMetadata("/TagInfo","beam_energy",beamEnergy) );
  //std::vector<float> bunchPattern; CHECK( retrieveMetadata("/Digitiation/Parameters","BeamIntensityPattern",bunchPattern) );



  return StatusCode::SUCCESS;
}


