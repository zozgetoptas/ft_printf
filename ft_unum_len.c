/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unum_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:20:39 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 11:20:41 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_unum_len(unsigned int n)
{
    int			len;
	unsigned long long	temp_n;

	len = 0;
	if (n == 0)
		return (1);
	temp_n = n;
	while (temp_n > 0)
	{
		temp_n /= 10;
		len++;
	}
	return (len);
}