bits 64

section .text
    global strlen

strlen:
    xor rax, rax ;ca met rax a 0.

loop:
    cmp BYTE[rdi + rax], 0 ; compare rdi (soit le 1er arg) a 0 pour voir si c la fin, le "+ rax" correspond au str++
    je return ; si la comparaison fut, on jean ma a return
    inc rax ;on INCremente rax
    jmp loop ; on jump sur loop ce qui correspond a de la recursivité

return:
    ret ; on return un truc il return rax a chaque fois
