#-- start of make_header -----------------

#====================================
#  Library TriggerList
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

cmt_TriggerList_has_no_target_tag = 1

#--------------------------------------------------------

ifdef cmt_TriggerList_has_target_tag

tags      = $(tag),$(CMTEXTRATAGS),target_TriggerList

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerList = $(TriggerList_tag)_TriggerList.make
cmt_local_tagfile_TriggerList = $(bin)$(TriggerList_tag)_TriggerList.make

else

tags      = $(tag),$(CMTEXTRATAGS)

TriggerList_tag = $(tag)

#cmt_local_tagfile_TriggerList = $(TriggerList_tag).make
cmt_local_tagfile_TriggerList = $(bin)$(TriggerList_tag).make

endif

include $(cmt_local_tagfile_TriggerList)
#-include $(cmt_local_tagfile_TriggerList)

ifdef cmt_TriggerList_has_target_tag

cmt_final_setup_TriggerList = $(bin)setup_TriggerList.make
cmt_dependencies_in_TriggerList = $(bin)dependencies_TriggerList.in
#cmt_final_setup_TriggerList = $(bin)TriggerList_TriggerListsetup.make
cmt_local_TriggerList_makefile = $(bin)TriggerList.make

else

cmt_final_setup_TriggerList = $(bin)setup.make
cmt_dependencies_in_TriggerList = $(bin)dependencies.in
#cmt_final_setup_TriggerList = $(bin)TriggerListsetup.make
cmt_local_TriggerList_makefile = $(bin)TriggerList.make

endif

#cmt_final_setup = $(bin)setup.make
#cmt_final_setup = $(bin)TriggerListsetup.make

#TriggerList :: ;

dirs ::
	@if test ! -r requirements ; then echo "No requirements file" ; fi; \
	  if test ! -d $(bin) ; then $(mkdir) -p $(bin) ; fi

javadirs ::
	@if test ! -d $(javabin) ; then $(mkdir) -p $(javabin) ; fi

srcdirs ::
	@if test ! -d $(src) ; then $(mkdir) -p $(src) ; fi

help ::
	$(echo) 'TriggerList'

binobj = 
ifdef STRUCTURED_OUTPUT
binobj = TriggerList/
#TriggerList::
#	@if test ! -d $(bin)$(binobj) ; then $(mkdir) -p $(bin)$(binobj) ; fi
#	$(echo) "STRUCTURED_OUTPUT="$(bin)$(binobj)
endif

${CMTROOT}/src/Makefile.core : ;
ifdef use_requirements
$(use_requirements) : ;
endif

#-- end of make_header ------------------
#-- start of libary_header ---------------

TriggerListlibname   = $(bin)$(library_prefix)TriggerList$(library_suffix)
TriggerListlib       = $(TriggerListlibname).a
TriggerListstamp     = $(bin)TriggerList.stamp
TriggerListshstamp   = $(bin)TriggerList.shstamp

TriggerList :: dirs  TriggerListLIB
	$(echo) "TriggerList ok"

#-- end of libary_header ----------------
#-- start of library_no_static ------

#TriggerListLIB :: $(TriggerListlib) $(TriggerListshstamp)
TriggerListLIB :: $(TriggerListshstamp)
	$(echo) "TriggerList : library ok"

$(TriggerListlib) :: $(bin)TriggerListAlg.o $(bin)TrigPassNums.o $(bin)TriggerList_entries.o $(bin)TriggerList_load.o
	$(lib_echo) "static library $@"
	$(lib_silent) cd $(bin); \
	  $(ar) $(TriggerListlib) $?
	$(lib_silent) $(ranlib) $(TriggerListlib)
	$(lib_silent) cat /dev/null >$(TriggerListstamp)

#------------------------------------------------------------------
#  Future improvement? to empty the object files after
#  storing in the library
#
##	  for f in $?; do \
##	    rm $${f}; touch $${f}; \
##	  done
#------------------------------------------------------------------

#
# We add one level of dependency upon the true shared library 
# (rather than simply upon the stamp file)
# this is for cases where the shared library has not been built
# while the stamp was created (error??) 
#

$(TriggerListlibname).$(shlibsuffix) :: $(bin)TriggerListAlg.o $(bin)TrigPassNums.o $(bin)TriggerList_entries.o $(bin)TriggerList_load.o $(use_requirements) $(TriggerListstamps)
	$(lib_echo) "shared library $@"
	$(lib_silent) $(shlibbuilder) $(shlibflags) -o $@ $(bin)TriggerListAlg.o $(bin)TrigPassNums.o $(bin)TriggerList_entries.o $(bin)TriggerList_load.o $(TriggerList_shlibflags)
	$(lib_silent) cat /dev/null >$(TriggerListstamp) && \
	  cat /dev/null >$(TriggerListshstamp)

$(TriggerListshstamp) :: $(TriggerListlibname).$(shlibsuffix)
	$(lib_silent) if test -f $(TriggerListlibname).$(shlibsuffix) ; then \
	  cat /dev/null >$(TriggerListstamp) && \
	  cat /dev/null >$(TriggerListshstamp) ; fi

