#include "../ft_printf.h"

int ft_put_unsigned(unsigned int n)
{
    int count;
    char c;
    
    count = 0;
    if (n >= 10)
        count += ft_put_unsigned(n / 10);

    c = (n % 10) + '0';
    count += write(1, &c, 1);

    return (count);
}

