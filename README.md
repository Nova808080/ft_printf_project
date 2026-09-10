# ft_printf

![C](https://img.shields.io/badge/language-C-00599C?logo=c&logoColor=white)
![Build](https://img.shields.io/badge/build-passing-brightgreen)

A from-scratch reimplementation of the mandatory subset of the C standard
library's `printf`, built as a static library. Supports the core conversions
without flags, width, or precision. Built as part of the 42 School curriculum.

## Features

Supported conversions:

| Specifier | Meaning                     |
|-----------|------------------------------|
| `%c`      | character                    |
| `%s`      | string (prints `(null)` for a NULL argument) |
| `%p`      | pointer (prints `(nil)` for NULL) |
| `%d`, `%i`| signed decimal integer       |
| `%u`      | unsigned decimal integer     |
| `%x`, `%X`| unsigned hex (lower/upper)   |
| `%%`      | literal `%`                  |

`ft_printf` returns the number of characters written, matching the return
value convention of the standard `printf`.

## Requirements

- A C compiler (`gcc`/`clang`)
- `make`

## Installation

```bash
git clone <this-repo-url>
cd ft_printf_42-main
make
```

This produces `libftprintf.a`. Other targets:

```bash
make clean   # remove object files
make fclean  # remove object files and libftprintf.a
make re      # fclean + all
```

## Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "World", 42);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o my_program
```

`main.c` at the project root is a self-contained comparison test: it runs the
same format strings through `ft_printf` and the real `printf` and prints both
return values side by side.

```bash
gcc -Wall -Wextra -Werror main.c libftprintf.a -o test_main
./test_main
```

## Bug Fixes Applied

The library (`ft_printf.c` and `helpers/`) was verified against the real
`printf` with a differential test suite (return values and output compared
byte-for-byte) covering `%d`/`%i`, `%u`, `%s` (including NULL), `%p`
(including NULL), `%x`/`%X`, `%%`, `INT_MIN`, and empty format strings — all
matched exactly, so no changes were needed there.

The bug was in the bundled `main.c` test file, which **did not compile**:

1. **Duplicate variable declarations.** `a`, `b`, and `i` were each declared
   with `int` more than once in the same scope (e.g. `int a = ...` appearing
   four separate times), which is a hard compile error in C.
2. **Invalid calls to the real `printf`.** `printf(NULL)` is undefined
   behavior and rejected at compile time by gcc's `nonnull` attribute;
   `printf("ttt%cttt%d\n")` and the `--%s--`/`--%p--` test passed too few or
   mismatched arguments, which fails under `-Werror=format`.
3. **Ordering issue.** The file called `fclose(stdout)` partway through and
   then kept calling `printf`/`ft_printf` on the now-closed stream, making
   the remaining output meaningless.

Rewrote `main.c` with uniquely named variables, valid arguments for every
`printf` call, and moved the closed-stdout check to the end. It now compiles
cleanly under `-Wall -Wextra -Werror` and runs to completion, confirming
`ft_printf`'s return values match `printf`'s in every case tested.

## License

This project has no explicit license; add one (e.g. MIT) if you plan to
distribute it publicly.
