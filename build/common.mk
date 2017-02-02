AR     := ar
CC     := g++ 
CFLAGS := -std=c++11 -g -Wall -Werror -fPIC -Wno-sign-compare -DHAVE_PTHREAD

ifeq ($(VERBOSE),1)
$(warning *** verbose mode ***)
V      :=
else
V      := @
endif
