# echo "setup WorkArea WorkArea-00-00-00 in /home/paredes/TestArea/athenaMetTest2"

if ( $?CMTROOT == 0 ) then
  setenv CMTROOT /cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/CMT/v1r25p20160527
endif
source ${CMTROOT}/mgr/setup.csh
set cmtWorkAreatempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if $status != 0 then
  set cmtWorkAreatempfile=/tmp/cmt.$$
endif
${CMTROOT}/${CMTBIN}/cmt.exe setup -csh -pack=WorkArea -version=WorkArea-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  -no_cleanup $* >${cmtWorkAreatempfile}
if ( $status != 0 ) then
  echo "${CMTROOT}/${CMTBIN}/cmt.exe setup -csh -pack=WorkArea -version=WorkArea-00-00-00 -path=/home/paredes/TestArea/athenaMetTest2  -no_cleanup $* >${cmtWorkAreatempfile}"
  set cmtsetupstatus=2
  /bin/rm -f ${cmtWorkAreatempfile}
  unset cmtWorkAreatempfile
  exit $cmtsetupstatus
endif
set cmtsetupstatus=0
source ${cmtWorkAreatempfile}
if ( $status != 0 ) then
  set cmtsetupstatus=2
endif
/bin/rm -f ${cmtWorkAreatempfile}
unset cmtWorkAreatempfile
exit $cmtsetupstatus

