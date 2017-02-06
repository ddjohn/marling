
NAME := esp8266
RUN  := 0

INCLUDES    := framework/serial framework/trace
STATIC_LIBS := trace 
SHARED_LIBS := serial

include ${DAJO_BUILD}/bin.mk
