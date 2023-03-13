/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:22:58 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/14 00:19:23 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
// src/..
void    ft_printf_putchar(char c, int * len);
void    ft_printf_putstr(char *str, int *len);
void    ft_printf_putnbr(int nb, int *len);
void    ft_printf_uns_putnbr(unsigned int nb, int *len);
void    ft_printf_uns_putpointer(void *p, int first, int *len);
void    ft_printf_puthex(unsigned int nb, int *len, char xhex);
// main function ..
int     ft_printf(const char *str, ...);

#endif
