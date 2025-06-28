/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:42:42 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/27 12:56:35 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	handle_hexadecimal(va_list *args, int letter_case)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	return (print_hexadecimal(n, letter_case));
}
