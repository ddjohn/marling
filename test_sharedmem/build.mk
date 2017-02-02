
NAME = test_sharedmem
RUN = 1

INCLUDES = $(DAJO_ROOT)/sharedmem $(DAJO_ROOT)/trace
STATIC_LIBS = sharedmem trace
SHARED_LIBS = 

include ${DAJO_BUILD}/bin.mk
