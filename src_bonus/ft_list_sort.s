section .text
  global  _ft_list_sort
; void	ft_list_sort(t_list **begin_list, int (*cmp)());
; begin_list == rdi, cmp == rsi
_ft_list_sort:
init:
  push  rbx         ; cmp
  mov   rbx, rsi
  push  r8          ; curr_a
  mov   r8, [rdi]
  push  r9          ; curr_b
loop_i:
  mov   r9, [r8+8]  ; curr_b = curr_a->next
  cmp   r9, 0       ; while (curr_a->next)
  je    end
loop_j:
  cmp   r9, 0       ; while (curr_b)
  je    loop_i_end
  push  rdi
  mov   rdi, [r8]   ; rdi = curr_a->data
  push  rsi
  mov   rsi, [r9]   ; rsi = curr_b->data
  push  r8
  push  r9
  call  rbx       ; rax = cmp (curr_a->data, curr_b->data)
  cmp   rax, 0
  pop   r9
  pop   r8
  jle   else
swap:
  mov   rsi, [r8]   ; curr_b->data = curr_a->data
  mov   rdi, [r9]   ; curr_a->data = curr_b->data
  mov   [r8], rdi
  mov   [r9], rsi
else:
  pop   rsi
  pop   rdi
  mov   r9, [r9+8]  ; curr_b = curr_b->next
  jmp   loop_j
loop_i_end:
  mov   r8, [r8+8]  ; curr_a = curr_a->next
  cmp   r8, 0
  je    end
  jmp   loop_i

end:
  pop   r9
  pop   r8
  pop   rbx
  xor   rax, rax
  ret
