/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns_putnbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:38:51 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/13 17:25:32 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void    ft_printf_uns_putnbr(unsigned int nb, int *len)
{
    long    nbr;

    nbr = nb;
    if (nb > 9)
    {
        ft_printf_uns_putnbr(nbr / 10, len);
        ft_printf_putchar(nbr % 10, len);
    }
    else 
        ft_printf_putchar(nbr + '0', len);
}