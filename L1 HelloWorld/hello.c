#include <stdio.h>
#include "lib.h"

int main()
{
    int x = 5;
    int y = 3;
    int result = fun(x, y);
    printf("%d + %d = %d\n", x, y, result);
}