#include "math.h"

int sign(int val){
  return (val < 0) * -1 + (val >=0) * 1;
}

// TODO: optimize by return val & 0xwithout_highest_bit (or inversion, don' know)
int abs(int val){
  return val * sign(val);
}

// https://stackoverflow.com/q/72640997
int inc(int n) {
  volatile int result;
  asm volatile(
      "addi %0, %1, 1;"
      : "=r" (result)
      : "r" (n)
      );
  return result;
}
