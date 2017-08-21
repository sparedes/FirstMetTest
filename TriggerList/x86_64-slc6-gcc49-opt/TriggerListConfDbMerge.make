#-- start of make_header -----------------

#====================================
#  Document TriggerListConfDbMerge
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

cmt_TriggerListConfDbMerge_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TriggerListConfDbMerge_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TriggerListConfDbMerge

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerListConfDbMerge = $(TriggerList_tag)_TriggerListConfDbMerge.make
cmt_local_tagfile_TriggerListConfDbMerge = $(bin)$(TriggerList_tag)_TriggerListConfDbMerge.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerListConfDbMerge = $(TriggerList_tag).make
cmt_local_tagfile_TriggerListConfDbMerge = $(bin)$(TriggerList_tag).make

endif

include $(cmt_local_tagfile_TriggerListConfDbMerge)
#-include $(cmt_local_tagfile_TriggerListConfDbMerge)

ifdef cmt_TriggerListConfDbMerge_has_target_tag

cmt_final_setup_TriggerListConfDbMerge = $(bin)setup_TriggerListConfDbMerge.make
cmt_dependencies_in_TriggerListConfDbMerge = $(bin)dependencies_TriggerListConfDbMerge.in
#cmt_final_setup_TriggerListConfDbMerge = $(bin)TriggerList_TriggerListConfDbMergesetup.make
cmt_local_TriggerListConfDbMerge_makefile = $(bin)TriggerListConfDbMerge.make

else

cmt_final_setup_TriggerListConfDbMerge = $(bin)setup.make
cmt_dependencies_in_TriggerListConfDbMerge = $(bin)dependencies.in
#cmt_final_setup_TriggerListConfDbMerge = $(bin)TriggerListsetup.make
cmt_local_TriggerListConfDbMerge_makefile = $(bin)TriggerListConfDbMerge.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TriggerListsetup.make

#TriggerListConfDbMerge :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TriggerListConfDbMerge'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TriggerListConfDbMerge/
#TriggerListConfDbMerge::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
# File: cmt/fragments/merge_genconfDb_header
# Author: Sebastien Binet (binet@cern.ch)

# Makefile fragment to merge a <library>.confdb file into a single
# <project>.confdb file in the (lib) install area

.PHONY: TriggerListConfDbMerge TriggerListConfDbMergeclean

# default is already '#'
#genconfDb_comment_char := "'#'"

instdir      := ${CMTINSTALLAREA}/$(tag)
confDbRef    := /home/paredes/TestArea/athenaMetTest2/TriggerList/genConf/TriggerList/TriggerList.confdb
stampConfDb  := $(confDbRef).stamp
mergedConfDb := $(instdir)/lib/$(project).confdb

TriggerListConfDbMerge :: $(stampConfDb) $(mergedConfDb)
	@:

.NOTPARALLEL : $(stampConfDb) $(mergedConfDb)

$(stampConfDb) $(mergedConfDb) :: $(confDbRef)
	@echo "Running merge_genconfDb  TriggerListConfDbMerge"
	$(merge_genconfDb_cmd) \
          --do-merge \
          --input-file $(confDbRef) \
          --merged-file $(mergedConfDb)

TriggerListConfDbMergeclean ::
	$(cleanup_silent) $(merge_genconfDb_cmd) \
          --un-merge \
          --input-file $(confDbRef) \
          --merged-file $(mergedConfDb)	;
	$(cleanup_silent) $(remove_command) $(stampConfDb)
libTriggerList_so_dependencies = ../x86_64-slc6-gcc49-opt/libTriggerList.so
#-- start of cleanup_header --------------

clean :: TriggerListConfDbMergeclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TriggerListConfDbMerge.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TriggerListConfDbMergeclean ::
#-- end of cleanup_header ---------------
