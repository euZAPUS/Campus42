*This project has been created as part of the 42 curriculum by alsanch3.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library function `printf()`.
The goal of the project is to learn how **variadic functions** work in C (functions
that accept a variable number of arguments) and to write code that is well structured
and easy to extend.

The result is a static library, `libftprintf.a`, that provides:

```c
int	ft_printf(char const *format, ...);
```

It prints `format` to the standard output, replacing each conversion with the next
argument, and returns the number of characters printed, just like the original.

Supported conversions:

| Conversion | Prints |
|------------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is `NULL`) |
| `%p` | a pointer address in hexadecimal, prefixed with `0x` (`(nil)` if `NULL`) |
| `%d` | a signed decimal integer |
| `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned hexadecimal integer, lowercase |
| `%X` | an unsigned hexadecimal integer, uppercase |
| `%%` | a percent sign |

Unlike the original `printf`, there is no output buffer: every character is written
directly with `write()`.

## Instructions

### Compilation

```sh
make        # builds libftprintf.a
make clean  # removes the object files
make fclean # removes the object files and the library
make re     # rebuilds everything from scratch
```

The sources are compiled with `cc -Wall -Wextra -Werror`, and the library is created
with `ar`. The Makefile does not relink: running `make` twice does nothing the second time.

### Usage

Include the header and link the library:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s, you are %d years old (%x in hex)\n", "42", 21, 21);
	return (0);
}
```

```sh
cc main.c -L. -lftprintf -o main
./main
```

## Algorithm and data structure

**Main loop.** `ft_printf` walks through `format` one character at a time with an
index. Ordinary characters are written as they are and counted. When it finds a `%`,
it reads the next character (the conversion letter), handles it, and moves the index
two positions forward. A `%` at the very end of the string is skipped, so the loop
never reads past the terminating `'\0'`.

**Reading the arguments.** The extra arguments are read with `va_start`, `va_arg` and
`va_end` from `<stdarg.h>`. Each `va_arg` call returns the next argument and advances,
so the arguments are consumed in the same order as the conversions appear in `format`.
The conversion letter tells which type to read (`int`, `unsigned int`, `char *` or
`void *`). `char` arguments are promoted to `int`, so `%c` is read as an `int`.
The `va_list` is passed to the helper function by pointer, so the position in the
argument list is kept between calls.

**Dispatcher.** `ft_conversion` receives the conversion letter and calls one small
function per type. Each of these functions prints its argument and returns the number
of characters it printed, which `ft_printf` adds to its total. Adding a new conversion
only needs one new line in the dispatcher and, if needed, one new function. This is
why this structure was chosen: it is short, easy to read and easy to extend.

**Printing numbers.** Numbers are printed with a recursive function: it first prints
`n / base` (all the digits except the last one) and then the last digit, `n % base`.
Decimal numbers use base 10. Hexadecimal numbers use base 16, and the digit is taken
from a "dictionary" string (`"0123456789abcdef"` or `"0123456789ABCDEF"`), so the same
function works for `%x`, `%X` and `%p`. Numbers are handled as `long` or
`unsigned long`, so `INT_MIN` can be made positive without overflowing and
pointers fit in full.

**Counting.** The number of characters printed is computed by counting how many times
the number can be divided by its base (plus one for the `-` sign of negative numbers).

No dynamic memory is used, so there is nothing to free and no possible leaks.

**Files.**

| File | Contents |
|------|----------|
| `ft_printf.h` | includes and prototypes |
| `ft_printf.c` | `ft_printf` (main loop) and `ft_conversion` (dispatcher) |
| `ft_print_chars.c` | `%c`, `%s` and a local `ft_strlen` |
| `ft_print_nbrs.c` | `%d`, `%i` and `%u` |
| `ft_print_hex.c` | `%x`, `%X` and `%p` |

## Resources

- `man 3 printf`: behaviour and return value of the original function.
- `man 3 stdarg`: `va_start`, `va_arg`, `va_copy` and `va_end`.
- [cppreference: Variadic functions](https://en.cppreference.com/w/c/variadic)
- [Wikipedia: Hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal)

### Use of AI

An AI assistant (Claude) was used as a tutor during this project:

- **Explanations:** variadic functions, how `va_arg` moves through the arguments,
  `NULL` pointers, recursion and base conversion were explained step by step with
  examples. The code itself was written by me, one conversion at a time.
- **Code review:** the assistant reviewed each version of my code, pointed out bugs
  (for example reading past the end of the string, or reading `NULL` in `%s`) and
  explained why they happened, so I could fix them.
- **Testing:** the assistant compiled my code and compared the output and the return
  value of `ft_printf` against the real `printf`.
- **Organisation:** the assistant split my finished code into several files with a
  header, and wrote the Makefile and this README.
