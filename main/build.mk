
NAME := main
RUN  := 0

INCLUDES    := framework/serial framework/trace
STATIC_LIBS := trace 
SHARED_LIBS := serial

include ${DAJO_BUILD}/bin.mk
