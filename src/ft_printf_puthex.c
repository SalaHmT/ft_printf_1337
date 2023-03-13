/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:20:26 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/14 00:24:44 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void    ft_printf_puthex(unsigned int nb, int *len, char xhex)
{
    char *hex_base;
    if (xhex == 'X')
        hex_base = "0123456789ABCDEF";
    if (xhex == 'x')
        hex_base = "0123456789abcdef";
    if (nb < 16)
        ft_printf_putchar(hex_base[nb], len);
    else
        {
            ft_printf_puthex(nb / 10, len, xhex);
            ft_printf_putchar(hex_base[nb % 10], len);
        }    
}