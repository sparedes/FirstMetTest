#Fri Apr 28 17:34:55 2017"""Automatically generated. DO NOT EDIT please"""
from GaudiKernel.GaudiHandles import *
from GaudiKernel.Proxy.Configurable import *

class MyAlg( ConfigurableAlgorithm ) :
  __slots__ = { 
    'OutputLevel' : 0, # int
    'Enable' : True, # bool
    'ErrorMax' : 1, # int
    'ErrorCounter' : 0, # int
    'AuditAlgorithms' : False, # bool
    'AuditInitialize' : False, # bool
    'AuditReinitialize' : False, # bool
    'AuditRestart' : False, # bool
    'AuditExecute' : False, # bool
    'AuditFinalize' : False, # bool
    'AuditBeginRun' : False, # bool
    'AuditEndRun' : False, # bool
    'AuditStart' : False, # bool
    'AuditStop' : False, # bool
    'MonitorService' : 'MonitorSvc', # str
    'RegisterForContextService' : False, # bool
    'EvtStore' : ServiceHandle('StoreGateSvc'), # GaudiHandle
    'DetStore' : ServiceHandle('StoreGateSvc/DetectorStore'), # GaudiHandle
    'UserStore' : ServiceHandle('UserDataSvc/UserDataSvc'), # GaudiHandle
    'Maker' : PublicToolHandle('IMETMaker'), # GaudiHandle
    'METMapName' : 'METAssoc', # str
    'METCoreName' : 'MET_Core', # str
    'METName' : 'MET_Reference', # str
    'METSoftClName' : 'SoftClus', # str
    'METSoftTrkName' : 'PVSoftTrk', # str
    'InputJets' : 'AntiKt4LCTopoJets', # str
    'InputElectrons' : 'Electrons', # str
    'InputPhotons' : 'Photons', # str
    'InputTaus' : 'TauJets', # str
    'InputMuons' : 'Muons', # str
    'MuonSelectionTool' : PublicToolHandle(''), # GaudiHandle
    'ElectronLHSelectionTool' : PublicToolHandle(''), # GaudiHandle
    'PhotonIsEMSelectionTool' : PublicToolHandle(''), # GaudiHandle
    'TauSelectionTool' : PublicToolHandle(''), # GaudiHandle
    'DoTruthLeptons' : False, # bool
    'IsData' : True, # bool
    'TrigDecTool' : PublicToolHandle(''), # GaudiHandle
    'MuonIsoSelTool' : PublicToolHandle(''), # GaudiHandle
    'ElectronIsoSelTool' : PublicToolHandle('CP::IIsolationSelectionTool'), # GaudiHandle
  }
  _propertyDocDct = { 
    'DetStore' : """ Handle to a StoreGateSvc/DetectorStore instance: it will be used to retrieve data during the course of the job """,
    'RegisterForContextService' : """ The flag to enforce the registration for Algorithm Context Service """,
    'UserStore' : """ Handle to a UserDataSvc/UserDataSvc instance: it will be used to retrieve user data during the course of the job """,
    'EvtStore' : """ Handle to a StoreGateSvc instance: it will be used to retrieve data during the course of the job """,
  }
  def __init__(self, name = Configurable.DefaultName, **kwargs):
      super(MyAlg, self).__init__(name)
      for n,v in kwargs.items():
         setattr(self, n, v)
  def getDlls( self ):
      return 'testMetMaker'
  def getType( self ):
      return 'MyAlg'
  pass # class MyAlg

class PtPlottingAlg( ConfigurableAlgorithm ) :
  __slots__ = { 
    'OutputLevel' : 0, # int
    'Enable' : True, # bool
    'ErrorMax' : 1, # int
    'ErrorCounter' : 0, # int
    'AuditAlgorithms' : False, # bool
    'AuditInitialize' : False, # bool
    'AuditReinitialize' : False, # bool
    'AuditRestart' : False, # bool
    'AuditExecute' : False, # bool
    'AuditFinalize' : False, # bool
    'AuditBeginRun' : False, # bool
    'AuditEndRun' : False, # bool
    'AuditStart' : False, # bool
    'AuditStop' : False, # bool
    'MonitorService' : 'MonitorSvc', # str
    'RegisterForContextService' : False, # bool
    'EvtStore' : ServiceHandle('StoreGateSvc'), # GaudiHandle
    'DetStore' : ServiceHandle('StoreGateSvc/DetectorStore'), # GaudiHandle
    'UserStore' : ServiceHandle('UserDataSvc/UserDataSvc'), # GaudiHandle
    'THistSvc' : ServiceHandle('THistSvc/THistSvc'), # GaudiHandle
    'RootStreamName' : '/', # str
    'RootDirName' : '', # str
    'HistNamePrefix' : '', # str
    'HistNamePostfix' : '', # str
    'HistTitlePrefix' : '', # str
    'HistTitlePostfix' : '', # str
    'Input' : 'Electrons', # str
    'HistogramName' : 'elePt', # str
    'FileName' : 'out-hist.root', # str
    'DirName' : '', # str
  }
  _propertyDocDct = { 
    'HistTitlePrefix' : """ The prefix for the histogram THx title """,
    'DetStore' : """ Handle to a StoreGateSvc/DetectorStore instance: it will be used to retrieve data during the course of the job """,
    'RegisterForContextService' : """ The flag to enforce the registration for Algorithm Context Service """,
    'RootStreamName' : """ Name of the output ROOT stream (file) that the THistSvc uses """,
    'HistNamePostfix' : """ The postfix for the histogram THx name """,
    'UserStore' : """ Handle to a UserDataSvc/UserDataSvc instance: it will be used to retrieve user data during the course of the job """,
    'HistTitlePostfix' : """ The postfix for the histogram THx title """,
    'EvtStore' : """ Handle to a StoreGateSvc instance: it will be used to retrieve data during the course of the job """,
    'THistSvc' : """ Handle to a THistSvc instance: it will be used to write ROOT objects to ROOT files """,
    'HistNamePrefix' : """ The prefix for the histogram THx name """,
    'RootDirName' : """ Name of the ROOT directory inside the ROOT file where the histograms will go """,
  }
  def __init__(self, name = Configurable.DefaultName, **kwargs):
      super(PtPlottingAlg, self).__init__(name)
      for n,v in kwargs.items():
         setattr(self, n, v)
  def getDlls( self ):
      return 'testMetMaker'
  def getType( self ):
      return 'PtPlottingAlg'
  pass # class PtPlottingAlg
