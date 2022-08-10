#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int irq=11; //16

// 自定义中断处理函数
static irqreturn_t irq_handler(int data,void *dev_id)
{
	printk("the data is :%dd \n",data);
	printk("in the interrupte handler function\n");
	return IRQ_HANDLED;
}

static int __init request_irq_init(void)
{
	int result=0;
	printk("into request_irq_init\n");

	result=request_irq(irq,irq_handler,IRQF_NOBALANCING,"A_New_Device",NULL);
	printk("the result of the request_irq is: %d\n",result);
	printk("out request_irq_init\n");
	return 0;
}

static void __exit request_irq_exit(void)
{
	free_irq(irq,NULL);
	printk("Goodbye request_irq\n");
	return;
}

module_init(request_irq_init);
module_exit(request_irq_exit);
