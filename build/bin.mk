include $(DAJO_BUILD)/common.mk
include $(DAJO_BUILD)/compile.mk

$(shell mkdir -p $(DAJO_OUT)/$(NAME))

OBJECTS := $(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cc,.o,$(wildcard src/*.cc)))
OBJECTS += $(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cpp,.o,$(wildcard src/*.cpp)))

OBJECTS := $(subst /src/,/,$(OBJECTS))

-include $(OBJECTS:.o=.d)

all: $(DAJO_OUT)/$(NAME).bin
ifeq ($(RUN),1)
	@date >> ${DAJO_ROOT}/unittest.log
	@echo " RUN $(DAJO_OUT)/$(NAME).bin"
	@$(DAJO_OUT)/$(NAME).bin >> ${DAJO_ROOT}/unittest.log 2>&1 && echo ok || echo nok
endif

$(DAJO_OUT)/$(NAME).bin: $(OBJECTS)
	@echo " BIN  $(DAJO_OUT)/$(NAME).bin"
	$(V) $(CC) -o $(DAJO_OUT)/$(NAME).bin $(OBJECTS) -L$(DAJO_OUT) -Wl,-Bstatic $(addprefix -l,$(STATIC_LIBS)) -Wl,-Bdynamic $(addprefix -l,$(SHARED_LIBS))

clean:
	@echo " RM $(OBJECTS)"
	$(V) rm -f $(OBJECTS)
	@echo " RM $(DAJO_OUT)/$(NAME).bin"
	$(V) rm -f $(DAJO_OUT)/$(NAME).bin
