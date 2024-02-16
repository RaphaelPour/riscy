#include <stdint.h>
#include "time.h"
#include "../driver/rtc.h"

void sleep(double seconds){
    uint64_t start = rtc_time();
    while(((double)(rtc_time()-start))/100000000 < seconds){
        asm volatile ("nop");
    }
}
