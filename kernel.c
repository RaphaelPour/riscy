#include <stdint.h>
#include <stddef.h>
#include "uart.h"
#include "io.h"

const char * prompt = "riscy> ";

void kmain(void) {
  uart_init();

  io_puts("Hello evilcookie...\n");
  io_puts("                L<L\n");
  io_puts("                ...I'm expecting you.\n");

  const char *input; 
  while(1) {
    io_puts(prompt);
    input = io_getline();
    io_puts(input);
    io_putchar('\n');
  }
}
