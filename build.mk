
all:
	@echo " CD   trace"
	@make -s -C trace -f build.mk all
	@echo " CD   alsa"
	@make -s -C alsa  -f build.mk all
	@echo " CD   sharedmem"
	@make -s -C sharedmem  -f build.mk all
	@echo " CD   main"
	@make -s -C main  -f build.mk all


test:
	@echo " CD   test_alsa"
	@make -s -C test_alsa -f build.mk all

clean:
	@rm -rf out
