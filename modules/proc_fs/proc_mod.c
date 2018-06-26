#include <linux/init.h>
#include <linux/module.h>
#include<linux/sched.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/proc_fs.h>

int len, temp;

char *msg;

struct proc_dir_entry *proc_file;

ssize_t procfile_read(struct file *filp, char *buf, size_t count, loff_t *offp)
{
	if(count>temp)
	{
		count=temp;
	}
	temp=temp-count;
	copy_to_user(buf, msg, count);
	if(count==0)
		temp=len;
	return count;
}

struct file_operations myproc_fops = {
	.read = procfile_read	
};

int init_module()
{
	int ret = 0;
	proc_file = proc_create("test", 0, NULL, &myproc_fops);

	printk(KERN_INFO "Trying to create /proc/test:\n");

	if (proc_file == NULL) {
    	ret = -ENOMEM;
    	remove_proc_entry("test", NULL);
    	printk(KERN_INFO "Error: Could not initialize /proc/test\n");
  	} else {
    	printk(KERN_INFO "Success!\n");
  	}

  	msg = "Hello, world!";
  	len = strlen(msg);
  	temp=len;
  	printk(KERN_INFO "1. len = %d", len);

  	return ret;
}

void cleanup_module()
{
	remove_proc_entry("test", NULL);
	printk(KERN_INFO "/proc/test removed\n");
}

MODULE_LICENSE("GPL");