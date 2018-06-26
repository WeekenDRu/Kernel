#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/proc_fs.h>

#define MAX_SIZE 10

int len, temp;

char *msg;

struct proc_dir_entry *proc_file;

ssize_t procfile_write(struct file *filp, const char *buf, size_t count, loff_t *offp)
{	
	
	strncpy_from_user(msg, buf, MAX_SIZE);
	printk(KERN_INFO "In write");
	if(count>MAX_SIZE){
	len = MAX_SIZE;
	temp = MAX_SIZE;
	msg[MAX_SIZE]='\0';
	}
	
	else{
		len = count;
		temp = len;
		msg[count] = '\0';}
	return count;
}

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
	read: procfile_read,
	write: procfile_write
};

int init_module(void)
{
	int ret = 0;
	proc_file = proc_create("test", 0666, NULL, &myproc_fops);
	printk(KERN_INFO "Trying to create /proc/test:\n");

	if (proc_file == NULL) {
    	ret = -ENOMEM;
    	remove_proc_entry("test", NULL);
   		printk(KERN_INFO "Error: Could not initialize /proc/test\n");
  	} else {
    	printk(KERN_INFO "Success!\n");
  	}
  	msg=kmalloc(MAX_SIZE*sizeof(char), GFP_KERNEL);
  	return ret;
}

void cleanup_module(void)
{
	remove_proc_entry("test", NULL);
	printk(KERN_INFO "/proc/test removed\n");
}

MODULE_LICENSE("GPL");