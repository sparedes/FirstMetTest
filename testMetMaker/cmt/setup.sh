# echo "setup testMetMaker testMetMaker-00-00-00 in /home/paredes/TestArea/athenaMetTest2"

if test "${CMTROOT}" = ""; then
  CMTROOT=/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.29/CMT/v1r25p20160527; export CMTROOT
fi
. ${CMTROOT}/mgr/setup.sh
cmttestMetMakertempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if test ! $? = 0 ; then cmttestMetMakertempfile=/tmp/cmt.$$; fi
${CMTROOT}/${CMTBIN}/cmt.exe setup -sh -pack=testMetMaker -version=testMetMaker-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  -no_cleanup $* >${cmttestMetMakertempfile}
if test $? != 0 ; then
  echo >&2 "${CMTROOT}/${CMTBIN}/cmt.exe setup -sh -pack=testMetMaker -version=testMetMaker-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  -no_cleanup $* >${cmttestMetMakertempfile}"
  cmtsetupstatus=2
  /bin/rm -f ${cmttestMetMakertempfile}
  unset cmttestMetMakertempfile
  return $cmtsetupstatus
fi
cmtsetupstatus=0
. ${cmttestMetMakertempfile}
if test $? != 0 ; then
  cmtsetupstatus=2
fi
/bin/rm -f ${cmttestMetMakertempfile}
unset cmttestMetMakertempfile
return $cmtsetupstatus

