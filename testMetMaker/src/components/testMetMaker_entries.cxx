
#include "GaudiKernel/DeclareFactoryEntries.h"

#include "../MyAlg.h"

DECLARE_ALGORITHM_FACTORY( MyAlg )


#include "../PtPlottingAlg.h"
DECLARE_ALGORITHM_FACTORY( PtPlottingAlg )


#include "../TestAlg.h"
DECLARE_ALGORITHM_FACTORY( TestAlg )

DECLARE_FACTORY_ENTRIES( testMetMaker ) 
{
  DECLARE_ALGORITHM( TestAlg );
  DECLARE_ALGORITHM( PtPlottingAlg );
  DECLARE_ALGORITHM( MyAlg );
}
