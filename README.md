# libasm
The aim of this project is to recode some C functions in assembly.

### Requirements:
- You must rewrite the following functions in asm:
  - ft_strlen (man 3 strlen)
  - ft_strcpy (man 3 strcpy)
  - ft_strcmp (man 3 strcmp)
  - ft_write (man 2 write)
  - ft_read (man 2 read)
  - ft_strdup (man 3 strdup, you can call to `malloc`)
- You must check for errors during syscalls and properly set them when needed.
- Your functions must set the variable errno properly (for that you can use the extern ___error).
