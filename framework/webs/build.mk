
NAME        := webs
INCLUDES    := external/websocket framework/trace
STATIC_LIBS := #trace 
SHARED_LIBS := websocket ssl crypto

include ${DAJO_BUILD}/lib.mk
