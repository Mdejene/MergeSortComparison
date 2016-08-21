//
//  SimpleTimer.h
//  MergeSorts
//
//  Created by Fekadeab Dejene on 2016-08-21.
//
//

#ifndef MergeSorts_SimpleTimer_h
#define MergeSorts_SimpleTimer_h
#include <assert.h>
#include <CoreServices/CoreServices.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
static uint64_t __start__;
static mach_timebase_info_data_t __timebase_info__;

static inline void SetCurrentTimeStamp(){
    if (__timebase_info__.denom == 0) {
        (void) mach_timebase_info(&__timebase_info__);
    }

    __start__ = mach_absolute_time();
    
}

static inline uint64_t GeElapsedNanoSeconds(){
    uint64_t end = mach_absolute_time();
    uint64_t elapsed = end - __start__;
    return ((elapsed) * __timebase_info__.numer) / (__timebase_info__.denom);
}

static inline uint64_t GetElapsedMilliSeconds(){
    return GeElapsedNanoSeconds() / (1000000);
}


#endif
