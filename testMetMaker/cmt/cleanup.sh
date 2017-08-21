# echo "cleanup testMetMaker testMetMaker-00-00-00 in /home/paredes/TestArea/athenaMetTest2"

if test "${CMTROOT}" = ""; then
  CMTROOT=/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.29/CMT/v1r25p20160527; export CMTROOT
fi
. ${CMTROOT}/mgr/setup.sh
cmttestMetMakertempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if test ! $? = 0 ; then cmttestMetMakertempfile=/tmp/cmt.$$; fi
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=testMetMaker -version=testMetMaker-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  $* >${cmttestMetMakertempfile}
if test $? != 0 ; then
  echo >&2 "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=testMetMaker -version=testMetMaker-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  $* >${cmttestMetMakertempfile}"
  cmtcleanupstatus=2
  /bin/rm -f ${cmttestMetMakertempfile}
  unset cmttestMetMakertempfile
  return $cmtcleanupstatus
fi
cmtcleanupstatus=0
. ${cmttestMetMakertempfile}
if test $? != 0 ; then
  cmtcleanupstatus=2
fi
/bin/rm -f ${cmttestMetMakertempfile}
unset cmttestMetMakertempfile
return $cmtcleanupstatus

