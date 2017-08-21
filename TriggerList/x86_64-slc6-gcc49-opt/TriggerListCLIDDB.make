#-- start of make_header -----------------

#====================================
#  Document TriggerListCLIDDB
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

cmt_TriggerListCLIDDB_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TriggerListCLIDDB_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TriggerListCLIDDB

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerListCLIDDB = $(TriggerList_tag)_TriggerListCLIDDB.make
cmt_local_tagfile_TriggerListCLIDDB = $(bin)$(TriggerList_tag)_TriggerListCLIDDB.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerListCLIDDB = $(TriggerList_tag).make
cmt_local_tagfile_TriggerListCLIDDB = $(bin)$(TriggerList_tag).make

endif

include $(cmt_local_tagfile_TriggerListCLIDDB)
#-include $(cmt_local_tagfile_TriggerListCLIDDB)

ifdef cmt_TriggerListCLIDDB_has_target_tag

cmt_final_setup_TriggerListCLIDDB = $(bin)setup_TriggerListCLIDDB.make
cmt_dependencies_in_TriggerListCLIDDB = $(bin)dependencies_TriggerListCLIDDB.in
#cmt_final_setup_TriggerListCLIDDB = $(bin)TriggerList_TriggerListCLIDDBsetup.make
cmt_local_TriggerListCLIDDB_makefile = $(bin)TriggerListCLIDDB.make

else

cmt_final_setup_TriggerListCLIDDB = $(bin)setup.make
cmt_dependencies_in_TriggerListCLIDDB = $(bin)dependencies.in
#cmt_final_setup_TriggerListCLIDDB = $(bin)TriggerListsetup.make
cmt_local_TriggerListCLIDDB_makefile = $(bin)TriggerListCLIDDB.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TriggerListsetup.make

#TriggerListCLIDDB :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TriggerListCLIDDB'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TriggerListCLIDDB/
#TriggerListCLIDDB::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
# File: cmt/fragments/genCLIDDB_header
# Author: Paolo Calafiura
# derived from genconf_header

# Use genCLIDDB_cmd to create package clid.db files

.PHONY: TriggerListCLIDDB TriggerListCLIDDBclean

outname := clid.db
cliddb  := TriggerList_$(outname)
instdir := $(CMTINSTALLAREA)/share
result  := $(instdir)/$(cliddb)
product := $(instdir)/$(outname)
conflib := $(bin)$(library_prefix)TriggerList.$(shlibsuffix)

TriggerListCLIDDB :: $(result)

$(instdir) :
	$(mkdir) -p $(instdir)

$(result) : $(conflib) $(product)
	@$(genCLIDDB_cmd) -p TriggerList -i$(product) -o $(result)

$(product) : $(instdir)
	touch $(product)

TriggerListCLIDDBclean ::
	$(cleanup_silent) $(uninstall_command) $(product) $(result)
	$(cleanup_silent) $(cmt_uninstallarea_command) $(product) $(result)

#-- start of cleanup_header --------------

clean :: TriggerListCLIDDBclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TriggerListCLIDDB.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TriggerListCLIDDBclean ::
#-- end of cleanup_header ---------------
