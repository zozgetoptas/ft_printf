/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:42:42 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 10:54:03 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int handle_hexadecimal(va_list *args, int lowercase)
{
    unsigned int n = va_arg(*args, unsigned int);

    if (n == 0)
        return write(1, "0", 1);

    return print_hexadecimal(n, lowercase);
}
