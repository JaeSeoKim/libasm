section .text
    global  _ft_read
    extern  ___error
; size_t   write(int fd, const void *buf, size_t nbyte);
; fd == rdi, buf == rsi, nbyte == rdx
_ft_read:
    mov     rax, 0x02000003
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
