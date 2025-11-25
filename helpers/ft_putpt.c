#include "../ft_printf.h"

int ft_putpt(unsigned long ptr)
{
    int count;
    
    count = 0;
    if (!ptr)
        return ft_putstr("(nil)");

    count += ft_putstr("0x");
    count += ft_puthex(ptr, 'x');

    return (count);
}


