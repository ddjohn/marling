include $(DAJO_BUILD)/common.mk

.PHONY: all
all: external framework
	@echo " CD   main"
	$(V) make -s -C main  -f build.mk all

.PHONY: framework
framework:
	@echo " CD   framework/trace"
	$(V) make -s -C framework/trace -f build.mk all
	@echo " CD   framework/alsa"
	$(V) make -s -C framework/alsa  -f build.mk all
	@echo " CD   framework/sharedmem"
	$(V) make -s -C framework/sharedmem  -f build.mk all

.PHONY: test
test: external framework
	@echo " CD   test/test_alsa"
	$(V) make -s -C test/test_alsa -f build.mk all
	@echo " CD   test/test_sharedmem"
	$(V) make -s -C test/test_sharedmem -f build.mk all

.PHONY: external
external:
	@echo " CD   external/zeromq"
	$(V) make -s -C external/zeromq -f build.mk all
	@echo " CD   external/protobuf"
	$(V) make -s -C external/protobuf -f build.mk all
	@echo " CD   external/sodium"
	$(V) make -s -C external/sodium -f build.mk all

.PHONY: clean
clean:
	@echo " RM   out (recursive)"
	$(V) rm -rf out
