/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:16:52 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/23 16:16:58 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *__format, ...);
int		prt_str(char const *str);
int		prt_ptr(void *ptr_addr);
int		prt_int(int n);
int		prt_unsigned(unsigned int nbr);
int		prt_hexa(unsigned int nbr, bool upper_case);

#endif