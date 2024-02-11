#include "selfcheck.h"
#include "../core/io.h"
#include "../core/str.h"
#include "../core/strconv.h"
#include "../core/math.h"

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
    return 0;
}
