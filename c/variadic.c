#include <stdio.h>
#include <stdarg.h>

int  sum (int count,...) {
    va_list args;
    int i, sum;

    va_start (args, count);

    sum = 0;
    for (i = 0; i < count; i++)
        sum += va_arg (args, int);

    va_end (args);
    return sum;
}

int main() {
    printf("SUM: %d\n", sum(3, 3, 2, 3));
}
