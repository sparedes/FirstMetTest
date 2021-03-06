#-- start of make_header -----------------

#====================================
#  Document check_install_python_modules
#
#   Generated Fri Apr 28 17:33:33 2017  by paredes
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_check_install_python_modules_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_check_install_python_modules_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_check_install_python_modules

TriggerList_tag = $(tag)

#cmt_local_tagfile_check_install_python_modules = $(TriggerList_tag)_check_install_python_modules.make
cmt_local_tagfile_check_install_python_modules = $(bin)$(TriggerList_tag)_check_install_python_modules.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TriggerList_tag = $(tag)

#cmt_local_tagfile_check_install_python_modules = $(TriggerList_tag).make
cmt_local_tagfile_check_install_python_modules = $(bin)$(TriggerList_tag).make

endif

include $(cmt_local_tagfile_check_install_python_modules)
#-include $(cmt_local_tagfile_check_install_python_modules)

ifdef cmt_check_install_python_modules_has_target_tag

cmt_final_setup_check_install_python_modules = $(bin)setup_check_install_python_modules.make
cmt_dependencies_in_check_install_python_modules = $(bin)dependencies_check_install_python_modules.in
#cmt_final_setup_check_install_python_modules = $(bin)TriggerList_check_install_python_modulessetup.make
cmt_local_check_install_python_modules_makefile = $(bin)check_install_python_modules.make

else

cmt_final_setup_check_install_python_modules = $(bin)setup.make
cmt_dependencies_in_check_install_python_modules = $(bin)dependencies.in
#cmt_final_setup_check_install_python_modules = $(bin)TriggerListsetup.make
cmt_local_check_install_python_modules_makefile = $(bin)check_install_python_modules.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TriggerListsetup.make

#check_install_python_modules :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'check_install_python_modules'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = check_install_python_modules/
#check_install_python_modules::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
#-- start of cmt_action_runner_header ---------------

ifdef ONCE
check_install_python_modules_once = 1
endif

ifdef check_install_python_modules_once

check_install_python_modulesactionstamp = $(bin)check_install_python_modules.actionstamp
#check_install_python_modulesactionstamp = check_install_python_modules.actionstamp

check_install_python_modules :: $(check_install_python_modulesactionstamp)
	$(echo) "check_install_python_modules ok"
#	@echo check_install_python_modules ok

#$(check_install_python_modulesactionstamp) :: $(check_install_python_modules_dependencies)
$(check_install_python_modulesactionstamp) ::
	$(silent) /cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25/External/ExternalPolicy/cmt/atlas_check_installations.sh -files=' -s=../python *.py ' -installdir=/home/paredes/TestArea/athenaMetTest2/InstallArea/python/TriggerList -level=
	$(silent) cat /dev/null > $(check_install_python_modulesactionstamp)
#	@echo ok > $(check_install_python_modulesactionstamp)

check_install_python_modulesclean ::
	$(cleanup_silent) /bin/rm -f $(check_install_python_modulesactionstamp)

else

#check_install_python_modules :: $(check_install_python_modules_dependencies)
check_install_python_modules ::
	$(silent) /cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.25/AthAnalysisBase/2.4.25/External/ExternalPolicy/cmt/atlas_check_installations.sh -files=' -s=../python *.py ' -installdir=/home/paredes/TestArea/athenaMetTest2/InstallArea/python/TriggerList -level=

endif

install ::
uninstall ::

#-- end of cmt_action_runner_header -----------------
#-- start of cleanup_header --------------

clean :: check_install_python_modulesclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(check_install_python_modules.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

check_install_python_modulesclean ::
#-- end of cleanup_header ---------------
