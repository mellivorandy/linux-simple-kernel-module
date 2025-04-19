/*
 * Modified from an example in:
 * Operating System Concepts by Silberschatz, Galvin, and Gagne
 * 
 * Original copyright © Abraham Silberschatz, Peter Baer Galvin, and Greg Gagne.
 * This modified version is provided under the GPL v2 for educational purposes.
 *
 * Modified by: Andy Yo
 * Date: 2025-04-19
 *
 * Description:
 * A simple Linux kernel module that creates a /proc/hello entry.
 * When read, it returns a "Hello World" message.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

#define BUFFER_SIZE 128
#define PROC_NAME "hello"

int proc_init(void);
void proc_exit(void);
ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);

static const struct proc_ops proc_ops = {
    .proc_read = proc_read,
};

/* This function is called when the module is loaded. */
int proc_init(void)
{
    /* creates the /proc/hello entry */
    proc_create(PROC_NAME, 0666, NULL, &proc_ops);
    
    return 0;
}

/* This function is called when the module is removed. */
void proc_exit(void)
{
    /* removes the /proc/hello entry */
    remove_proc_entry(PROC_NAME, NULL);
}
 
/* This function is called each time /proc/hello is read */
ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
    int rv = 0;
    char buffer[BUFFER_SIZE];
    static int completed = 0;

    if (completed) {
        completed = 0;
        return 0;
    }

    completed = 1;

    rv = sprintf(buffer, "Hello World\n");

    if (copy_to_user(usr_buf, buffer, rv)) {
        return -EFAULT;
    }

    return rv;
}
    
module_init(proc_init);
module_exit(proc_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello Module");
MODULE_AUTHOR("Andy Yo (modified from SGG example)");
