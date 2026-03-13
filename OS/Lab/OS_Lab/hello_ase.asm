section .data
    prompt db "Enter your name: "
    prompt_len equ $ - prompt
    greet db "Hello, "
    greet_len equ $ - greet

section .bss
    buffer resb 64        ; Reserve 64 bytes for user input

section .text
    global _start

_start:
    ; 1. Print the prompt
    mov rax, 1            ; sys_write
    mov rdi, 1            ; stdout
    mov rsi, prompt
    mov rdx, prompt_len
    syscall

    ; 2. Read user input
    mov rax, 0            ; sys_read
    mov rdi, 0            ; stdin (keyboard)
    mov rsi, buffer       ; Address to store input
    mov rdx, 64           ; Max bytes to read
    syscall               ; The number of bytes read is now in RAX
    
    push rax              ; Save the number of bytes read for later

    ; 3. Print the greeting "Hello, "
    mov rax, 1            ; sys_write
    mov rdi, 1            ; stdout
    mov rsi, greet
    mov rdx, greet_len
    syscall

    ; 4. Print the user's input back
    mov rax, 1            ; sys_write
    mov rdi, 1            ; stdout
    mov rsi, buffer
    pop rdx               ; Retrieve the number of bytes read (from step 2)
    syscall

    ; 5. Exit
    mov rax, 60           ; sys_exit
    xor rdi, rdi
    syscall

