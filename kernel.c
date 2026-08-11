#include "keyboard.h"
#include "terminal.h"
#include "idt.h"
#include "pic.h"
#include "timer.h"

void main(){
    terminal_initialize();
    terminal_writestring("initializing prismaOS\n");
    terminal_writestring("made with <3 by neocipher27...\n");

    idt_init();
    pic_remap();
    init_keyboard();
    init_timer(100);
    
    __asm__ volatile("sti");
    terminal_writestring("waiting 3 secs...");
    sleep_ms(3000);
    terminal_writestring("3 seconds done! ... timer works\n");
    terminal_writestring("type something below... \n");
}
