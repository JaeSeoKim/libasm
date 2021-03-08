# Libasm

[![jaeskim's 42 Libasm Score](https://badge42.herokuapp.com/api/project/jaeskim/libasm)](https://github.com/JaeSeoKim/badge42)

> The aim of this project is to get familiar with assembly language.
> ## 📝 PDF
>
> - [**`FILE LINK`**](https://github.com/JaeSeoKim/42cursus/blob/master/pdf/en.subject-Libasm.pdf)

## 🚀 Content

- You must write 64 bits ASM. Beware of the "calling convention".
- You can’t do inline ASM, you must do ’.s’ files.
- You must compile your assembly code with nasm.
- You must use the Intel syntax, not the AT&T.

### 🚩 Mandatory part

The library must be called libasm.a.

You must submit a main that will test your functions and that will compile with your library to show that it’s functional.

You must rewrite the following functions in asm:

- ft_strlen (man 3 strlen)
- ft_strcpy (man 3 strcpy)
- ft_strcmp (man 3 strcmp)
- ft_write (man 2 write)
- ft_read (man 2 read)
- ft_strdup (man 3 strdup, you can call to malloc)

You must check for errors during syscalls and properly set them when needed

Your code must set the variable errno properly.

For that, you are allowed to call the extern ___error.

### 🚩 Bonus part

You can rewrite these functions in asm. The linked list function will use the following
structure:
 
```c
typedef sturct      s_list
{
    void            *data;
    struct s_list   *next;
}                   t_list;
```

- ft_atoi_base (like the one in the piscine)
- ft_list_push_front (like the one in the piscine)
- ft_list_size (like the one in the piscine)
- ft_list_sort (like the one in the piscine)
- ft_list_remove_if (like the one in the piscine)
