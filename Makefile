#
# OMNeT++/OMNEST Makefile for omnet-tiirt
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out
#

# Name of target to be created (-o option)
TARGET = omnet-tiirt$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -IScheduler \
    -Iadminssioncontrol \
    -Igenerator \
    -Ipacket \
    -Iprofiler \
    -Iresults

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cpp and .msg files
OBJS = \
    $O/Scheduler/PiorityScheduler.o \
    $O/Scheduler/RR.o \
    $O/Scheduler/FCFS.o \
    $O/Scheduler/SJF.o \
    $O/adminssioncontrol/Blue.o \
    $O/adminssioncontrol/RED.o \
    $O/adminssioncontrol/wRED.o \
    $O/adminssioncontrol/SourceBanlist.o \
    $O/adminssioncontrol/AdmissionControl.o \
    $O/generator/ExponentialGen.o \
    $O/generator/MMPPGen.o \
    $O/generator/SimpleGen.o \
    $O/generator/OnOffGen.o \
    $O/generator/Sink.o \
    $O/generator/PoissonGen.o \
    $O/profiler/TokenBucket.o \
    $O/profiler/LeakyBucket.o \
    $O/profiler/HTokenBucket.o \
    $O/packet/Packet_m.o

# Message files
MSGFILES = \
    packet/Packet.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cpp

$O/%.o: %.cpp $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(COPTS) -o $@ $<

%_m.cpp %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cpp $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f omnet-tiirt omnet-tiirt.exe libomnet-tiirt.so libomnet-tiirt.a libomnet-tiirt.dll libomnet-tiirt.dylib
	$(Q)-rm -f ./*_m.cpp ./*_m.h
	$(Q)-rm -f Scheduler/*_m.cpp Scheduler/*_m.h
	$(Q)-rm -f adminssioncontrol/*_m.cpp adminssioncontrol/*_m.h
	$(Q)-rm -f generator/*_m.cpp generator/*_m.h
	$(Q)-rm -f packet/*_m.cpp packet/*_m.h
	$(Q)-rm -f profiler/*_m.cpp profiler/*_m.h
	$(Q)-rm -f results/*_m.cpp results/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cpp Scheduler/*.cpp adminssioncontrol/*.cpp generator/*.cpp packet/*.cpp profiler/*.cpp results/*.cpp

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/Scheduler/FCFS.o: Scheduler/FCFS.cpp \
	Scheduler/FCFS.h \
	packet/Packet_m.h
$O/Scheduler/PiorityScheduler.o: Scheduler/PiorityScheduler.cpp \
	Scheduler/FCFS.h \
	Scheduler/PriorityScheduler.h \
	packet/Packet_m.h
$O/Scheduler/RR.o: Scheduler/RR.cpp \
	Scheduler/FCFS.h \
	Scheduler/RR.h \
	packet/Packet_m.h
$O/Scheduler/SJF.o: Scheduler/SJF.cpp \
	Scheduler/FCFS.h \
	Scheduler/SJF.h \
	packet/Packet_m.h
$O/adminssioncontrol/AdmissionControl.o: adminssioncontrol/AdmissionControl.cpp \
	adminssioncontrol/AdmissionControl.h \
	packet/Packet_m.h
$O/adminssioncontrol/Blue.o: adminssioncontrol/Blue.cpp \
	adminssioncontrol/AdmissionControl.h \
	adminssioncontrol/Blue.h \
	packet/Packet_m.h
$O/adminssioncontrol/RED.o: adminssioncontrol/RED.cpp \
	adminssioncontrol/AdmissionControl.h \
	adminssioncontrol/RED.h \
	packet/Packet_m.h
$O/adminssioncontrol/SourceBanlist.o: adminssioncontrol/SourceBanlist.cpp \
	adminssioncontrol/AdmissionControl.h \
	adminssioncontrol/SourceBanlist.h \
	packet/Packet_m.h
$O/adminssioncontrol/wRED.o: adminssioncontrol/wRED.cpp \
	adminssioncontrol/AdmissionControl.h \
	adminssioncontrol/RED.h \
	adminssioncontrol/wRED.h \
	packet/Packet_m.h
$O/generator/ExponentialGen.o: generator/ExponentialGen.cpp \
	generator/ExponentialGen.h \
	generator/SimpleGen.h \
	packet/Packet_m.h
$O/generator/MMPPGen.o: generator/MMPPGen.cpp \
	generator/MMPPGen.h \
	generator/SimpleGen.h \
	packet/Packet_m.h
$O/generator/OnOffGen.o: generator/OnOffGen.cpp \
	generator/MMPPGen.h \
	generator/OnOffGen.h \
	generator/SimpleGen.h \
	packet/Packet_m.h
$O/generator/PoissonGen.o: generator/PoissonGen.cpp \
	generator/PoissonGen.h \
	generator/SimpleGen.h \
	packet/Packet_m.h
$O/generator/SimpleGen.o: generator/SimpleGen.cpp \
	generator/SimpleGen.h \
	packet/Packet_m.h
$O/generator/Sink.o: generator/Sink.cpp \
	generator/Sink.h \
	packet/Packet_m.h
$O/profiler/HTokenBucket.o: profiler/HTokenBucket.cpp \
	packet/Packet_m.h \
	profiler/HTokenBucket.h \
	profiler/LeakyBucket.h \
	profiler/TokenBucket.h
$O/profiler/LeakyBucket.o: profiler/LeakyBucket.cpp \
	packet/Packet_m.h \
	profiler/LeakyBucket.h
$O/profiler/TokenBucket.o: profiler/TokenBucket.cpp \
	packet/Packet_m.h \
	profiler/LeakyBucket.h \
	profiler/TokenBucket.h

