AR     := ar
CC     := g++ 
CFLAGS := -std=c++11 -g -Wall -Werror -fPIC

ifeq ($(VERBOSE),1)
$(warning *** verbose mode ***)
V      :=
else
V      := @
endif
