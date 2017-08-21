----------> uses
# use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#   use ExternalPolicy ExternalPolicy-* External (no_version_directory)
#     use PlatformPolicy PlatformPolicy-* External (no_version_directory)
#       use GaudiPolicy *  (no_version_directory)
#         use LCG_Settings *  (no_version_directory)
#         use Python * LCG_Interfaces (no_auto_imports) (no_version_directory) (native_version=2.7.9.p1)
#           use LCG_Configuration v*  (no_version_directory)
#           use LCG_Settings v*  (no_version_directory)
#         use tcmalloc * LCG_Interfaces (no_auto_imports) (no_version_directory) (native_version=2.4)
#           use LCG_Configuration v*  (no_version_directory)
#           use LCG_Settings v*  (no_version_directory)
#           use libunwind v* LCG_Interfaces (no_version_directory) (native_version=5c2cade)
#             use LCG_Configuration v*  (no_version_directory)
#             use LCG_Settings v*  (no_version_directory)
#         use Reflex v* LCG_Interfaces (no_auto_imports) (no_version_directory)
#       use AtlasCommonPolicy AtlasCommonPolicy-*  (no_version_directory)
#         use LCG_Platforms *  (no_version_directory)
#         use AtlasDoxygen AtlasDoxygen-* Tools (no_version_directory) (native_version=)
#           use LCG_Settings *  (no_version_directory)
#           use LCG_Configuration *  (no_version_directory)
#             use LCG_Platforms *  (no_version_directory)
#     use Mac105_Compat Mac105_Compat-* External (no_version_directory) (native_version=1.0.0)
#       use AtlasExternalArea AtlasExternalArea-* External (no_version_directory)
#         use LCG_Settings v*  (no_version_directory)
#         use PlatformPolicy PlatformPolicy-* External (no_version_directory)
#       use PlatformPolicy PlatformPolicy-* External (no_version_directory)
#   use AtlasCxxPolicy AtlasCxxPolicy-*  (no_version_directory)
#     use GaudiPolicy v*  (no_auto_imports) (no_version_directory)
#     use ExternalPolicy ExternalPolicy-* External (no_version_directory)
#     use AtlasCompilers AtlasCompilers-* External (no_version_directory)
#       use LCG_Platforms *  (no_version_directory)
#     use CheckerGccPlugins CheckerGccPlugins-* External (no_version_directory) (native_version=CheckerGccPlugins-00-01-84)
#       use ExternalPolicy ExternalPolicy-* External (no_version_directory)
#       use AtlasCompilers AtlasCompilers-* External (no_version_directory)
#   use AtlasCommonPolicy AtlasCommonPolicy-*  (no_version_directory)
#   use GaudiPolicy v*  (no_auto_imports) (no_version_directory)
#   use CodeCheck CodeCheck-* Tools (no_version_directory)
#   use AtlasDoxygen AtlasDoxygen-* Tools (no_version_directory) (native_version=)
# use GaudiInterface GaudiInterface-* External (no_version_directory)
#   use ExternalPolicy ExternalPolicy-00-* External (no_version_directory)
#   use GaudiKernel v*  (no_version_directory)
#     use GaudiPolicy *  (no_version_directory)
#     use GaudiPluginService *  (no_version_directory)
#       use GaudiPolicy *  (no_version_directory)
#     use Reflex * LCG_Interfaces (no_version_directory)
#       use LCG_Configuration v*  (no_version_directory)
#       use LCG_Settings v*  (no_version_directory)
#       use ROOT v* LCG_Interfaces (no_auto_imports) (no_version_directory) (native_version=6.04.16)
#     use Boost * LCG_Interfaces (no_version_directory) (native_version=1.59.0_python2.7)
#       use LCG_Configuration v*  (no_version_directory)
#       use LCG_Settings v*  (no_version_directory)
#       use Python v* LCG_Interfaces (no_auto_imports) (no_version_directory) (native_version=2.7.9.p1)
# use AthAnalysisBaseComps AthAnalysisBaseComps-* Control (no_version_directory)
#   use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#   use GaudiInterface GaudiInterface-* External (no_version_directory)
#   use StoreGate StoreGate-* Control (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use AthenaKernel AthenaKernel-* Control (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use uuid v* LCG_Interfaces (no_version_directory) (native_version=dummy)
#         use LCG_Configuration v*  (no_version_directory)
#         use LCG_Settings v*  (no_version_directory)
#       use GaudiInterface GaudiInterface-* External (no_version_directory)
#       use DataModelRoot DataModelRoot-* Control (no_version_directory)
#         use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#         use AtlasROOT AtlasROOT-* External (no_version_directory)
#           use ExternalPolicy ExternalPolicy-* External (no_version_directory)
#           use ROOT v* LCG_Interfaces (no_version_directory) (native_version=6.04.16)
#             use LCG_Configuration v*  (no_version_directory)
#             use LCG_Settings v*  (no_version_directory)
#             use GCCXML v* LCG_Interfaces (no_auto_imports) (no_version_directory) (native_version=0.9.0_20131026)
#               use LCG_Configuration v*  (no_version_directory)
#               use LCG_Settings v*  (no_version_directory)
#             use Python v* LCG_Interfaces (no_auto_imports) (no_version_directory) (native_version=2.7.9.p1)
#             use xrootd v* LCG_Interfaces (no_version_directory) (native_version=4.2.3)
#               use LCG_Configuration v*  (no_version_directory)
#               use LCG_Settings v*  (no_version_directory)
#         use AtlasReflex AtlasReflex-* External (no_version_directory)
#           use ExternalPolicy ExternalPolicy-* External (no_version_directory)
#           use AtlasRELAX AtlasRELAX-* External (no_auto_imports) (no_version_directory)
#             use ExternalPolicy ExternalPolicy-* External (no_version_directory)
#             use RELAX v* LCG_Interfaces (no_version_directory) (native_version=RELAX-root6)
#               use LCG_Configuration v*  (no_version_directory)
#               use LCG_Settings v*  (no_version_directory)
#           use AtlasROOT AtlasROOT-* External (no_version_directory)
#       use CxxUtils CxxUtils-* Control (no_version_directory)
#         use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#         use AtlasBoost AtlasBoost-* External (no_version_directory)
#           use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#           use Boost v* LCG_Interfaces (no_version_directory) (native_version=1.59.0_python2.7)
#       use AtlasBoost AtlasBoost-* External (no_version_directory)
#       use Scripts Scripts-* Tools (no_auto_imports) (no_version_directory)
#         use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use SGTools SGTools-* Control (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use CxxUtils CxxUtils-* Control (no_version_directory)
#       use AthenaKernel AthenaKernel-* Control (no_version_directory)
#       use AtlasBoost AtlasBoost-* External (no_version_directory)
#       use GaudiInterface GaudiInterface-* External (no_version_directory)
#     use AtlasBoost AtlasBoost-* External (no_version_directory)
#     use AtlasTBB AtlasTBB-* External (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use ExternalPolicy ExternalPolicy-* External (no_version_directory)
#       use PyCmt PyCmt-* Tools (no_auto_imports) (no_version_directory)
#         use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#         use AtlasPython AtlasPython-* External (no_auto_imports) (no_version_directory)
#           use ExternalPolicy ExternalPolicy-00-* External (no_version_directory)
#           use Python v* LCG_Interfaces (no_version_directory) (native_version=2.7.9.p1)
#     use GaudiInterface GaudiInterface-* External (no_version_directory)
#     use AthAllocators AthAllocators-* Control (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use GaudiInterface GaudiInterface-* External (no_version_directory)
#       use AtlasBoost AtlasBoost-* External (no_version_directory)
#     use AthContainersInterfaces AthContainersInterfaces-* Control (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use SGTools SGTools-* Control (no_version_directory)
#       use CxxUtils CxxUtils-* Control (no_version_directory)
#       use AtlasBoost AtlasBoost-* External (no_version_directory)
#   use AthenaBaseComps AthenaBaseComps-* Control (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use GaudiInterface GaudiInterface-* External (no_version_directory)
#     use AtlasROOT AtlasROOT-* External (no_version_directory)
#     use AthenaKernel AthenaKernel-* Control (no_version_directory)
#     use StoreGate StoreGate-* Control (no_version_directory)
#     use SGTools SGTools-* Control (no_version_directory)
#     use CxxUtils CxxUtils-* Control (no_version_directory)
#   use IOVDbDataModel IOVDbDataModel-* Database (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use GaudiInterface GaudiInterface-* External (no_version_directory)
#     use CLIDSvc CLIDSvc-* Control (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use SGTools SGTools-* Control (no_version_directory)
#       use AtlasPython AtlasPython-* External (no_auto_imports) (no_version_directory)
#     use AthenaPoolUtilities AthenaPoolUtilities-* Database/AthenaPOOL (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use AtlasCORAL AtlasCORAL-* External (no_version_directory)
#         use ExternalPolicy ExternalPolicy-00-* External (no_version_directory)
#         use CORAL v* LCG_Interfaces (no_version_directory) (native_version=3_1_0)
#           use LCG_Configuration v*  (no_version_directory)
#           use LCG_Settings v*  (no_version_directory)
#           use Boost v* LCG_Interfaces (no_version_directory) (native_version=1.59.0_python2.7)
#         use AtlasReflex AtlasReflex-00-* External (no_auto_imports) (no_version_directory)
#       use AthenaKernel AthenaKernel-* Control (no_version_directory)
#       use CLIDSvc CLIDSvc-* Control (no_version_directory)
#       use DataModel DataModel-* Control (no_version_directory)
#         use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#         use SGTools SGTools-* Control (no_version_directory)
#         use AthAllocators AthAllocators-* Control (no_version_directory)
#         use AthLinks AthLinks-* Control (no_version_directory)
#           use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#           use AthenaKernel AthenaKernel-* Control (no_version_directory)
#           use SGTools SGTools-* Control (no_version_directory)
#           use CxxUtils CxxUtils-* Control (no_version_directory)
#           use AtlasBoost AtlasBoost-* External (no_version_directory)
#           use GaudiInterface GaudiInterface-* External (no_version_directory)
#           use AtlasReflex AtlasReflex-* External (no_version_directory)
#         use AthContainers AthContainers-* Control (no_version_directory)
#           use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#           use AthenaKernel AthenaKernel-* Control (no_version_directory)
#           use SGTools SGTools-* Control (no_version_directory)
#           use CxxUtils CxxUtils-* Control (no_version_directory)
#           use AthContainersInterfaces AthContainersInterfaces-* Control (no_version_directory)
#           use AthLinks AthLinks-* Control (no_version_directory)
#           use AtlasBoost AtlasBoost-* External (no_version_directory)
#           use GaudiInterface GaudiInterface-* External (no_version_directory)
#         use CxxUtils CxxUtils-* Control (no_version_directory)
#       use PersistentDataModel PersistentDataModel-* Database (no_version_directory)
#         use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#         use AtlasCORAL AtlasCORAL-* External (no_version_directory)
#         use GaudiInterface GaudiInterface-* External (no_version_directory)
#         use CLIDSvc CLIDSvc-* Control (no_version_directory)
#         use SGTools SGTools-* Control (no_version_directory)
#       use DBDataModel DBDataModel-* Database/AthenaPOOL (no_version_directory)
#         use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#         use CLIDSvc CLIDSvc-* Control (no_version_directory)
#         use DataModel DataModel-* Control (no_version_directory)
#     use AthenaKernel AthenaKernel-* Control (no_version_directory)
#   use AtlasROOT AtlasROOT-* External (no_version_directory)
#   use AthContainers AthContainers-* Control (no_version_directory)
# use AthenaBaseComps AthenaBaseComps-* Control (no_version_directory)
# use AsgTools AsgTools-* Control/AthToolSupport (no_version_directory)
#   use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#   use xAODRootAccess xAODRootAccess-* Control (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use AtlasROOT AtlasROOT-* External (no_version_directory)
#     use AthContainers AthContainers-* Control (no_version_directory)
#     use AthContainersInterfaces AthContainersInterfaces-* Control (no_version_directory)
#     use xAODCore xAODCore-* Event/xAOD (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use AthenaKernel AthenaKernel-* Control (no_version_directory)
#       use SGTools SGTools-* Control (no_version_directory)
#       use AthLinks AthLinks-* Control (no_version_directory)
#       use AthContainersInterfaces AthContainersInterfaces-* Control (no_version_directory)
#       use AthContainers AthContainers-* Control (no_version_directory)
#       use AtlasROOT AtlasROOT-* External (no_version_directory)
#       use CxxUtils CxxUtils-* Control (no_version_directory)
#     use xAODEventFormat xAODEventFormat-* Event/xAOD (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use xAODCore xAODCore-* Event/xAOD (no_version_directory)
#     use xAODRootAccessInterfaces xAODRootAccessInterfaces-* Control (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use AtlasROOT AtlasROOT-* External (no_version_directory)
#   use GaudiInterface GaudiInterface-* External (no_version_directory)
#   use AthenaBaseComps AthenaBaseComps-* Control (no_version_directory)
#   use SGTools SGTools-* Control (no_version_directory)
#   use IOVDbDataModel IOVDbDataModel-* Database (no_version_directory)
# use TrigDecisionTool TrigDecisionTool-* Trigger/TrigAnalysis (no_version_directory)
#   use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#   use GaudiInterface GaudiInterface-* External (no_version_directory)
#   use AtlasBoost AtlasBoost-* External (no_version_directory)
#   use AtlasROOT AtlasROOT-* External (no_version_directory)
#   use StoreGate StoreGate-* Control (no_version_directory)
#   use AthenaBaseComps AthenaBaseComps-* Control (no_version_directory)
#   use TrigRoiConversion TrigRoiConversion-* Trigger/TrigEvent (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use TrigSteeringEvent TrigSteeringEvent-* Trigger/TrigEvent (no_version_directory)
#       use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#       use CLIDSvc CLIDSvc-* Control (no_version_directory)
#       use GaudiInterface GaudiInterface-* External (no_version_directory)
#       use SGTools SGTools-* Control (no_version_directory)
#       use TrigConfHLTData TrigConfHLTData-* Trigger/TrigConfiguration (no_version_directory)
#         use DetCommonPolicy *  (no_version_directory)
#           use LCG_Policy *  (no_version_directory)
#             use LCG_Settings *  (no_version_directory)
#           use LCG_Settings *  (no_version_directory)
#           use AtlasCommonPolicy *  (no_version_directory)
#         use Boost v* LCG_Interfaces (no_version_directory) (native_version=1.59.0_python2.7)
#         use TrigConfL1Data TrigConfL1Data-* Trigger/TrigConfiguration (no_version_directory)
#           use DetCommonPolicy *  (no_version_directory)
#           use Boost v* LCG_Interfaces (no_version_directory) (native_version=1.59.0_python2.7)
#       use RoiDescriptor RoiDescriptor-* DetectorDescription (no_version_directory)
#         use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#         use IRegionSelector IRegionSelector-* DetectorDescription (no_version_directory)
#           use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#           use AthenaKernel AthenaKernel-* Control (no_version_directory)
#           use GaudiInterface GaudiInterface-* External (no_version_directory)
#           use Identifier Identifier-* DetectorDescription (no_version_directory)
#             use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#             use AtlasCxxPolicy AtlasCxxPolicy-*  (no_version_directory)
#             use AtlasBoost AtlasBoost-* External (no_version_directory)
#       use xAODCore xAODCore-* Event/xAOD (no_version_directory)
#       use AsgTools AsgTools-* Control/AthToolSupport (no_version_directory)
#       use AthContainers AthContainers-* Control (no_version_directory)
#       use AthenaKernel AthenaKernel-* Control (no_version_directory)
#     use AsgTools AsgTools-* Control/AthToolSupport (no_version_directory)
#     use AthenaBaseComps AthenaBaseComps-* Control (no_version_directory)
#   use TrigConfInterfaces TrigConfInterfaces-* Trigger/TrigConfiguration (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use GaudiInterface GaudiInterface-* External (no_version_directory)
#     use AsgTools AsgTools-* Control/AthToolSupport (no_version_directory)
#   use TrigSteeringEvent TrigSteeringEvent-* Trigger/TrigEvent (no_version_directory)
#   use TrigConfHLTData TrigConfHLTData-* Trigger/TrigConfiguration (no_version_directory)
#   use TrigConfL1Data TrigConfL1Data-* Trigger/TrigConfiguration (no_version_directory)
#   use TrigDecisionInterface TrigDecisionInterface-* Trigger/TrigEvent (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use AsgTools AsgTools-* Control/AthToolSupport (no_version_directory)
#   use xAODTrigger xAODTrigger-* Event/xAOD (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use AthenaKernel AthenaKernel-* Control (no_version_directory)
#     use AthContainersInterfaces AthContainersInterfaces-* Control (no_version_directory)
#     use AthContainers AthContainers-* Control (no_version_directory)
#     use AthLinks AthLinks-* Control (no_version_directory)
#     use xAODCore xAODCore-* Event/xAOD (no_version_directory)
#   use AsgTools AsgTools-* Control/AthToolSupport (no_version_directory)
#   use TrigNavStructure TrigNavStructure-* Trigger/TrigEvent (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use AtlasBoost AtlasBoost-* External (no_version_directory)
#     use AsgTools AsgTools-* Control/AthToolSupport (no_version_directory)
#     use AthContainers AthContainers-* Control (no_version_directory)
#   use xAODBase xAODBase-* Event/xAOD (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use AtlasROOT AtlasROOT-* External (no_version_directory)
#     use SGTools SGTools-* Control (no_version_directory)
#     use AthContainers AthContainers-* Control (no_version_directory)
#   use EventInfo EventInfo-* Event (no_version_directory)
#     use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#     use SGTools SGTools-* Control (no_version_directory)
#     use GaudiInterface GaudiInterface-* External (no_version_directory)
# use TrigDecisionInterface TrigDecisionInterface-* Trigger/TrigEvent (no_version_directory)
# use TrigConfInterfaces TrigConfInterfaces-* Trigger/TrigConfiguration (no_version_directory)
# use TrigConfxAOD TrigConfxAOD-* Trigger/TrigConfiguration (no_version_directory)
#   use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#   use AsgTools AsgTools-* Control/AthToolSupport (no_version_directory)
#   use TrigConfL1Data TrigConfL1Data-* Trigger/TrigConfiguration (no_version_directory)
#   use TrigConfHLTData TrigConfHLTData-* Trigger/TrigConfiguration (no_version_directory)
#   use TrigConfInterfaces TrigConfInterfaces-* Trigger/TrigConfiguration (no_version_directory)
#   use xAODTrigger xAODTrigger-* Event/xAOD (no_version_directory)
# use GaudiKernel v*  (no_auto_imports) (no_version_directory)
# use GaudiCoreSvc *  (no_auto_imports) (no_version_directory)
#   use GaudiKernel *  (no_version_directory)
#   use Boost * LCG_Interfaces (no_auto_imports) (no_version_directory) (native_version=1.59.0_python2.7)
#   use ROOT * LCG_Interfaces (no_auto_imports) (no_version_directory) (native_version=6.04.16)
# use CLIDComps * Control (no_auto_imports) (no_version_directory)
#   use AtlasPolicy AtlasPolicy-*  (no_version_directory)
#
# Selection :
use CMT v1r25p20160527 (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25)
use CodeCheck CodeCheck-01-02-03 Tools (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use LCG_Platforms v1  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e)
use AtlasCompilers AtlasCompilers-00-00-25 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use LCG_Configuration v1  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e)
use LCG_Settings v1  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e)
use LCG_Policy v1  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e)
use RELAX v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e) (no_auto_imports)
use uuid v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e)
use AtlasDoxygen AtlasDoxygen-00-04-10 Tools (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AtlasCommonPolicy AtlasCommonPolicy-00-00-56  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use DetCommonPolicy DetCommonPolicy-00-00-27  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use xrootd v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e)
use GCCXML v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e) (no_auto_imports)
use libunwind v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e) (no_auto_imports)
use tcmalloc v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e) (no_auto_imports)
use Python v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e) (no_auto_imports)
use Boost v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e)
use TrigConfL1Data TrigConfL1Data-02-00-62 Trigger/TrigConfiguration (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use TrigConfHLTData TrigConfHLTData-01-00-35 Trigger/TrigConfiguration (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use CORAL v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e)
use ROOT v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e)
use Reflex v1 LCG_Interfaces (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e)
use GaudiPolicy GaudiPolicy-15-05-00  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/GAUDI/v26r2p1-lcg81e)
use GaudiPluginService GaudiPluginService-02-02-00  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/GAUDI/v26r2p1-lcg81e)
use GaudiKernel GaudiKernel-31-05-04  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/GAUDI/v26r2p1-lcg81e)
use GaudiCoreSvc GaudiCoreSvc-03-04-00  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/GAUDI/v26r2p1-lcg81e) (no_auto_imports)
use PlatformPolicy PlatformPolicy-00-00-20 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AtlasExternalArea AtlasExternalArea-00-00-27 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use Mac105_Compat Mac105_Compat-00-00-01 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use ExternalPolicy ExternalPolicy-00-01-72 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AtlasPython AtlasPython-00-01-07 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25) (no_auto_imports)
use AtlasRELAX AtlasRELAX-00-01-00 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25) (no_auto_imports)
use AtlasROOT AtlasROOT-02-03-28 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AtlasReflex AtlasReflex-00-03-10 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AtlasCORAL AtlasCORAL-00-00-10 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use GaudiInterface GaudiInterface-01-03-04 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use CheckerGccPlugins CheckerGccPlugins-00-01-85 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AtlasCxxPolicy AtlasCxxPolicy-00-00-77  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AtlasPolicy AtlasPolicy-01-08-46-04  (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use CLIDComps CLIDComps-00-06-18-03 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25) (no_auto_imports)
use xAODRootAccessInterfaces xAODRootAccessInterfaces-00-00-07 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use PyCmt PyCmt-00-00-47 Tools (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25) (no_auto_imports)
use AtlasTBB AtlasTBB-00-00-09 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use Scripts Scripts-00-01-88 Tools (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25) (no_auto_imports)
use AtlasBoost AtlasBoost-00-00-11 External (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use Identifier Identifier-00-09-32 DetectorDescription (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AthAllocators AthAllocators-00-01-12 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use CxxUtils CxxUtils-00-01-57 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use DataModelRoot DataModelRoot-00-00-20 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AthenaKernel AthenaKernel-00-57-00-01 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use IRegionSelector IRegionSelector-01-00-08 DetectorDescription (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use RoiDescriptor RoiDescriptor-00-01-01 DetectorDescription (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use SGTools SGTools-00-26-03-01 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use EventInfo EventInfo-00-11-12 Event (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AthLinks AthLinks-00-02-25 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use CLIDSvc CLIDSvc-00-05-02 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use PersistentDataModel PersistentDataModel-00-00-47 Database (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AthContainersInterfaces AthContainersInterfaces-00-01-33 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AthContainers AthContainers-00-02-61 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use xAODBase xAODBase-00-00-24 Event/xAOD (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use xAODCore xAODCore-00-01-23 Event/xAOD (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use xAODTrigger xAODTrigger-00-00-48 Event/xAOD (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use xAODEventFormat xAODEventFormat-00-00-15 Event/xAOD (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use xAODRootAccess xAODRootAccess-00-01-59 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use DataModel DataModel-00-23-71 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use DBDataModel DBDataModel-00-08-02 Database/AthenaPOOL (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AthenaPoolUtilities AthenaPoolUtilities-00-07-19 Database/AthenaPOOL (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use IOVDbDataModel IOVDbDataModel-00-00-28 Database (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use StoreGate StoreGate-03-05-01-02 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AthenaBaseComps AthenaBaseComps-00-07-02-01 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AsgTools AsgTools-00-01-06 Control/AthToolSupport (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use TrigNavStructure TrigNavStructure-00-00-20 Trigger/TrigEvent (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use TrigDecisionInterface TrigDecisionInterface-00-01-02 Trigger/TrigEvent (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use TrigConfInterfaces TrigConfInterfaces-00-00-06 Trigger/TrigConfiguration (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use TrigConfxAOD TrigConfxAOD-00-00-22 Trigger/TrigConfiguration (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use TrigSteeringEvent TrigSteeringEvent-01-06-19 Trigger/TrigEvent (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use TrigRoiConversion TrigRoiConversion-00-00-09 Trigger/TrigEvent (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use TrigDecisionTool TrigDecisionTool-00-03-55 Trigger/TrigAnalysis (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use AthAnalysisBaseComps AthAnalysisBaseComps-00-00-32 Control (/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25)
use CMTUSERCONTEXT v0 (/cvmfs/atlas.cern.ch/repo/tools/slc6/cmt)
----------> tags
x86_64-slc6-gcc49-opt (from CMTCONFIG) package [LCG_Platforms PlatformPolicy] implies [target-x86_64 target-slc6 target-gcc49 target-opt Linux slc6 64 gcc-4.9 opt x86_64-slc6-gcc49]
ATLAS (from arguments) package [GaudiPolicy] implies [use-shared-dir no-pyzip] applied [ExternalPolicy]
ManaCore (from arguments)
AthAnalysisBase (from arguments)
CMTv1 (from CMTVERSION)
CMTr25 (from CMTVERSION)
CMTp20160527 (from CMTVERSION)
Linux (from uname) package [CMT LCG_Platforms AtlasCxxPolicy AtlasPolicy] implies [Unix host-linux cpp_native_dependencies]
STANDALONE (from CMTSITE)
CMTUSERCONTEXT_no_config (from PROJECT) excludes [CMTUSERCONTEXT_config]
CMTUSERCONTEXT_no_root (from PROJECT) excludes [CMTUSERCONTEXT_root]
CMTUSERCONTEXT_cleanup (from PROJECT) excludes [CMTUSERCONTEXT_no_cleanup]
CMTUSERCONTEXT_scripts (from PROJECT) excludes [CMTUSERCONTEXT_no_scripts]
CMTUSERCONTEXT_no_prototypes (from PROJECT) excludes [CMTUSERCONTEXT_prototypes]
CMTUSERCONTEXT_with_installarea (from PROJECT) excludes [CMTUSERCONTEXT_without_installarea]
CMTUSERCONTEXT_without_version_directory (from PROJECT) excludes [CMTUSERCONTEXT_with_version_directory]
TestArea_no_config (from PROJECT) excludes [TestArea_config]
TestArea_no_root (from PROJECT) excludes [TestArea_root]
TestArea_cleanup (from PROJECT) excludes [TestArea_no_cleanup]
TestArea_scripts (from PROJECT) excludes [TestArea_no_scripts]
TestArea_no_prototypes (from PROJECT) excludes [TestArea_prototypes]
TestArea_with_installarea (from PROJECT) excludes [TestArea_without_installarea]
TestArea_without_version_directory (from PROJECT) excludes [TestArea_with_version_directory]
TestArea (from PROJECT)
AthAnalysisBase_no_config (from PROJECT) excludes [AthAnalysisBase_config]
AthAnalysisBase_no_root (from PROJECT) excludes [AthAnalysisBase_root]
AthAnalysisBase_cleanup (from PROJECT) excludes [AthAnalysisBase_no_cleanup]
AthAnalysisBase_scripts (from PROJECT) excludes [AthAnalysisBase_no_scripts]
AthAnalysisBase_no_prototypes (from PROJECT) excludes [AthAnalysisBase_prototypes]
AthAnalysisBase_with_installarea (from PROJECT) excludes [AthAnalysisBase_without_installarea]
AthAnalysisBase_without_version_directory (from PROJECT) excludes [AthAnalysisBase_with_version_directory]
GAUDI_no_config (from PROJECT) excludes [GAUDI_config]
GAUDI_root (from PROJECT) excludes [GAUDI_no_root]
GAUDI_cleanup (from PROJECT) excludes [GAUDI_no_cleanup]
GAUDI_scripts (from PROJECT) excludes [GAUDI_no_scripts]
GAUDI_prototypes (from PROJECT) excludes [GAUDI_no_prototypes]
GAUDI_with_installarea (from PROJECT) excludes [GAUDI_without_installarea]
GAUDI_without_version_directory (from PROJECT) excludes [GAUDI_with_version_directory]
LCGCMT_no_config (from PROJECT) excludes [LCGCMT_config]
LCGCMT_no_root (from PROJECT) excludes [LCGCMT_root]
LCGCMT_cleanup (from PROJECT) excludes [LCGCMT_no_cleanup]
LCGCMT_scripts (from PROJECT) excludes [LCGCMT_no_scripts]
LCGCMT_prototypes (from PROJECT) excludes [LCGCMT_no_prototypes]
LCGCMT_with_installarea (from PROJECT) excludes [LCGCMT_without_installarea]
LCGCMT_without_version_directory (from PROJECT) excludes [LCGCMT_with_version_directory]
x86_64 (from package CMT) package [LCG_Platforms] implies [host-x86_64] applied [CMT]
sl69 (from package CMT) package [PlatformPolicy] implies [host-slc6] applied [CMT]
gcc493 (from package CMT) applied [CMT]
Unix (from package CMT) package [LCG_Platforms] implies [host-unix] excludes [WIN32 Win32]
c_native_dependencies (from package CMT) activated GaudiPolicy
cpp_native_dependencies (from package CMT) activated GaudiPolicy
/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25:/cvmfs/atlas.cern.ch/repo/sw/tdaq/tdaqnotProject (from package ExternalPolicy) applied [ExternalPolicy]
target-unix (from package LCG_Settings) activated LCG_Platforms
target-x86_64 (from package LCG_Settings) activated LCG_Platforms
target-gcc49 (from package LCG_Settings) package [LCG_Platforms] implies [target-gcc4 target-lcg-compiler lcg-compiler target-c11] activated LCG_Platforms
host-x86_64 (from package LCG_Settings) activated LCG_Platforms
target-slc (from package LCG_Settings) package [LCG_Platforms] implies [target-linux] activated LCG_Platforms
target-gcc (from package LCG_Settings) activated LCG_Platforms
target-gcc4 (from package LCG_Settings) package [LCG_Platforms] implies [target-gcc] activated LCG_Platforms
target-lcg-compiler (from package LCG_Settings) activated LCG_Platforms
host-linux (from package LCG_Platforms) package [LCG_Platforms] implies [host-unix]
host-unix (from package LCG_Platforms)
host-slc6 (from package LCG_Platforms) package [LCG_Platforms] implies [host-slc] activated PlatformPolicy
host-slc (from package LCG_Platforms) package [LCG_Platforms] implies [host-linux] activated PlatformPolicy
target-opt (from package LCG_Platforms)
target-slc6 (from package LCG_Platforms) package [LCG_Platforms] implies [target-slc]
target-linux (from package LCG_Platforms) package [LCG_Platforms] implies [target-unix]
lcg-compiler (from package LCG_Platforms)
target-c11 (from package LCG_Platforms) excludes [RELAX]
ROOT_GE_5_15 (from package LCG_Configuration) applied [LCG_Configuration]
ROOT_GE_5_19 (from package LCG_Configuration) applied [LCG_Configuration]
ROOT_GE_6_00 (from package LCG_Configuration) applied [LCG_Configuration]
use-shared-dir (from package GaudiPolicy)
do_genconf (from package GaudiPolicy) applied [AtlasPolicy] activated AtlasPolicy
no-pyzip (from package GaudiPolicy)
separate-debug (from package AtlasCommonPolicy) excludes [no-separate-debug] applied [AtlasCommonPolicy]
NICOS (from package AtlasCommonPolicy) package AtlasCommonPolicy excludes [NICOSrel_nightly] applied [AtlasCommonPolicy]
LCGCMT_INSTALLED (from package PlatformPolicy) applied [PlatformPolicy ExternalPolicy]
block-tdaqc (from package PlatformPolicy) applied [PlatformPolicy ExternalPolicy]
opt (from package PlatformPolicy) package [AtlasPolicy] implies [optimized]
gcc (from package PlatformPolicy)
64 (from package PlatformPolicy) package [PlatformPolicy] implies [target-64]
gcc-4.9 (from package PlatformPolicy) package [PlatformPolicy] implies [gcc49x gcc49 gcc]
gcc49x (from package PlatformPolicy)
gcc49 (from package PlatformPolicy)
slc6 (from package PlatformPolicy)
x86_64-slc6-gcc49 (from package PlatformPolicy)
target-64 (from package PlatformPolicy)
asNeeded (from package PlatformPolicy) applied [PlatformPolicy]
CheckerGccPlugins_project_AthAnalysisBase (from package CheckerGccPlugins) applied [CheckerGccPlugins]
optimized (from package AtlasPolicy) package [AtlasPolicy] implies [opt] excludes [debug]
HasAthenaRunTime (from package AtlasPolicy) applied [AtlasPolicy]
SITE_ (from package AtlasPolicy) applied [AtlasPolicy]
HAVE_GAUDI_PLUGINSVC (from package GaudiPluginService) applied [GaudiPluginService]
ROOTBasicLibs (from package AtlasROOT) applied [AtlasROOT]
ROOTCintexLibs (from package AtlasROOT) applied [xAODCore] activated xAODCore
ROOTMathLibs (from package AtlasROOT) applied [xAODBase] activated xAODBase
ROOTNetLibs (from package AtlasROOT) applied [xAODRootAccess] activated xAODRootAccess
NEEDS_CORAL_RELATIONAL_ACCESS (from package CORAL) applied [AtlasCORAL] activated AtlasCORAL
NEEDS_CORAL_BASE (from package CORAL) applied [AthenaPoolUtilities] activated AthenaPoolUtilities
TrigDecisionTool_Trigger/TrigEvent/TrigNavigation_hasPP (from package TrigDecisionTool) applied [TrigDecisionTool]
TrigSteeringEvent_External/DataCollection_hasPP (from package TrigSteeringEvent) applied [TrigSteeringEvent]
TrigSteeringEvent_Event/xAOD/xAODTrigger_hasPP (from package TrigSteeringEvent) applied [TrigSteeringEvent]
TrigSteeringEvent_Trigger/TrigDataAccess/TrigSerializeUtils_hasPP (from package TrigSteeringEvent) applied [TrigSteeringEvent]
TrigSteeringEvent_Trigger/TrigT1/TrigT1Interfaces_hasPP (from package TrigSteeringEvent) applied [TrigSteeringEvent]
TrigSteeringEvent_Trigger/TrigEvent/TrigNavigation_hasPP (from package TrigSteeringEvent) applied [TrigSteeringEvent]
TrigDecisionTool_PhysicsAnalysis/AnalysisTrigger/AnalysisTriggerEvent_hasPP (from package TrigDecisionTool) applied [TrigDecisionTool]
TrigDecisionTool_Trigger/TrigEvent/TrigStorageDefinitions_hasPP (from package TrigDecisionTool) applied [TrigDecisionTool]
TrigDecisionTool_Trigger/TrigEvent/TrigDecisionEvent_hasPP (from package TrigDecisionTool) applied [TrigDecisionTool]
TrigDecisionTool_Trigger/TrigEvent/TrigMuonEvent_hasPP (from package TrigDecisionTool) applied [TrigDecisionTool]
no_pack_dist_check (from package TriggerList) applied [TriggerList]
----------> CMTPATH
# Add path /cvmfs/atlas.cern.ch/repo/tools/slc6/cmt from CMTUSERCONTEXT
# Add path /home/paredes/TestArea/athenaMetTest2 from initialization
# Add path /cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25 from initialization
# Add path /cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/GAUDI/v26r2p1-lcg81e from ProjectPath
# Add path /cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/LCGCMT/LCGCMT_81e from ProjectPath
