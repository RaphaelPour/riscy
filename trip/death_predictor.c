#include "selfcheck.h"
#include "../core/io.h"
#include "../core/str.h"
#include "../core/strconv.h"

int death_predictor_departure(int luggage_num, const char *luggage[]) {
  io_puts("*******************************\n");
  io_puts("* D E A T H                   *\n");
  io_puts("* P R E D I C T O R           *\n");
  io_puts("*******************************\n");
  io_puts("Your year of birth: ");
  int a = atoi(io_getline());

  io_puts("How old you wanna get: ");
  a += atoi(io_getline());
  
  io_puts("You'll die in the year ");
  io_puts(itoa(a));
  io_puts(".\n");

  return 0;
}
