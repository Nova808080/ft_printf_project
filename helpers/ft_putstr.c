/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchergua <bchergua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:05:58 by bchergua          #+#    #+#             */
/*   Updated: 2025/11/23 01:48:22 by bchergua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_putstr(char *s)
{
    int count;

    count = 0;
    if (!s)
        return write(1, "(null)", 6);

    while (*s)
        count += write(1, s++, 1);
    return (count);
}

