*This project has been created as part of the 42 curriculum by alsanch3.*

# get_next_line

## Description

`get_next_line` is a function that returns **one line at a time** from a file descriptor.
Calling it repeatedly (for example inside a loop) reads the content of a file, or of the
standard input, line by line until the end.

```c
char	*get_next_line(int fd);
```

- It returns the line that has just been read, **including the trailing `\n`**. The only
  exception is the last line of a file that does not end with a `\n`.
- It returns `NULL` when there is nothing left to read or when an error happens.
- It works with files and with the standard input (`fd` 0).
- It only uses `read`, `malloc` and `free`. No `libft`, no `lseek` and no global variables.

The size of the chunks read from the file is set at compile time with the macro
`BUFFER_SIZE`. The code works with any positive value, from `1` to very large numbers.

The goal of the project is to learn what a **static variable** is: a variable that keeps
its value between calls, which is what lets the function remember what it has already read.

## Instructions

### Compilation

The project has no Makefile. Compile the sources together with your own `main`:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

`BUFFER_SIZE` can be changed with `-D BUFFER_SIZE=n`. If the flag is not given, the header
defines a default value of `42`.

### Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

The caller owns every returned line and must `free` it. Every run of the program starts
from the beginning of the file: the remembered data only lives while the program runs.

### Files

| File                    | Content                                                     |
|-------------------------|-------------------------------------------------------------|
| `get_next_line.h`       | Includes, default `BUFFER_SIZE` and function prototypes.     |
| `get_next_line.c`       | `get_next_line` and its three `static` helper functions.     |
| `get_next_line_utils.c` | Small string and memory helpers.                             |

### Functions

| Function         | File                    | Description                                                              |
|------------------|-------------------------|--------------------------------------------------------------------------|
| `get_next_line`  | `get_next_line.c`       | Public function. Fills the stash, cuts a line from it and keeps the rest. |
| `ft_fill_stash`  | `get_next_line.c`       | Reads chunks and appends them to the stash until it contains a `\n` or the file ends. |
| `ft_get_line`    | `get_next_line.c`       | Returns a new string with the stash up to the first `\n` (included).     |
| `ft_new_stash`   | `get_next_line.c`       | Returns a new stash with what comes after the first `\n`, and frees the old one. |
| `ft_strlen`      | `get_next_line_utils.c` | Length of a string (`0` for `NULL`).                                     |
| `ft_strchr`      | `get_next_line_utils.c` | First occurrence of a character in a string (`NULL` if the string is `NULL`). |
| `ft_strjoin`     | `get_next_line_utils.c` | New string made of two strings (`NULL` counts as an empty string).        |
| `ft_append`      | `get_next_line_utils.c` | Joins the stash with a new chunk and frees the old stash.                |
| `ft_clean`       | `get_next_line_utils.c` | Frees a buffer and the stash and returns `NULL`; used to exit on errors.  |

## Algorithm and data structure

### The problem

`read` knows nothing about lines: it returns up to `BUFFER_SIZE` bytes, wherever the `\n`
happens to fall. A chunk can contain half a line, one line, or several lines. Whatever is
read beyond the end of the requested line cannot be given back to the file (`lseek` is
forbidden), so it has to be **kept by the program** for the next call.

### The data structure: the stash

The only state is a single `static char *stash`, a string that holds the data that has been
read from the file but not returned yet. A static variable keeps its value between calls
and is initialised to `NULL`. It is not a global variable: only `get_next_line` can see it.

### One call, in three steps

1. **Fill** (`ft_fill_stash`). While the stash does not contain a `\n` and the file has not
   ended, read `BUFFER_SIZE` bytes into a temporary buffer, add a `'\0'` at the end and append
   it to the stash. If the stash already holds a full line from a previous call, nothing is read.
2. **Cut** (`ft_get_line`). Copy the stash up to the first `\n` (included), or up to the end if
   there is no `\n`, into a new string. That string is the return value. If the stash is empty,
   the result is `NULL`: there are no more lines.
