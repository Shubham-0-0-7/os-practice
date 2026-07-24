CC = i686-elf-gcc
LD = i686-elf-ld
CFLAGS = -ffreestanding -c
all: os-image.bin
run: os-image.bin
	qemu-system-x86_64 -fda os-image.bin

os-image.bin: main.bin kernel.bin
	cat main.bin kernel.bin > os-image.bin
	truncate -s 1474560 os-image.bin

main.bin: main.asm print.asm print-hex.asm disk.asm gdt-32bit.asm switch.asm print-32bit.asm
	nasm -f bin main.asm -o main.bin

kernel_entry.o: kernel_entry.asm
	nasm -f elf32 $< -o $@

kernel.o: kernel.c
	$(CC) $(CFLAGS) $< -o $@

kernel.bin: kernel_entry.o kernel.o terminal.o
	$(LD) -o $@ -Ttext 0x1000 $^ --oformat binary

terminal.o: terminal.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.bin *.o os-image.bin
