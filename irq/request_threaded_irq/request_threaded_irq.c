#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int irq=16;

static irqreturn_t irq_handler(int data,void *dev_id)
{
	printk("the data is :%d \n",data);
	printk("in the interrupt handler function \n");
	return IRQ_WAKE_THREAD;
}

static irqreturn_t irq_thread_fn(int data, void *dev_id)
{
	printk("the data is :%d \n",data);
	printk("in the interrupt thread function\n");
	return IRQ_HANDLED;
}

static int __init request_threaded_irq_init(void)
{
	int result=0;
	printk("into request_threaded_irq_init\n");

	result=request_threaded_irq(irq,irq_handler,irq_thread_fn,0,"A_New_Device",NULL);
	printk("the result of the request_threaded_irq is :%d\n",result);
	disable_irq(irq);
	enable_irq(irq);
	printk("out request_threaded_irq_init\n");
	return 0;
}

static void __exit request_threaded_irq_exit(void)
{
	free_irq(irq,NULL);
	printk("Goodbye request_threaded_irq\n");
	return;
}
module_init(request_threaded_irq_init);
module_exit(request_threaded_irq_exit);

