/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns_putpointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:06:16 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/13 17:25:28 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void    ft_printf_uns_putpointer(void *p, int first, int *len)
{
    unsigned long   ptr;
    char    *hex_base;

    ptr = (unsigned long)p;
    hex_base = "0123456789abcdef";
    if (first == 0)
        ft_printf_putstr("0x",len);
    if (ptr >= 16)
    {
        ft_printf_uns_putpointer((void *)(ptr / 16), 1, len);
        ft_printf_putchar(hex_base[ptr % 10],len);
    }
    else
        ft_printf_putchar(hex_base[ptr], len);
}