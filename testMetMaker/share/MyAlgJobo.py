#!/usr/bin/python

#Skeleton joboption for a simple analysis job

#---- Minimal joboptions -------

#theApp.EvtMax=vars().get("nEvents",10)                                         #says how many events to run over. Set to -1 for all events
#theApp.EvtMax=vars().get("nEvents",100)                                         #says how many events to run over. Set to -1 for all events
#theApp.EvtMax=vars().get("nEvents",1000)                                         #says how many events to run over. Set to -1 for all events
#theApp.EvtMax=vars().get("nEvents",10000)                                         #says how many events to run over. Set to -1 for all events
#theApp.EvtMax=vars().get("nEvents",100000)                                         #says how many events to run over. Set to -1 for all events
theApp.EvtMax=vars().get("nEvents",-1)                                         #says how many events to run over. Set to -1 for all events

import AthenaPoolCnvSvc.ReadAthenaPool                   #sets up reading of POOL files (e.g. xAODs)
# off for grid job svcMgr.EventSelector.InputCollections= ["/data/atlas/atlasdata3/paredes/JETM11/data15_13TeV.00267639.physics_Main.merge.DAOD_JETM11.r7600_p2521_p2950_tid10325988_00/DAOD_JETM11.10325988._000129.pool.root.1"]# This is a file of new dataset (the one for first grid test)
#svcMgr.EventSelector.InputCollections= ["/home/paredes/TestArea/athenaMetTest2/data16_13TeV.00307126.physics_Main.merge.DAOD_JETM11.f731_m1659_p2950/DAOD_JETM11.10313648._000040.pool.root.1"]# sample of new new file 
svcMgr.EventSelector.InputCollections= ["/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000200.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000558.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000329.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000280.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000254.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000485.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000639.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000619.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000203.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000167.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000258.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000195.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000657.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000541.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000263.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000050.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000029.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000106.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000384.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000398.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000333.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000767.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000722.pool.root.1",
                                        "/data/atlas/atlasdata3/paredes/JETM11/data16_13TeV.00307732.physics_Main.merge.DAOD_JETM11.f741_m1673_p2950_tid10313937_00/DAOD_JETM11.10313937._000503.pool.root.1"]

#svcMgr.EventSelector.InputCollections= ["/home/paredes/TestArea/athenaMetTest2/data16_13TeV.00307126.physics_Main.merge.DAOD_JETM11.f731_m1659_p2950/DAOD_JETM11.10313648._000075.pool.root.1"]# sample of new new file 
#svcMgr.EventSelector.InputCollections= ["/data/atlas/atlasdata3/paredes/JETM11/data15_13TeV.00280862.physics_Main.merge.DAOD_JETM11.r7562_p2521_p2667_tid08612234_00/DAOD_JETM11.08612234._000040.pool.root.1"]#old file, now unavailable in rucio. for tests only
#for GRID svcMgr.EventSelector.InputCollections= ["/data/atlas/atlasdata3/paredes/JETM11/data15_13TeV.00280862.physics_Main.merge.DAOD_JETM11.r7562_p2521_p2667_tid08612234_00/DAOD_JETM11.08612234._000040.pool.root.1"]

#DATA TEST SAMPLE svcMgr.EventSelector.InputCollections= ["/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7562/data15_13TeV.00284154.physics_Main.merge.AOD.r7562_p2521/AOD.07687819._000382.pool.root.1"]
#MC TEST SAMPLE svcMgr.EventSelector.InputCollections= ["/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1"]
#svcMgr.EventSelector.InputCollections = ["/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7562/data15_13TeV.00284154.physics_Main.merge.AOD.r7562_p2521/AOD.07687819._000382.pool.root.1"]
#svcMgr.EventSelector.InputCollections= ["/afs/cern.ch/atlas/project/PAT/xAODs/r8565/valid2.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e4993_s2887_r8565/AOD.09534072._000257.pool.root.1"]

