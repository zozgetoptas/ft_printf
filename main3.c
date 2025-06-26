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
    printf("\n=== FT_PRINTF KAPSAMLI TEST SÃœÄ°TÄ° ===\n\n");
    
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
    
    printf("=== TEST SÃœÄ°TÄ° TAMAMLANDI ===\n\n");
    return (0);
}

void test_char(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("%%c - KARAKTER TESTLERÄ°\n");
    printf("====================================================================\n");
    
    // Normal karakterler
    printf("---- Test 1: Normal Karakterler ----\n");
    original_ret = printf("Original: [%c]\n", 'A');
    my_ret = ft_printf("My Func : [%c]\n", 'A');
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%c]\n", 'z');
    my_ret = ft_printf("My Func : [%c]\n", 'z');
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // Ã–zel karakterler
    printf("---- Test 2: Ã–zel Karakterler ----\n");
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
    
    // ASCII deÄŸerleri
    printf("---- Test 4: ASCII DeÄŸerleri ----\n");
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
    printf("%%s - STRING TESTLERÄ°\n");
    printf("====================================================================\n");
    
    // Normal string
    printf("---- Test 1: Normal String ----\n");
    original_ret = printf("Original: [%s]\n", "Hello World");
    my_ret = ft_printf("My Func : [%s]\n", "Hello World");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // BoÅŸ string
    printf("---- Test 2: BoÅŸ String ----\n");
    original_ret = printf("Original: [%s]\n", "");
    my_ret = ft_printf("My Func : [%s]\n", "");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // NULL pointer
    printf("---- Test 3: NULL Pointer ----\n");
    original_ret = printf("Original: [%s]\n", null_str);
    my_ret = ft_printf("My Func : [%s]\n", null_str);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // Ã–zel karakterler iÃ§eren string
    printf("---- Test 4: Ã–zel Karakterler ----\n");
    original_ret = printf("Original: [%s]\n", "Hello\nWorld\t!");
    my_ret = ft_printf("My Func : [%s]\n", "Hello\nWorld\t!");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // Uzun string
    printf("---- Test 5: Uzun String ----\n");
    original_ret = printf("Original: [%s]\n", "Bu Ã§ok uzun bir string Ã¶rneÄŸidir ve performans testinde kullanÄ±lÄ±r");
    my_ret = ft_printf("My Func : [%s]\n", "Bu Ã§ok uzun bir string Ã¶rneÄŸidir ve performans testinde kullanÄ±lÄ±r");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_pointer(void)
{
    int original_ret, my_ret;
    int x = 42;
    char *str = "test";
    void *null_ptr = NULL;
    
    printf("====================================================================\n");
    printf("%%p - POINTER TESTLERÄ°\n");
    printf("====================================================================\n");
    
    // GeÃ§erli pointer
    printf("---- Test 1: GeÃ§erli Pointer ----\n");
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
    printf("%%d - DECIMAL TESTLERÄ°\n");
    printf("====================================================================\n");
    
    // Pozitif sayÄ±lar
    printf("---- Test 1: Pozitif SayÄ±lar ----\n");
    original_ret = printf("Original: [%d]\n", 42);
    my_ret = ft_printf("My Func : [%d]\n", 42);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%d]\n", 12345);
    my_ret = ft_printf("My Func : [%d]\n", 12345);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // Negatif sayÄ±lar
    printf("---- Test 2: Negatif SayÄ±lar ----\n");
    original_ret = printf("Original: [%d]\n", -42);
    my_ret = ft_printf("My Func : [%d]\n", -42);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%d]\n", -12345);
    my_ret = ft_printf("My Func : [%d]\n", -12345);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // SÄ±fÄ±r
    printf("---- Test 3: SÄ±fÄ±r ----\n");
    original_ret = printf("Original: [%d]\n", 0);
    my_ret = ft_printf("My Func : [%d]\n", 0);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    // SÄ±nÄ±r deÄŸerleri
    printf("---- Test 4: SÄ±nÄ±r DeÄŸerleri ----\n");
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
    printf("%%i - INTEGER TESTLERÄ°\n");
    printf("====================================================================\n");
    
    // %i ve %d aynÄ± ÅŸekilde Ã§alÄ±ÅŸÄ±r
    printf("---- Test 1: Pozitif SayÄ±lar ----\n");
    original_ret = printf("Original: [%i]\n", 42);
    my_ret = ft_printf("My Func : [%i]\n", 42);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: Negatif SayÄ±lar ----\n");
    original_ret = printf("Original: [%i]\n", -42);
    my_ret = ft_printf("My Func : [%i]\n", -42);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: SÄ±fÄ±r ----\n");
    original_ret = printf("Original: [%i]\n", 0);
    my_ret = ft_printf("My Func : [%i]\n", 0);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 4: SÄ±nÄ±r DeÄŸerleri ----\n");
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
    printf("%%u - UNSIGNED TESTLERÄ°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: Pozitif SayÄ±lar ----\n");
    original_ret = printf("Original: [%u]\n", 42U);
    my_ret = ft_printf("My Func : [%u]\n", 42U);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%u]\n", 4294967295U);
    my_ret = ft_printf("My Func : [%u]\n", 4294967295U);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: SÄ±fÄ±r ----\n");
    original_ret = printf("Original: [%u]\n", 0U);
    my_ret = ft_printf("My Func : [%u]\n", 0U);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: Negatif SayÄ± (Unsigned Cast) ----\n");
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
    printf("%%x - HEXADECIMAL LOWERCASE TESTLERÄ°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: KÃ¼Ã§Ã¼k SayÄ±lar ----\n");
    original_ret = printf("Original: [%x]\n", 0);
    my_ret = ft_printf("My Func : [%x]\n", 0);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%x]\n", 10);
    my_ret = ft_printf("My Func : [%x]\n", 10);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%x]\n", 255);
    my_ret = ft_printf("My Func : [%x]\n", 255);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: BÃ¼yÃ¼k SayÄ±lar ----\n");
    original_ret = printf("Original: [%x]\n", 3735928559);
    my_ret = ft_printf("My Func : [%x]\n", 3735928559);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: Negatif SayÄ± (Unsigned Cast) ----\n");
    original_ret = printf("Original: [%x]\n", (unsigned int)-1);
    my_ret = ft_printf("My Func : [%x]\n", (unsigned int)-1);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_hex_upper(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("%%X - HEXADECIMAL UPPERCASE TESTLERÄ°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: KÃ¼Ã§Ã¼k SayÄ±lar ----\n");
    original_ret = printf("Original: [%X]\n", 0);
    my_ret = ft_printf("My Func : [%X]\n", 0);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%X]\n", 10);
    my_ret = ft_printf("My Func : [%X]\n", 10);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    original_ret = printf("Original: [%X]\n", 255);
    my_ret = ft_printf("My Func : [%X]\n", 255);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: BÃ¼yÃ¼k SayÄ±lar ----\n");
    original_ret = printf("Original: [%X]\n", 3735928559);
    my_ret = ft_printf("My Func : [%X]\n", 3735928559);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: Negatif SayÄ± (Unsigned Cast) ----\n");
    original_ret = printf("Original: [%X]\n", (unsigned int)-1);
    my_ret = ft_printf("My Func : [%X]\n", (unsigned int)-1);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_percent(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("%%%% - YÃœZDE Ä°ÅARETÄ° TESTLERÄ°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: Tek YÃ¼zde Ä°ÅŸareti ----\n");
    original_ret = printf("Original: [%%]\n");
    my_ret = ft_printf("My Func : [%%]\n");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: Ã‡oklu YÃ¼zde Ä°ÅŸareti ----\n");
    original_ret = printf("Original: [%%%%%%]\n");
    my_ret = ft_printf("My Func : [%%%%%%]\n");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: YÃ¼zde Ä°ÅŸareti Metinle ----\n");
    original_ret = printf("Original: 100%% baÅŸarÄ± oranÄ±!\n");
    my_ret = ft_printf("My Func : 100%% baÅŸarÄ± oranÄ±!\n");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_mixed(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("KARMA TESTLERÄ°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: Ã‡oklu Format Specifier ----\n");
    original_ret = printf("Original: Karakter: %c, String: %s, SayÄ±: %d\n", 'A', "test", 42);
    my_ret = ft_printf("My Func : Karakter: %c, String: %s, SayÄ±: %d\n", 'A', "test", 42);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: TÃ¼m Format Specifier'lar ----\n");
    original_ret = printf("Original: %c|%s|%p|%d|%i|%u|%x|%X|%%\n", 'X', "hello", &original_ret, -42, 42, 42U, 255, 255);
    my_ret = ft_printf("My Func : %c|%s|%p|%d|%i|%u|%x|%X|%%\n", 'X', "hello", &my_ret, -42, 42, 42U, 255, 255);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: Kompleks Metin ----\n");
    original_ret = printf("Original: Ä°sim: %s, YaÅŸ: %d, Adres: %p, MaaÅŸ: %u TL (%x hex)\n", "Ahmet", 25, &original_ret, 5000U, 5000);
    my_ret = ft_printf("My Func : Ä°sim: %s, YaÅŸ: %d, Adres: %p, MaaÅŸ: %u TL (%x hex)\n", "Ahmet", 25, &my_ret, 5000U, 5000);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}

void test_edge_cases(void)
{
    int original_ret, my_ret;
    
    printf("====================================================================\n");
    printf("EDGE CASE TESTLERÄ°\n");
    printf("====================================================================\n");
    
    printf("---- Test 1: BoÅŸ String ----\n");
    original_ret = printf("");
    my_ret = ft_printf("");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 2: Sadece Metin (Format Yok) ----\n");
    original_ret = printf("Original: Bu sadece dÃ¼z metindir.\n");
    my_ret = ft_printf("My Func : Bu sadece dÃ¼z metindir.\n");
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 3: ArdÄ±ÅŸÄ±k Format Specifier'lar ----\n");
    original_ret = printf("Original: %d%d%d%d\n", 1, 2, 3, 4);
    my_ret = ft_printf("My Func : %d%d%d%d\n", 1, 2, 3, 4);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 4: Ã‡ok SayÄ±da ArgÃ¼man ----\n");
    original_ret = printf("Original: %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    my_ret = ft_printf("My Func : %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
    
    printf("---- Test 5: Null Byte Karakteri ----\n");
    original_ret = printf("Original: Before null%cAfter null\n", '\0');
    my_ret = ft_printf("My Func : Before null%cAfter null\n", '\0');
    printf("Return -> Original: %d, My Func: %d\n\n", original_ret, my_ret);
}