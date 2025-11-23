#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;

    printf("=== TEST: Characters ===\n");
    ret1 = printf("printf: %c %c %c\n", 'A', '0', '#');
    ret2 = ft_printf("ft_printf: %c %c %c\n\n", 'A', '0', '#');
    printf("ret printf = %d | ret ft_printf = %d\n\n", ret1, ret2);

    printf("=== TEST: Strings ===\n");
    ret1 = printf("printf: %s | %s\n", "Hello", "");
    ret2 = ft_printf("ft_printf: %s | %s\n\n", "Hello", "");
    printf("ret printf = %d | ret ft_printf = %d\n\n", ret1, ret2);

    printf("=== TEST: Integers (d/i) ===\n");
    ret1 = printf("printf: %d | %i | %d\n", 42, -1234, 0);
    ret2 = ft_printf("ft_printf: %d | %i | %d\n\n", 42, -1234, 0);
    printf("ret printf = %d | ret ft_printf = %d\n\n", ret1, ret2);

    printf("=== TEST: Unsigned ===\n");
    ret1 = printf("printf: %u | %u | %u\n", 0u, 1u, 4294967295u);
    ret2 = ft_printf("ft_printf: %u | %u | %u\n\n", 0u, 1u, 4294967295u);
    printf("ret printf = %d | ret ft_printf = %d\n\n", ret1, ret2);

    printf("=== TEST: Hexadecimal ===\n");
    ret1 = printf("printf: %x | %X | %x\n", 255, 255, 0);
    ret2 = ft_printf("ft_printf: %x | %X | %x\n\n", 255, 255, 0);
    printf("ret printf = %d | ret ft_printf = %d\n\n", ret1, ret2);

    printf("=== TEST: Pointer ===\n");
    int x = 42;
    ret1 = printf("printf: %p | %p | %p\n", &x, NULL, (void*)0x1234);
    ret2 = ft_printf("ft_printf: %p | %p | %p\n\n", &x, NULL, (void*)0x1234);
    printf("ret printf = %d | ret ft_printf = %d\n\n", ret1, ret2);

    printf("=== TEST: Percent ===\n");
    ret1 = printf("printf: %% %% %%\n");
    ret2 = ft_printf("ft_printf: %% %% %%\n\n");
    printf("ret printf = %d | ret ft_printf = %d\n\n", ret1, ret2);

    return 0;
}
