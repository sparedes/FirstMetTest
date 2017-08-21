#-- start of make_header -----------------

#====================================
#  Document TriggerListMergeComponentsList
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

cmt_TriggerListMergeComponentsList_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TriggerListMergeComponentsList_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TriggerListMergeComponentsList

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerListMergeComponentsList = $(TriggerList_tag)_TriggerListMergeComponentsList.make
cmt_local_tagfile_TriggerListMergeComponentsList = $(bin)$(TriggerList_tag)_TriggerListMergeComponentsList.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerListMergeComponentsList = $(TriggerList_tag).make
cmt_local_tagfile_TriggerListMergeComponentsList = $(bin)$(TriggerList_tag).make

endif

include $(cmt_local_tagfile_TriggerListMergeComponentsList)
#-include $(cmt_local_tagfile_TriggerListMergeComponentsList)

ifdef cmt_TriggerListMergeComponentsList_has_target_tag

cmt_final_setup_TriggerListMergeComponentsList = $(bin)setup_TriggerListMergeComponentsList.make
cmt_dependencies_in_TriggerListMergeComponentsList = $(bin)dependencies_TriggerListMergeComponentsList.in
#cmt_final_setup_TriggerListMergeComponentsList = $(bin)TriggerList_TriggerListMergeComponentsListsetup.make
cmt_local_TriggerListMergeComponentsList_makefile = $(bin)TriggerListMergeComponentsList.make

else

cmt_final_setup_TriggerListMergeComponentsList = $(bin)setup.make
cmt_dependencies_in_TriggerListMergeComponentsList = $(bin)dependencies.in
#cmt_final_setup_TriggerListMergeComponentsList = $(bin)TriggerListsetup.make
cmt_local_TriggerListMergeComponentsList_makefile = $(bin)TriggerListMergeComponentsList.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TriggerListsetup.make

#TriggerListMergeComponentsList :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TriggerListMergeComponentsList'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TriggerListMergeComponentsList/
#TriggerListMergeComponentsList::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
# File: cmt/fragments/merge_componentslist_header
# Author: Sebastien Binet (binet@cern.ch)

# Makefile fragment to merge a <library>.components file into a single
# <project>.components file in the (lib) install area
# If no InstallArea is present the fragment is dummy


.PHONY: TriggerListMergeComponentsList TriggerListMergeComponentsListclean

# default is already '#'
#genmap_comment_char := "'#'"

componentsListRef    := ../$(tag)/TriggerList.components

ifdef CMTINSTALLAREA
componentsListDir    := ${CMTINSTALLAREA}/$(tag)/lib
mergedComponentsList := $(componentsListDir)/$(project).components
stampComponentsList  := $(componentsListRef).stamp
else
componentsListDir    := ../$(tag)
mergedComponentsList :=
stampComponentsList  :=
endif

TriggerListMergeComponentsList :: $(stampComponentsList) $(mergedComponentsList)
	@:

.NOTPARALLEL : $(stampComponentsList) $(mergedComponentsList)

$(stampComponentsList) $(mergedComponentsList) :: $(componentsListRef)
	@echo "Running merge_componentslist  TriggerListMergeComponentsList"
	$(merge_componentslist_cmd) --do-merge \
         --input-file $(componentsListRef) --merged-file $(mergedComponentsList)

TriggerListMergeComponentsListclean ::
	$(cleanup_silent) $(merge_componentslist_cmd) --un-merge \
         --input-file $(componentsListRef) --merged-file $(mergedComponentsList) ;
	$(cleanup_silent) $(remove_command) $(stampComponentsList)
libTriggerList_so_dependencies = ../x86_64-slc6-gcc49-opt/libTriggerList.so
#-- start of cleanup_header --------------

clean :: TriggerListMergeComponentsListclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TriggerListMergeComponentsList.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TriggerListMergeComponentsListclean ::
#-- end of cleanup_header ---------------
