/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:41:49 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/27 12:59:01 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	handle_ptr(va_list *args)
{
	void	*ptr;
	int		len;

	ptr = va_arg(*args, void *);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	len = 0;
	len += write(1, "0x", 2);
	len += print_hexadecimal((unsigned long)ptr, 1);
	return (len);
}
