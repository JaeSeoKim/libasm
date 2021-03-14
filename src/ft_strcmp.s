section .text
    global  _ft_strcmp
; int   strcmp(const char *s1, const char *s2);
; s1 == rdi, s2 == rsi
_ft_strcmp:
    push    rcx;
    xor     rcx, rcx;

loop:
    cmp     BYTE[rdi+rcx], 0
    je      end
    cmp     BYTE[rsi+rcx], 0
    je      end
    mov     al, BYTE[rdi+rcx]
    cmp     al, BYTE[rsi+rcx]
    je      end

end:
    sub     al, BYTE[rsi+rcx]
    pop     rcx
    ret
