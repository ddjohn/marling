include $(DAJO_BUILD)/common.mk
include $(DAJO_BUILD)/compile.mk

$(shell mkdir -p $(DAJO_OUT)/$(NAME))

OBJECTS := $(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cc,.o,$(wildcard *.cc)))
OBJECTS += $(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cpp,.o,$(wildcard *.cpp)))

-include $(OBJECTS:.o=.d)

all: $(DAJO_OUT)/$(NAME).a

$(DAJO_OUT)/$(NAME).a: $(OBJECTS) 
	@echo " LIB  $(DAJO_OUT)/$(NAME).a"
	$(V) $(AR) ru $(DAJO_OUT)/$(NAME).a $(OBJECTS)
	@echo " LIB  $(DAJO_OUT)/$(NAME).so"
	$(V) $(CC) -sh$(AR)ed -o $(DAJO_OUT)/$(NAME).o $(OBJECTS)

clean:
	@echo "  RM  $(OBJECTS)"
	$(V) rm -f $(OBJECTS)
	@echo "  RM  $(DAJO_OUT)/$(NAME).a"
	$(V) rm -f $(DAJO_OUT)/$(NAME).a
