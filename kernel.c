#include <stdint.h>
#include <stddef.h>

#include "core/io.h"
#include "core/strconv.h"
#include "core/memory.h"
#include "core/time.h"
#include "driver/rtc.h"
#include "driver/uart.h"
#include "trip/selfcheck.h"

const char * prompt = " riscy> ";


void kmain(void) {
  uart_init();

  io_bleep("Hello evilcookie...\n");
  io_bleep("                L<L\n");
  io_bleep("                ...I'm expecting you.\n");

  departure(0,NULL);

  io_bleep(itoa_base(255,16));
  io_bleep("\n");

  const char *input; 
  while(1) {
    io_bleep(u64toa(rtc_time()));
    io_bleep(prompt);
    input = io_getline();
    io_bleep(input);
    io_putchar('\n');
  }
}
