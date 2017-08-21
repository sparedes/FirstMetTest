#!/bin/bash
# job_setup.sh 08 Mar 2017 12:13:08

export VO_ATLAS_SW_DIR=/cvmfs/atlas.cern.ch/repo/sw
if [ -f $VO_ATLAS_SW_DIR/local/setup.sh ]; then
  source $VO_ATLAS_SW_DIR/local/setup.sh
fi

export PANDA_RESOURCE="ANALY_SLAC";
export ROOT_TTREECACHE_SIZE=1;
export FRONTIER_ID="[10916444_3267651254]";
export CMSSW_VERSION=$FRONTIER_ID;
export RUCIO_APPID="panda-client-0.5.78-jedi-athena";
export RUCIO_ACCOUNT="pilot";
export ROOTCORE_NCPUS=1;
export MAKEFLAGS="-j1 QUICK=1 -l1";
export X509_USER_PROXY=/nfs/slac/g/grid/osg/u/osgatlas01/home_bl_osgserv06.slac.stanford.edu_9619_osgserv06.slac.stanford.edu#15718349.0#1488974977/bl_100fb119c4eb.proxy;
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase;
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh --quiet;
source $AtlasSetup/scripts/asetup.sh AthAnalysisBase,2.4.25 --cmtconfig=x86_64-slc6-gcc49-opt;
./runAthena-00-00-12 -l panda.0308105652.430739.lib._10916444.8727237564.lib.tgz --sourceURL https://aipanda078.cern.ch:25443 -r ./  -i "['DAOD_JETM11.10014747._000007.pool.root.1']" -o "{'IROOT': [('myEfffile.root', 'user.saparede.10916444.EXT0._000003.myEfffile.root')], 'THIST': [('MYSTREAM', 'user.saparede.10916444.MYSTREAM._000003.root')]}"  -j "%20testMetMaker/share/MyAlgJobo.py" --usePFCTurl --directIn --inputGUIDs "['CCB0DCA6-3793-CF4F-BEBE-C46E7D187BF0']"

