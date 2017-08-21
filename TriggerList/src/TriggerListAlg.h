#ifndef TRIGGERLIST_TRIGGERLISTALG_H
#define TRIGGERLIST_TRIGGERLISTALG_H 1

#include "AthAnalysisBaseComps/AthAnalysisAlgorithm.h"
#include "AsgTools/AnaToolHandle.h" //use asg::AnaToolHandle instead of regular ToolHandles for full dual-use experience!

#include "TrigDecisionTool/TrigDecisionTool.h"
//namespace Trig {
  //class TrigDecisionTool;
//}
#include "TrigConfInterfaces/ITrigConfigTool.h"
//namespace TrigConf {
  //class ITrigConfigTool;
//}


class TriggerListAlg: public ::AthAnalysisAlgorithm { 
 public: 
  TriggerListAlg( const std::string& name, ISvcLocator* pSvcLocator );
  virtual ~TriggerListAlg(); 

  virtual StatusCode  initialize();
  virtual StatusCode  execute();
  virtual StatusCode  finalize();
  
  virtual StatusCode beginInputFile();

 private: 

  asg::AnaToolHandle<TrigConf::ITrigConfigTool> m_trigConf;
  asg::AnaToolHandle<Trig::TrigDecisionTool> m_trigTool;

}; 

#endif //> !TRIGGERLIST_TRIGGERLISTALG_H
