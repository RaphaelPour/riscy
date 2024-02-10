#include <stdint.h>
#include <stddef.h>

#include "core/io.h"
#include "core/strconv.h"
#include "driver/rtc.h"
#include "driver/uart.h"
#include "trip/selfcheck.h"

const char * prompt = " riscy> ";


void kmain(void) {
  uart_init();

  io_puts("Hello evilcookie...\n");
  io_puts("                L<L\n");
  io_puts("                ...I'm expecting you.\n");
  
  io_puts(itoa_base(255,16));
  io_puts("\n");

  departure(0,NULL);

  const char *input; 
  while(1) {
    io_puts(u64toa(rtc_time()));
    io_puts(prompt);
    input = io_getline();
    io_puts(input);
    io_putchar('\n');
  }
}
