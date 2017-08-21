// TriggerList includes
#include "TriggerListAlg.h"
#include "TrigConfxAOD/xAODConfigTool.h"
#include "TrigDecisionTool/ChainGroup.h"

//#include "xAODEventInfo/EventInfo.h"

//uncomment the line below to use the HistSvc for outputting trees and histograms
//#include "GaudiKernel/ITHistSvc.h"
//#include "TTree.h"
//#include "TH1D.h"



TriggerListAlg::TriggerListAlg( const std::string& name, ISvcLocator* pSvcLocator ) : AthAnalysisAlgorithm( name, pSvcLocator ){

  //declareProperty( "Property", m_nProperty ); //example property declaration

}


TriggerListAlg::~TriggerListAlg() {}


StatusCode TriggerListAlg::initialize() {
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

  ATH_CHECK(m_trigConf.make("TrigConf::xAODConfigTool/configTool") );
  ATH_CHECK(m_trigConf.retrieve() );

  ATH_CHECK(m_trigTool.make("Trig::TrigDecisionTool/trigTool") );
  ATH_CHECK(m_trigTool.setProperty("ConfigTool", m_trigConf.getHandle() ) );
  ATH_CHECK(m_trigTool.setProperty("TrigDecisionKey", "xTrigDecision") );
  ATH_CHECK(m_trigTool.retrieve() );

  return StatusCode::SUCCESS;
}

StatusCode TriggerListAlg::finalize() {
  ATH_MSG_INFO ("Finalizing " << name() << "...");
  //
  //Things that happen once at the end of the event loop go here
  //


  return StatusCode::SUCCESS;
}

StatusCode TriggerListAlg::execute() {  
  ATH_MSG_DEBUG ("Executing " << name() << "...");
  setFilterPassed(false); //optional: start with algorithm not passed

  const Trig::ChainGroup* HLT = m_trigTool->getChainGroup(".*");
  for (const std::string& trigName : HLT->getListOfTriggers() ) {
    ATH_MSG_INFO(trigName << ", " << m_trigTool->getChainGroup(trigName)->getPrescale() );
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

StatusCode TriggerListAlg::beginInputFile() { 
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


