#ifndef TESTMETMAKER_PTPLOTTINGALG_H
#define TESTMETMAKER_PTPLOTTINGALG_H 1

#include "AthAnalysisBaseComps/AthAnalysisAlgorithm.h"


#include <TFile.h>
#include "xAODBase/IParticleContainer.h"




class PtPlottingAlg: public ::AthAnalysisAlgorithm { 
 public: 
  PtPlottingAlg( const std::string& name, ISvcLocator* pSvcLocator );
  virtual ~PtPlottingAlg(); 

  virtual StatusCode  initialize();
  virtual StatusCode  execute();
  virtual StatusCode  finalize();
  
  virtual StatusCode beginInputFile();
  // Configurables
  std::string m_inputCollection;
  std::string m_histogramName;
  std::string m_fileName;
  std::string m_dirName;

  TH1* m_histoPtr;


 private: 

}; 

#endif //> !TESTMETMAKER_PTPLOTTINGALG_H
