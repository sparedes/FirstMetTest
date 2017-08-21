#ifndef TRIGGERLIST_TRIGPASSNUMS_H
#define TRIGGERLIST_TRIGPASSNUMS_H 1

//#include "AthAnalysisBaseComps/AthHistogramAlgorithm.h"
#include "AthenaBaseComps/AthHistogramAlgorithm.h"
#include "AsgTools/AnaToolHandle.h" //use asg::AnaToolHandle instead of regular ToolHandles for full dual-use experience!
#include <vector>
#include <string>

namespace Trig {
  //class ITrigDecisionTool;
  class TrigDecisionTool;
}

class TrigPassNums: public ::AthHistogramAlgorithm { 
 public: 
  TrigPassNums( const std::string& name, ISvcLocator* pSvcLocator );
  virtual ~TrigPassNums(); 

  virtual StatusCode  initialize();
  virtual StatusCode  execute();
  virtual StatusCode  finalize();
  
  virtual StatusCode beginInputFile();

 private: 
  //asg::AnaToolHandle<Trig::ITrigDecisionTool> m_trigDec;
  asg::AnaToolHandle<Trig::TrigDecisionTool> m_trigDec;
  std::vector<std::string> m_trigGroups;
  bool firstEvent;
  bool m_doCorrelations;
  std::vector<std::string> m_trigNames;
}; 

#endif //> !TRIGGERLIST_TRIGPASSNUMS_H
