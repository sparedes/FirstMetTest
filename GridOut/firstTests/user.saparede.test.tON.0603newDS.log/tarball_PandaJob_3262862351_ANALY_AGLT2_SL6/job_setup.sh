#!/bin/bash
# job_setup.sh 06 Mar 2017 17:12:54

export VO_ATLAS_SW_DIR=/cvmfs/atlas.cern.ch/repo/sw
if [ -f $VO_ATLAS_SW_DIR/local/setup.sh ]; then
  source $VO_ATLAS_SW_DIR/local/setup.sh
fi

export PANDA_RESOURCE="ANALY_AGLT2_SL6";
export ROOT_TTREECACHE_SIZE=1;
export FRONTIER_ID="[10897679_3262862351]";
export CMSSW_VERSION=$FRONTIER_ID;
export RUCIO_APPID="panda-client-0.5.77-jedi-athena";
export RUCIO_ACCOUNT="pilot";
export ROOTCORE_NCPUS=1;
export MAKEFLAGS="-j1 QUICK=1 -l1";
export X509_USER_PROXY=/tmp/condor/execute/dir_2554172/jhovercernprodProxy;
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase;
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh --quiet;
source $AtlasSetup/scripts/asetup.sh AthAnalysisBase,2.4.25 --cmtconfig=x86_64-slc6-gcc49-opt;
./runAthena-00-00-12 -l panda.0306125325.545669.lib._10897679.8699656411.lib.tgz --sourceURL https://aipanda012.cern.ch:25443 -r ./  -i "['DAOD_JETM11.10014747._000002.pool.root.1']" -o "{'IROOT': [('myEfffile.root', 'user.saparede.10897679.EXT0._000001.myEfffile.root')], 'THIST': [('MYSTREAM', 'user.saparede.10897679.MYSTREAM._000001.root')]}"  -j "%20testMetMaker/share/MyAlgJobo.py" --usePFCTurl --directIn --inputGUIDs "['F164FAD9-C568-E941-B2EF-219009B4DB1A']"

