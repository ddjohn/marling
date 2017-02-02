include $(DAJO_BUILD)/common.mk

$(shell mkdir -p $(DAJO_OUT)/$(NAME))

$(DAJO_OUT)/$(NAME)/%.o: %.cc
	@echo " C++   $@"
	$(V) $(CC) $(CFLAGS) $(addprefix -I,$(INCLUDES)) -o $@ -c $<
	$(V) $(CC) -MM $(CFLAGS) $(addprefix -I,$(INCLUDES)) $< > $(subst .o,.d,$@)

