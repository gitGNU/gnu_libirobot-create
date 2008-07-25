include $(top_srcdir)/build-aux/init.mk

# Add available warnings flags.
AM_CXXFLAGS += $(WARNING_CXXFLAGS)

lib_LTLIBRARIES = libirobot-create.la

include_HEADERS =					\
				irobot-create-fwd.hh	\
				irobot-create.hh

libirobot_create_la_SOURCES = 				\
				doc.hh			\
				irobot-create.cc

bin_PROGRAMS = irobot-create-ctl

irobot_create_ctl_SOURCES = irobot-create-ctl.cc
irobot_create_ctl_LDADD = libirobot-create.la
