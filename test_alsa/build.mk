
NAME = test_alsa
RUN = 1

INCLUDES = $(DAJO_ROOT)/alsa $(DAJO_ROOT)/trace
STATIC_LIBS = alsa trace
SHARED_LIBS = asound

include ${DAJO_BUILD}/bin.mk
