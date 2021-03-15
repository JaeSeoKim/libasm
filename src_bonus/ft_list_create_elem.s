section .text
  global  _ft_list_create_elem
  extern  _malloc
; t_list	*ft_create_elem(void *data)
; data == rdi
_ft_list_create_elem:
  push  rdi
  mov   rdi, 16
  call  _malloc
  pop   rdi
  mov   [rax], rdi
  mov   QWORD [rax+8], 0x0
  ret
