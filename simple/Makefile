CC   := x86_64-linux-gnu-gcc-13                     # Compiler to use
KDIR := /lib/modules/$(shell uname -r)/build        # Kernel build directory
PWD  := $(shell pwd)                                # Current working directory

obj-m := simple.o


all:
	$(MAKE) -C $(KDIR) M=$(PWD) CC=$(CC) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
