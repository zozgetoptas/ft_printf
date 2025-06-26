/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:42:27 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 10:53:44 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_unsigned(va_list *args)
{
	unsigned int n = va_arg(*args, unsigned int);
	int printed = print_unsigned_number(n);

	if (printed == -1)
		return (-1);
	return (printed);
}

