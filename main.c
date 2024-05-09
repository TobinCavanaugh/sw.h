#include "stopwatch.h"

int main(void)
{
    double prev = sw_start_ms();
    //...
    sw_print_ms(prev);


    return 0;
}
