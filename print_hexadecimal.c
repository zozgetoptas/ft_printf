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

    if (lowercase)
    digits = "0123456789abcdef";
    else
    digits = "0123456789ABCDEF";

    if (n >= 16)
        return print_hexadecimal(n / 16, lowercase) + write(1, &digits[n % 16], 1);
    else
        return write(1, &digits[n], 1);
}