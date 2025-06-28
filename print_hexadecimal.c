/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:10:28 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/27 13:04:59 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_hexadecimal(unsigned long n, int letter_case)
{
	char	*digits;
	int		count;
	char	c;
	int		ret;

	count = 0;
	if (letter_case)
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	if (n >= 16)
	{
		ret = print_hexadecimal(n / 16, letter_case);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = digits[n % 16];
	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