#jps.AthenaCommonFlags.FilesInput = ["/afs/cern.ch/atlas/project/PAT/xAODs/r8565/valid2.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.recon.AOD.e4993_s2887_r8565/AOD.09534072._000257.pool.root.1"]   #insert your list of input files here (do this before next lines)
#import AthenaRootComps.ReadAthenaxAODHybrid             #alternative for FAST xAOD reading!

from AthenaCommon.AthenaCommonFlags import athenaCommonFlags
from AthenaCommon.AppMgr import ServiceMgr
from AthenaCommon import CfgMgr
from AthenaCommon.AppMgr import ToolSvc
from glob import glob



ToolSvc += CfgMgr.met__METMaker("METMaker")
ToolSvc += CfgMgr.CP__MuonSelectionTool("MuonSelectionTool")
#muonSel = CfgMgr.CP__MuonSelectionTool("MuonSelectionTool_METMakerAlg",
#                                       MuQuality=1, # Medium
#                                       MaxEta=2.4)
#ToolSvc += muonSel


ToolSvc += CfgMgr.CP__IsolationSelectionTool("muonIsoTool", MuonWP="Gradient")
ToolSvc += CfgMgr.CP__IsolationSelectionTool("eleIsoTool", ElectronWP="Gradient")


ToolSvc += CfgMgr.AsgElectronLikelihoodTool("EleSelTool", WorkingPoint = "MediumLHElectron");
ToolSvc += CfgMgr.AsgPhotonIsEMSelector("PhotonSelTool", WorkingPoint = "TightPhoton" )
#ToolSvc += CfgMgr.TauAnalysisTools__TauSelectionTool("TauSelTool")
tauSel = CfgMgr.TauAnalysisTools__TauSelectionTool("TauSelectionTool_METMakerAlg")
ToolSvc += tauSel

ToolSvc += CfgMgr.JetCalibrationTool("myJESTool")
ToolSvc.myJESTool.IsData=True
ToolSvc.myJESTool.ConfigFile="JES_MC15cRecommendation_May2016.config"
ToolSvc.myJESTool.CalibSequence="JetArea_Residual_Origin_EtaJES_GSC_Insitu"
ToolSvc.myJESTool.JetCollection="AntiKt4EMTopo" 

ToolSvc += CfgMgr.TrigConf__xAODConfigTool("xAODConfigTool")

ToolSvc += CfgMgr.Trig__TrigDecisionTool("TrigDecTool",
                                         ConfigTool = ToolSvc.xAODConfigTool,
                                         TrigDecisionKey = "xTrigDecision")

algseq = CfgMgr.AthSequencer("AthAlgSeq")                #gets the main AthSequencer
algseq += CfgMgr.AthEventCounter(Frequency = 1000)
algseq += CfgMgr.CP__CalibratedMuonsProvider(Input = "Muons", Output = "CalibratedMuons")
algseq += CfgMgr.CP__CalibratedEgammaProvider("ElectronCalib", Input= "Electrons",Output= "CalibratedElectrons")
algseq += CfgMgr.CP__CalibratedEgammaProvider("PhotonCalib", Input= "Photons",Output= "CalibratedPhotons")

algseq += CfgMgr.MyAlg("MyMETAlg",
                       Maker = ToolSvc.METMaker,
                       METMapName = "METAssoc_AntiKt4EMTopo",
                       METCoreName = "MET_Core_AntiKt4EMTopo",
                       METName = "MyBuiltMET",
                       InputJets = "AntiKt4EMTopoJets",
                       InputMuons = "CalibratedMuons",
                       InputElectrons = "CalibratedElectrons",
                       InputPhotons = "CalibratedPhotons",
                       MuonSelectionTool = ToolSvc.MuonSelectionTool,
                       MuonIsoSelTool = ToolSvc.muonIsoTool,
                       ElectronIsoSelTool = ToolSvc.eleIsoTool,
#ToolSvc += CfgMgr.CP__IsolationSelectionTool("muonIsoTool", MuonWP="Gradient")
#ToolSvc += CfgMgr.CP__IsolationSelectionTool("eleIsoTool", ElectronWP="Gradient")
                       #IsolationSelection = ToolSvc.IsolationSelectionTool,
                       ElectronLHSelectionTool = ToolSvc.EleSelTool,
                       PhotonIsEMSelectionTool = ToolSvc.PhotonSelTool,
                       TauSelectionTool=tauSel,
                       TrigDecTool = ToolSvc.TrigDecTool,
                       OutputLevel = DEBUG)

                       #TauSelectionTool = ToolSvc.TauSelTool)                                 #adds an instance of your alg to it
