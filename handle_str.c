/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:40:32 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 10:53:13 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int handle_str(va_list *args)
{
	char *str = va_arg(*args, char *);
	int len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	if (write(1, str, len) == -1)
        return (-1);
    return (len);
}