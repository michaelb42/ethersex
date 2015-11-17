TOPDIR ?= ../..
include $(TOPDIR)/.config

$(NEPTUN_SUPPORT)_SRC += \
services/project_neptun/neptun.c \
services/project_neptun/neptun_datastore.c \
services/project_neptun/neptun_lighting.c \
services/project_neptun/neptun_mmi.c \
services/project_neptun/neptun_onewire.c

$(NEPTUN_SUPPORT)_ECMD_SRC += services/project_neptun/neptun_ecmd.c

##############################################################################
# generic fluff
include $(TOPDIR)/scripts/rules.mk
