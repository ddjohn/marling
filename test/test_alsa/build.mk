
NAME = test_alsa
RUN = 1

INCLUDES = framework/alsa framework/trace
STATIC_LIBS = alsa trace
SHARED_LIBS = asound

include ${DAJO_BUILD}/bin.mk
