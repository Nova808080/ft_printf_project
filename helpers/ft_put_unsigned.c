/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchergua <bchergua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:04:51 by bchergua          #+#    #+#             */
/*   Updated: 2025/11/22 12:54:45 by bchergua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

