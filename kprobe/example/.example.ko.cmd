cmd_/github/kernel_module/kprobe/example/example.ko := ld -r  -m elf_x86_64  --build-id=sha1  -T scripts/module.lds -o /github/kernel_module/kprobe/example/example.ko /github/kernel_module/kprobe/example/example.o /github/kernel_module/kprobe/example/example.mod.o;  true
