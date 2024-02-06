#include <stdint.h>
#include <stddef.h>

const KEY_ENTER = 13;

unsigned char * uart = (unsigned char *)0x10000000; 
void putchar(char c) {
	*uart = c;
	return;
}
 
void print(const char * str) {
	while(*str != '\0') {
		putchar(*str);
		str++;
	}
	return;
}

static struct{
  char data[256];
  unsigned size;
}buf;

void buffer_init() {
  buf.size = 0;
  for(int i=0;i<256;i++) {
    buf.data[i] = 0x0;
  }
}

void buffer_add(unsigned char c){
  buf.data[buf.size] = c;
  buf.size++;
}

void buffer_print() {
  for(unsigned i=0;i<buf.size && i < 256;i++) {
    putchar(buf.data[i]);
  }
}

void buffer_clear() {
  for(unsigned i=0;i<buf.size && i < 256;i++) {
    buf.data[i] = 0x0;
  }
  buf.size = 0;
}

int is_printable(char c) {
  return (c >='a' && c <='z') ||
         (c >='A' && c <='Z') ||
         (c >='0' && c <='9');
}

void kmain(void) {
	print("Hello you!\r\n");
  buffer_init();

  while(1) {
    char in = *uart;
		// Read input from the UART
    if(in == 'q'){
      goto done;
    } else if (in == KEY_ENTER) {
      print("riscy> ");
      buffer_print();
      print("\r\n");
      buffer_clear();
      goto done;
    } else if (is_printable(in)) {
      buffer_add(in);
    } else {
      print("unknown input '");
      putchar(in+'0');
      print("'\r\n");
    }
	}

done:
  print("done\r\n");
	return;
}
