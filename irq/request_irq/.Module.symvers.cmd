cmd_/github/kernel_module/irq/request_irq/Module.symvers := sed 's/\.ko$$/\.o/' /github/kernel_module/irq/request_irq/modules.order | scripts/mod/modpost -m -a  -o /github/kernel_module/irq/request_irq/Module.symvers -e -i Module.symvers   -T -