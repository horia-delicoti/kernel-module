/******************************************************************************
 * Functions that print messages when the kernel module is loaded.  
 *****************************************************************************/

#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");

int hello_init(void)
{
	printk(KERN_ALERT "HelloWorld kernel module has loaded!\n");
	return 0;
}

void hello_exit(void)
{
	printk(KERN_ALERT "HelloWorld kernel module is removed!\n");
}

module_init(hello_init);
module_exit(hello_exit);
