cmd_/home/aleksei/modules/Hello_world/hello_world.ko := ld -r -m elf_x86_64 -z max-page-size=0x200000 -T ./scripts/module-common.lds --build-id  -o /home/aleksei/modules/Hello_world/hello_world.ko /home/aleksei/modules/Hello_world/hello_world.o /home/aleksei/modules/Hello_world/hello_world.mod.o ;  true