TriggerListclean ::
	$(cleanup_echo) objects TriggerList
	$(cleanup_silent) /bin/rm -f $(bin)TriggerListAlg.o $(bin)TrigPassNums.o $(bin)TriggerList_entries.o $(bin)TriggerList_load.o
	$(cleanup_silent) /bin/rm -f $(patsubst %.o,%.d,$(bin)TriggerListAlg.o $(bin)TrigPassNums.o $(bin)TriggerList_entries.o $(bin)TriggerList_load.o) $(patsubst %.o,%.dep,$(bin)TriggerListAlg.o $(bin)TrigPassNums.o $(bin)TriggerList_entries.o $(bin)TriggerList_load.o) $(patsubst %.o,%.d.stamp,$(bin)TriggerListAlg.o $(bin)TrigPassNums.o $(bin)TriggerList_entries.o $(bin)TriggerList_load.o)
	$(cleanup_silent) cd $(bin); /bin/rm -rf TriggerList_deps TriggerList_dependencies.make

#-----------------------------------------------------------------
#
#  New section for automatic installation
#
#-----------------------------------------------------------------

install_dir = ${CMTINSTALLAREA}/$(tag)/lib
TriggerListinstallname = $(library_prefix)TriggerList$(library_suffix).$(shlibsuffix)

TriggerList :: TriggerListinstall ;

install :: TriggerListinstall ;

TriggerListinstall :: $(install_dir)/$(TriggerListinstallname)
ifdef CMTINSTALLAREA
	$(echo) "installation done"
endif

$(install_dir)/$(TriggerListinstallname) :: $(bin)$(TriggerListinstallname)
ifdef CMTINSTALLAREA
	$(install_silent) $(cmt_install_action) \
	    -source "`(cd $(bin); pwd)`" \
	    -name "$(TriggerListinstallname)" \
	    -out "$(install_dir)" \
	    -cmd "$(cmt_installarea_command)" \
	    -cmtpath "$($(package)_cmtpath)"
endif

##TriggerListclean :: TriggerListuninstall

uninstall :: TriggerListuninstall ;

TriggerListuninstall ::
ifdef CMTINSTALLAREA
	$(cleanup_silent) $(cmt_uninstall_action) \
	    -source "`(cd $(bin); pwd)`" \
	    -name "$(TriggerListinstallname)" \
	    -out "$(install_dir)" \
	    -cmtpath "$($(package)_cmtpath)"
endif

#-- end of library_no_static ------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),TriggerListclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)TriggerListAlg.d

$(bin)$(binobj)TriggerListAlg.d :

$(bin)$(binobj)TriggerListAlg.o : $(cmt_final_setup_TriggerList)

$(bin)$(binobj)TriggerListAlg.o : $(src)TriggerListAlg.cxx
	$(cpp_echo) $(src)TriggerListAlg.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(TriggerList_pp_cppflags) $(lib_TriggerList_pp_cppflags) $(TriggerListAlg_pp_cppflags) $(use_cppflags) $(TriggerList_cppflags) $(lib_TriggerList_cppflags) $(TriggerListAlg_cppflags) $(TriggerListAlg_cxx_cppflags)  $(src)TriggerListAlg.cxx
endif
endif

else
$(bin)TriggerList_dependencies.make : $(TriggerListAlg_cxx_dependencies)

$(bin)TriggerList_dependencies.make : $(src)TriggerListAlg.cxx

$(bin)$(binobj)TriggerListAlg.o : $(TriggerListAlg_cxx_dependencies)
	$(cpp_echo) $(src)TriggerListAlg.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(TriggerList_pp_cppflags) $(lib_TriggerList_pp_cppflags) $(TriggerListAlg_pp_cppflags) $(use_cppflags) $(TriggerList_cppflags) $(lib_TriggerList_cppflags) $(TriggerListAlg_cppflags) $(TriggerListAlg_cxx_cppflags)  $(src)TriggerListAlg.cxx

endif

#-- end of cpp_library ------------------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),TriggerListclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)TrigPassNums.d

$(bin)$(binobj)TrigPassNums.d :

$(bin)$(binobj)TrigPassNums.o : $(cmt_final_setup_TriggerList)

$(bin)$(binobj)TrigPassNums.o : $(src)TrigPassNums.cxx
	$(cpp_echo) $(src)TrigPassNums.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(TriggerList_pp_cppflags) $(lib_TriggerList_pp_cppflags) $(TrigPassNums_pp_cppflags) $(use_cppflags) $(TriggerList_cppflags) $(lib_TriggerList_cppflags) $(TrigPassNums_cppflags) $(TrigPassNums_cxx_cppflags)  $(src)TrigPassNums.cxx
endif
endif

else
$(bin)TriggerList_dependencies.make : $(TrigPassNums_cxx_dependencies)

