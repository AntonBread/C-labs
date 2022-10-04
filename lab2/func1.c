#include <stdarg.h>

double func1(int n, ...)
{
    int sum = 0;
    int i;
    va_list ptr;
    va_start(ptr, n);
    
    for (i = 0; i < n; i++)
    {
        sum += va_arg(ptr, int);
    }
    va_end(ptr);
    
    return (double)sum / n;
}
