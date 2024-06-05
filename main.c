#include <stm32g431xx.h>
#include "lib/pins.c"
#include "lib/bases.c"
#include "lib/helpers.c"
#include "lib/macros.c"
#include "system.c"
#include "colors.c"
#include "matrix.c"
#include "buttons.c"
#include "nose.c"
#include "roar.c"
#include "random.c"
#include "images.c"
#include "ears.c"
#include "scenarios/beat.c"
#include "scenarios/digit.c"
#include "scenarios/nose.c"
#include "scenarios/roar.c"
#include "scenarios/ears.c"
#include "scenarios/heart.c"
#include "uart.c"
#include "hello.c"

void main ( void ) {
  initEyes();
  initPin_InputPU(GPIOA,0);
  initPin_InputPU(GPIOB,13);
  initADC_Common();
  initOPAMP2();
  initADC1();
  initADC2();
  initRoar();
  hello();
  initUART(115200);
  putString("CyberBear v1-a3 reporting in!\n\r");
  putString("My firmware is at git rev ");
  putString(_FIR_GIT_REV);
  putString("\n\r");
  while (1) {
    if ( scHeartCounter ) {
      scHeartPos();
    }
    else {
      switch ( checkButtons()) {
        case 0b00://не нажато
          scEarsPos();
          scDigitNeg();
          scRoarNeg();
          break;
        case 0b01://левая
          scBeatNeg();
          scDigitPos();
          scRoarNeg();
          scEarsNeg();
          break;
        case 0b10://правая
          scBeatNeg();
          scNosePos();
          scRoarNeg();
          scEarsNeg();
          break;
        case 0b11://обе
          scBeatNeg();
          scRoarPos();
          scEarsNeg();
          break;
        default:
          break;
      }
    }
  }
}
