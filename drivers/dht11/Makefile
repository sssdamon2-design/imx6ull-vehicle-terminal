obj-m += vehicle_dht11.o

KDIR := /home/book/100ask_imx6ull-sdk/Buildroot_2020.02.x/output/build/linux-origin_master
MODULE_DIR := $(shell pwd)

ARCH := arm
CROSS_COMPILE := /home/book/100ask_imx6ull-sdk/Buildroot_2020.02.x/output/host/bin/arm-buildroot-linux-gnueabihf-

all:
	$(MAKE) -C $(KDIR) M=$(MODULE_DIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	$(MAKE) -C $(KDIR) M=$(MODULE_DIR) clean
