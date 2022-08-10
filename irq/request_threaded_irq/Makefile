#obj-m += tasklet_hi_schedule.o
obj-m += request_threaded_irq.o
#else
#PWD:=$(shell pwd)
#KVER:=$(shell uname -r)
#KDIR:=/lib/modules/$(KVER)/build
PWD:=$(shell pwd)
KVER:=$(shell uname -r)
KDIR:=/lib/modules/$(KVER)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
