/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:20:14 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 11:20:16 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putunbr_fd(unsigned int n, int fd)
{
    unsigned long	num;

	num = n;
	if (num >= 10)
		ft_putunbr_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}