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

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

# define HEX_UPPER_BASE "0123456789ABCDEF"
# define HEX_LOWER_BASE "0123456789abcdef"

int		ft_printf(const char *__format, ...);
int print_hexadecimal(unsigned long n, int lowercase);
int  printed_char_count(char *str);
int printed_int_count(int n);
int printed_unsigned_count(unsigned int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
void	handle_char(va_list *args, int *total_len);
void	handle_str(va_list *args, int *total_len);
void	handle_ptr(va_list *args, int *total_len);
void	handle_number(va_list *args, int *total_len);
void	handle_unsigned(va_list *args, int *total_len);
void	handle_hexadecimal(va_list *args, int lowercase, int *total_len);
void	handle_percent(int *total_len);
void ft_putnbr_base(unsigned long long n, char *base);
void ft_putunbr_fd(unsigned int n, int fd);
int ft_unum_len(unsigned int n);
int ft_num_len_base(unsigned long long n, int base_len);

#endif