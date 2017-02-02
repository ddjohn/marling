include $(DAJO_BUILD)/common.mk

#$(shell echo MKDIR $(DAJO_OUT)/$(NAME))
$(shell mkdir -p $(DAJO_OUT)/$(NAME))

$(DAJO_OUT)/$(NAME)/%.o: %.cc
	@echo " C++   $@"
	@$(CC) $(CFLAGS) $(addprefix -I,$(INCLUDES)) -o $@ -c $<
	@$(CC) -MM $(CFLAGS) $(addprefix -I,$(INCLUDES)) -c $< > $(subst .o,.d,$@)

