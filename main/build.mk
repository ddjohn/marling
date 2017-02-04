
NAME = main
RUN = 0

INCLUDES = framework/trace external/zeromq
STATIC_LIBS = trace
SHARED_LIBS = zeromq

include ${DAJO_BUILD}/bin.mk
