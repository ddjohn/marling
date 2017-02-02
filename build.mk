include $(DAJO_BUILD)/common.mk

.PHONY: all
all:
	@echo " CD   trace"
	$(V) make -s -C trace -f build.mk all
	@echo " CD   alsa"
	$(V) make -s -C alsa  -f build.mk all
	@echo " CD   sharedmem"
	$(V) make -s -C sharedmem  -f build.mk all
	@echo " CD   main"
	$(V) make -s -C main  -f build.mk all

.PHONY: test
test:
	@echo " CD   test_alsa"
	$(V) make -s -C test_alsa -f build.mk all
	@echo " CD   test_sharedmem"
	$(V) make -s -C test_sharedmem -f build.mk all

.PHONY: external
external:
	@echo " CD   zeromq"
	$(V) make -s -C external/zeromq/src -f build.mk all
	@echo " CD   protobuf"
	$(V) make -s -C external/protobuf/src -f build.mk all

.PHONY: clean
clean:
	@echo " RM   out (recursive)"
	$(V) rm -rf out
