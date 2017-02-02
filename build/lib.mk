include $(DAJO_BUILD)/common.mk
include $(DAJO_BUILD)/compile.mk

$(shell mkdir -p $(DAJO_OUT)/$(NAME))

SOURCES=$(wildcard *.cc)
OBJECTS=$(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cc,.o,$(SOURCES)))

-include $(OBJECTS:.o=.d)

all: $(DAJO_OUT)/$(NAME).a

$(DAJO_OUT)/$(NAME).a: $(OBJECTS) 
	@echo " LIB  $(DAJO_OUT)/$(NAME).a"
	$(V) ar r $(DAJO_OUT)/$(NAME).a $(OBJECTS)

clean:
	@echo "  RM  $(OBJECTS)"
	$(V) rm -f $(OBJECTS)
	@echo "  RM  $(DAJO_OUT)/$(NAME).a"
	$(V) rm -f $(DAJO_OUT)/$(NAME).a
