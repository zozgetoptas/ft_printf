/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:42:13 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 10:53:49 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int handle_number(va_list *args)
{
	int n = va_arg(*args, int);
	int printed = 0;
	int ret;

	if (n < 0)
	{
		ret = write(1, "-", 1);
		if (ret == -1)
			return (-1);
		printed += ret;
		ret = print_unsigned_number((unsigned int)(-n));
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
