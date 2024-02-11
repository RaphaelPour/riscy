#include "str.h"

int str_len(const char* s) {
  int len;
  while(*s++)len++;
  return len;
}

int str_eq(const char *a, const char *b){
  while(*a && *b  && *a++ == *b++);
  return *a == *b;
}

int str_neq(const char* a, const char* b){
  return !str_eq(a,b);
}
