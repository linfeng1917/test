# A trivial bus driver Makefile. Saved as “Makefile” exactly  
ifneq ($(KERNELRELEASE),)  
	obj-m := ycbus.o  
else  
	KERNDIR ?= /lib/modules/$(shell uname -r)/build  
	PWD := $(shell pwd)  
default:  
	$(MAKE) -C ${KERNDIR} M=${PWD} modules  
endif  
clean:  
	rm -rf modules.order Module.symvers .tmp_versions ycbus.ko .ycbus.ko.cmd ycbus.mod.c ycbus.mod.o .ycbus.mod.o.cmd ycbus.o .ycbus.o.cmd  
