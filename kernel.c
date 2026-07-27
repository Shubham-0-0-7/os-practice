#include "terminal.h"
#include "idt.h"

void main(){
    terminal_initialize();
    terminal_writestring("hellow world from C kernel!\n");
    terminal_writestring("this is written using our new VGA terminal driver\n");

    terminal_writestring("Initializing IDT...\n");
    idt_init();
    terminal_writestring("testing interrupt exception 3 (breakpoint):\n");
    __asm__ volatile ("int $3");
    terminal_writestring("testing interrupt exception 0 (Divide By Zero):\n");
    __asm__ volatile ("int $0");
}
