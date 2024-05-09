#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <time.h>

//=====================
//HOW TO USE:
/*
    //Printing milliseconds example:
    double prev = sw_start_ms();
    //...
    sw_print_ms(prev);


    //Getting microseconds example:
    double start = sw_start_us();


    //Getting elapsed seconds example:
    double start = sw_start_s();
    //...
    double elapsed = sw_stop_s(start);
*/


//=====================
//MACROS

//Should print functions be enabled? (Comment to disable)
#define SW_PRINT_FUNCTIONS

//Should the minute functions be enabled? (Uncomment to enable)
// #define SW_MINUTE_FUNCTIONS

//Print format, we use doubles, so make sure to use a %f
#define PRINT_US_FORMAT "%.0fus\n"
#define PRINT_MS_FORMAT "%.4fms\n"
#define PRINT_S_FORMAT "%.4fs\n"
#define PRINT_MIN_FORMAT "%.2fmins\n"

//Include stdio.h if we are enabling print functions
#ifdef SW_PRINT_FUNCTIONS
#include <stdio.h>
#endif //SW_PRINT_FUNCTIONS

//=====================
//MICROSECOND FUNCTIONS

/// Start the microsecond timer, returns the start time
/// @return The current timeofday in microseconds, use this as the prev arg for `sw_stop_us()`
double sw_start_us()
{
    struct timespec a;
    clock_gettime(CLOCK_MONOTONIC, &a);
    return a.tv_nsec / 1000;
}

/// Stop the microsecond timer
/// @param prev The start time from `double sw_start_us()`
/// @return The time between stop and start in microseconds
double sw_stop_us(double prev)
{
    return (sw_start_us() - prev);
}

#ifdef SW_PRINT_FUNCTIONS
/// Prints the elapsed seconds since prev in microseconds
/// @param prev The start time from `double sw_start_us()`
void sw_print_us(double prev)
{
    printf(PRINT_US_FORMAT, sw_stop_us(prev));
}
#endif //SW_PRINT_FUNCTIONS

//=====================
//MILLISECOND FUNCTIONS

/// Start the millisecond timer, returns the start time.
/// @return The current timeofday in milliseconds, use this as the prev arg for `sw_stop_ms()'
double sw_start_ms()
{
    return sw_start_us() / 1000.0;
}

/// Stop the millisecond timer
/// @param prev The start time from `double sw_start_ms()`
/// @return The time between stop and start in milliseconds
double sw_stop_ms(double prev)
{
    return (sw_start_ms() - prev);
}

#ifdef SW_PRINT_FUNCTIONS
/// Prints the elapsed seconds since prev in miliseconds
/// @param prev The start time from `double sw_start_ms()`
void sw_print_ms(double prev)
{
    printf(PRINT_MS_FORMAT, sw_stop_ms(prev));
}
#endif //SW_PRINT_FUNCTIONS

//=====================
//SECOND FUNCTIONS

/// Start the second timer, returns the start time.
/// @return The current timeofday in seconds, use this as the prev arg for `sw_stop_s`
double sw_start_s()
{
    return sw_start_ms() / 1000;
}

/// Stop the second timer
/// @param prev The start time from `double sw_start_s()`
/// @return The time between stop and start in seconds
double sw_stop_s(double prev)
{
    return (sw_start_s() - prev);
}


#ifdef SW_PRINT_FUNCTIONS
/// Prints the elapsed seconds since prev in seconds
/// @param prev The start time from `double sw_start_s()`
void sw_print_s(double prev)
{
    printf(PRINT_S_FORMAT, sw_stop_s(prev));
}
#endif //SW_PRINT_FUNCTIONS


//=====================
//MINUTE FUNCTIONS

#ifdef SW_MINUTE_FUNCTIONS
/// Start the second timer, returns the start time.
/// @return The current timeofday in seconds, use this as the prev arg for `sw_stop_min`
double sw_start_min()
{
    return sw_start_s() / 60;
}

/// Stop the second timer
/// @param prev The start time from `double sw_start_min()`
/// @return The time between stop and start in minutes
double sw_stop_min(double prev)
{
    return (sw_start_min() - prev);
}

#ifdef SW_PRINT_FUNCTIONS
/// Prints the elapsed seconds since prev in mins
/// @param prev The start time from `double sw_start_min()`
void sw_print_min(double prev)
{
    printf(PRINT_MIN_FORMAT, sw_stop_min(prev));
}
#endif //SW_PRINT_FUNCTIONS

#endif //SW_MINUTE_FUNCTIONS

#endif //STOPWATCH_H

//
// Created by TobinC on 5/9/2024.
//
