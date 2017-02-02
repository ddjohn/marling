CC = g++ 
CFLAGS = -std=c++11 -g -Wall -Werror

$(DAJO_OUT)/$(NAME)/%.o: %.cc
	@echo " C++   $@"
	$(CC) $(CFLAGS) $(addprefix -I,$(INCLUDES)) -o $@ -c $<

