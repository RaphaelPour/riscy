#include <stdint.h>
#include "strconv.h"
#include "math.h"
#include "str.h"
#include "io.h"

#ifdef BIG_HEX
const char *number_lut = "0123456789ABCDEF";
#else
const char *number_lut = "0123456789abcdef";
#endif

int atoi(const char *s){
    int result = 0;
    /* go backwards through the string from least significant
     * to most significant digit, multiply it with the base (10).
     * A char representing a digit can be converted to an integer
     * by subtracting the char '0'. Multiply the base by itself after
     * each iteration to go to the next digit (base 10: 1,10,100,1000,...)
     *
     * This is needed since numbers are read from right-to-left, but in 
     * memory from left-to-right.
     *
     * E.g. the number 2000 gets stored as string "2000", where index
     * 0 is 2.
     */
    for(int i=1,j=str_len(s)-1; j>=0; i*=10,j--){
        result += i*(s[j]-'0');
    }
    return result;
}

const char* itoa(int val) {
  return itoa_base(val, 10);
}

// https://clc-wiki.net/wiki/K&R2_solutions:Chapter_3:Exercise_4
const char* itoa_base(int val, int base) {
  if (val == 0) {
    return "0";
  }

  static char buf[256];
  int s = sign(val);
  val = abs(val);

  // convert last digit to char -> get char via index from table
  // use lookup-table over '0'+index trick because of hex char a-f
  // since we use the lowest digit and append it to the buffer,
  // it will be in reverse order, let's fix this later
  int i = 0;
  while(val){
    buf[i++] = number_lut[val % base];
    val /=base;
  }

  // append minus (if any), so it get to the front after reverse
  if(s == -1) buf[i++] = '-';

  // reverse via pair-wise xor-swap
  for(int j=0, k=i-1;j<k;j++,k--){
    buf[j] ^= buf[k];
    buf[k] ^= buf[j];
    buf[j] ^= buf[k];
  }

  // at string terminator at the end
  buf[i] = '\0';
  return buf;
}

const char* u64toa(uint64_t val) {
  return u64toa_base(val, 10);
}

const char* u64toa_base(uint64_t val, int base) {
  static char buf[256];

  // convert last digit to char -> get char via index from table
  // use lookup-table over '0'+index trick because of hex char a-f
  // since we use the lowest digit and append it to the buffer,
  // it will be in reverse order, let's fix this later
  int i = 0;
  while(val){
    buf[i++] = number_lut[val % base];
    val /=base;
  }

  // reverse via pair-wise xor-swap
  for(int j=0, k=i-1;j<k;j++,k--){
    buf[j] ^= buf[k];
    buf[k] ^= buf[j];
    buf[j] ^= buf[k];
  }

  // at string terminator at the end
  buf[i] = '\0';
  return buf;
}