svcMgr += CfgMgr.THistSvc()
svcMgr.THistSvc.Output += ["MYSTREAM DATAFILE='myHistoFile.root' OPT='RECREATE'"]
#svcMgr.THistSvc.Output += ["MYOTHERSTREAM DATAFILE='myNewTestHistoFile.root' OPT='RECREATE'"]
#svcMgr.THistSvc.Output += ["ANOTHERSTREAM DATAFILE='anotherfile.root' OPT='RECREATE'"]




##output histogram file
#svcMgr += CfgMgr.THistSvc ()
#svcMgr.THistSvc.Output = ["MYSTREAM DATAFILE='myStream.root' OPT='RECREATE'"]



#-------------------------------


#note that if you edit the input files after this point you need to pass the new files to the EventSelector:
#like this: svcMgr.EventSelector.InputCollections = ["new","list"] 





##--------------------------------------------------------------------
## This section shows up to set up a HistSvc output stream for outpu
#ing histograms and trees
## See https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/AthAnalysisBase#How_to_output_trees_and_histogra for more details and examples

#if not hasattr(svcMgr, 'THistSvc'): svcMgr += CfgMgr.THistSvc() #only add the histogram service if not already present (will be the case in this jobo)
#svcMgr.THistSvc.Output += ["MYSTREAM DATAFILE='myfile.root' OPT='RECREATE'"] #add an output root file stream

##--------------------------------------------------------------------


##--------------------------------------------------------------------
## The lines below are an example of how to create an output xAOD
## See https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/AthAnalysisBase#How_to_create_an_output_xAOD for more details and examples

#from OutputStreamAthenaPool.MultipleStreamManager import MSMgr
#xaodStream = MSMgr.NewPoolRootStream( "StreamXAOD", "xAOD.out.root" )

##EXAMPLE OF BASIC ADDITION OF EVENT AND METADATA ITEMS
##AddItem and AddMetaDataItem methods accept either string or list of strings
#xaodStream.AddItem( ["xAOD::JetContainer#*","xAOD::JetAuxContainer#*"] ) #Keeps all JetContainers (and their aux stores)
#xaodStream.AddMetaDataItem( ["xAOD::TriggerMenuContainer#*","xAOD::TriggerMenuAuxContainer#*"] )
#ToolSvc += CfgMgr.xAODMaker__TriggerMenuMetaDataTool("TriggerMenuMetaDataTool") #MetaDataItems needs their corresponding MetaDataTool
#svcMgr.MetaDataSvc.MetaDataTools += [ ToolSvc.TriggerMenuMetaDataTool ] #Add the tool to the MetaDataSvc to ensure it is loaded

##EXAMPLE OF SLIMMING (keeping parts of the aux store)
#xaodStream.AddItem( ["xAOD::ElectronContainer#Electrons","xAOD::ElectronAuxContainer#ElectronsAux.pt.eta.phi"] ) #example of slimming: only keep pt,eta,phi auxdata of electrons

##EXAMPLE OF SKIMMING (keeping specific events)
#xaodStream.AddAcceptAlgs( "MyAlg" ) #will only keep events where 'setFilterPassed(false)' has NOT been called in the given algorithm

##--------------------------------------------------------------------


include("AthAnalysisBaseComps/SuppressLogging.py")              #Optional include to suppress as much athena output as possible. Keep at bottom of joboptions so that it doesn't suppress the logging of the things you have configured above

