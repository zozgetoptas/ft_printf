/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:05:07 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/27 13:05:07 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_unsigned_number(unsigned int n)
{
	int		printed;
	int		ret;
	char	c;

	printed = 0;
	if (n >= 10)
	{
		ret = print_unsigned_number(n / 10);
		if (ret == -1)
			return (-1);
		printed += ret;
	}
	c = (n % 10) + '0';
	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	printed += ret;
	return (printed);
}
