# echo "cleanup testMetMaker testMetMaker-00-00-00 in /home/paredes/TestArea/athenaMetTest2"

if ( $?CMTROOT == 0 ) then
  setenv CMTROOT /cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.29/CMT/v1r25p20160527
endif
source ${CMTROOT}/mgr/setup.csh
set cmttestMetMakertempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if $status != 0 then
  set cmttestMetMakertempfile=/tmp/cmt.$$
endif
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -csh -pack=testMetMaker -version=testMetMaker-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  $* >${cmttestMetMakertempfile}
if ( $status != 0 ) then
  echo "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -csh -pack=testMetMaker -version=testMetMaker-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  $* >${cmttestMetMakertempfile}"
  set cmtcleanupstatus=2
  /bin/rm -f ${cmttestMetMakertempfile}
  unset cmttestMetMakertempfile
  exit $cmtcleanupstatus
endif
set cmtcleanupstatus=0
source ${cmttestMetMakertempfile}
if ( $status != 0 ) then
  set cmtcleanupstatus=2
endif
/bin/rm -f ${cmttestMetMakertempfile}
unset cmttestMetMakertempfile
exit $cmtcleanupstatus
