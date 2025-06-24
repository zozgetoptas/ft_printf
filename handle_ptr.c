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

void handle_ptr(va_list *args, int *total_len)
{
	void *ptr = va_arg(*args, void *);

	if (ptr == NULL)
    {
        ft_putstr_fd("(nil)", 1);
        *total_len += 5;
    }
    else
    {
        unsigned long long addr = (unsigned long long)ptr;
        int len;

        ft_putstr_fd("0x", 1);
        ft_putnbr_base(addr, "0123456789abcdef");
        
        len = ft_num_len_base(addr, 16) + 2;
        *total_len += len;
    }
}

