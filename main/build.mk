
NAME = main
RUN = 0

INCLUDES = $(DAJO_ROOT)/sharedmem $(DAJO_ROOT)/alsa $(DAJO_ROOT)/trace
STATIC_LIBS = alsa sharedmem trace
SHARED_LIBS = asound

include ${DAJO_BUILD}/bin.mk
