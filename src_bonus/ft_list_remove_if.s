section .text
  global  _ft_list_remove_if
  extern  _free
; void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
; (*cmp)(list_ptr->data, data_ref);
; (*free_fct)(list_ptr->data);
; rdi = begin_list
; rsi = data_ref
; rdx = cmp
; rcx = free_fct
_ft_list_remove_if:
  push  r8
  mov   r8, [rdi]     ; r8 = *begin_list
  jmp   loop

set_begin_list:
  push  rdi
  push  r8
  mov   rdi, [r8]      ; (*begin_list)->data
  call  rcx            ; free_cnt(list->data);
  pop   r8
  pop   rdi
  mov   rax, [r8+8]    ; *begin_list = (*begin_list)->next
  mov   [rdi], rax
  push  rdi
  push  r8
  mov   rdi, r8
  call  _free           ; free(list)
  pop   r8
  pop   rdi
  mov   r8, [rdi]     ; curr = *begin_list

loop:
  cmp   r8, 0         ; while (*begin_list)
  je    end
  push  rdi
  mov   rdi, [r8]     ; rdi = list->data
  push  r8
  push  rcx
  push  rsi
  call  rdx           ; cret = cmp((*begin_list)->data, data_ref);
  pop   rsi
  pop   rcx
  pop   r8
  pop   rdi
  cmp   rax, 0
  je    set_begin_list  ; if (!ret)
  mov   rdi, r8         ; rdi == prev
  jmp   curr_loop

set_curr:
  mov   rax, [r8+8]     ; curr->next
  mov   [rdi+8], rax    ; prev->next = curr->next
  push  rdi
  push  rdx
  push  r8
  mov   rdi, [r8]       ; free_cnt(curr->data);
  call  rcx
  pop   r8
  mov   rdi, r8
  call  _free           ; free(curr);
  pop   rdx
  pop   rdi
  mov   r8, [rdi+8]     ; curr = prev->next

curr_loop:
  cmp   r8, 0
  je    end
  push  rdi
  mov   rdi, [r8]
  push  rsi
  push  r8
  push  rcx
  call  rdx
  pop   rcx
  pop   r8
  pop   rsi
  pop   rdi
  cmp   rax, 0
  je    set_curr
  mov   rdi, r8
  mov   rax, [r8+8]
  mov   r8, rax
  jmp   curr_loop

end:
  pop   r8
  xor   rax, rax
  ret
