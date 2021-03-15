section .text
  global  _ft_list_size
; int		ft_list_size(t_list *begin_list);
; begin_list == rdi
_ft_list_size:
init:
  push	rbp
  mov		rbp, rsp

  xor   rax, rax
loop:
  cmp   rdi, 0
  je    return
  mov   rdi, [rdi+8]
  inc   rax
  jmp   loop

return:
  leave
  ret
