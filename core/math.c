#include "math.h"

// TODO: optimize by return val & 0xhighest_bit (or inversion, don't know)
int sign(int val){
  if(val >=0){
    return 1;
  }
  return -1;
}

// TODO: optimize by return val & 0xwithout_highest_bit (or inversion, don' know)
int abs(int val){
  return val * sign(val);
}
