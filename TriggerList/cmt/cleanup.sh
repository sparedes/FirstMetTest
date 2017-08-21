# echo "cleanup TriggerList TriggerList-00-00-00 in /home/paredes/TestArea/athenaMetTest2"

if test "${CMTROOT}" = ""; then
  CMTROOT=/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/CMT/v1r25p20160527; export CMTROOT
fi
. ${CMTROOT}/mgr/setup.sh
cmtTriggerListtempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if test ! $? = 0 ; then cmtTriggerListtempfile=/tmp/cmt.$$; fi
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=TriggerList -version=TriggerList-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  $* >${cmtTriggerListtempfile}
if test $? != 0 ; then
  echo >&2 "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=TriggerList -version=TriggerList-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  $* >${cmtTriggerListtempfile}"
  cmtcleanupstatus=2
  /bin/rm -f ${cmtTriggerListtempfile}
  unset cmtTriggerListtempfile
  return $cmtcleanupstatus
fi
cmtcleanupstatus=0
. ${cmtTriggerListtempfile}
if test $? != 0 ; then
  cmtcleanupstatus=2
fi
/bin/rm -f ${cmtTriggerListtempfile}
unset cmtTriggerListtempfile
return $cmtcleanupstatus