$(bin)TriggerList_dependencies.make : $(src)TrigPassNums.cxx

$(bin)$(binobj)TrigPassNums.o : $(TrigPassNums_cxx_dependencies)
	$(cpp_echo) $(src)TrigPassNums.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(TriggerList_pp_cppflags) $(lib_TriggerList_pp_cppflags) $(TrigPassNums_pp_cppflags) $(use_cppflags) $(TriggerList_cppflags) $(lib_TriggerList_cppflags) $(TrigPassNums_cppflags) $(TrigPassNums_cxx_cppflags)  $(src)TrigPassNums.cxx

endif

#-- end of cpp_library ------------------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),TriggerListclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)TriggerList_entries.d

$(bin)$(binobj)TriggerList_entries.d :

$(bin)$(binobj)TriggerList_entries.o : $(cmt_final_setup_TriggerList)

$(bin)$(binobj)TriggerList_entries.o : $(src)components/TriggerList_entries.cxx
	$(cpp_echo) $(src)components/TriggerList_entries.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(TriggerList_pp_cppflags) $(lib_TriggerList_pp_cppflags) $(TriggerList_entries_pp_cppflags) $(use_cppflags) $(TriggerList_cppflags) $(lib_TriggerList_cppflags) $(TriggerList_entries_cppflags) $(TriggerList_entries_cxx_cppflags) -I../src/components $(src)components/TriggerList_entries.cxx
endif
endif

else
$(bin)TriggerList_dependencies.make : $(TriggerList_entries_cxx_dependencies)

$(bin)TriggerList_dependencies.make : $(src)components/TriggerList_entries.cxx

$(bin)$(binobj)TriggerList_entries.o : $(TriggerList_entries_cxx_dependencies)
	$(cpp_echo) $(src)components/TriggerList_entries.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(TriggerList_pp_cppflags) $(lib_TriggerList_pp_cppflags) $(TriggerList_entries_pp_cppflags) $(use_cppflags) $(TriggerList_cppflags) $(lib_TriggerList_cppflags) $(TriggerList_entries_cppflags) $(TriggerList_entries_cxx_cppflags) -I../src/components $(src)components/TriggerList_entries.cxx

endif

#-- end of cpp_library ------------------
#-- start of cpp_library -----------------

ifneq (-MMD -MP -MF $*.d -MQ $@,)

ifneq ($(MAKECMDGOALS),TriggerListclean)
ifneq ($(MAKECMDGOALS),uninstall)
-include $(bin)$(binobj)TriggerList_load.d

$(bin)$(binobj)TriggerList_load.d :

$(bin)$(binobj)TriggerList_load.o : $(cmt_final_setup_TriggerList)

$(bin)$(binobj)TriggerList_load.o : $(src)components/TriggerList_load.cxx
	$(cpp_echo) $(src)components/TriggerList_load.cxx
	$(cpp_silent) $(cppcomp) -MMD -MP -MF $*.d -MQ $@ -o $@ $(use_pp_cppflags) $(TriggerList_pp_cppflags) $(lib_TriggerList_pp_cppflags) $(TriggerList_load_pp_cppflags) $(use_cppflags) $(TriggerList_cppflags) $(lib_TriggerList_cppflags) $(TriggerList_load_cppflags) $(TriggerList_load_cxx_cppflags) -I../src/components $(src)components/TriggerList_load.cxx
endif
endif

else
$(bin)TriggerList_dependencies.make : $(TriggerList_load_cxx_dependencies)

$(bin)TriggerList_dependencies.make : $(src)components/TriggerList_load.cxx

$(bin)$(binobj)TriggerList_load.o : $(TriggerList_load_cxx_dependencies)
	$(cpp_echo) $(src)components/TriggerList_load.cxx
	$(cpp_silent) $(cppcomp) -o $@ $(use_pp_cppflags) $(TriggerList_pp_cppflags) $(lib_TriggerList_pp_cppflags) $(TriggerList_load_pp_cppflags) $(use_cppflags) $(TriggerList_cppflags) $(lib_TriggerList_cppflags) $(TriggerList_load_cppflags) $(TriggerList_load_cxx_cppflags) -I../src/components $(src)components/TriggerList_load.cxx

endif

#-- end of cpp_library ------------------
#-- start of cleanup_header --------------

clean :: TriggerListclean ;
#	@cd .

ifndef PEDANTIC
.DEFAULT::
	$(echo) "(TriggerList.make) $@: No rule for such target" >&2
else
.DEFAULT::
	$(error PEDANTIC: $@: No rule for such target)
endif

TriggerListclean ::
#-- end of cleanup_header ---------------
#-- start of cleanup_library -------------
	$(cleanup_echo) library TriggerList
	-$(cleanup_silent) cd $(bin) && \rm -f $(library_prefix)TriggerList$(library_suffix).a $(library_prefix)TriggerList$(library_suffix).$(shlibsuffix) TriggerList.stamp TriggerList.shstamp
#-- end of cleanup_library ---------------
