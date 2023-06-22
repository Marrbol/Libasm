bits 64

section .text
    global memmove

memmove:
    xor rcx, rcx ;ca met rcx a 0.
    xor rax, rax ;ca met rax a 0.

loop:
    cmp rcx, rdx ; compare si rcx est a la size donné en param
    je return ; dans ce cas on return
    mov bl, BYTE[rsi + rcx] ;sinon on move le char du 2nd arg le "str[i]" dans un registre temp
    mov BYTE[rdi + rcx], bl ; on move ce registre tmp dans au même endroit mais dans rdi
    inc rcx; a force j'ai compris on inc rcx
    jmp loop ; on refais tous

return:
    mov rax, rdi ; rax c la valeur de retour et on me rdi (le ptr sur la string) dans rax
    ret
