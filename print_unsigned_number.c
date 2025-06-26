#include <unistd.h>

int print_unsigned_number(unsigned int n)
{
	int printed = 0;
	int ret;
	char c;

	if (n >= 10)
	{
		ret = print_unsigned_number(n / 10);
		if (ret == -1)
			return (-1);
		printed += ret;
	}
	c = (n % 10) + '0';
	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	printed += ret;
    return (printed);
}
