cmd_/github/kernel_module/kprobe/example/modules.order := {   echo /github/kernel_module/kprobe/example/example.ko; :; } | awk '!x[$$0]++' - > /github/kernel_module/kprobe/example/modules.order
