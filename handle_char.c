/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:38:18 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 10:53:23 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(va_list *args, int *total_len)
{
	char c = (char)va_arg(*args, int);
	ft_putchar_fd(c, 1);
	(*total_len)++;
}