*This project has been created as part of the 42 curriculum by sojadiri.*

# ft_printf

## Description

The **ft_printf** project consists of recreating the standard C `printf()` function.

The goal is to implement a custom `ft_printf()` function that handles formatted output using a variable number of arguments (variadic functions).

This project focuses on understanding:

- Variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`).
- Format string parsing.
- Number conversion between different bases.
- Modular programming and code organization.

The implementation reproduces the behavior of the original `printf()` for the mandatory conversions without implementing its internal buffer management.

## Supported Conversions

| Conversion | Description                                         |
| :--------: | --------------------------------------------------- |
|    `%c`    | Prints a single character.                          |
|    `%s`    | Prints a string.                                    |
|    `%p`    | Prints a pointer address in hexadecimal format.     |
|    `%d`    | Prints a signed decimal integer.                    |
|    `%i`    | Prints an integer in base 10.                       |
|    `%u`    | Prints an unsigned decimal integer.                 |
|    `%x`    | Prints an unsigned hexadecimal number in lowercase. |
|    `%X`    | Prints an unsigned hexadecimal number in uppercase. |
|    `%%`    | Prints a percent sign.                              |

## Algorithm and Implementation

The implementation follows a modular approach. Instead of handling every conversion inside a single function, `ft_printf()` acts as the main controller and delegates the actual printing to dedicated helper functions.

### 1. Format String Parsing

The main function iterates through the format string character by character.

There are two possible cases:

- **Regular character:** If the current character is not `%`, it is printed directly using `write()`.
- **Format specifier:** If the current character is `%`, the next character is examined to determine which conversion is required.

### 2. Variadic Arguments

The function uses `va_list` to access the additional arguments passed to `ft_printf()`.

- `va_start()` initializes the argument list.
- `va_arg()` retrieves the next argument with the appropriate type.
- `va_end()` finishes the argument processing.

Each conversion retrieves its corresponding argument and passes it to the appropriate helper function.

### 3. Conversion Dispatching

Once a conversion specifier is identified, the main function dispatches the operation to the corresponding helper.

For example:

- `%c` and `%%` use the character printing helper.
- `%s` uses the string printing helper.
- `%d` and `%i` use the signed decimal printing helper.
- `%u` uses the unsigned decimal printing helper.
- `%x` and `%X` use the hexadecimal printing helper.
- `%p` uses the address printing helper.

### 4. Printing Numbers

The numerical conversion helpers handle the process of displaying numbers in their required bases.

For decimal numbers, the base is 10.

For hexadecimal numbers, the base is 16, using either lowercase or uppercase characters depending on the conversion specifier.

The printing functions handle the conversion and output of the values using `write()`.

### 5. Return Value

Like the original `printf()`, `ft_printf()` returns the number of characters printed.

The count includes both regular characters and characters produced by the conversion specifiers.

## Data Structure and Algorithm Justification

### 1. Data Structures

This implementation does not require complex data structures such as linked lists, trees, or hash tables. It uses simple structures provided by the C language.

**Format String (Character Array)**

The format string is a sequence of characters stored in memory. It is traversed sequentially using an index to identify regular characters and conversion specifiers.

For example:

```c
ft_printf("Hello %s, number: %d", "World", 42);
```

The format string is processed from left to right. When a `%` character is encountered, the next character determines which conversion function must be called.

**Variadic Argument List (`va_list`)**

`va_list` is used to access the additional arguments passed to `ft_printf()`.

Arguments are retrieved sequentially using `va_arg()`, with the appropriate type for each conversion.

For example:

```c
ft_printf("%s %d", "Hello", 42);
```

The first conversion retrieves a string, while the second retrieves an integer.

**Character Counter (`int`)**

An integer counter tracks the total number of characters successfully printed. It is updated after printing regular characters and conversion results.

### 2. Algorithm Choice: Sequential Parsing and Dispatching

The chosen algorithm is a sequential parsing algorithm.

The format string is traversed once, from beginning to end. Each character is examined to determine whether it is a regular character or a conversion specifier.

When a conversion is found, the corresponding helper function is called to handle the argument and print its representation.

This approach was chosen because:

- It processes the format string in its original order.
- It does not require additional memory allocation.
- It keeps the main function simple and separates conversion logic into independent helper functions.
- It allows each conversion to be implemented and tested independently.

**Time Complexity:**

Let `n` represent the length of the format string and `m` represent the total number of characters printed by the conversion functions.

The overall complexity is approximately:

- Format string traversal: O(n).
- Printing converted values: O(m).

Therefore, the total time complexity is O(n + m), assuming each character written takes constant time.

**Space Complexity:**

The format string is processed directly without creating an additional copy. The implementation does not require dynamic data structures or additional allocated buffers.

The auxiliary space is O(1), excluding the storage used internally by the C variadic argument mechanism and the call stack.

## Project Structure

```text
ft_printf/
│
├── ft_printf.c
├── ft_printf.h
├── Makefile
├── README.md
│
└── srcs/
    ├── ft_print_address.c
    ├── ft_print_decimal.c
    ├── ft_print_hexadecimal.c
    ├── ft_print_str.c
    ├── ft_print_u_decimal.c
    └── ft_putchar.c
```

### Helper Functions

| File                     | Responsibility                                        |
| ------------------------ | ----------------------------------------------------- |
| `ft_putchar.c`           | Prints a single character.                            |
| `ft_print_str.c`         | Prints a string.                                      |
| `ft_print_decimal.c`     | Prints signed decimal integers.                       |
| `ft_print_u_decimal.c`   | Prints unsigned decimal integers.                     |
| `ft_print_hexadecimal.c` | Prints hexadecimal numbers in lowercase or uppercase. |
| `ft_print_address.c`     | Prints pointer addresses in hexadecimal format.       |

## Instructions

### Compilation

Compile the library using:

```bash
make
```

The Makefile uses the following compilation flags:

```bash
-Wall -Wextra -Werror
```

These flags enable common compiler warnings and treat warnings as errors, helping maintain clean and reliable code.

This generates the static library:

```text
libftprintf.a
```

Other available Makefile commands:

```bash
make clean
make fclean
make re
```

### Usage

Include the header in your C program:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Character: %c\n", 'A');

    return (0);
}
```

Compile your program with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
```

Run it:

```bash
./test
```

## Resources

The following resources were useful for understanding the concepts behind this project.

### Documentation and References

- [printf() - Linux Manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg.h - C Variadic Arguments](https://en.cppreference.com/w/c/variadic.html)
- [GNU Make Documentation](https://www.gnu.org/software/make/manual/make.html)

### Additional Learning Resources

- [Understanding Variadic Functions in C](https://www.youtube.com/watch?v=7Sph8JlRo0g)
- [System V Application Binary Interface - AMD64 Architecture Processor Supplement](https://refspecs.linuxbase.org/elf/x86_64-abi-0.99.pdf)

### Why the Linux Manual?

The Linux Manual (man pages) is an important reference for understanding how C library functions and Linux system calls work.

During this project, it was useful for studying the behavior of functions such as `printf()` and `write()`, including their parameters, return values, and error handling.

It is also a valuable resource for understanding the difference between standard library functions and system calls.

### AI Usage

AI tools were used as learning support to understand variadic functions, argument handling, and the overall architecture of the project.

They were also used to clarify technical concepts and help organize the project documentation. The implementation and testing process were carried out as part of the learning experience.
