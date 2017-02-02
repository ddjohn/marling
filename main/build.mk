
NAME = main
RUN = 0

INCLUDES = $(DAJO_ROOT)/sharedmem $(DAJO_ROOT)/alsa $(DAJO_ROOT)/trace
LIBS = alsa sharedmem trace

include ${DAJO_BUILD}/bin.mk
