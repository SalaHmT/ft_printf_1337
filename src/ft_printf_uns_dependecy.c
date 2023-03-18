/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns_dependecy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:11:29 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/18 15:11:33 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printf_uns_putnbr(unsigned int nb, int *len)
{
	long	nbr;

	nbr = nb;
	if (nb > 9)
	{
		ft_printf_uns_putnbr(nbr / 10, len);
		ft_printf_uns_putnbr(nbr % 10, len);
	}
	else
		ft_printf_putchar(nbr + '0', len);
}

void	ft_printf_puthex(unsigned int nb, int *len, char xhex)
{
	char	*hex_base;

	if (xhex == 'X')
		hex_base = "0123456789ABCDEF";
	if (xhex == 'x')
		hex_base = "0123456789abcdef";
	if (nb < 16)
		ft_printf_putchar(hex_base[nb], len);
	else
	{
		ft_printf_puthex(nb / 16, len, xhex);
		ft_printf_putchar(hex_base[nb % 16], len);
	}
}

void	ft_printf_uns_putpointer(void *p, int first, int *len)
{
	unsigned long	ptr;
	char			*hex_base;

	ptr = (unsigned long)p;
	hex_base = "0123456789abcdef";
	if (first == 0)
		ft_printf_putstr("0x", len);
	if (ptr >= 16)
	{
		ft_printf_uns_putpointer((void *)(ptr / 16), 1, len);
		ft_printf_putchar(hex_base[ptr % 16], len);
	}
	else
		ft_printf_putchar(hex_base[ptr], len);
}
