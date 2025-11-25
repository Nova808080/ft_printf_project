#include "ft_printf.h"

static int ver(const char *s)
{
    if (*s == 'c' || *s == 's' || *s == 'p'
        || *s == 'd' || *s == 'i' || *s == 'u'
        || *s == 'x' || *s == 'X' || *s == '%')
        return (1);
    return (0);
}

static int ft_handle_format(char c, va_list args)
{
    if (c == 'c')
        return (ft_putchar(va_arg(args, int)));
    if (c == 's')
        return (ft_putstr(va_arg(args, char *)));
    if (c == 'p')
        return (ft_putpt(va_arg(args, unsigned long)));
    if (c == 'd' || c == 'i')
        return (ft_putnbr(va_arg(args, int)));
    if (c == 'u')
        return (ft_put_unsigned(va_arg(args, unsigned int)));
    if (c == 'x' || c == 'X')
        return (ft_puthex(va_arg(args, unsigned int), c));
    if (c == '%')
        return (ft_putchar('%'));
    return (0);
}

static int percent(const char *format, int *i, va_list args)
{
    int count;

    count = 0;
    if (!format[*i + 1])
        return (-1);
    if (ver(&format[*i + 1]))
    {
        (*i)++;
        count += ft_handle_format(format[*i], args);
    }
    else
    {
        count += ft_putchar('%');
        count += ft_putchar(format[*i + 1]);
        (*i)++;
    }
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     count;
    int     i;

    if (!format || write(1, "", 0) < 0)
        return (-1);
    va_start(args, format);
    count = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            int r = percent(format, &i, args);
            if (r == -1)
                return (va_end(args), -1);
            count += r;
        }
        else
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}

