#include <stdlib.h>
#include "utils.h"

int RandomInteger(int a, int b)
{
    int k;
    double d;
    d = (double)rand() / ((double)RAND_MAX + 1);
    k = d * (b - a + 1);
    return a + k;
}