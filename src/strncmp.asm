bits 64

section .text
    global strncmp

strncmp:
    xor rax, rax ;ca met rax a 0.
    cmp rdx, 0
    je return_error

loop:
    cmp rax, rdx
    je return
    mov bl, BYTE[rdi]
    mov cl, BYTE[rsi]
    cmp bl, 0
    je return
    cmp cl, 0
    je return
    cmp bl, cl
    jne return
    inc rdi
    inc rsi
    inc rax
    jmp loop


return:
	sub bl, cl
    movsx rax, bl

return_error:
    ret