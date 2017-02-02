include $(DAJO_BUILD)/compile.mk

SOURCES=$(wildcard *.cc)
OBJECTS=$(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cc,.o,$(SOURCES)))

#$(shell echo MKDIR $(DAJO_OUT)/$(NAME))
$(shell mkdir -p $(DAJO_OUT)/$(NAME))

-include $(OBJECTS:.o=.d)

all: $(DAJO_OUT)/$(NAME).a

$(DAJO_OUT)/$(NAME).a: $(OBJECTS) 
	@echo " LIB  $(DAJO_OUT)/$(NAME).a"
	@ar r $(DAJO_OUT)/$(NAME).a $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f $(DAJO_OUT)/$(NAME).a
