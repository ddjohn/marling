include $(DAJO_BUILD)/common.mk

all:
	@echo " CD   trace"
	$(V) make -s -C trace -f build.mk all
	@echo " CD   alsa"
	$(V) make -s -C alsa  -f build.mk all
	@echo " CD   sharedmem"
	$(V) make -s -C sharedmem  -f build.mk all
	@echo " CD   main"
	$(V) make -s -C main  -f build.mk all


test:
	@echo " CD   test_alsa"
	$(V) make -s -C test_alsa -f build.mk all
	@echo " CD   test_sharedmem"
	$(V) make -s -C test_sharedmem -f build.mk all

clean:
	@echo " RM   out (recursive)"
	$(V) rm -rf out
