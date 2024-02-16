#ifndef IO_H
#define IO_H

#ifndef BLEEP_TIME
#define BLEEP_TIME 0.3
#endif

void io_bleepchar(const char c);
void io_bleep(const char *s);
void io_putchar(const char c);
void io_puts(const char * str);
char io_getchar();
const char * io_getline();

int io_strlen(const char *s);

#endif
