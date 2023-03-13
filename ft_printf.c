/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:21:17 by shamsate          #+#    #+#             */
/*   Updated: 2023/03/14 00:32:27 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static  void    check_args(char c, va_list args, int *len)
{
    if (c == 'c')
        ft_printf_putchar(va_arg(args, int), len);
    else if (c == 's')
        ft_printf_putstr(va_arg(args, char *), len);
    else if (c == 'i' || c == 'd')
        ft_printf_putnbr(va_arg(args, int), len);
    else if (c == 'u')
        ft_printf_uns_putnbr(va_arg(args, unsigned int), len);
    else if (c == 'x'|| c == 'X')
        ft_printf_puthex(va_arg(args, unsigned int), len, c);
    else if (c == 'p')
        ft_printf_uns_putpointer(va_arg(args, void *), 0, len);
    else if ( c == '%')
        ft_printf_putchar('%', len);
    else
        ft_printf_putchar(c, len);
 }

 int    ft_printf(const char *str, ...)
 {
    va_list args;
    int p_len;

    p_len = 0;
    va_start(args, str);
    if (write(1, 0, 0))
        return (-1);
    while (*str)
	{

        if (*str == '%')
		{
			str++;
			check_args(*str, args, &p_len);
		}
        else
            ft_printf_putchar(*str, &p_len);
		str++;
	}
    va_end(args);
    return (p_len);
 }

//  // INT MAIN :
// /* variables C en octets */
// //------------------------------------------
//   int main()
//  {
// //------------------------------------------
//  ft_printf("[%05]\n"); 
//  ft_printf("[%5]\n");
// ft_printf("%050 d\n", 500);
// ft_printf("{%05.*d}\n", -15, 42);
// //------------------------------------------
//  int test = 42; 
// ft_printf("bonjour\n"); 
// ft_printf("char:                    %c\n", 'r'); 
// ft_printf("string:                  %s\n", "bonjour"); 
// ft_printf("pointer:                 %p\n", &test); 
// ft_printf("int:                     %d or %i\n", 45, 54); 
//  ft_printf("uint:                    %u\n", 1 << 31); 
// ft_printf("hex lower:               %x\n", 12); 
// ft_printf("hex upper:               %X\n", 15); 
// ft_printf("percent:                 %%\n"); 
// ft_printf("multiple stuff:          %d %u %d %x %d\n", 1, -2, 3, 0xa, 5);
// /*  */
// //-----------------------------------------
// ft_printf("\n char a une taille de %d octets", sizeof(char));
// ft_printf("\n int a une taille de %i octets",sizeof(int));
// ft_printf("\n short a une taille de %i octets",sizeof(short));
// ft_printf("\n long a une taille de % octets", sizeof(long));
// ft_printf("\n unsigned char a une taille de %d octets",sizeof(unsigned char));
// ft_printf("\n unsigned int a une taille de %d octets",sizeof(unsigned int));
// ft_printf("\n unsigned short a une taille de %d octets",
// sizeof(unsigned short));
// ft_printf("\n unsigned long a une taille de %d octets",sizeof(unsigned long));
// ft_printf("\n float a une taille de %d octets",sizeof(float));
// ft_printf("\n double a une taille de %d octets\n",sizeof(double));
// //------------------------------------------
// ft_printf("%f\n", 0.14159);
// ft_printf("%hi\n", 32768);
// ft_printf("%%\n", 32768);
// //------------------------------------------
// }
// //------------------------------------------

