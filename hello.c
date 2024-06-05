#ifdef _CODE_HELLO
#else
#define _CODE_HELLO

#include "leds.c"

struct Color foo = { 0,0,0,0 };

//Мигание светодиодами на старте
void hello ( void ) {
  void f ( struct Color *c ) {
    eyeL.color = c;
    eyeR.color = c;
  }
  imageNone(0);
  for (uint16_t i = 0; i<=0xff; i++ ) {
    struct Color foo = { 0,0,0,0 };
    uint16_t k = i/(0xff/12);
    foo.red = 0;
    foo.green = 6;
    foo.blue = 5;
    foo.black = 0xff-i;
    f(&foo);
    delay(2);
  }
  f(&ColorCyan);
  delay(200);
  return;
}
#endif
