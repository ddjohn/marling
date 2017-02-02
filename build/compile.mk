CC = g++ 
CFLAGS = -std=c++11 -g -Wall -Werror

#$(shell echo MKDIR $(DAJO_OUT)/$(NAME))
$(shell mkdir -p $(DAJO_OUT)/$(NAME))

$(DAJO_OUT)/$(NAME)/%.o: %.cc
	@echo " C++   $@"
	@$(CC) $(CFLAGS) $(addprefix -I,$(INCLUDES)) -o $@ -c $<

