#include "ft_printf.h"

int ft_putpt(unsigned long ptr)
{
    int count = 0;

    count += ft_putstr("(0x)");
    count += ft_puthex((unsigned int)ptr, 'x');

    return count;
}
