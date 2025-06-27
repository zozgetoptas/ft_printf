/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:40:32 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/27 12:59:57 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	handle_str(va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	if (write(1, str, len) == -1)
		return (-1);
	return (len);
}
