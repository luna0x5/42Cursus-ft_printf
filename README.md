# ft_printf - 42 Cursus Project

A custom implementation of the C standard library's `printf` function. This project recreates the core functionality of the standard printf, supporting various format specifiers and variable arguments.

## Project Overview

`ft_printf` is a 42 School curriculum project that challenges students to implement a variadic function capable of formatting and printing output similar to the standard C library's `printf`. This implementation handles multiple data types and format specifiers while demonstrating advanced C programming concepts like variadic functions, type casting, and memory management.

## Features

The following format specifiers are supported:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal (0x prefix) |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer (same as %d) |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned integer in hexadecimal (lowercase) |
| `%X` | Prints an unsigned integer in hexadecimal (uppercase) |
| `%%` | Prints a literal percent sign |

## Project Structure

```
ft_printf/
├── ft_printf.h          # Header file with function declarations
├── ft_printf.c          # Main printf function with format parsing logic
├── ft_putchar.c         # Outputs a single character
├── ft_putstr.c          # Outputs a string
├── ft_putnbr.c          # Outputs a signed integer
├── ft_putuns.c          # Outputs an unsigned integer
├── ft_puthexa.c         # Outputs a number in hexadecimal format
├── ft_putptr.c          # Outputs a pointer address
├── Makefile             # Build configuration
└── README.md            # This file
```

## Compilation

### Build the library

```bash
make
```

This compiles all source files and creates the static library `libftprintf.a`.

### Clean up

```bash
make clean        # Remove object files
make fclean       # Remove object files and library
make re           # Rebuild everything (fclean + all)
```

## Usage

### Linking the library

Include the header and link against the library in your project:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World");
    return (0);
}
```

Compile with:
```bash
gcc -o program program.c -L. -lftprintf
```

### Examples

```c
#include "ft_printf.h"

int main(void)
{
    // Basic usage
    ft_printf("Character: %c\n", 'A');           // Output: Character: A
    ft_printf("String: %s\n", "ft_printf");      // Output: String: ft_printf
    
    // Numbers
    ft_printf("Integer: %d\n", 42);              // Output: Integer: 42
    ft_printf("Unsigned: %u\n", 100);            // Output: Unsigned: 100
    
    // Hexadecimal
    ft_printf("Hex (lower): %x\n", 255);         // Output: Hex (lower): ff
    ft_printf("Hex (upper): %X\n", 255);         // Output: Hex (upper): FF
    
    // Pointer
    int x = 10;
    ft_printf("Pointer: %p\n", &x);              // Output: Pointer: 0x7fff...
    
    // Multiple arguments
    ft_printf("%d + %d = %d\n", 5, 3, 8);       // Output: 5 + 3 = 8
    
    return (0);
}
```

## Return Value

The `ft_printf` function returns the number of characters printed (excluding the null terminator). If an error occurs, it returns -1.

## Implementation Details

- **Variadic Arguments**: Uses `<stdarg.h>` to handle variable number of arguments
- **Format Parsing**: Iterates through the format string character by character, dispatching to specialized functions for each format specifier
- **Error Handling**: Checks for write errors and returns -1 on failure
- **Compilation Flags**: Built with `-Wall -Wextra -Werror` for strict compliance

## Technical Requirements

- Compiler: GCC or Clang compatible C compiler
- Standard: C89 compatible
- Dependencies: Standard C library only
- Platform: Unix-like systems (Linux, macOS)

