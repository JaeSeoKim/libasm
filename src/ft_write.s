section .text
    global  _ft_write
    extern  ___error
; size_t   write(int fd, const void *buf, size_t count);
; fd == rdi, buf == rsi, count == rdx
_ft_write:
    mov     rax, 0x02000004
    syscall
    jc      err
    ret

err:
    push    rax
    call    ___error
    pop     rdx
    mov     [rax], rdx
    mov     rax, -1
    ret
