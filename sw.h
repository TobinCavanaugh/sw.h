#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <time.h>

//MACRO OPTIONS ======================================================================

//Should print functions be enabled? (Comment to disable)
#define SW_PRINT_FUNCTIONS

//Should the minute functions be enabled? (Uncomment to enable)
// #define SW_MINUTE_FUNCTIONS

//Should memory functions be enabled (Comment to disable)
#define SW_MEMORY

//Printing time format, we use doubles, so make sure to use a %f
#define PRINT_US_FORMAT "%.0fus\n"
#define PRINT_MS_FORMAT "%.4fms\n"
#define PRINT_S_FORMAT "%.4fs\n"
#define PRINT_MIN_FORMAT "%.2fmins\n"

//Printing sizes format
#define PRINT_B_FORMAT "%.0fB\n"
#define PRINT_KB_FORMAT "%.2fKB\n"
#define PRINT_MB_FORMAT "%.5fMB\n"
#define PRINT_GB_FORMAT "%.5fGB\n"

//MACRO BACKEND ======================================================================

//Include stdio.h if we are enabling print functions
#ifdef SW_PRINT_FUNCTIONS

#include <stdio.h>

#endif //SW_PRINT_FUNCTIONS

#ifdef SW_MEMORY
#ifdef __WIN32

#include <windows.h>
#include <psapi.h>

#elif __linux__

#include <sys/resource.h>

#endif

#include <math.h>

#endif //SW_MEMORY

//MICROSECOND FUNCTIONS ======================================================================

/// Start the microsecond timer, returns the start time
/// @return The current timeofday in microseconds, use this as the prev arg for `sw_stop_us()`
static inline double sw_start_us() {
    struct timespec a;
    clock_gettime(CLOCK_MONOTONIC, &a);
    return a.tv_nsec / 1000.0 + (double) a.tv_sec * 1000.0 * 1000.0;
}

/// Stop the microsecond timer
/// @param prev The start time from `static inline  double sw_start_us()`
/// @return The time between stop and start in microseconds
static inline double sw_stop_us(const double prev) {
    return fabs(sw_start_us() - prev);
}

#ifdef SW_PRINT_FUNCTIONS

/// Prints the elapsed seconds since prev in microseconds
/// @param prev The start time from `static inline  double sw_start_us()`
static inline void sw_print_us(const double prev) {
    printf(PRINT_US_FORMAT, sw_stop_us(prev));
}

#endif //SW_PRINT_FUNCTIONS

//MILLISECOND FUNCTIONS ======================================================================

/// Start the millisecond timer, returns the start time.
/// @return The current timeofday in milliseconds, use this as the prev arg for `sw_stop_ms()'
static inline double sw_start_ms() {
    return sw_start_us() / 1000.0;
}

/// Stop the millisecond timer
/// @param prev The start time from `static inline  double sw_start_ms()`
/// @return The time between stop and start in milliseconds
static inline double sw_stop_ms(const double prev) {
    return fabs(sw_start_ms() - prev);
}

#ifdef SW_PRINT_FUNCTIONS

/// Prints the elapsed seconds since prev in miliseconds
/// @param prev The start time from `static inline  double sw_start_ms()`
static inline void sw_print_ms(const double prev) {
    printf(PRINT_MS_FORMAT, sw_stop_ms(prev));
}

#endif //SW_PRINT_FUNCTIONS

//SECOND FUNCTIONS ======================================================================

/// Start the second timer, returns the start time.
/// @return The current timeofday in seconds, use this as the prev arg for `sw_stop_s`
static inline double sw_start_s() {
    return sw_start_ms() / 1000;
}

/// Stop the second timer
/// @param prev The start time from `static inline  double sw_start_s()`
/// @return The time between stop and start in seconds
static inline double sw_stop_s(const double prev) {
    return fabs(sw_start_s() - prev);
}

#ifdef SW_PRINT_FUNCTIONS

/// Prints the elapsed seconds since prev in seconds
/// @param prev The start time from `static inline  double sw_start_s()`
static inline void sw_print_s(const double prev) {
    printf(PRINT_S_FORMAT, sw_stop_s(prev));
}

#endif //SW_PRINT_FUNCTIONS


//MINUTE FUNCTIONS ======================================================================

