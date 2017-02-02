CC     := g++ 
CFLAGS := -std=c++11 -g -Wall -Werror

ifeq ($(VERBOSE),1)
V      :=
else
V      := @
endif
