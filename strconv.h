#ifndef STRCONV_H
#define STRCONV_H

const char* itoa_base(int val, int base);
const char* itoa(int val);

const char* u64toa_base(uint64_t val, int base);
const char* u64toa(uint64_t val);

#endif
