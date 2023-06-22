bits 64

section .text
    global strchr

strchr:
    xor rcx, rcx ;ca met rcx a 0.
    xor rax, rax ;ca met rax a 0.

loop:
    mov bl, BYTE[rdi + rcx] ; je met le char dans le registre bl
    cmp bl, sil ; il compare le char a sil (sil est le registre 8 bit du 2 nd arg soit le char qui veut)
        je save_ptr ; si c'est le cas, il save le ptr
    cmp bl, 0; je compare le char a 0 pour voir si on est a la fin de la string
        je check_end; si c le cas, il end
    inc rcx ; il increment rcx du et ca va passer au char suivant quand on va revenir a la ligne 11
    jmp loop; il refait loop

save_ptr:
    add rdi, rcx ; tu décale le prt rdi de rcx soit si rcx vaut 5 tu décale le ptr de 5 soit str +=5 en c
    mov rax, rdi ; tu met rdi dans rax, rax est ce que tu vas return

check_end:
    cmp sil, 0 ; on compare si sil est = a 0, sil est le char 8 bits du 2nd arg
    jne return ; si ce n'est pas un \0, on return jmp a return
    mov rax, rdi ;"sinon" on met rdi dans rax

return:
    ret ; et on return