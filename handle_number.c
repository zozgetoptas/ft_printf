/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:42:13 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/27 12:57:41 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	handle_number(va_list *args)
{
	int	n;
	int	printed;
	int	ret;

	n = va_arg(*args, int);
	printed = 0;
	if (n < 0)
	{
		ret = write(1, "-", 1);
		if (ret == -1)
			return (-1);
		printed += ret;
		ret = print_unsigned_number((unsigned int)(-(long)n));
	}
	else
	{
		ret = print_unsigned_number((unsigned int)n);
	}
	if (ret == -1)
		return (-1);
	printed += ret;
	return (printed);
}