3. **Keep** (`ft_new_stash`). Build a new stash with what comes after the `\n` and free the old
   one. If nothing is left, the stash becomes `NULL`.

Step 2 must run before step 3, because step 3 frees the stash that step 2 reads.

### Example

File `hola que tal\nyo estoy bien\n` with `BUFFER_SIZE=5`:

| Call | Chunks read                 | Stash before cutting       | Returned            | Stash kept |
|------|-----------------------------|----------------------------|---------------------|------------|
| 1    | `hola `, `que t`, `al\nyo`  | `hola que tal\nyo`         | `hola que tal\n`    | `yo`       |
| 2    | ` esto`, `y bie`, `n\n`     | `yo estoy bien\n`          | `yo estoy bien\n`   | (empty)    |
| 3    | (`read` returns 0)          | (empty)                    | `NULL`              | `NULL`     |

### Why this algorithm

- **It reads as little as possible.** It stops reading as soon as the stash has a `\n`, as
  the subject asks. It never reads the whole file to split it afterwards.
- **It works for any `BUFFER_SIZE`.** The loop does not assume that a chunk is smaller or
  larger than a line, so `1`, `42`, `9999` and `10000000` all give the same result. The read
  buffer is allocated with `malloc` (`BUFFER_SIZE + 1`) and not on the stack, so a huge
  `BUFFER_SIZE` does not overflow the stack.
- **It is simple to reason about memory.** Every function that allocates has one clear owner
  for the result, and `ft_clean` gives a single way out for errors, so there are no leaks on
  any path (checked with `valgrind`).
- **Only one static variable and no globals,** as the subject requires.

### Limits and edge cases

- Reading is `fd`-agnostic: files, pipes and standard input behave the same way.
- An invalid `fd` (negative, closed, or a directory) or a `read` error makes the function
  return `NULL` and free what it holds.
- The subject leaves two cases undefined: a file that changes between calls, and binary files.
- The stash is joined into a new string for every chunk read. With normal files this is
  instant, but with a very small `BUFFER_SIZE` and a single extremely long line (hundreds of
  thousands of characters) the cost grows quickly, because each join copies the whole stash.
  Reading a bigger chunk, or keeping a length counter, would improve it; it was not needed here.

### Possible testing

Compile with several values (`-D BUFFER_SIZE=1`, `=42`, `=10000000`) and try: a normal file, an
empty file, a file without a final `\n`, a file of only `\n`, very long lines, the standard
input, and an invalid `fd`. Run the program under `valgrind --leak-check=full` to check that
nothing leaks.

## Resources

### References

- `man 2 read`, `man 3 malloc`, `man 3 free` ([man7.org](https://man7.org/linux/man-pages/))
- [cppreference: storage duration and linkage (`static`)](https://en.cppreference.com/w/c/language/storage_duration)
- [Valgrind manual](https://valgrind.org/docs/manual/manual.html)
- *The C Programming Language*, Brian W. Kernighan and Dennis M. Ritchie.

### Use of AI

AI (Claude) was used as a tutor and for part of the code:

- To explain concepts I did not understand yet: file descriptors and `read`, static variables,
  pointers and `malloc`/`free`, why a `free` is needed on every path, and the 42 Norm limits.
- To review my code and point out bugs (for example a missing `\0`, a `malloc` of the wrong
  size, or a leak on an error path), which I then fixed myself.
- To write the following parts, at my request: the `while` loop inside `ft_fill_stash`, the
  helper functions `ft_append` and `ft_clean`, and the first split of the original long function
  into `ft_fill_stash` and `get_next_line` to fit the Norm. I have read, tested and understood
  these parts.
- To test the project (several `BUFFER_SIZE` values, `valgrind`, edge cases), and to help write
  and translate this README into English.

The rest of the code was written by me: the header, `ft_strlen`, `ft_strchr`, `ft_strjoin`,
`ft_get_line`, `ft_new_stash` and the final `get_next_line`.
