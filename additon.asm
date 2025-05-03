bits 64

; constantes 
SYS_WRITE: equ 1
STDOUT: equ 1
SYS_EXIT: equ 60
BUFFER_SIZE: equ 1

section .data
    newline db 10

section .bss
    result resb BUFFER_SIZE

section .text
    global _start
    _start:
        ; initialliser les 2 valeur
        mov rax, 5
        mov rbx, 3

        ; Additionner
        add rax, rbx

        ;convertir en ASCII
        add rax, '0'
        mov [result], rax

        ; Afficher
        mov rax, SYS_WRITE
        mov rdi, STDOUT
        mov rsi, result
        mov rdx, 1
        syscall
        
        ; Nouvelle ligne
        mov rax, SYS_WRITE
        mov rdi, STDOUT
        mov rsi, newline
        mov rdx, 1
        syscall

        ; Exit
        mov rax, SYS_EXIT
        mov rdi, 0
        syscall
