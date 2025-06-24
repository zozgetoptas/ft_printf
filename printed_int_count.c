/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_int_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:09:00 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 11:05:26 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int printed_int_count(int n)
{
    int printed = 0;
    char c;

    if (n == -2147483648)
        return write(1, "-2147483648", 11);

    if (n < 0)
    {
        printed += write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        printed += printed_int_count(n / 10);
    c = (n % 10) + '0';
    printed += write(1, &c, 1);

    return (printed);
}