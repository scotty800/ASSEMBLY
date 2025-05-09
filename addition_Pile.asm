bits 64

;Constant
SYS_WRITE: equ 1
STDOUT: equ 1
SYS_EXIT: equ 60
BUFFER_SIZE: equ 2

section .data
    newline db 10

section .bss 
    result resb BUFFER_SIZE

section .text
    global _start
    _start:
        ; Empiler deux valuers
        mov rax, 4
        push rax
        mov rax, 6
        push rax

        ; Dépiler dans rbx et rcx 
        pop rbx
        pop rcx

        ; additionner
        add rbx, rcx

        ; Diviser pour obtenir les chiffres ASCII
        mov rax, rbx
        xor rdx, rdx
        mov rcx, 10
        div rcx 

        ; Convertir en ASCII
        add al, '0'
        add dl, '0'

       ; Stocker
       mov [result], al
       mov [result + 1], dl

        ; Afficher
        mov rax, SYS_WRITE
        mov rdi, STDOUT
        mov rsi, result
        mov rdx, 2
        syscall

        ; Ligne saut
        mov rax, SYS_WRITE
        mov rdi, STDOUT
        mov rsi, newline
        mov rdx, 1
        syscall

        ; Exit
        mov rax, SYS_EXIT
        mov rdi, rdi
        syscall