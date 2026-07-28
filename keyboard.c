#include "keyboard.h"
#include "ports.h"
#include "isr.h"
#include "terminal.h"

static const char scancode_ascii[] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};

static void keyboard_callback(registers_t regs){
    uint8_t scancode = inb(0x60);
    if(scancode < sizeof(scancode_ascii)){
        char letter = scancode_ascii[scancode];
        if(letter != 0) terminal_putchar(letter);
    }
}

void init_keyboard(void){
    register_interrupt_handler(33, keyboard_callback);
}