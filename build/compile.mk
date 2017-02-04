include $(DAJO_BUILD)/common.mk

$(shell mkdir -p $(DAJO_OUT)/$(NAME))

$(DAJO_OUT)/$(NAME)/%.o: src/%.cc
	@echo " C++   $@"
	$(V) $(CC) $(CFLAGS) $(addsuffix /api,$(addprefix -I$(DAJO_ROOT)/,$(INCLUDES))) -o $@ -c $<
	$(V) $(CC) $(CFLAGS) $(addsuffix /api,$(addprefix -I$(DAJO_ROOT)/,$(INCLUDES))) -MM -MT $@ $< -MF $(subst .o,.d,$@)

$(DAJO_OUT)/$(NAME)/%.o: src/%.cpp
	@echo " C++   $@"
	$(V) $(CC) $(CFLAGS) $(addsuffix /api,$(addprefix -I$(DAJO_ROOT)/,$(INCLUDES))) -o $@ -c $<
	$(V) $(CC) $(CFLAGS) $(addsuffix /api,$(addprefix -I$(DAJO_ROOT)/,$(INCLUDES))) -MM -MT $@ $< -MF $(subst .o,.d,$@)

$(DAJO_OUT)/$(NAME)/%.o: src/%.c
	@echo " C++   $@"
	$(V) $(CC) $(CFLAGS) $(addsuffix /api,$(addprefix -I$(DAJO_ROOT)/,$(INCLUDES))) -o $@ -c $<
	$(V) $(CC) $(CFLAGS) $(addsuffix /api,$(addprefix -I$(DAJO_ROOT)/,$(INCLUDES))) -MM -MT $@ $< -MF $(subst .o,.d,$@)

