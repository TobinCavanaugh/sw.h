#include "sw.h"

int main(void)
{
    sw_memory_print_auto();

    // return 1;

    //Testing elapsed microseconds
    {
        double prev = sw_start_us();
        //...
        sw_print_us(prev);
    }

    //Testing elapsed milliseconds
    {
        double prev = sw_start_ms();
        //...
        double elapsed = sw_stop_ms(prev);
        printf("%fms elapsed!\n");
    }

    //Testing elapsed second
    {
        double prev = sw_start_s();
        //...
        sw_print_s(prev);
    }

    return 0;
}
