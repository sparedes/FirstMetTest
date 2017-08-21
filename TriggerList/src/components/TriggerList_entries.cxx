
#include "GaudiKernel/DeclareFactoryEntries.h"

#include "../TriggerListAlg.h"

DECLARE_ALGORITHM_FACTORY( TriggerListAlg )


#include "../TrigPassNums.h"
DECLARE_ALGORITHM_FACTORY( TrigPassNums )

DECLARE_FACTORY_ENTRIES( TriggerList ) 
{
  DECLARE_ALGORITHM( TrigPassNums );
  DECLARE_ALGORITHM( TriggerListAlg );
}
