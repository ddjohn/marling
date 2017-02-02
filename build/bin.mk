include $(DAJO_BUILD)/compile.mk

$(shell mkdir -p $(DAJO_OUT)/$(NAME))

SOURCES=$(wildcard *.cc)
OBJECTS=$(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cc,.o,$(SOURCES)))

-include $(OBJECTS:.o=.d)

all: $(DAJO_OUT)/$(NAME).bin
ifeq ($(RUN),1)
	$(DAJO_OUT)/$(NAME).bin
endif

$(DAJO_OUT)/$(NAME).bin: $(OBJECTS)
	@echo " BIN  $(DAJO_OUT)/$(NAME).bin"
	$(V) $(CC) -o $(DAJO_OUT)/$(NAME).bin $(OBJECTS) -L$(DAJO_OUT) -Wl,-Bstatic $(addprefix -l,$(STATIC_LIBS)) -Wl,-Bdynamic $(addprefix -l,$(SHARED_LIBS))

clean:
	@echo " RM $(OBJECTS)"
	$(V) rm -f $(OBJECTS)
	@echo " RM $(DAJO_OUT)/$(NAME).bin"
	$(V) rm -f $(DAJO_OUT)/$(NAME).bin
