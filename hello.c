/******************************************************************************
 * Command line argument passing to a kernel module.  
 *****************************************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h> 

MODULE_LICENSE("GPL");

static int Major;
char *buff;

buff = kzalloc(2.097.152, GFP_ATOMIC);
if (!buff) {
	printk(KERN_IFNO "Buffer not allocated.");
}

// Obtaining device number to work with.
int register_chrdev_region(dev_t first, unsigned int count,
			   char *name);

int hello_init(void)
{
	Major = register_chrdev(0, chardev, &fops);
	if (Major < 0) {
		printk("Registering the character device failed with %d\n", Major);
		return Major;
	}

	printk(KERN_INFO "Chardev kernel module has loaded!\n");
	return 0;
}

void hello_exit(void)
{
	printk(KERN_INFO "Chardev kernel module is removed!\n");
	void unregister_chrdev_region(dev_t first, unsigned int count);
	kfree(buff);
}	

module_init(hello_init);
module_exit(hello_exit);
