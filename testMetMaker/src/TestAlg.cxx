// testMetMaker includes
#include "TestAlg.h"



TestAlg::TestAlg( const std::string& name, ISvcLocator* pSvcLocator ) : AthAlgorithm( name, pSvcLocator ){

  //declareProperty( "Property", m_nProperty ); //example property declaration

}


TestAlg::~TestAlg() {}


StatusCode TestAlg::initialize() {
  ATH_MSG_INFO ("Initializing " << name() << "...");

  return StatusCode::SUCCESS;
}

StatusCode TestAlg::finalize() {
  ATH_MSG_INFO ("Finalizing " << name() << "...");

  return StatusCode::SUCCESS;
}

StatusCode TestAlg::execute() {  
  ATH_MSG_DEBUG ("Executing " << name() << "...");

  return StatusCode::SUCCESS;
}


