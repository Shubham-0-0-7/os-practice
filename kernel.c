#include "keyboard.h"
#include "terminal.h"
#include "idt.h"
#include "pic.h"

void main(){
    terminal_initialize();
    terminal_writestring("initializing prismaOS\n");
    terminal_writestring("made with <3 by neocipher27 !!\n");

    idt_init();
    pic_remap();
    init_keyboard();
    
    __asm__ volatile("sti");
    terminal_writestring("type something below!! \n");
}
