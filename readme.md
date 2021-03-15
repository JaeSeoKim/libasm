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
    > size_t	ft_strlen(const char *s);
- ft_strcpy (man 3 strcpy)
    > char	*ft_strcpy(char *dst, const char *src);
- ft_strcmp (man 3 strcmp)
    > int		ft_strcmp(const char *s1, const char *s2);
- ft_write (man 2 write)
    > ssize_t	ft_write(int fd, const char *buf, size_t count);
- ft_read (man 2 read)
    > ssize_t	ft_read(int fd, const char *buf, size_t count);
- ft_strdup (man 3 strdup, you can call to malloc)
    > char	*ft_strdup(const char *s1);

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
    > int ft_atoi_base(char *str, char *base);
    > - Write a function that converts the initial portion of the string pointed by str to int
    > representation.
    > - str is in a specific base given as a second parameter.
    > - excepted the base rule, the function should work exactly like ft_atoi.
    > - If there’s an invalid argument, the function should return 0. Examples of invalid
    > - arguments :
    >   - base is empty or size of 1;
    >   - base contains the same character twice ;
    >   - base contains + or - or whitespaces;

- ft_list_push_front (like the one in the piscine)
    > void ft_list_push_front(t_list **begin_list, void *data);
    > - Create the function ft_list_push_front which adds a new element of type t_list to the beginning of the list.
    > - It should assign data to the given argument.
    > - If necessary, it’ll update the pointer at the beginning of the list.
    > - Here’s how it should be prototyped
- ft_list_size (like the one in the piscine)
- ft_list_sort (like the one in the piscine)
- ft_list_remove_if (like the one in the piscine)
