// TriggerList includes
#include "TrigPassNums.h"

//#include "xAODEventInfo/EventInfo.h"

//uncomment the line below to use the HistSvc for outputting trees and histograms
//#include "GaudiKernel/ITHistSvc.h"
//#include "TTree.h"
//#include "TH1D.h"
//#include "TrigDecisionInterface/ITrigDecisionTool.h"
#include "TrigConfInterfaces/ITrigConfigTool.h"
#include "TrigDecisionTool/TrigDecisionTool.h"


TrigPassNums::TrigPassNums( const std::string& name, ISvcLocator* pSvcLocator )
  : AthHistogramAlgorithm( name, pSvcLocator ),
    firstEvent(true)
{
  declareProperty( "TriggerGroups", m_trigGroups );
  declareProperty( "DoCorrelations", m_doCorrelations = true );
  //declareProperty( "Property", m_nProperty ); //example property declaration

}


TrigPassNums::~TrigPassNums() {}


StatusCode TrigPassNums::initialize() {
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

  ATH_CHECK( m_trigDec.make("Trig::TrigDecisionTool/TrigDecisionTool") );
  if (!m_trigDec.isUserConfigured() ) {
    asg::AnaToolHandle<TrigConf::ITrigConfigTool> trigConfTool;
    ATH_CHECK( trigConfTool.make("TrigConf::xAODConfigTool/xAODConfigTool") );
    ATH_CHECK( trigConfTool.retrieve() );

    ATH_CHECK( m_trigDec.setProperty( "ConfigTool", trigConfTool ) );
    ATH_CHECK( m_trigDec.setProperty( "TrigDecisionKey", "xTrigDecision" ) );
  }
  ATH_CHECK( m_trigDec.retrieve() );

  return StatusCode::SUCCESS;
}

StatusCode TrigPassNums::finalize() {
  ATH_MSG_INFO ("Finalizing " << name() << "...");
  //
  //Things that happen once at the end of the event loop go here
  //

  hist("passTrigger")->LabelsDeflate("X");
  if (m_doCorrelations) {
    hist2d("passTrigger_corr")->LabelsDeflate("X");
    hist2d("passTrigger_corr")->LabelsDeflate("Y");
  }

  return StatusCode::SUCCESS;
}

StatusCode TrigPassNums::execute() {  
  ATH_MSG_DEBUG ("Executing " << name() << "...");
  setFilterPassed(false); //optional: start with algorithm not passed

  if (firstEvent) {
    firstEvent = false;
    ATH_CHECK( book(TH1F("passTrigger", "", 1, 0, 1) ) );
    if (m_doCorrelations) ATH_CHECK( book(TH2F("passTrigger_corr", "", 1, 0, 1, 1, 0, 1) ) );
    for (const std::string& group : m_trigGroups) {
      for (const std::string& trigName : m_trigDec->getChainGroup(group)->getListOfTriggers() ) {
        m_trigNames.push_back(trigName);
        hist("passTrigger")->Fill(trigName.c_str(), 0);
        if (m_doCorrelations) hist2d("passTrigger_corr")->Fill(trigName.c_str(), trigName.c_str(), 0);
      }
    }
  }

  TH1* h1 = hist("passTrigger");
  TH2* h2;
  if (m_doCorrelations) h2 = hist2d("passTrigger_corr");
  for (const std::string& trigName : m_trigNames) {
    if (m_trigDec->isPassed(trigName) ) {
      h1->Fill(trigName.c_str(), 1);
      if (m_doCorrelations) {
        for (const std::string& trigName2 : m_trigNames) {
          if (m_trigDec->isPassed(trigName2) ) {
            h2->Fill(trigName.c_str(), trigName2.c_str(), 1);
          }
        }
      }
    }
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

StatusCode TrigPassNums::beginInputFile() { 
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


