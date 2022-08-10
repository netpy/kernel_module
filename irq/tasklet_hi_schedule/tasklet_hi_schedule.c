#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
static unsigned long data=0;
static struct tasklet_struct tasklet,tasklet1;

// 自定义的软中断处理函数，只有打印输出的功能
static void irq_tasklet_action(unsigned long data)
{
	// 显示当前软中断的状态
	printk("in irq_tasklet_action the state of the tasklet is: %ld\n",(&tasklet)->state);
	printk("tasklet running. by author\n");
	return;
}

// 自定义软中断处理函数，在此只有显示的作用
static void irq_tasklet_action1(unsigned long data)
{
	// 显示当前软中断的状态
	printk("in irq_tasklet_action1 the state of the tasklet1 is:%ld \n",(&tasklet1)->state);
	printk("tasklet1 running. by author\n");
	return ;
}

static int __init __tasklet_hi_schedule_init(void)
{
	printk("into __tasklet_hi_schedule\n");

	// 申请两个软中断
	tasklet_init(&tasklet,irq_tasklet_action,data);
	tasklet_init(&tasklet1, irq_tasklet_action1, data);
	// 显示当前中断状态
	printk("The state of the tasklet is:%ld \n",(&tasklet)->state);
	printk("The state of the tasklet1 is:%ld \n",(&tasklet1)->state);

	tasklet_schedule(&tasklet);   // 把中断送入普通中断队列
	//if(!test_and_set_bit(TASKLET_STATE_SCHED, &tasklet1.state))
	//	__tasklet_hi_schedule(&tasklet1);
	 tasklet_schedule(&tasklet1);
	tasklet_kill(&tasklet);
	tasklet_kill(&tasklet1);
	printk("out __tasklet_hi_schedule\n");
	return 0;
}

static void __exit __tasklet_hi_schedule_exit(void)
{
	printk("Goodbye __tasklet_hi_schedule\n");
	return;
}

module_init(__tasklet_hi_schedule_init);
module_exit(__tasklet_hi_schedule_exit);

