#include "selfcheck.h"
#include "../core/io.h"
#include "../core/str.h"
#include "../core/strconv.h"
#include "../core/math.h"
#include "../core/memory.h"

void check(int condition, const char *msg) {
  io_puts(msg);
  io_puts(": ");
  if(condition) {
    io_puts("ok\n");
  } else {
    io_puts("failed\n");
  }
}

int departure(int luggage_num, const char *luggage[]) {
    io_puts("*******************************\n");
    io_puts("*      S E L F C H E C K      *\n"); 
    io_puts("*******************************\n");
  
    io_puts("\n** Math\n");
    check(abs(-1) == 1, "abs(-1)=1");
    check(abs(1) == 1, "abs(1)=1");
    check(sign(-1) == -1, "sign(-1)=-1");
    check(sign(1) == 1, "sign(1)=1");
    check(inc(1) == 2, "inc(1)=1");
    io_puts(itoa(inc(1)));

    io_puts("\n** String\n");
    check(str_eq("", ""), "str_eq(\"\",\"\")");
    check(str_eq("selfcheck", "selfcheck"), "str_eq(\"selfcheck\",\"selfcheck\")");
    check(str_neq("selfcheck", "self"), "str_neq(\"selfcheck\",\"self\")");
    check(str_neq("selfcheck", ""), "str_neq(\"selfcheck\",\"\")");
    
    io_puts("\n** String conversion\n");
    check(str_eq(itoa_base(255,10),"255"), "iota_base(255,10) == 255");
    check(str_eq(itoa_base(15,2),"11111"), "iota_base(15,2) == 1111");
#ifdef BIG_HEX
    check(str_eq(itoa_base(255,16),"FF"), "iota_base(255,16) == FF");
#else
    check(str_eq(itoa_base(255,16), "ff"), "iota_base(255,16) == ff");
#endif

    io_puts("\n** Memory allocation\n");
    intptr_t first_allocation = (intptr_t) malloc(10);
    check(first_allocation < (intptr_t) malloc(10), "malloc(10) < malloc(10)");

    intptr_t addr_size = 50;
    intptr_t addr = (intptr_t) malloc(addr_size);
    check(addr + addr_size == (intptr_t) malloc(10), "malloc(50) + 50 == malloc(10)");
    free();
    check((intptr_t) malloc(10) == first_allocation, "free(); malloc(10) == first_allocation");

    int *malloc_a = malloc(sizeof(int));
    *malloc_a = 500;
    memset(malloc_a, 0, sizeof(int));
    check(*malloc_a == 0, "Set value of allocated memory");
    int *malloc_b = malloc(sizeof(int));
    check(memcmp(malloc_a, malloc_b, sizeof(int)), "Compare values of two allocated memories (positive)");
    *malloc_b = 1000;
    check(!memcmp(malloc_a, malloc_b, sizeof(int)), "Compare values of two allocated memories (negative)");

    memcpy(malloc_b, malloc_a, sizeof(int));
    check(*malloc_a == *malloc_b, "Copy memory from one address to another");

    return 0;
}
