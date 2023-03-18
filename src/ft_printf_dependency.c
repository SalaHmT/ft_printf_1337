/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dependency.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:11:16 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/18 15:11:19 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printf_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_printf_putstr(char *str, int *len)
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

void	ft_printf_putnbr(int nb, int *len)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_printf_putchar('-', len);
		nbr *= (-1);
	}
	if (nbr > 9)
	{
		ft_printf_putnbr(nbr / 10, len);
		ft_printf_putnbr(nbr % 10, len);
	}
	else
		ft_printf_putchar(nbr + '0', len);
}
