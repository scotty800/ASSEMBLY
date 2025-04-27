bits 64

;constant 
SYS_WRITE : equ 1
STDOUT: equ 1
SYS_EXIT: equ 60

section .data
    message: db "Hello, World!", 10
    MESSAGE_EQUALS_LEN: equ $-message

section .text
    global _start
    _start:

            mov rax, SYS_WRITE
            mov rdi, STDOUT
            mov rsi, message
            mov rdx, MESSAGE_EQUALS_LEN
            syscall

            ;Quitter le programme
            mov rax, SYS_EXIT
            mov rdi, 0
            syscall
            