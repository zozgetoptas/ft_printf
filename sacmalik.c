#include <stdarg.h>
#include <stdio.h>
int sum(const char *format, ...)
{
    va_list args;
    int i;

    i = 0;
    int sum = 0;

    va_start(args,format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'd')
            {
                sum += va_arg(args, int);
            }
            else
            {
                (void)va_arg(args, void *);
            }
        }
        i++;
    }
va_end(args);
printf("%d",sum);
return (sum);
}
int main()
{
    sum("%d %i %s %d", 23, 1, "ed", 4);
}