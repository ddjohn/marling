include $(DAJO_BUILD)/compile.mk

SOURCES=$(wildcard *.cc)
OBJECTS=$(addprefix $(DAJO_OUT)/$(NAME)/,$(subst .cc,.o,$(SOURCES)))

#$(warning "sources="$(SOURCES))
#$(warning "objects="$(OBJECTS))

#$(shell echo MKDIR $(DAJO_OUT)/$(NAME))
$(shell mkdir -p $(DAJO_OUT)/$(NAME))

all: $(DAJO_OUT)/$(NAME)/$(NAME) 

$(DAJO_OUT)/$(NAME)/$(NAME): $(OBJECTS)
	@echo " BIN  $(DAJO_OUT)/$(NAME)/$(NAME)"
	g++ -o $(DAJO_OUT)/$(NAME)/$(NAME) $(OBJECTS) -L$(DAJO_OUT) -Wl,-Bstatic $(addprefix -l,$(LIBS)) -Wl,-Bdynamic -lasound

