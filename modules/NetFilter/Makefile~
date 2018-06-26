MY_VAR = net_filter

obj-m +=  $(MY_VAR).o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
load: all
	sudo insmod $(MY_VAR).ko
	sudo dmesg
unload:
	sudo rmmod $(MY_VAR)
	sudo dmesg