#ifdef SW_MINUTE_FUNCTIONS
/// Start the second timer, returns the start time.
/// @return The current timeofday in seconds, use this as the prev arg for `sw_stop_min`
static inline  double sw_start_min()
{
    return sw_start_s() / 60;
}

/// Stop the second timer
/// @param prev The start time from `static inline  double sw_start_min()`
/// @return The time between stop and start in minutes
static inline  double sw_stop_min(const double prev)
{
    return fabs(sw_start_min() - prev);
}

#ifdef SW_PRINT_FUNCTIONS
/// Prints the elapsed seconds since prev in mins
/// @param prev The start time from `static inline  double sw_start_min()`
static inline  void sw_print_min(const double prev)
{
    printf(PRINT_MIN_FORMAT, sw_stop_min(prev));
}
#endif //SW_PRINT_FUNCTIONS

#endif //SW_MINUTE_FUNCTIONS

#ifdef __WIN32
static HANDLE hproc = NULL;
static PROCESS_MEMORY_COUNTERS_EX pmc;
#endif


#ifdef SW_MEMORY

/// Get the current memory usage of this application
/// @return The size of memory in bytes
static inline double sw_memory_size_b() {
#ifdef __WIN32

    if (hproc == NULL) {
        hproc = GetCurrentProcess();
    }

    if (GetProcessMemoryInfo(hproc, (PPROCESS_MEMORY_COUNTERS) &pmc, sizeof(pmc))) {
        //In bytes?
        return pmc.WorkingSetSize;
    }
    return -1;

#elif __linux__
    struct rusage use;
    getrusage(RUSAGE_SELF, &use);
    return use.ru_maxrss * 1000.0;
#endif
}

#ifdef SW_PRINT_FUNCTIONS

/// Gets and prints the memory usage in bytes
static inline void sw_memory_print_b() {
    printf(PRINT_B_FORMAT, sw_memory_size_b());
}

#endif //SW_PRINT_FUNCTIONS

/// Get the current memory usage of this application
/// @return The size of memory in kilobytes
static inline double sw_memory_size_kb() {
    return sw_memory_size_b() / 1000.0;
}

#ifdef SW_PRINT_FUNCTIONS

/// Gets and prints the memory usage in kilobytes
static inline void sw_memory_print_kb() {
    printf(PRINT_KB_FORMAT, sw_memory_size_kb());
}

#endif //SW_PRINT_FUNCTIONS

/// Get the current memory usage of this application
/// @return The size of memory in megabytes
static inline double sw_memory_size_mb() {
    return sw_memory_size_kb() / 1000.0;
}

#ifdef SW_PRINT_FUNCTIONS

/// Gets and prints the memory usage in megabytes
static inline void sw_memory_print_mb() {
    printf(PRINT_MB_FORMAT, sw_memory_size_mb());
}

#endif //SW_PRINT_FUNCTIONS

/// Get the current memory usage of this application
/// @return The size of memory in gigabytes
static inline double sw_memory_size_gb() {
    return sw_memory_size_mb() / 1000.0;
}

#ifdef SW_PRINT_FUNCTIONS

/// Gets and prints the memory usage in gigabytes
static inline void sw_memory_print_gb() {
    printf(PRINT_GB_FORMAT, sw_memory_size_gb());
}

#endif //SW_PRINT_FUNCTIONS


#ifdef SW_PRINT_FUNCTIONS

/// Prints the memory usage with the correct formatting in the ideal size.
/// i.e. doesnt print 1000 bytes as "1000b" but as "1mb"
static inline void sw_memory_print_auto() {
    const double size = sw_memory_size_b();
    if (size < 1000) {
        printf(PRINT_B_FORMAT, size);
    } else if (size < 1000 * 1000) {
        printf(PRINT_KB_FORMAT, size / 1000.0);
    } else if (size < 1000 * 1000 * 1000) {
        printf(PRINT_MB_FORMAT, size / 1000.0 / 1000.0);
    } else {
        printf(PRINT_GB_FORMAT, size / 1000.0 / 1000.0 / 1000.0);
    }
}

#endif//SW_PRINT_FUNCTIONS

#endif//SW_MEMORY

#endif//STOPWATCH_H

//
// Created by TobinC on 5/9/2024.
//
