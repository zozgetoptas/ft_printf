/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:16:52 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 11:28:34 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>


# define HEX_UPPER_BASE "0123456789ABCDEF"
# define HEX_LOWER_BASE "0123456789abcdef"

int	ft_printf(const char *__format, ...);
int handle_char(va_list *args);
int handle_str(va_list *args);
int handle_ptr(va_list *args);
int handle_number(va_list *args);
int handle_unsigned(va_list *args);
int handle_hexadecimal(va_list *args, int lowercase);
int handle_percent(void);
int print_hexadecimal(unsigned long n, int lowercase);
int print_unsigned_number(unsigned int n);

#endif