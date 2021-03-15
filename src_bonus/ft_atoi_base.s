section .text
  global  _ft_atoi_base
  extern  _ft_strlen
; int		ft_atoi_base(char *str, char *base);
; str == rdi, base == rsi
_ft_atoi_base:

check_base_len:
  push  rdi
  mov   rdi, rsi
  call   _ft_strlen       ; rax = ft_strlen(base)
  cmp   rax, 2            ; if (rax < 2) return (error());
  pop   rdi
  jb    error             ; if (rax < 2) return (error());

check_base_dup:
  push  rcx;
  xor   rcx, rcx          ; rcx == i
check_base_dup_loop_i:
  cmp   BYTE[rsi+rcx], 0  ; while (base[i])
  je    check_base_dup_loop_i_end
  mov   rax, rcx          ; rax == j, j = i
  inc   rax               ; j++
check_white_space:
  cmp   BYTE[rsi+rcx], 9   ; *str == '\t'
  je    skip_str_white_space_inc
  cmp   BYTE[rsi+rcx], 10   ; *str == '\n'
  je    skip_str_white_space_inc
  cmp   BYTE[rsi+rcx], 11   ; *str == '\v'
  je    skip_str_white_space_inc
  cmp   BYTE[rsi+rcx], 12   ; *str == '\f'
  je    skip_str_white_space_inc
  cmp   BYTE[rsi+rcx], 13   ; *str == '\r'
  je    error_dup_loop
  cmp   BYTE[rsi+rcx], ' '   ; base[i] == ' '
  je    error_dup_loop
  cmp   BYTE[rsi+rcx], '+'   ; base[i] == '+'
  je    error_dup_loop
  cmp   BYTE[rsi+rcx], '-'   ; base[i] == '-'
  je    error_dup_loop
check_base_dup_loop_j:
  cmp   BYTE[rsi+rax], 0  ; while (base[j])
  je    check_base_dup_loop_j_end
  push  rax
  mov   al, BYTE[rsi+rax]
  cmp   al, BYTE[rsi+rcx] ; base[i] == base[j]
  pop   rax
  je    error_dup_loop
  inc   rax               ; j++
  jmp   check_base_dup_loop_j
check_base_dup_loop_j_end:
  inc   rcx               ; i++
  jmp   check_base_dup_loop_i
check_base_dup_loop_i_end:
  jmp    skip_str_white_space
skip_str_white_space_inc:
  inc   rdi;
skip_str_white_space:
  cmp   BYTE[rdi], 9   ; *str == '\t'
  je    skip_str_white_space_inc
  cmp   BYTE[rdi], 10   ; *str == '\n'
  je    skip_str_white_space_inc
  cmp   BYTE[rdi], 11   ; *str == '\v'
  je    skip_str_white_space_inc
  cmp   BYTE[rdi], 12   ; *str == '\f'
  je    skip_str_white_space_inc
  cmp   BYTE[rdi], 13   ; *str == '\r'
  je    skip_str_white_space_inc
  cmp   BYTE[rdi], ' '   ; *str == ' '
  je    skip_str_white_space_inc
check_flag:
  push  r8
  xor   r8, r8    ; r8 == flag
  jmp   check_flag_loop
is_minus:
  xor   r8b, 0x00000001
is_plus:
  inc   rdi
check_flag_loop:
  cmp   BYTE[rdi], '-'
  je    is_minus
  cmp   BYTE[rdi], '+'
  je    is_plus
  xor   rax, rax
  jmp   atoi_loop
atoi_loop:
  push  r9          ; r9 == str_base_index
  mov   r9, rcx
check_is_vaild_str:
  dec   r9
  cmp   r9, -1
  je    atoi_end
  push  rax
  mov   al, BYTE[rdi]
  mov   r15b, BYTE[rsi+r9]
  cmp   al, BYTE[rsi+r9]
  pop   rax
  je    atoi
  jmp   check_is_vaild_str
atoi:
  imul  rax, rcx    ; num *= base
  add   rax, r9     ; num += str_base_index
  pop   r9
  inc   rdi
  jmp   atoi_loop

atoi_end:
  pop   r9
  cmp   r8, 0
  pop   r8
  pop   rcx
  jne    mul_minus
  ret

mul_minus:
  imul  rax, -1
  ret

error_dup_loop:
  pop   rcx
error:
  mov   rax, 0
  ret