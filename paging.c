#include "paging.h"
#include "terminal.h"
#include "string.h"

static uint32_t* page_directory=0;
static uint32_t* first_page_table=0;

void page_fault_handler(registers_t regs){
    uint32_t faulting_address;
    __asm__ volatile ("mov %%cr2, %0" : "=r" (faulting_address));
    int present = !(regs.err_code & 0x1);
    int rw = regs.err_code & 0x2;
    int us = regs.err_code & 0x4;
    int reserved = regs.err_code & 0x8;

    terminal_writestring("\n---[ KERNEL PAGE FAULT ]---\n");
    terminal_writestring("faulting address: 0x");
    char buf[32];
    itoa(faulting_address, buf, 16);

}