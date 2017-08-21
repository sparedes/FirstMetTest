#-- start of make_header -----------------

#====================================
#  Document TriggerListComponentsList
#
#   Generated Fri Apr 28 17:34:06 2017  by paredes
#
#====================================

include ${CMTROOT}/src/Makefile.core

ifdef tag
CMTEXTRATAGS = $(tag)
else
tag       = $(CMTCONFIG)
endif

cmt_TriggerListComponentsList_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TriggerListComponentsList_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TriggerListComponentsList

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerListComponentsList = $(TriggerList_tag)_TriggerListComponentsList.make
cmt_local_tagfile_TriggerListComponentsList = $(bin)$(TriggerList_tag)_TriggerListComponentsList.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerListComponentsList = $(TriggerList_tag).make
cmt_local_tagfile_TriggerListComponentsList = $(bin)$(TriggerList_tag).make

endif

include $(cmt_local_tagfile_TriggerListComponentsList)
#-include $(cmt_local_tagfile_TriggerListComponentsList)

ifdef cmt_TriggerListComponentsList_has_target_tag

cmt_final_setup_TriggerListComponentsList = $(bin)setup_TriggerListComponentsList.make
cmt_dependencies_in_TriggerListComponentsList = $(bin)dependencies_TriggerListComponentsList.in
#cmt_final_setup_TriggerListComponentsList = $(bin)TriggerList_TriggerListComponentsListsetup.make
cmt_local_TriggerListComponentsList_makefile = $(bin)TriggerListComponentsList.make

else

cmt_final_setup_TriggerListComponentsList = $(bin)setup.make
cmt_dependencies_in_TriggerListComponentsList = $(bin)dependencies.in
#cmt_final_setup_TriggerListComponentsList = $(bin)TriggerListsetup.make
cmt_local_TriggerListComponentsList_makefile = $(bin)TriggerListComponentsList.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TriggerListsetup.make

#TriggerListComponentsList :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TriggerListComponentsList'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TriggerListComponentsList/
#TriggerListComponentsList::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
##
componentslistfile = TriggerList.components
COMPONENTSLIST_DIR = ../$(tag)
fulllibname = libTriggerList.$(shlibsuffix)

TriggerListComponentsList :: ${COMPONENTSLIST_DIR}/$(componentslistfile)
	@:

${COMPONENTSLIST_DIR}/$(componentslistfile) :: $(bin)$(fulllibname)
	@echo 'Generating componentslist file for $(fulllibname)'
	cd ../$(tag);$(listcomponents_cmd) --output ${COMPONENTSLIST_DIR}/$(componentslistfile) $(fulllibname)

install :: TriggerListComponentsListinstall
TriggerListComponentsListinstall :: TriggerListComponentsList

uninstall :: TriggerListComponentsListuninstall
TriggerListComponentsListuninstall :: TriggerListComponentsListclean

TriggerListComponentsListclean ::
	@echo 'Deleting $(componentslistfile)'
	@rm -f ${COMPONENTSLIST_DIR}/$(componentslistfile)

#-- start of cleanup_header --------------

clean :: TriggerListComponentsListclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TriggerListComponentsList.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TriggerListComponentsListclean ::
#-- end of cleanup_header ---------------
