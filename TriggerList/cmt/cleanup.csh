# echo "cleanup TriggerList TriggerList-00-00-00 in /home/paredes/TestArea/athenaMetTest2"

if ( $?CMTROOT == 0 ) then
  setenv CMTROOT /cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/CMT/v1r25p20160527
endif
source ${CMTROOT}/mgr/setup.csh
set cmtTriggerListtempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if $status != 0 then
  set cmtTriggerListtempfile=/tmp/cmt.$$
endif
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -csh -pack=TriggerList -version=TriggerList-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  $* >${cmtTriggerListtempfile}
if ( $status != 0 ) then
  echo "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -csh -pack=TriggerList -version=TriggerList-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  $* >${cmtTriggerListtempfile}"
  set cmtcleanupstatus=2
  /bin/rm -f ${cmtTriggerListtempfile}
  unset cmtTriggerListtempfile
  exit $cmtcleanupstatus
endif
set cmtcleanupstatus=0
source ${cmtTriggerListtempfile}
if ( $status != 0 ) then
  set cmtcleanupstatus=2
endif
/bin/rm -f ${cmtTriggerListtempfile}
unset cmtTriggerListtempfile
exit $cmtcleanupstatus

