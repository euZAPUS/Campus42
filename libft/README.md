# Libft - Málaga_42

El proyecto **Libft** es el primero del curso de 42. El objetivo es entender cómo funcionan las funciones estándar de C reescribiéndolas desde cero, además de crear funciones de utilidad para manipular strings, memoria y listas enlazadas.

## Funciones:

### 1. Funciones de la Libc
Reescritura de funciones estándar:
* `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
* `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
* `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
* `ft_toupper`, `ft_tolower`, `ft_atoi`, `ft_calloc`, `ft_strdup`

### 2. Funciones Adicionales
Herramientas extra para manejo de strings y file descriptors.
* `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`
* `ft_strmapi`, `ft_striteri`
* `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 3. Bonus (Listas Enlazadas)
Estructura de datos dinámica.
* `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`
* `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Compilación y Uso

La librería incluye un `Makefile`. Para compilarla, simplemente clona el repositorio y ejecuta:

make
