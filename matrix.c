#ifdef _CODE_MATRIX
#else
#define _CODE_MATRIX

#include "leds.c"

uint8_t globalLEDcounter;

typedef struct LedController {
  uint8_t value; //Internal use, state
  uint8_t (*led)(uint8_t); //Action for led
} LedController;

LedController LEDa1 = { 0, &led_a1 };
LedController LEDa2 = { 0, &led_a2 };
LedController LEDa3 = { 0, &led_a3 };
LedController LEDa4 = { 0, &led_a4 };
LedController LEDa5 = { 0, &led_a5 };
LedController LEDb1 = { 0, &led_b1 };
LedController LEDb2 = { 0, &led_b2 };
LedController LEDb3 = { 0, &led_b3 };
LedController LEDb4 = { 0, &led_b4 };
LedController LEDb5 = { 0, &led_b5 };
LedController LEDc1 = { 0, &led_c1 };
LedController LEDc2 = { 0, &led_c2 };
LedController LEDc3 = { 0, &led_c3 };
LedController LEDc4 = { 0, &led_c4 };
LedController LEDc5 = { 0, &led_c5 };
LedController LEDd1 = { 0, &led_d1 };
LedController LEDd2 = { 0, &led_d2 };
LedController LEDd3 = { 0, &led_d3 };
LedController LEDd4 = { 0, &led_d4 };
LedController LEDd5 = { 0, &led_d5 };
LedController LEDe1 = { 0, &led_e1 };
LedController LEDe2 = { 0, &led_e2 };
LedController LEDe3 = { 0, &led_e3 };
LedController LEDe4 = { 0, &led_e4 };
LedController LEDe5 = { 0, &led_e5 };

LedController * matrixA [5] = { &LEDa1, &LEDa2, &LEDa3, &LEDa4, &LEDa5 };
LedController * matrixB [5] = { &LEDb1, &LEDb2, &LEDb3, &LEDb4, &LEDb5 };
LedController * matrixC [5] = { &LEDc1, &LEDc2, &LEDc3, &LEDc4, &LEDc5 };
LedController * matrixD [5] = { &LEDd1, &LEDd2, &LEDd3, &LEDd4, &LEDd5 };
LedController * matrixE [5] = { &LEDe1, &LEDe2, &LEDe3, &LEDe4, &LEDe5 };

LedController ** matrix [5] = { matrixA, matrixB, matrixC, matrixD, matrixE };

void
processLed
( struct LedController *x
) {
  if (( x -> value ) <= globalLEDcounter ) {
    x -> led(OFF);
    return;
  }
  if ( globalLEDcounter == 0 ) {
    x -> led(ON);
    return;
  }
}

void
processMatrix
( void )
{
  for (uint8_t i = 0; i<5; i++ ) {
    for (uint8_t j = 0; j<5; j++ ) {
      processLed(matrix[i][j]);
    }
  }
  globalLEDcounter++;
}
#endif
