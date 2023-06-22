bits 64

section .text
    global strcmp

strcmp:
    xor rax, rax ;ca met rax a 0.

loop:
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
    jmp loop

return:
    movzx rax, bl
	movzx rbx, cl
	sub rax, rbx
	ret