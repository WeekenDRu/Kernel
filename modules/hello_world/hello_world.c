#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int my_init(void)
{
	printk(KERN_ALERT "Hello, world!\n");

	return 0;
}

static void my_exit(void)
{
	printk(KERN_ALERT "Goodbye, world.");
}

module_init(my_init);
module_exit(my_exit);