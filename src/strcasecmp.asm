bits 64

section .text
    global strcasecmp

strcasecmp:
    xor rcx, rcx

loop:
    mov al, BYTE[rdi + rcx]
    sub al, BYTE[rsi + rcx]
    cmp al, 32
    je check
    cmp al, -32
    je check
    cmp al, 0
    jne return

check:
    cmp BYTE[rdi + rcx], 0
    je return
    cmp BYTE[rsi + rcx], 0
    je return
    inc rcx
    jmp loop

return:
    movsx rax, al
    ret