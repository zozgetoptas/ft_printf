#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
 	char	*str = "zozgetoptas";
	char	c = 'a';
	void	*ptr = &str;
	int		d = -123;
	int		i = 13;
	unsigned int u = 4294967295;
	unsigned int hex = 305441741; // 0x1234ABCD
	int		ret1, ret2;

	// %c
	ret1 = ft_printf("ft: %%c = [%c]\n", c);
	ret2 = printf   ("og: %%c = [%c]\n", c);
	printf("Return ft: %d | Return og: %d\n\n", ret1, ret2);

	// %s
	ret1 = ft_printf("ft: %%s = [%s]\n", str);
	ret2 = printf   ("og: %%s = [%s]\n", str);
	printf("Return ft: %d | Return og: %d\n\n", ret1, ret2);

	// %p
	ret1 = ft_printf("ft: %%p = [%p]\n", ptr);
	ret2 = printf   ("og: %%p = [%p]\n", ptr);
	printf("Return ft: %d | Return og: %d\n\n", ret1, ret2);

	// %d / %i
	ret1 = ft_printf("ft: %%d/%%i = [%d] [%i]\n", d, i);
	ret2 = printf   ("og: %%d/%%i = [%d] [%i]\n", d, i);
	printf("Return ft: %d | Return og: %d\n\n", ret1, ret2);

	// %u
	ret1 = ft_printf("ft: %%u = [%u]\n", u);
	ret2 = printf   ("og: %%u = [%u]\n", u);
	printf("Return ft: %d | Return og: %d\n\n", ret1, ret2);

	// %x
	ret1 = ft_printf("ft: %%x = [%x]\n", hex);
	ret2 = printf   ("og: %%x = [%x]\n", hex);
	printf("Return ft: %d | Return og: %d\n\n", ret1, ret2);

	// %X
	ret1 = ft_printf("ft: %%X = [%X]\n", hex);
	ret2 = printf   ("og: %%X = [%X]\n", hex);
	printf("Return ft: %d | Return og: %d\n\n", ret1, ret2);

	// %%
	ret1 = ft_printf("ft: %% = [%%]\n");
	ret2 = printf   ("og: %% = [%%]\n");
	printf("Return ft: %d | Return og: %d\n\n", ret1, ret2);

	// NULL string
	ret1 = ft_printf("ft: NULL string = [%s]\n", (char *)NULL);
	ret2 = printf   ("og: NULL string = [%s]\n", (char *)NULL);
	printf("Return ft: %d | Return og: %d\n\n", ret1, ret2);

	// INT_MIN
	ret1 = ft_printf("ft: INT_MIN = [%d]\n", INT_MIN);
	ret2 = printf   ("og: INT_MIN = [%d]\n", INT_MIN);
	printf("Return ft: %d | Return og: %d\n\n", ret1, ret2);


}
