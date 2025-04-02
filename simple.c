/*
 * Based on an example from:
 * Operating System Concepts by Silberschatz, Galvin, and Gagne
 * 
 * Original copyright © Abraham Silberschatz, Peter Baer Galvin, and Greg Gagne.
 * This modified version is provided under the GPL v2 for educational purposes.
 *
 * Modified by: Andy Yo
 * Date: 2025-04-02
 *
 * Description:
 * This is a modified version of the original simple Linux kernel module
 * demonstrating basic load and unload mechanisms.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int simple_init(void);
void simple_exit(void);

/* This function is called when the module is loaded. */
int simple_init(void)
{
    printk(KERN_INFO "Loading Kernel Module\n");
    
    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void)
{
    printk(KERN_INFO "Removing Kernel Module\n");
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
