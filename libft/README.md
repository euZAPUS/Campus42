*This project has been created as part of the 42 curriculum by alsanch3.*

# Libft

## Description

Libft is the first project of the 42 curriculum. Its goal is to understand how the standard C library works by rewriting a selection of its functions from scratch, and to build additional utility functions for handling strings, memory, file descriptors and linked lists.

The result is a static library, `libft.a`, that can be reused in later 42 projects.

## Instructions

### Requirements

- A C compiler (`cc`) and `make`.
- The code is compiled with the flags `-Wall -Wextra -Werror`.

### Compilation

Clone the repository and run `make` at its root:

```bash
git clone <repository-url> libft
cd libft
make
```

This creates the static library `libft.a`.

### Makefile rules

| Rule          | Effect                                                   |
|---------------|----------------------------------------------------------|
| `make`        | Compiles the library and creates `libft.a`.              |
| `make bonus`  | Adds the linked list (bonus) functions to `libft.a`.     |
| `make clean`  | Removes the object files (`.o`).                         |
| `make fclean` | Removes the object files and `libft.a`.                  |
| `make re`     | Runs `fclean` and then compiles everything again.        |

### Using the library

Include the header in your code:

```c
#include "libft.h"
```

Then link the library when compiling:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

## Library description

### 1. Libc functions

Re-implementations of standard C library functions, with the same behaviour as the originals.

**Character checks and conversions**

| Function      | Description                                              |
|---------------|----------------------------------------------------------|
| `ft_isalpha`  | Checks if a character is a letter.                       |
| `ft_isdigit`  | Checks if a character is a digit (0 to 9).               |
| `ft_isalnum`  | Checks if a character is a letter or a digit.            |
| `ft_isascii`  | Checks if a value is in the ASCII table (0 to 127).      |
| `ft_isprint`  | Checks if a character is printable (including space).    |
| `ft_toupper`  | Converts a lowercase letter to uppercase.                |
| `ft_tolower`  | Converts an uppercase letter to lowercase.               |

**Strings**

| Function      | Description                                                         |
|---------------|---------------------------------------------------------------------|
| `ft_strlen`   | Returns the length of a string.                                     |
| `ft_strlcpy`  | Copies a string into a buffer of a given size, always null-terminated. |
| `ft_strlcat`  | Appends a string to another within a given buffer size.             |
| `ft_strchr`   | Finds the first occurrence of a character in a string.              |
| `ft_strrchr`  | Finds the last occurrence of a character in a string.               |
| `ft_strncmp`  | Compares up to `n` characters of two strings.                       |
| `ft_strnstr`  | Finds a substring inside the first `len` characters of a string.    |
| `ft_atoi`     | Converts a string to an `int`.                                      |
| `ft_strdup`   | Returns a newly allocated copy of a string.                         |

**Memory**

| Function      | Description                                                         |
|---------------|---------------------------------------------------------------------|
| `ft_memset`   | Fills a block of memory with a given byte.                          |
| `ft_bzero`    | Sets a block of memory to zero.                                     |
| `ft_memcpy`   | Copies `n` bytes from one memory area to another (no overlap).      |
| `ft_memmove`  | Copies `n` bytes between memory areas, handling overlap safely.     |
| `ft_memchr`   | Finds the first occurrence of a byte in a memory area.              |
| `ft_memcmp`   | Compares two memory areas byte by byte.                             |
| `ft_calloc`   | Allocates memory for an array and sets it to zero.                  |

### 2. Additional functions

Functions that are not in the standard library (or differ from it), useful for strings and file descriptors.

| Function        | Description                                                              |
|-----------------|--------------------------------------------------------------------------|
| `ft_substr`     | Returns a new string with a part of the given string.                    |
| `ft_strjoin`    | Returns a new string that joins two strings.                             |
| `ft_strtrim`    | Returns a copy of a string with the given characters removed from both ends. |
| `ft_split`      | Splits a string into an array of strings, using a delimiter character.   |
| `ft_itoa`       | Converts an `int` to a newly allocated string.                           |
| `ft_strmapi`    | Applies a function to each character and returns a new string.           |
| `ft_striteri`   | Applies a function to each character of a string, modifying it in place. |
| `ft_putchar_fd` | Writes a character to a file descriptor.                                 |
| `ft_putstr_fd`  | Writes a string to a file descriptor.                                    |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor.              |
| `ft_putnbr_fd`  | Writes an integer to a file descriptor.                                  |

### 3. Bonus: linked lists

Functions to create and manage a simple linked list, using this structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function          | Description                                                            |
|-------------------|------------------------------------------------------------------------|
| `ft_lstnew`       | Creates a new list node with the given content.                        |
| `ft_lstadd_front` | Adds a node at the beginning of a list.                                |
| `ft_lstsize`      | Counts the number of nodes in a list.                                  |
| `ft_lstlast`      | Returns the last node of a list.                                       |
| `ft_lstadd_back`  | Adds a node at the end of a list.                                      |
| `ft_lstdelone`    | Frees one node's content with a given function, then frees the node.   |
| `ft_lstclear`     | Deletes and frees every node of a list.                                |
| `ft_lstiter`      | Applies a function to the content of every node.                       |
| `ft_lstmap`       | Creates a new list by applying a function to every node's content.     |

## Resources

### References

- Linux manual pages: `man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`, `man 3 calloc`, etc. ([man7.org](https://man7.org/linux/man-pages/))
- [cppreference: C standard library](https://en.cppreference.com/w/c)
- *The C Programming Language*, Brian W. Kernighan and Dennis M. Ritchie.
- [GNU Make manual](https://www.gnu.org/software/make/manual/)
- [Linked list (Wikipedia)](https://en.wikipedia.org/wiki/Linked_list)

### Use of AI

AI (Claude) was used as a learning aid:

- To explain concepts I did not understand yet, such as pointers, memory allocation and memory overlap in `ft_memmove`.
- To help write and translate this README into English.

AI was **not** used to write the code of the library functions. All functions were written by me.
