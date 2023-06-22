bits 64

section .text
    global memset
memset:
    xor rcx, rcx ;ca met rcx a 0.
    xor rax, rax ;ca met rax a 0.

loop:
    cmp rcx, rdx ;je compare rcx avec rdx (rdx est le 3 eme arg soit le nombre de byte a set)
    je return ;si c vrai alors j'arrete
    mov BYTE[rdi + rcx], sil ; je met sil (le 8 bits du 2nd arg soit le char donné en arg, dans rdi (la main string) apres après avoir décaler le ptr avec rcx)
    inc rcx ; j'increment rcx
    jmp loop ; je jump a loop, cad je recommence

return:
    mov rax, rdi ; je met rdi soit la string dans rax, la valeur de return
    ret ; return rax
