#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int ret1, ret2;

	// %c testleri
	ret1 = ft_printf("FT: Char test -> [%c]\n", 'A');
	ret2 = printf("OG: Char test -> [%c]\n", 'A');
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	ret1 = ft_printf("FT: Char null -> [%c]\n", 0);
	ret2 = printf("OG: Char null -> [%c]\n", 0);
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	// %s testleri
	ret1 = ft_printf("FT: Str test -> [%s]\n", "hello");
	ret2 = printf("OG: Str test -> [%s]\n", "hello");
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	ret1 = ft_printf("FT: Null str test -> [%s]\n", NULL);
	ret2 = printf("OG: Null str test -> [%s]\n", NULL);
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	// %d / %i testleri
	ret1 = ft_printf("FT: Number -> [%d] [%i]\n", 42, -42);
	ret2 = printf("OG: Number -> [%d] [%i]\n", 42, -42);
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	ret1 = ft_printf("FT: INT_MIN -> [%d]\n", -2147483648);
	ret2 = printf("OG: INT_MIN -> [%d]\n", -2147483648);
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	// %u testleri
	ret1 = ft_printf("FT: Unsigned -> [%u]\n", 3000000000u);
	ret2 = printf("OG: Unsigned -> [%u]\n", 3000000000u);
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	// %x / %X testleri
	ret1 = ft_printf("FT: Hex -> [%x] [%X]\n", 255, 255);
	ret2 = printf("OG: Hex -> [%x] [%X]\n", 255, 255);
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	// %p testleri
	void *ptr = (void *)0x1234abcd;
	ret1 = ft_printf("FT: Pointer -> [%p]\n", ptr);
	ret2 = printf("OG: Pointer -> [%p]\n", ptr);
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	// % test
	ret1 = ft_printf("FT: Percent -> [%%]\n");
	ret2 = printf("OG: Percent -> [%%]\n");
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	// Geçersiz format
	ret1 = ft_printf("FT: Invalid specifier -> [%q]\n");
	ret2 = printf("OG: Invalid specifier -> [%q]\n");
	printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

	return (0);
}
