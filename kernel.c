#include <stdint.h>
#include <stddef.h>
#include "uart.h"

void kmain(void) {
  uart_init();

  uart_puts("Hello evilcookie...\n");
  uart_puts("                L<L\n");
  uart_puts("                ...I'm expecting you.\n");

  const char *input; 
  while(1) {
    uart_getline();
    uart_puts(">");
    uart_putbuf();
    uart_putchar('\n');
  }
}
