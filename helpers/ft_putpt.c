/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchergua <bchergua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:05:50 by bchergua          #+#    #+#             */
/*   Updated: 2025/11/22 13:15:39 by bchergua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


