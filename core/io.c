#include "../driver/uart.h"
#include "io.h"
#include "time.h"

void io_bleepchar(const char c) {
    uart_transmit(c);
    sleep(BLEEP_TIME);
}

void io_bleep(const char *str) {
  while(*str != '\0') {
    io_bleepchar(*str);
    str++;
  }
}

void io_putchar(const char c) {
#ifdef BLEEP_BLEEP_MF
  io_bleepchar(c);
#else
  uart_transmit(c);
#endif
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
  while((c = uart_receive()) != 13){
    if(!is_printable(c)) continue;
    buffer[i++] = c;
    io_putchar(c);
  }
  buffer[i] = '\0';
  io_putchar('\n');
  return (const char *)buffer;
}

char io_getchar(){
    char c;
    for(c=uart_receive();!is_printable(c);c=uart_receive());
    return c;
}

