# ----------------------------
# Makefile Options
# ----------------------------

NAME ?= WAFFLY
ICON ?=
DESCRIPTION ?= "Waffly devlopment"
COMPRESSED ?= NO
ARCHIVED ?= NO

CFLAGS ?= -Wall -Wextra -Oz -std=c11
CXXFLAGS ?= -Wall -Wextra -Oz -std=c++17

# ----------------------------

ifndef CEDEV
$(error CEDEV environment path variable is not set)
endif

include $(CEDEV)/meta/makefile.mk
