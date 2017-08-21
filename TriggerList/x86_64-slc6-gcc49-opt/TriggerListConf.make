#-- start of make_header -----------------

#====================================
#  Document TriggerListConf
#
#   Generated Fri Apr 28 17:34:05 2017  by paredes
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_TriggerListConf_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TriggerListConf_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TriggerListConf

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerListConf = $(TriggerList_tag)_TriggerListConf.make
cmt_local_tagfile_TriggerListConf = $(bin)$(TriggerList_tag)_TriggerListConf.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerListConf = $(TriggerList_tag).make
cmt_local_tagfile_TriggerListConf = $(bin)$(TriggerList_tag).make

endif

include $(cmt_local_tagfile_TriggerListConf)
#-include $(cmt_local_tagfile_TriggerListConf)

ifdef cmt_TriggerListConf_has_target_tag

cmt_final_setup_TriggerListConf = $(bin)setup_TriggerListConf.make
cmt_dependencies_in_TriggerListConf = $(bin)dependencies_TriggerListConf.in
#cmt_final_setup_TriggerListConf = $(bin)TriggerList_TriggerListConfsetup.make
cmt_local_TriggerListConf_makefile = $(bin)TriggerListConf.make

else

cmt_final_setup_TriggerListConf = $(bin)setup.make
cmt_dependencies_in_TriggerListConf = $(bin)dependencies.in
#cmt_final_setup_TriggerListConf = $(bin)TriggerListsetup.make
cmt_local_TriggerListConf_makefile = $(bin)TriggerListConf.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TriggerListsetup.make

#TriggerListConf :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TriggerListConf'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TriggerListConf/
#TriggerListConf::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
# File: cmt/fragments/genconfig_header
# Author: Wim Lavrijsen (WLavrijsen@lbl.gov)

# Use genconf.exe to create configurables python modules, then have the
# normal python install procedure take over.

.PHONY: TriggerListConf TriggerListConfclean

confpy  := TriggerListConf.py
conflib := $(bin)$(library_prefix)TriggerList.$(shlibsuffix)
confdb  := TriggerList.confdb
instdir := $(CMTINSTALLAREA)$(shared_install_subdir)/python/$(package)
product := $(instdir)/$(confpy)
initpy  := $(instdir)/__init__.py

ifdef GENCONF_ECHO
genconf_silent =
else
genconf_silent = $(silent)
endif

TriggerListConf :: TriggerListConfinstall

install :: TriggerListConfinstall

TriggerListConfinstall : /home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList/$(confpy)
	@echo "Installing /home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList in /home/paredes/TestArea/athenaMetTest2/InstallArea/python" ; \
	 $(install_command) --exclude="*.py?" --exclude="__init__.py" --exclude="*.confdb" /home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList /home/paredes/TestArea/athenaMetTest2/InstallArea/python ; \

/home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList/$(confpy) : $(conflib) /home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList
	$(genconf_silent) $(genconfig_cmd)   -o /home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList -p $(package) \
	  --configurable-module=GaudiKernel.Proxy \
	  --configurable-default-name=Configurable.DefaultName \
	  --configurable-algorithm=ConfigurableAlgorithm \
	  --configurable-algtool=ConfigurableAlgTool \
	  --configurable-auditor=ConfigurableAuditor \
          --configurable-service=ConfigurableService \
	  -i ../$(tag)/$(library_prefix)TriggerList.$(shlibsuffix)

/home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList:
	@ if [ ! -d /home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList ] ; then mkdir -p /home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList ; fi ;

TriggerListConfclean :: TriggerListConfuninstall
	$(cleanup_silent) $(remove_command) /home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList/$(confpy) /home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList/$(confdb)

uninstall :: TriggerListConfuninstall

TriggerListConfuninstall ::
	@$(uninstall_command) /home/paredes/TestArea/athenaMetTest2/InstallArea/python
libTriggerList_so_dependencies = ../x86_64-slc6-gcc49-opt/libTriggerList.so
#-- start of cleanup_header --------------

clean :: TriggerListConfclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TriggerListConf.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TriggerListConfclean ::
#-- end of cleanup_header ---------------
