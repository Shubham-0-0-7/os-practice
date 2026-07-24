#include "terminal.h"

void main(){
    terminal_initialize();
    terminal_writestring("hellow world from C kernel!\n");
    terminal_writestring("this is written using our new VGA terminal driver");
}
