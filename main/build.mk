
NAME = main
RUN = 0

INCLUDES = framework/trace external/protobuf external/zeromq
STATIC_LIBS = trace 
SHARED_LIBS = protobuf zeromq sodium pthread

include ${DAJO_BUILD}/bin.mk
