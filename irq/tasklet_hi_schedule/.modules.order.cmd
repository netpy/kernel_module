cmd_/github/kernel_module/irq/modules.order := {   echo /github/kernel_module/irq/tasklet_hi_schedule.ko; :; } | awk '!x[$$0]++' - > /github/kernel_module/irq/modules.order
