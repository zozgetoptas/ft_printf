/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:17:46 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 11:17:52 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_base(unsigned long long n, char *base)
{
    int base_len = ft_strlen(base);

    if (n >= (unsigned long long)base_len)
        ft_putnbr_base(n / base_len, base);
    ft_putchar_fd(base[n % base_len], 1);
}