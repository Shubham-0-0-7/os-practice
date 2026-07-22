[org 0x7c00]
mov ah, 0x0e

mov bp, 0x8000
mov sp, bp

push "A"
push "B"
push "C"

pop bx
mov al, bl
int 0x10

pop bx
mov al, bl
int 0x10

pop bx
mov al, bl
int 0x10

mov al, [0x8000]
int 0x10

mov bx, hello
call print

call print_nl

mov al, " "
int 0x10

mov al, "7"
int 0x10
mov al, [the_secret]
int 0x10

jmp $

%include "print.asm"

hello:
    db "hellow world", 0
bye_bye:
    db "goodbye", 0 

the_secret:
    db "X"

times 510-($-$$) db 0
dw 0xaa55
