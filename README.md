# SW : Single C header file benchmarking

#### Clarity rejects verbosity

No more `time_t` or `timeval`. They have their place, but 99% of the time you want to time something, they just get in
they way.

<!---# Keep this updated! #--->
[Download `sw.h`](https://github.com/TobinCavanaugh/sw.h/releases/download/0.0.4/sw.h)

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

    //Testing elapsed second
    {
        double prev = sw_start_s();
        //...
        sw_print_s(prev);
    }

    //Print the current memory usage in whatever unit is ideal
    {
        sw_memory_print_auto();
    }

    //Print the current memory usage in gb
    {
        double sizegb = sw_memory_size_gb();
        printf("%.5fgb\n", sizegb);
    }

    //Print the current memory usage in kb
    {
        sw_memory_print_kb();
    }

    return 0;
}
```

```
0us
0.000000ms elapsed!
0.0000s
2.96550MB
0.00297GB
2965.50KB
```

### Functions

```C
//MICROSECOND FUNCTIONS ======================================================================

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
```

```C
//MILLISECOND FUNCTIONS ======================================================================

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
```

```C
//SECOND FUNCTIONS ======================================================================

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

```C
//MEMORY FUNCTIONS ======================================================================

/// Get the current memory usage of this application
/// @return The size of memory in bytes
inline double sw_memory_size_b();

/// Gets and prints the memory usage in bytes
inline void sw_memory_print_b();

/// Get the current memory usage of this application
/// @return The size of memory in kilobytes
inline double sw_memory_size_kb();

/// Gets and prints the memory usage in kilobytes
inline void sw_memory_print_kb();

/// Get the current memory usage of this application
/// @return The size of memory in megabytes
inline double sw_memory_size_mb();

/// Gets and prints the memory usage in megabytes
inline void sw_memory_print_mb();

/// Get the current memory usage of this application
/// @return The size of memory in gigabytes
inline double sw_memory_size_gb();

/// Gets and prints the memory usage in gigabytes
inline void sw_memory_print_gb();

/// Prints the memory usage with the correct formatting in the ideal size.
/// i.e. doesnt print 1000 bytes as "1000b" but as "1mb"
inline void sw_memory_print_auto();
```
