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
	int		ret;

	ptr = va_arg(*args, void *);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	len = 0;
	ret = write(1, "0x", 2);
	if (ret == -1)
		return (-1);
	len += ret;
	ret = print_hexadecimal((unsigned long)ptr, 1);
	if (ret == -1)
		return (-1);
	len += ret;
	return (len);
}
