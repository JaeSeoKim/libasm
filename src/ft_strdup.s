section .text
  global  _ft_strdup
  extern  _ft_strlen
  extern  _ft_strcpy
  extern  _malloc
; char	*strdup(const char *s1);
; s1 == rdi
_ft_strdup:
  push  rdi
  call  _ft_strlen
  inc   rax
  mov   rdi, rax
  call  _malloc
  mov   rdi, rax
  pop   rsi
  call  _ft_strcpy
  ret
