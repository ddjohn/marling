//#include <linux/module.h>
//#include <linux/kernel.h>

#include <linux/init.h>
#include <linux/module.h>
 
static int habba_init(void) {
	printk(KERN_INFO "Hello world 1.\n");
                       return  0;
}
 
static void habba_exit(void) {
	printk(KERN_INFO "Goodbye world 1.\n");
                       return;
}
 
module_init(habba_init);
module_exit(habba_exit);
