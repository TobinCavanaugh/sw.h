# SW : A simple C stopwatch for benchmarking
#### Clarity rejects verbosity

No more `time_t` or `timeval`. They have their place, but 99% of the time you want to time something, they just get in they way.

### Example
```C
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

    //Testing elapsed seconds
    {
        double prev = sw_start_s();
        //...
        sw_print_s(prev);
    }

    return 0;
}
```

```
0us
0.000000ms elapsed!
0.0000s
```


### Functions
  ```C
//===============================================================
//MICROSECOND FUNCTIONS

/// Start the microsecond timer, returns the start time
/// @return The current timeofday in microseconds, use this as the prev arg for `sw_stop_us()`
double sw_start_us();

/// Stop the microsecond timer
/// @param prev The start time from `double sw_start_us()`
/// @return The time between stop and start in microseconds
double sw_stop_us(double prev);

/// Prints the elapsed seconds since prev in microseconds
/// @param prev The start time from `double sw_start_us()`
void sw_print_us(double prev);
  
//===============================================================
//MILLISECOND FUNCTIONS

/// Start the millisecond timer, returns the start time.
/// @return The current timeofday in milliseconds, use this as the prev arg for `sw_stop_ms()'
double sw_start_ms();

/// Stop the millisecond timer
/// @param prev The start time from `double sw_start_ms()`
/// @return The time between stop and start in milliseconds
double sw_stop_ms(double prev);

/// Prints the elapsed seconds since prev in miliseconds
/// @param prev The start time from `double sw_start_ms()`
void sw_print_ms(double prev);

//===============================================================
//SECOND FUNCTIONS

/// Start the second timer, returns the start time.
/// @return The current timeofday in seconds, use this as the prev arg for `sw_stop_s`
double sw_start_s();

/// Stop the second timer
/// @param prev The start time from `double sw_start_s()`
/// @return The time between stop and start in seconds
double sw_stop_s(double prev);

/// Prints the elapsed seconds since prev in seconds
/// @param prev The start time from `double sw_start_s()`
void sw_print_s(double prev);
```
