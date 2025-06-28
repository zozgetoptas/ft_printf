/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:16:52 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/27 12:54:12 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *__format, ...);
int	handle_char(va_list *args);
int	handle_str(va_list *args);
int	handle_ptr(va_list *args);
int	handle_number(va_list *args);
int	handle_unsigned(va_list *args);
int	handle_hexadecimal(va_list *args, int letter_case);
int	handle_percent(void);
int	print_hexadecimal(unsigned long n, int letter_case);
int	print_unsigned_number(unsigned int n);

#endif