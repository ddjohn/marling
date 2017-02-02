include $(DAJO_BUILD)/common.mk

$(shell mkdir -p $(DAJO_OUT)/$(NAME))

$(DAJO_OUT)/$(NAME)/%.o: %.cc
	@echo " C++   $@"
	$(V) $(CC) $(CFLAGS) $(addprefix -I,$(INCLUDES)) -o $@ -c $<
	$(V) $(CC) $(CFLAGS) $(addprefix -I,$(INCLUDES)) -MM -MT $@ $< -MF $(subst .o,.d,$@)

$(DAJO_OUT)/$(NAME)/%.o: %.cpp
	@echo " C++   $@"
	$(V) $(CC) $(CFLAGS) $(addprefix -I,$(INCLUDES)) -o $@ -c $<
	$(V) $(CC) $(CFLAGS) $(addprefix -I,$(INCLUDES)) -MM -MT $@ $< -MF $(subst .o,.d,$@)

