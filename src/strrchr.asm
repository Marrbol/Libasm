bits 64

section .text
    global strrchr

strrchr:
    xor rax, rax ;ca met rax a 0.

loop:
    mov bl, BYTE[rdi]
    cmp bl, 0
    je check_end
    cmp bl, sil
    je make_pointer
    inc rdi
    jmp loop

make_pointer:
    mov rax, rdi
    inc rdi
    jmp loop

check_end:
    cmp sil, 0
    jne return
    mov rax, rdi

return:
    ret