#ifndef TESTMETMAKER_TESTALG_H
#define TESTMETMAKER_TESTALG_H 1

#include "AthenaBaseComps/AthAlgorithm.h"
#include "GaudiKernel/ToolHandle.h" //included under assumption you'll want to use some tools! Remove if you don't!



class TestAlg: public ::AthAlgorithm { 
 public: 
  TestAlg( const std::string& name, ISvcLocator* pSvcLocator );
  virtual ~TestAlg(); 

  virtual StatusCode  initialize();
  virtual StatusCode  execute();
  virtual StatusCode  finalize();

 private: 

}; 

#endif //> !TESTMETMAKER_TESTALG_H
