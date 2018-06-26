MY_VAR = proc_wr.o 
MY_VAR2 = proc_wr.ko

obj-m +=  $(MY_VAR)  

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
load: all
	sudo insmod $(MY_VAR2)
	sudo dmesg
unload:
	sudo rmmod $(MY_VAR2)
	sudo dmesg