#include "isr.h"
#include "terminal.h"

isr_t interrupt_handlers[256];

void register_interrupt_handler(uint8_t n, isr_t handler){
    interrupt_handlers[n]=handler;
}

static const char* exception_messages[] = {
    "0: Division By Zero",
    "1: Debug",
    "2: Non Maskable Interrupt",
    "3: Breakpoint",
    "4: Into Detected Overflow",
    "5: Out of Bounds",
    "6: Invalid Opcode",
    "7: No Coprocessor",
    "8: Double Fault",
    "9: Coprocessor Segment Overrun",
    "10: Bad TSS",
    "11: Segment Not Present",
    "12: Stack Fault",
    "13: General Protection Fault",
    "14: Page Fault",
    "15: Unknown Interrupt",
    "16: Coprocessor Fault",
    "17: Alignment Check",
    "18: Machine Check",
    "19: SIMD Floating-Point Exception",
    "20: Virtualization Exception",
    "21: Control Protection Exception",
    "22: Reserved",
    "23: Reserved",
    "24: Reserved",
    "25: Reserved",
    "26: Reserved",
    "27: Reserved",
    "28: Hypervisor Injection Exception",
    "29: VMM Communication Exception",
    "30: Security Exception",
    "31: Reserved"
};
void isr_handler(registers_t regs){
    terminal_writestring("RECEIVED INTERRUPT EXCEPTION: ");
    if(regs.int_no<32){
        terminal_writestring(exception_messages[regs.int_no]);
    }else{
        terminal_writestring("Unknown Exception");
    }
    terminal_writestring("\n");
}

