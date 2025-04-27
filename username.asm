bits 64

;Constant
SYS_WRITE: equ 1
SYS_READ: equ 0
STDOUT: equ 1
STDIN: equ 0
SYS_EXIT: equ 60

section .data 
    message: db 'Quel est ton nom : ',
    MESSAGE_EQUALS_LEN: equ $-message
    MAX_LEN_USER: equ 11

section .bss
    username: resb MAX_LEN_USER
section .text
    global _start
    _start:
            ; Affiche la question
            mov rax, SYS_WRITE
            mov rdi, STDOUT
            mov rsi, message
            mov rdx, MESSAGE_EQUALS_LEN
            syscall

            ; Ecrit la reponse
            mov rax, SYS_READ
            mov rdi, STDIN
            mov rsi, username
            mov rdx, MAX_LEN_USER
            syscall

            ; Afficher la réponse
            mov rax, SYS_WRITE
            mov rdi, STDOUT
            mov rsi, username
            mov rdx, MAX_LEN_USER
            syscall

            ;Quitte le progamme
            mov rax, SYS_EXIT
            mov rdi, 0
            syscall
