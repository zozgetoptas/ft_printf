/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:21:43 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/23 16:34:52 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static int  printed_char_count(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int printed_int_count(int n)
{
    int printed = 0;
    char c;

    if (n == -2147483648) // int min kontrolü (negatif en küçük sayı)
        return write(1, "-2147483648", 11);

    if (n < 0)
    {
        printed += write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        printed += ft_putnbr(n / 10);
    c = (n % 10) + '0';
    printed += write(1, &c, 1);

    return printed;
}

int ft_puthex(unsigned long n, int lowercase)
{
    char *digits;

    digits = lowercase ? "0123456789abcdef" : "0123456789ABCDEF";

    if (n >= 16)
        return ft_puthex(n / 16, lowercase) + write(1, &digits[n % 16], 1);
    else
        return write(1, &digits[n], 1);
}

int		ft_printf(const char *format, ...)
{
	va_list 		args;
	int     		i;
	int     		printed;
	char    		c;
	char    		*str;
	unsigned long   addr;
	void     		*ptr;
	int				nmbr;

	i = 0;
	printed = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				printed++;
				i++;
			}
			else if (format[i] == 's')
			{
				str = (char *)va_arg(args, char *);
				if (!str)
					str = "(null)";
				printed += ft_putstr_fd(str);
				i++;
			}
			else if (format[i] == 'p')
			{
				ptr = va_arg(args, void *);
				addr = (unsigned long)ptr;
				write(1, "0x", 2);
				printed += ft_puthex(addr, 1);
				i++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				nmbr = va_arg(args, int);
				printed += printed_int_count(nmbr);
				i++;
			}
			else if (format[i] == 'u')
			{
				
			}
			else if (format[i] == 'x')
			{
				
			}
			else if (format[i] == 'X')
			{
				
			}
			else if (format[i] == '%')
			{
				
			}
			else
			{
				write(1, &format[i], 1);
				printed++;
				i++;
			}
		}
		va_end(args);
		return (printed);
	}
}
int main()
{
	ft_printf("%c\n%d\n%c\n",'a',18, 'a');
	printf("%c\n%d\n%c\n",'a',18, 'a');
	return (0);
}