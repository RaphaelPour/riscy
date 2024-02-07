#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stddef.h>

#define UART0 0x10000000
#define uart_addr(offset) ((unsigned char *)(UART0 + offset))
#define uart_write(offset, value) (*(uart_addr(offset)) = (value))
#define uart_read(offset) (*(uart_addr(offset)))

/* The Interrupt Enable Register (IER) masks the incoming interrupts from receiver ready,
 * transmitter empty, line status and modem status registers to the INT output pin.
 */
#define INTERRUPT_ENABLE_REGISTER 0x1
#define INTERRUPT_ENABLE_REGISTER_RX_ENABLE 0x1
#define INTERRUPT_ENABLE_REGISTER_TX_ENABLE 0x2


/* The line Control Register is used to specify the asynchronous data communication format. 
 * The number of the word length, stop bits, and parity can be selected by writing appro-
 * priate bits in this register.
 */
#define LINE_CONTROL_REGISTER 0x3
/* The internal baud rate counter latch enable (DLAB).*/
#define LINE_CONTROL_REGISTER_BAUD_LATCH (0x1<<7)

/* bit 0+1: word length = 0b11 => 8 bits
 * bit 2:   number of stop bits = 0 => 1 bit
 * bit 3:   parity = 0 => no parity
 * bit 4:   even/odd parity => doesn't matter since parity is off
 * bit 5:   force parity => -*-
 * bit 6:   break control = 0 => no break control
 * bit 7:   set baud rate = 0 => don't set baud rate
 */
#define LINE_CONTROL_REGISTER_EIGHT_BITS_NO_PARITY 0x3

/* This register is used to enable the FIFOs, clear the FIFOs, set the receiver FIFO trigger 
 * level, and select the type of DMA signaling.
 */
#define FIFO_CONTROL_REGISTER 0x2

#define FIFO_CONTROL_REGISTER_ENABLE 0x1
#define FIFO_CONTROL_REGISTER_CLEAR_RX 0x2
#define FIFO_CONTROL_REGISTER_CLEAR_TX 0x4

#define UART_TX_BUFFER_SIZE 32;
char buffer[UART_TX_BUFFER_SIZE];

#endif
