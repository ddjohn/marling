#include <linux/init.h>
#include <linux/module.h>
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("David Johansson ddjohn@gmail.com");
MODULE_DESCRIPTION("Test Driver");

static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
static int myintArray[2] = { -1, -1 };
static int arr_argc = 0;

/*
/sys/module/habba/parameters/myint
*/
module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");

module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");

module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");

module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integers");

static int data __initdata = 42;

static int habba_init(void) {
	printk(KERN_INFO "Hello world %d\n", data);
                       //return  -1;
                       return  0;
}
 
static void habba_exit(void) {
	printk(KERN_INFO "Goodbye world 1.\n");
                       return;
}
 
module_init(habba_init);
module_exit(habba_exit);


/*  
 *  This module uses /dev/testdevice.  The MODULE_SUPPORTED_DEVICE macro might
 *  be used in the future to help automatic configuration of modules, but is 
 *  currently unused other than for documentation purposes.
 */
MODULE_SUPPORTED_DEVICE("testdevice");
