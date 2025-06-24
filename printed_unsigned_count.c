/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_unsigned_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:09:29 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 10:52:11 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printed_unsigned_count(unsigned int n)
{
	int printed = 0;
	char c;

	if (n >= 10)
		printed += printed_unsigned_count(n / 10);
	c = (n % 10) + '0';
	printed += write(1, &c, 1);
	return printed;
}