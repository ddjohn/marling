
NAME := main
RUN  := 0

INCLUDES    := framework/trace external/libjson
STATIC_LIBS := trace
SHARED_LIBS := json

include ${DAJO_BUILD}/bin.mk
