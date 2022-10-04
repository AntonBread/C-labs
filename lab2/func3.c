#include <math.h>

double func3(double (*expression)(double, double, double), double x, double y, double z)
{
    return expression(x, y, z);
}

double calculateLab1(double x, double y, double z)
{
    return sqrt(z*(sqrt(y) + x*x)) * (log(fabs(x)) - fabs(z - y));
}
