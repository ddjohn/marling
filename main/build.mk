
NAME = main

INCLUDES = $(DAJO_ROOT)/alsa $(DAJO_ROOT)/trace
LIBS = alsa trace

include ${DAJO_BUILD}/bin.mk
