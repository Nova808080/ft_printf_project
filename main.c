#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int r1, r2;
	int x = 42;

	// Characters
	r1 = printf("%c\n", 'A');
	r2 = ft_printf("%c\n", 'A');
	printf("ret: %d | %d\n\n", r1, r2);

	// Strings
	r1 = printf("%s\n","basma");
	r2 = ft_printf("%s\n","basma");
	printf("ret: %d | %d\n\n", r1, r2);

	r1 = printf("%s\n", "");
	r2 = ft_printf("%s\n", "");
	printf("ret: %d | %d\n\n", r1, r2);

	// Integers
	r1 = printf("%d\n", 42);
	r2 = ft_printf("%d\n", 42);
	printf("ret: %d | %d\n\n", r1, r2);

	r1 = printf("%d\n", (int)-2147483648);
	r2 = ft_printf("%d\n", (int)-2147483648);
	printf("ret: %d | %d\n\n", r1, r2);

	r1 = printf("%i\n", 0);
	r2 = ft_printf("%i\n", 0);
	printf("ret: %d | %d\n\n", r1, r2);

	// Unsigned
	r1 = printf("%u\n", 0u);
	r2 = ft_printf("%u\n", 0u);
	printf("ret: %d | %d\n\n", r1, r2);

	r1 = printf("%u\n", 4294967295u);
	r2 = ft_printf("%u\n", 4294967295u);
	printf("ret: %d | %d\n\n", r1, r2);

	// Hexadecimal
	r1 = printf("%x\n", 255);
	r2 = ft_printf("%x\n", 255);
	printf("ret: %d | %d\n\n", r1, r2);

	r1 = printf("%X\n", 255);
	r2 = ft_printf("%X\n", 255);
	printf("ret: %d | %d\n\n", r1, r2);

	r1 = printf("%x\n", 0);
	r2 = ft_printf("%x\n", 0);
	printf("ret: %d | %d\n\n", r1, r2);

	// Pointers
	r1 = printf("%p\n", &x);
	r2 = ft_printf("%p\n", &x);
	printf("ret: %d | %d\n\n", r1, r2);

	r1 = printf("%p\n", NULL);
	r2 = ft_printf("%p\n", NULL);
	printf("ret: %d | %d\n\n", r1, r2);

	// Percent
	r1 = printf("%%\n");
	r2 = ft_printf("%%\n");
	printf("ret: %d | %d\n\n", r1, r2);

	// Mixed
	r1 = printf("%c %s %d %u %x %p %%\n", 'A', "test", -42, 100u, 255, &x);
	r2 = ft_printf("%c %s %d %u %x %p %%\n", 'A', "test", -42, 100u, 255, &x);
	printf("ret: %d | %d\n\n", r1, r2);

	return 0;
}