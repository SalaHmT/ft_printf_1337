/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:48:51 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/13 17:25:15 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void    ft_printf_putstr(char *str, int *len)
{
    if (!str)
        ft_printf_putstr("(null)", len);
    else
    {
        while (*str)
        {
            ft_printf_putchar(*str, len);
            str++;
        }
    }
}