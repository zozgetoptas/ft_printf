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

void handle_unsigned(va_list *args, int *total_len)
{
	unsigned int n = va_arg(*args, unsigned int);
	(*total_len) += printed_unsigned_count(n);
}
