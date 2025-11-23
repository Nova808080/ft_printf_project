/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchergua <bchergua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:04:30 by bchergua          #+#    #+#             */
/*   Updated: 2025/11/23 01:50:45 by bchergua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_format(char c, va_list *args)
{
    if (c == 'c')
        return ft_putchar(va_arg(*args, int));
    if (c == 's')
        return ft_putstr(va_arg(*args, char *));
    if (c == 'p')
        return ft_putpt(va_arg(*args, unsigned long));
    if (c == 'd' || c == 'i')
        return ft_putnbr(va_arg(*args, int));
    if (c == 'u')
        return ft_put_unsigned(va_arg(*args, unsigned int));
    if (c == 'x' || c == 'X')
        return ft_puthex(va_arg(*args, unsigned int), c);
    if (c == '%')
        return ft_putchar('%');
    return 0;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int count;

    if (!format)
        return -1;
    va_start(args, format);
    i = 0;
    count = 0;
    
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            count += handle_format(format[i + 1], &args);
            i += 2;
        }
        else
        {
            count += ft_putchar(format[i]);
            i ++;
        }
    }
    va_end(args);
    return (count);
}
