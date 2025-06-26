/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:38:18 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 10:53:23 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	handle_char(va_list *args)
{
	char c = (char)va_arg(*args, int);
	 if (write(1, &c, 1) == -1)
        return (-1);
    return (1);
}