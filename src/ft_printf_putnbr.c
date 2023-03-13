/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:17:18 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/13 17:02:08 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void    ft_printf_putnbr(int nb, int *len)
{
    long    nbr;

    nbr = nb;
    if (nbr < 0)
        {
            ft_printf_putchar('-',len);
            nbr = nb * (-1);
        }
    if (nbr > 9)
    {
        ft_printf_putnbr(nbr / 10, len);
        ft_printf_putchar(nbr % 10, len);
    }
    else
        ft_printf_putchar(nbr + '0', len);
}