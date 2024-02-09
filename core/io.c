#include "../driver/uart.h"
#include "io.h"

void io_putchar(const char c) {
  uart_transmit(c);
}

void io_puts(const char * str) {
  while(*str != '\0') {
    io_putchar(*str);
    str++;
  }
}

int is_printable(char c) {
  return c >= ' ' && c <= '~';
}

int io_strlen(const char *s){
  int length =0;
  while(*s++)length++;
  return length;
}

// TODO: return const string instead of reliying on the magic buffer
const char* io_getline() {
  static char buffer[256];
  char c;
  int i = 0;
  while((c = io_getchar()) != 13){
    if(!is_printable(c)) continue;
    buffer[i++] = c;
    io_putchar(c);
  }
  buffer[i] = '\0';
  io_putchar('\n');
  return (const char *)buffer;
}

char io_getchar() {
  return uart_receive();
}
