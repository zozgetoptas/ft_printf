/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:31:20 by ztoptas           #+#    #+#             */
/*   Updated: 2025/06/24 11:34:11 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    /* char c = 'a';
    char *str = "zozgetoptas";
    void *ptr = (void *)str;
    int d = -3;
    int i = 23;
    unsigned int u = 3000000000;
    int x = 255;
    int X = 48879;

	ft_printf("benimki:\n");
    ft_printf("char: %c\n", c);
    ft_printf("str: %s\n", str);
    ft_printf("pointer: %p\n", ptr);
    ft_printf("decimal: %d\n", d);
    ft_printf("int: %i\n", i);
    ft_printf("unsigned: %u\n", u);
    ft_printf("hexadecimal (lower): %x\n", x);
    ft_printf("hexadecimal (upper): %X\n", X);
    ft_printf("percent: %%\n\n");

	printf("orijinal:\n");
    printf("char: %c\n", c);
    printf("str: %s\n", str);
    printf("pointer: %p\n", ptr);
    printf("decimal: %d\n", d);
    printf("int: %i\n", i);
    printf("unsigned: %u\n", u);
    printf("hexadecimal (lower): %x\n", x);
    printf("hexadecimal (upper): %X\n", X);
    printf("percent: %%\n"); */
    ft_printf("%q\n");
    printf("%q");
	

    return 0;
}