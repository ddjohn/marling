include $(DAJO_BUILD)/compile.mk

SOURCES=$(wildcard *.cc)
OBJECTS=$(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cc,.o,$(SOURCES)))

#$(warning "sources="$(SOURCES))
#$(warning "objects="$(OBJECTS))

#$(shell echo MKDIR $(DAJO_OUT)/$(NAME))
$(shell mkdir -p $(DAJO_OUT)/$(NAME))

all: $(OBJECTS) 
	@echo " LIB  $(DAJO_OUT)/$(NAME)/$(NAME).a"
	@ar r $(DAJO_OUT)/$(NAME)/$(NAME).a $(OBJECTS)
