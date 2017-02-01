CC = g++ 
CFLAGS = -std=c++11 -g -Wall -Werror

$(DAJO_OUT)/$(NAME)/%.o: %.cc
	$(CC) $(CFLAGS) -o $@ -c $<

