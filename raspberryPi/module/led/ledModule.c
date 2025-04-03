// sudo apt install raspberrypi-kernel-headers

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <asm/uaccess.h>
#include <asm/io.h>

#define HIGH 1
#define LOW 0

int led[4] = {23, 24, 25, 1};

static int led_module_init(void)
{
    int ret, i;
    printk(KERN_INFO "led module init!\n");
    for (i = 0; i < 4; ++i)
    {
        ret = gpio_request(led[i], "LED");
        if (ret < 0)
        {
            printk(KERN_INFO "led module gpio request failed.");
        }
    }
    for (i = 0; i < 4; ++i)
    {
        ret = gpio_free(led[i], HIGH);
    }
    return 0;
}

static void led_module_exit(void)
{
    printk(KERN_INFO "module_exit!\n");
}

module_init(led_module_init);
module_exit(led_module_exit);
MODULE_LICENSE("GPL");