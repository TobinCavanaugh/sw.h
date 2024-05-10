#include "sw.h"

int main(void)
{
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

    {
        sw_memory_print_auto();
        sw_memory_print_auto();
    }

    {
        double sizegb = sw_memory_size_gb();
        printf("%.5fgb\n", sizegb);
    }

    {
        sw_memory_print_kb();
    }

    return 0;
}
