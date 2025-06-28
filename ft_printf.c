/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:21:43 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/27 16:45:40 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	format_handler(const char conversion_specifier, va_list *args)
{
	if (conversion_specifier == '%')
		return (handle_percent());
	else if (conversion_specifier == 'c')
		return (handle_char(args));
	else if (conversion_specifier == 's')
		return (handle_str(args));
	else if (conversion_specifier == 'p')
		return (handle_ptr(args));
	else if (conversion_specifier == 'd' || conversion_specifier == 'i')
		return (handle_number(args));
	else if (conversion_specifier == 'u')
		return (handle_unsigned(args));
	else if (conversion_specifier == 'x')
		return (handle_hexadecimal(args, 1));
	else if (conversion_specifier == 'X')
		return (handle_hexadecimal(args, 0));
	return (0);
}

static int	process_conversion_specifier(const char *format,
										int *i, va_list *args)
{
	int		ret;
	char	c;

	c = format[*i];
	if (c == '%' || c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
	{
		ret = format_handler(c, args);
		(*i)++;
		return (ret);
	}
	else
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		(*i)++;
		return (1);
	}
}

static int	printf_loop(const char *format, va_list *args)
{
	int	i;
	int	ret;
	int	printed;

	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret = process_conversion_specifier(format, &i, args);
		}
		else
			ret = write(1, &format[i++], 1);
		if (ret == -1)
			return (-1);
		printed += ret;
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	if (!format)
		return (-1);
	va_start(args, format);
	printed = printf_loop(format, &args);
	va_end(args);
	return (printed);
}
