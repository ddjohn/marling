include $(DAJO_BUILD)/compile.mk

SOURCES=$(wildcard *.cc)
OBJECTS=$(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cc,.o,$(SOURCES)))

-include $(OBJECTS:.o=.d)

#$(shell echo MKDIR $(DAJO_OUT)/$(NAME))
$(shell mkdir -p $(DAJO_OUT)/$(NAME))

all: $(DAJO_OUT)/$(NAME).bin

$(DAJO_OUT)/$(NAME).bin: $(OBJECTS)
	@echo " BIN  $(DAJO_OUT)/$(NAME).bin"
	@$(CC) -o $(DAJO_OUT)/$(NAME).bin $(OBJECTS) -L$(DAJO_OUT) -Wl,-Bstatic $(addprefix -l,$(LIBS)) -Wl,-Bdynamic -lasound

