/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:10:28 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 10:10:37 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int print_hexadecimal(unsigned long n, int lowercase)
{
    char *digits;
    int count = 0;

    if (lowercase)
        digits = "0123456789abcdef";
    else
        digits = "0123456789ABCDEF";

    if (n >= 16)
        count += print_hexadecimal(n / 16, lowercase);
    char c = digits[n % 16];
    count += write(1, &c, 1);

    return (count);
}
