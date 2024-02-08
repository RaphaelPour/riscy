#include "uart.h"

char buf[256];

void uart_init() {
    // disable any interrupt, so we can set up some uart settings
    uart_write(INTERRUPT_ENABLE_REGISTER, 0x00); 

    // enter baud rate mode
    uart_write(LINE_CONTROL_REGISTER, LINE_CONTROL_REGISTER_BAUD_LATCH);

    // set baud rate to 38.4K
    uart_write(0, 0x01);
    uart_write(1, 0x00);

    // leave baud rate mode
    uart_write(LINE_CONTROL_REGISTER, LINE_CONTROL_REGISTER_EIGHT_BITS_NO_PARITY);

    // enable and clear FIFO
    uart_write(
        FIFO_CONTROL_REGISTER, 
        FIFO_CONTROL_REGISTER_ENABLE |
        FIFO_CONTROL_REGISTER_CLEAR_TX |
        FIFO_CONTROL_REGISTER_CLEAR_RX
    );

    // enable interrupts again
    uart_write(INTERRUPT_ENABLE_REGISTER,
        INTERRUPT_ENABLE_REGISTER_RX_ENABLE |
        INTERRUPT_ENABLE_REGISTER_TX_ENABLE
    );

    for(int i=0;i<256;i++) buf[i] = '.';
}

static int uart_rx_ready() {
  volatile uint32_t* const uart0 = (uint32_t*)UART0;
  return !(uart0[1] & 0x80000000); // TODO: Why does this work?? Replace with explicit byte-oriented flags
  // return uart_read(LINE_CONTROL_REGISTER+LINE_CONTROL_REGISTER_RX_READY);
}

static int uart_tx_ready() {
  volatile uint32_t* const uart0 = (uint32_t*)UART0;
  return !(uart0[0] & 0x80000000); // TODO: Why does this work?? Replace with explicit byte-oriented flags
}

void uart_putchar(const char c) {
  while(!uart_tx_ready()){}
  uart_write(0, c);
}

void uart_puts(const char * str) {
  while(*str != '\0') {
    uart_putchar(*str);
    str++;
  }
}

void uart_putbuf() {
  for(int i=0; i<256 && buf[i]; i++) uart_putchar(buf[i]);
}

int is_printable(char c) {
  return c >= ' ' && c <= '~';
}

// TODO: return const string instead of reliying on the magic buffer
void uart_getline() {
  char c;
  int i = 0;
  while((c = uart_getchar()) != 13){
    if(is_printable(c)) buf[i++] = c;
  }
  buf[i] = '\0';
}

char uart_getchar() {
  while(!uart_rx_ready()){}
  return uart_read(0) & 0xFF;
}
