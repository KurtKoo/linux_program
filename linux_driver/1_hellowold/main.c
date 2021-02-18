#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

//"printf" function is achieved by the "glibc" in the user mode
//a kernel module cannot use the "glibc" so print something with the "printk"
//the "printk" function requires a printing mode and you can check the modes in the current system by "cat /proc/sys/kernel/printk"
//the command above shows modes for 4 purpose and if user hopes to print something in the terminal the printing mode in the function should be lower than the first out of 4.
//in the often case the 4 numbers are 4 4 1 7

//printing mode
/*
	#define KERN_EMERG   "<0>" information before the system aborts
	#define KERN_ALERT   "<1>" information that need to be dealt with right away
	#define KERN_CRIT    "<2>" information that is critical
	#define KERN_ERR     "<3>" information about error
	#define KERN_WARNING "<4>" information about warning
	#define KERN_NOTICE  "<5>" information that should be noticed
	#define KERN_INFO    "<6>" regular information
	#define KERN_DEBUG   "<7>" DEBUG information

*/


static int __init hello_init()
{
	printk(KERN_EMERG "[ KERN_EMERG ] Hello World Module Init\n"); //will print
	printk("[ default ] Hello World\n");     //not print
	return 0;
}

static void __exit hello_exit()
{
	printk("[ default ] goodbye\n");
}

module_init(hello_init);  //use "sudo insmod module_name" to run this module
module_exit(hello_exit);  //use "sudo rmmod module_name" to exit this module

MODULE_LICENSE("GPL2");
MODULE_AUTHOR("rookie");
MODULE_DESCRIPTION("just a test");
MODULE_ALIAS("test_module");
