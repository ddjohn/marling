AR       := ar
CPP      := g++ 
CC       := gcc 
CPPFLAGS := -std=c++11 -g -Wall -Werror -fPIC -Wno-sign-compare -Wno-unknown-pragmas -DHAVE_PTHREAD -Iapi -Iinc  -DCONFIGURED -Wno-unused-variable -fpermissive -Wno-error
CFLAGS   := -g -Wall -Werror -fPIC -Wno-sign-compare -Wno-unknown-pragmas -DHAVE_PTHREAD -Iapi -Iinc  -DCONFIGURED -Wno-unused-variable -Wno-error

ifeq ($(VERBOSE),1)
V        :=
else
V        := @
endif
