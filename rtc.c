#include <stdint.h>
#include "rtc.h"

// google goldfish rtc timer
// https://android.googlesource.com/platform/external/qemu/+/master/docs/GOLDFISH-VIRTUAL-HARDWARE.TXT#203
// https://github.com/torvalds/linux/blob/master/drivers/rtc/rtc-goldfish.c#L110
volatile uint32_t *rtc = (uint32_t *) 0x101000;
uint64_t rtc_time() {
  uint64_t time_low = rtc[0];
  uint64_t time_high = rtc[1];
  return (time_high << 32 | time_low);
}
