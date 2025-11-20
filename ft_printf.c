#include "ft_printf.h"

static int handle_format(char c, va_list args)
{
    if (c == 'c')
        return ft_putchar(va_arg(args, int));
    if (c == 's')
    {
        char *str = va_arg(args, char *);
        if (!str)
            str = "(null)";
        return ft_putstr(str);
    }
    if (c == 'p')
        return ft_putpt(va_arg(args, unsigned long));
    if (c == 'd' || c == 'i')
        return ft_putnbr(va_arg(args, int));
    if (c == 'u')
        return ft_putnbr_unsigned(va_arg(args, unsigned int));
    if (c == 'x' || c == 'X')
        return ft_puthex(va_arg(args, unsigned int), c);
    if (c == '%')
        return ft_putchar('%');
    return 0;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            if (format[i + 1])
            {
                count += handle_format(format[i + 1], args);
                i++;
            }
        }
        else
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return count;
}