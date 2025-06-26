/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:41:49 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 11:29:09 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int handle_ptr(va_list *args)
{
    void *ptr = va_arg(*args, void *);

    if (ptr == NULL)
        return write(1, "(nil)", 5);

    int len = 0;
    len += write(1, "0x", 2);
    len += print_hexadecimal((unsigned long)ptr, 1);

    return (len);
}

