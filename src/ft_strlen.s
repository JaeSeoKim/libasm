section .text
    global  _ft_strlen
; size_t    ft_strlen(char *s);
; s == rdi
_ft_strlen:
    xor rax, rax

loop:
    cmp BYTE [rdi + rax], 0
    je  return
    inc rax
    jmp loop

return:
    ret
