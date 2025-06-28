#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "ft_printf.h"

// Test fonksiyonu prototipleri
void test_char(void);
void test_string(void);
void test_pointer(void);
void test_decimal(void);
void test_integer(void);
void test_unsigned(void);
void test_hex_lower(void);
void test_hex_upper(void);
void test_percent(void);
void test_mixed(void);
void test_edge_cases(void);

int main(void)
{
    printf("\n=== FT_PRINTF KAPSAMLI TEST SÃƒÅ“Ã„Â°TÃ„Â° ===\n\n");
    
    test_char();
    test_string();
    test_pointer();
    test_decimal();
    test_integer();
    test_unsigned();
    test_hex_lower();
    test_hex_upper();
    test_percent();
    test_mixed();
    test_edge_cases();
    
    printf("=== TEST SÃƒÅ“Ã„Â°TÃ„Â° TAMAMLANDI ===\n\n");
    return (0);
}

void test_char(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("%%c - KARAKTER TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    // Normal karakterler
    printf("---- Test 1: Normal Karakterler ----\n");
    original_ret = printf("Original: [%c]\n", 'A');
    my_ret = ft_printf("My Func : [%c]\n", 'A');
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%c]\n", 'z');
    my_ret = ft_printf("My Func : [%c]\n", 'z');
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // Ãƒâ€“zel karakterler
    printf("---- Test 2: Ãƒâ€“zel Karakterler ----\n");
    original_ret = printf("Original: [%c]\n", '\n');
    my_ret = ft_printf("My Func : [%c]\n", '\n');
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%c]\n", '\t');
    my_ret = ft_printf("My Func : [%c]\n", '\t');
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // Null karakter
    printf("---- Test 3: Null Karakter ----\n");
    original_ret = printf("Original: [%c]\n", '\0');
    my_ret = ft_printf("My Func : [%c]\n", '\0');
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // ASCII deÃ„Å¸erleri
    printf("---- Test 4: ASCII DeÃ„Å¸erleri ----\n");
    original_ret = printf("Original: [%c]\n", 32); // Space
    my_ret = ft_printf("My Func : [%c]\n", 32);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%c]\n", 126); // ~
    my_ret = ft_printf("My Func : [%c]\n", 126);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_string(void)
{
    int original_ret, my_ret;
    char *null_str = NULL;
    
    printf("====================================================================\n");
    printf("%%s - STRING TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    // Normal string
    printf("---- Test 1: Normal String ----\n");
    original_ret = printf("Original: [%s]\n", "Hello World");
    my_ret = ft_printf("My Func : [%s]\n", "Hello World");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // BoÃ…Å¸ string
    printf("---- Test 2: BoÃ…Å¸ String ----\n");
    original_ret = printf("Original: [%s]\n", "");
    my_ret = ft_printf("My Func : [%s]\n", "");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // NULL pointer
    printf("---- Test 3: NULL Pointer ----\n");
    original_ret = printf("Original: [%s]\n", null_str);
    my_ret = ft_printf("My Func : [%s]\n", null_str);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // Ãƒâ€“zel karakterler iÃƒÂ§eren string
    printf("---- Test 4: Ãƒâ€“zel Karakterler ----\n");
    original_ret = printf("Original: [%s]\n", "Hello\nWorld\t!");
    my_ret = ft_printf("My Func : [%s]\n", "Hello\nWorld\t!");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // Uzun string
    printf("---- Test 5: Uzun String ----\n");
    original_ret = printf("Original: [%s]\n", "Bu ÃƒÂ§ok uzun bir string ÃƒÂ¶rneÃ„Å¸idir ve performans testinde kullanÃ„Â±lÃ„Â±r");
    my_ret = ft_printf("My Func : [%s]\n", "Bu ÃƒÂ§ok uzun bir string ÃƒÂ¶rneÃ„Å¸idir ve performans testinde kullanÃ„Â±lÃ„Â±r");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_pointer(void)
{
    int original_ret, my_ret;
    int x = 42;
    char *str = "test";
    void *null_ptr = NULL;
    
    printf("====================================================================\n");
    printf("%%p - POINTER TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    // GeÃƒÂ§erli pointer
    printf("---- Test 1: GeÃƒÂ§erli Pointer ----\n");
    original_ret = printf("Original: [%p]\n", &x);
    my_ret = ft_printf("My Func : [%p]\n", &x);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // String pointer
    printf("---- Test 2: String Pointer ----\n");
    original_ret = printf("Original: [%p]\n", str);
    my_ret = ft_printf("My Func : [%p]\n", str);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // NULL pointer
    printf("---- Test 3: NULL Pointer ----\n");
    original_ret = printf("Original: [%p]\n", null_ptr);
    my_ret = ft_printf("My Func : [%p]\n", null_ptr);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // Fonksiyon pointer
    printf("---- Test 4: Fonksiyon Pointer ----\n");
    original_ret = printf("Original: [%p]\n", &test_pointer);
    my_ret = ft_printf("My Func : [%p]\n", &test_pointer);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_decimal(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("%%d - DECIMAL TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    // Pozitif sayÃ„Â±lar
    printf("---- Test 1: Pozitif SayÃ„Â±lar ----\n");
    original_ret = printf("Original: [%d]\n", 42);
    my_ret = ft_printf("My Func : [%d]\n", 42);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%d]\n", 12345);
    my_ret = ft_printf("My Func : [%d]\n", 12345);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // Negatif sayÃ„Â±lar
    printf("---- Test 2: Negatif SayÃ„Â±lar ----\n");
    original_ret = printf("Original: [%d]\n", -42);
    my_ret = ft_printf("My Func : [%d]\n", -42);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%d]\n", -12345);
    my_ret = ft_printf("My Func : [%d]\n", -12345);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // SÃ„Â±fÃ„Â±r
    printf("---- Test 3: SÃ„Â±fÃ„Â±r ----\n");
    original_ret = printf("Original: [%d]\n", 0);
    my_ret = ft_printf("My Func : [%d]\n", 0);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // SÃ„Â±nÃ„Â±r deÃ„Å¸erleri
    printf("---- Test 4: SÃ„Â±nÃ„Â±r DeÃ„Å¸erleri ----\n");
    original_ret = printf("Original: [%d]\n", INT_MAX);
    my_ret = ft_printf("My Func : [%d]\n", INT_MAX);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%d]\n", INT_MIN);
    my_ret = ft_printf("My Func : [%d]\n", INT_MIN);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_integer(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("%%i - INTEGER TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    // %i ve %d aynÃ„Â± Ã…Å¸ekilde ÃƒÂ§alÃ„Â±Ã…Å¸Ã„Â±r
    printf("---- Test 1: Pozitif SayÃ„Â±lar ----\n");
    original_ret = printf("Original: [%i]\n", 42);
    my_ret = ft_printf("My Func : [%i]\n", 42);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: Negatif SayÃ„Â±lar ----\n");
    original_ret = printf("Original: [%i]\n", -42);
    my_ret = ft_printf("My Func : [%i]\n", -42);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: SÃ„Â±fÃ„Â±r ----\n");
    original_ret = printf("Original: [%i]\n", 0);
    my_ret = ft_printf("My Func : [%i]\n", 0);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 4: SÃ„Â±nÃ„Â±r DeÃ„Å¸erleri ----\n");
    original_ret = printf("Original: [%i]\n", INT_MAX);
    my_ret = ft_printf("My Func : [%i]\n", INT_MAX);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%i]\n", INT_MIN);
    my_ret = ft_printf("My Func : [%i]\n", INT_MIN);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_unsigned(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("%%u - UNSIGNED TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: Pozitif SayÃ„Â±lar ----\n");
    original_ret = printf("Original: [%u]\n", 42U);
    my_ret = ft_printf("My Func : [%u]\n", 42U);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%u]\n", 4294967295U);
    my_ret = ft_printf("My Func : [%u]\n", 4294967295U);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: SÃ„Â±fÃ„Â±r ----\n");
    original_ret = printf("Original: [%u]\n", 0U);
    my_ret = ft_printf("My Func : [%u]\n", 0U);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: Negatif SayÃ„Â± (Unsigned Cast) ----\n");
    original_ret = printf("Original: [%u]\n", (unsigned int)-1);
    my_ret = ft_printf("My Func : [%u]\n", (unsigned int)-1);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 4: UINT_MAX ----\n");
    original_ret = printf("Original: [%u]\n", UINT_MAX);
    my_ret = ft_printf("My Func : [%u]\n", UINT_MAX);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_hex_lower(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("%%x - HEXADECIMAL LOWERCASE TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: KÃƒÂ¼ÃƒÂ§ÃƒÂ¼k SayÃ„Â±lar ----\n");
    original_ret = printf("Original: [%x]\n", 0);
    my_ret = ft_printf("My Func : [%x]\n", 0);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%x]\n", 10);
    my_ret = ft_printf("My Func : [%x]\n", 10);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%x]\n", 255);
    my_ret = ft_printf("My Func : [%x]\n", 255);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: BÃƒÂ¼yÃƒÂ¼k SayÃ„Â±lar ----\n");
    original_ret = printf("Original: [%x]\n", 3735928559);
    my_ret = ft_printf("My Func : [%x]\n", 3735928559);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: Negatif SayÃ„Â± (Unsigned Cast) ----\n");
    original_ret = printf("Original: [%x]\n", (unsigned int)-1);
    my_ret = ft_printf("My Func : [%x]\n", (unsigned int)-1);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_hex_upper(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("%%X - HEXADECIMAL UPPERCASE TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: KÃƒÂ¼ÃƒÂ§ÃƒÂ¼k SayÃ„Â±lar ----\n");
    original_ret = printf("Original: [%X]\n", 0);
    my_ret = ft_printf("My Func : [%X]\n", 0);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%X]\n", 10);
    my_ret = ft_printf("My Func : [%X]\n", 10);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%X]\n", 255);
    my_ret = ft_printf("My Func : [%X]\n", 255);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: BÃƒÂ¼yÃƒÂ¼k SayÃ„Â±lar ----\n");
    original_ret = printf("Original: [%X]\n", 3735928559);
    my_ret = ft_printf("My Func : [%X]\n", 3735928559);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: Negatif SayÃ„Â± (Unsigned Cast) ----\n");
    original_ret = printf("Original: [%X]\n", (unsigned int)-1);
    my_ret = ft_printf("My Func : [%X]\n", (unsigned int)-1);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_percent(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("%%%% - YÃƒÅ“ZDE Ã„Â°Ã…ÂARETÃ„Â° TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: Tek YÃƒÂ¼zde Ã„Â°Ã…Å¸areti ----\n");
    original_ret = printf("Original: [%%]\n");
    my_ret = ft_printf("My Func : [%%]\n");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: Ãƒâ€¡oklu YÃƒÂ¼zde Ã„Â°Ã…Å¸areti ----\n");
    original_ret = printf("Original: [%%%%%%]\n");
    my_ret = ft_printf("My Func : [%%%%%%]\n");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: YÃƒÂ¼zde Ã„Â°Ã…Å¸areti Metinle ----\n");
    original_ret = printf("Original: 100%% baÃ…Å¸arÃ„Â± oranÃ„Â±!\n");
    my_ret = ft_printf("My Func : 100%% baÃ…Å¸arÃ„Â± oranÃ„Â±!\n");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_mixed(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("KARMA TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: Ãƒâ€¡oklu Format Specifier ----\n");
    original_ret = printf("Original: Karakter: %c, String: %s, SayÃ„Â±: %d\n", 'A', "test", 42);
    my_ret = ft_printf("My Func : Karakter: %c, String: %s, SayÃ„Â±: %d\n", 'A', "test", 42);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: TÃƒÂ¼m Format Specifier'lar ----\n");
    original_ret = printf("Original: %c|%s|%p|%d|%i|%u|%x|%X|%%\n", 'X', "hello", &original_ret, -42, 42, 42U, 255, 255);
    my_ret = ft_printf("My Func : %c|%s|%p|%d|%i|%u|%x|%X|%%\n", 'X', "hello", &my_ret, -42, 42, 42U, 255, 255);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: Kompleks Metin ----\n");
    original_ret = printf("Original: Ã„Â°sim: %s, YaÃ…Å¸: %d, Adres: %p, MaaÃ…Å¸: %u TL (%x hex)\n", "Ahmet", 25, &original_ret, 5000U, 5000);
    my_ret = ft_printf("My Func : Ã„Â°sim: %s, YaÃ…Å¸: %d, Adres: %p, MaaÃ…Å¸: %u TL (%x hex)\n", "Ahmet", 25, &my_ret, 5000U, 5000);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_edge_cases(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("EDGE CASE TESTLERÃ„Â°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: BoÃ…Å¸ String ----\n");
    original_ret = printf("");
    my_ret = ft_printf("");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: Sadece Metin (Format Yok) ----\n");
    original_ret = printf("Original: Bu sadece dÃƒÂ¼z metindir.\n");
    my_ret = ft_printf("My Func : Bu sadece dÃƒÂ¼z metindir.\n");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: ArdÃ„Â±Ã…Å¸Ã„Â±k Format Specifier'lar ----\n");
    original_ret = printf("Original: %d%d%d%d\n", 1, 2, 3, 4);
    my_ret = ft_printf("My Func : %d%d%d%d\n", 1, 2, 3, 4);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 4: Ãƒâ€¡ok SayÃ„Â±da ArgÃƒÂ¼man ----\n");
    original_ret = printf("Original: %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    my_ret = ft_printf("My Func : %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 5: Null Byte Karakteri ----\n");
    original_ret = printf("Original: Before null%cAfter null\n", '\0');
    my_ret = ft_printf("My Func : Before null%cAfter null\n", '\0');
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}