include $(DAJO_BUILD)/compile.mk

SOURCES=$(wildcard *.cc)
OBJECTS=$(DAJO_OUT)/$(NAME)/$(subst .cc,.o,$(SOURCES))

all: $(OBJECTS) | mkdir
	@echo " LIB  $(DAJO_OUT)/$(NAME)/$(NAME).a"
	@ar r $(DAJO_OUT)/$(NAME)/$(NAME).a $(OBJECTS)

mkdir:
	@echo "MKDIR $(DAJO_OUT)/$(NAME)" 
	@mkdir -p $(DAJO_OUT)/$(NAME)
