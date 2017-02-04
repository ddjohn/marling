include $(DAJO_BUILD)/common.mk
#-include $(OBJECTS:.o=.d)

$(shell mkdir -p $(DAJO_OUT)/$(NAME))

OBJECTS := $(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cc,.o,$(wildcard src/*.cc)))
OBJECTS += $(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cpp,.o,$(wildcard src/*.cpp)))

OBJECTS := $(subst /src/,/,$(OBJECTS))

include $(DAJO_BUILD)/compile.mk

all: $(DAJO_OUT)/lib$(NAME).a

$(DAJO_OUT)/lib$(NAME).a: $(OBJECTS) 
	@echo " LIB  $(DAJO_OUT)/lib$(NAME).a"
	$(V) $(AR) ru $(DAJO_OUT)/lib$(NAME).a $(OBJECTS)
	@echo " LIB  $(DAJO_OUT)/lib$(NAME).so"
	$(V) $(CC) -shared -o $(DAJO_OUT)/lib$(NAME).o $(OBJECTS)

clean:
	@echo "  RM  $(OBJECTS)"
	$(V) rm -f $(OBJECTS)
	@echo "  RM  $(DAJO_OUT)/$(NAME).a"
	$(V) rm -f $(DAJO_OUT)/$(NAME).a
