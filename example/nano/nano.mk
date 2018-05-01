NAME := nano

$(NAME)_SOURCES := nano.c

GLOBAL_DEFINES += AOS_NO_WIFI CONFIG_NO_TCPIP

mesh ?= 0

ifeq ($(BENCHMARKS),1)
$(NAME)_COMPONENTS  += benchmarks
GLOBAL_DEFINES      += CONFIG_CMD_BENCHMARKS
endif

