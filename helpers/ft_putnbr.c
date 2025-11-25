#include "../ft_printf.h"

int ft_putnbr(int n)
{
    long num;
    int count;
    char c;

    num = n;
    count = 0;

    if (num < 0)
    {
        count += write(1, "-", 1);
        num = -num;
    }

    if (num >= 10)
        count += ft_putnbr(num / 10);

    c = (num % 10) + '0';
    count += write(1, &c, 1);

    return (count);
}

