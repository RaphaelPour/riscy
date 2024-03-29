#include <stdint.h>
#include <stddef.h>

#include "core/io.h"
#include "core/strconv.h"
#include "core/memory.h"
#include "core/time.h"
#include "core/str.h"
#include "driver/rtc.h"
#include "driver/uart.h"
#include "trip/selfcheck.h"
#include "trip/death_predictor.h"

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
    if(str_eq(input,"death-predictor")){
        death_predictor_departure(0, NULL);
    } else if(str_eq(input, "selfcheck")){
        departure(0,NULL);
    } else if(str_eq(input, "help")){
        io_puts(" == A V A I L A B L E   T R I P S ==\n");
        io_puts("|                                   |\n");
        io_puts("| help ............ show this help  |\n");
        io_puts("| selfcheck ....... test core lib   |\n");
        io_puts("| death-predictor.. calculate your  |\n");
        io_puts("|                   year of death   |\n");
        io_puts(" ==================================\n");
    } else {
        io_puts("unknown command ");
        io_puts(input);
        io_puts("\n");
    }
  }
}
