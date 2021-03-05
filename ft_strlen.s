section .text
    global _ft_strlen

_ft_strlen:
    mov rax, 0
    jmp loop

loop:
    cmp BYTE [rdi + rax], 0
    ue  return
    inc rax
    jmp loop

return:
    ret
