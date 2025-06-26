#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;
    int n = -42;
    unsigned int u = 4294967295;
    char *str = "hello";
    char *null_str = NULL;
    void *ptr = &n;
    void *null_ptr = NULL;

   // 1. Basit string
    ret1 = ft_printf("FT: Hello, %s!\n", str);
    ret2 = printf("OG: Hello, %s!\n", str);
    printf("Return: ft_printf=%d | printf=%d\n\n", ret1, ret2);

    // 2. Null string
    ret1 = ft_printf("FT: Null string: %s\n", null_str);
    ret2 = printf("OG: Null string: %s\n", null_str);
    printf("Return: ft_printf=%d | printf=%d\n\n", ret1, ret2);

    // 3. Integer, negatif değer
    ret1 = ft_printf("FT: Number: %d\n", n);
    ret2 = printf("OG: Number: %d\n", n);
    printf("Return: ft_printf=%d | printf=%d\n\n", ret1, ret2);

    // 4. Unsigned max
    ret1 = ft_printf("FT: Unsigned: %u\n", u);
    ret2 = printf("OG: Unsigned: %u\n", u);
    printf("Return: ft_printf=%d | printf=%d\n\n", ret1, ret2);

    // 5. Hexadecimal (lowercase)
    ret1 = ft_printf("FT: Hex: %x\n", u);
    ret2 = printf("OG: Hex: %x\n", u);
    printf("Return: ft_printf=%d | printf=%d\n\n", ret1, ret2);

    // 6. Hexadecimal (uppercase)
    ret1 = ft_printf("FT: Hex: %X\n", u);
    ret2 = printf("OG: Hex: %X\n", u);
    printf("Return: ft_printf=%d | printf=%d\n\n", ret1, ret2);

    // 7. Pointer (valid)
    ret1 = ft_printf("FT: Pointer: %p\n", ptr);
    ret2 = printf("OG: Pointer: %p\n", ptr);
    printf("Return: ft_printf=%d | printf=%d\n\n", ret1, ret2);

    // 8. Pointer (null)
    ret1 = ft_printf("FT: Null pointer: %p\n", null_ptr);
    ret2 = printf("OG: Null pointer: %p\n", null_ptr);
    printf("Return: ft_printf=%d | printf=%d\n\n", ret1, ret2);

    // 9. Karakter ve yüzde
    ret1 = ft_printf("FT: Char: %c %%\n", 'A');
    ret2 = printf("OG: Char: %c %%\n", 'A');
    printf("Return: ft_printf=%d | printf=%d\n\n", ret1, ret2);
 
    // 10. Bilinmeyen format
    ret1 = ft_printf("FT: Unknown specifier: %q\n");
    ret2 = printf("OG: Unknown specifier: %q\n");
    printf("Return: ft_printf=%d | printf=%d\n\n", ret1, ret2);
 
    return 0;
}
