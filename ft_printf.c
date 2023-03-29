/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:10:34 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/18 15:10:43 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static	void	check_args(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_printf_putchar (va_arg(args, int), len);
	else if (c == 's')
		ft_printf_putstr(va_arg(args, char *), len);
	else if ((c == 'i') || (c == 'd'))
		ft_printf_putnbr(va_arg(args, int), len);
	else if (c == 'u')
		ft_printf_uns_putnbr(va_arg(args, unsigned int), len);
	else if ((c == 'x') || (c == 'X'))
		ft_printf_puthex(va_arg(args, unsigned int), len, c);
	else if (c == 'p')
		ft_printf_uns_putpointer(va_arg(args, void *), 0, len);
	else if (c == '%')
		ft_printf_putchar('%', len);
	else
		ft_printf_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		p_len;

	p_len = 0;
	va_start(args, str);
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				break ;
			check_args(*str, args, &p_len);
		}
		else
			ft_printf_putchar(*str, &p_len);
		str++;
	}
	va_end(args);
	return (p_len);
}
