
NAME = test_sharedmem
RUN = 1

INCLUDES = framework/sharedmem framework/trace
STATIC_LIBS = sharedmem trace
SHARED_LIBS = 

include ${DAJO_BUILD}/bin.mk
