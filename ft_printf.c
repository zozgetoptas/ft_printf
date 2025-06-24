/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:21:43 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 11:40:30 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static void	format_handler(const char specifier, va_list *args, int* total_len)
{
	if (specifier == '%')
		handle_percent(total_len);
	else if (specifier == 'c')
		handle_char(args, total_len);
	else if (specifier == 's')
		handle_str(args, total_len);
	else if (specifier == 'p')
		handle_ptr(args, total_len);
	else if (specifier == 'd' || specifier == 'i')
		handle_number(args,total_len);
	else if (specifier == 'u')
		handle_unsigned(args,total_len);
	else if (specifier == 'x')
		handle_hexadecimal(args,0,total_len);
	else if (specifier == 'X')
		handle_hexadecimal(args,1,total_len);
}
int		ft_printf(const char *format, ...)
{
	va_list 		args;
	int     		i;
	int     		printed;

	i = 0;
	printed = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			format_handler(format[i], &args, &printed);
			i++;
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