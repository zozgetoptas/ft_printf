/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:18:18 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 11:18:25 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_num_len_base(unsigned long long n, int base_len)
{
    int			len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}