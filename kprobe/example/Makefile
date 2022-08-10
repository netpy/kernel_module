#ifneq($(KERNELRELEASE),)
#mymoudle-objs:= __tasklet_hi_schedule.o
obj-m += example.o

#else
PWD:=$(shell pwd)
KVER:=$(shell uname -r)
KDIR:=/lib/modules/$(KVER)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	#rm -rf *.o *.mod.c *.ko *.symvers *.order *.markers *~
	make -C $(KDIR) M=$(PWD) clean
#endif
