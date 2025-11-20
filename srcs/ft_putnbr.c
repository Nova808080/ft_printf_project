#include "ft_printf.h"

int ft_putnbr(int n)
{
    long num;
    int count = 0;
    char c;

    num = n;
    if (num < 0)
    {
        write(1,"-",1);
        count++;
        num = -num;
    }
    if (num >= 10)
        count += ft_putnbr(num / 10);
    
    c = (num % 10) + '0';
    write(1,&c,1);

    return (count + 1);
}