
NAME = test_zeromq
RUN = 0

INCLUDES = framework/trace external/zeromq
STATIC_LIBS = trace 
SHARED_LIBS = zeromq sodium pthread

include ${DAJO_BUILD}/bin.mk
