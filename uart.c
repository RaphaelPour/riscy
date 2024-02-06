#include "uart.h"

void uart_init() {
    // disable any interrupt, so we can set up some uart settings
    uart_write(INTERRUPT_ENABLE_REGISTER, 0x00); 

    // enter baud rate mode
    uart_write(LINE_CONTROL_REGISTER, LINE_CONTROL_REGISTER_BAUD_LATCH);

    // set baud rate to 38.4K
    uart_write(0, 0x03);
    uart_write(1, 0x00);

    // leave baud rate mode
    uart_write(LINE_CONTROL_REGISTER, LINE_CONTROL_REGISTER_EIGHT_BITS_NO_PARITY)
}
