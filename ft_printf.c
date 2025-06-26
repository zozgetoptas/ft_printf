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

#include <unistd.h>
#include "ft_printf.h"

static int format_check(char c)
{
    return(c == '%' || c == 'c' || c == 's' || c == 'p' || 
            c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

static int	format_handler(const char specifier, va_list *args)
{
	 if (specifier == '%')
        return handle_percent();
    else if (specifier == 'c')
        return handle_char(args);
    else if (specifier == 's')
        return handle_str(args);
    else if (specifier == 'p')
        return handle_ptr(args);
    else if (specifier == 'd' || specifier == 'i')
        return handle_number(args);
    else if (specifier == 'u')
        return handle_unsigned(args);
    else if (specifier == 'x')
        return handle_hexadecimal(args, 1);
    else if (specifier == 'X')
        return handle_hexadecimal(args, 0);
    return (0);
}

static int	handle_format_or_percent(const char *format, int *i, va_list *args)
{
	int	ret;

	if (format_check(format[*i]))
	{
		ret = format_handler(format[*i], args);
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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;
	int		ret;

	if (!format)
		return (-1);
	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret = handle_format_or_percent(format, &i, &args);
		}
		else
			ret = write(1, &format[i++], 1);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		printed += ret;
	}
	va_end(args);
	return (printed);
}