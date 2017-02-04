AR     := ar
CC     := g++ 
CFLAGS := -std=c++11 -g -Wall -Werror -fPIC -Wno-sign-compare -Wno-unknown-pragmas -DHAVE_PTHREAD -Iapi -Iinc  -DCONFIGURED -Wno-unused-variable

ifeq ($(VERBOSE),1)
$(warning *** verbose mode ***)
V      :=
else
V      := @
endif
