#ifdef _CODE_PINS
#else
#define _CODE_PINS

#include "const.h"
#include "lib/pins.c"

__attribute__((always_inline)) 
static inline
uint8_t
led_a1
( uint8_t x ) {
  return setPin_OD ( GPIOD, 7, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_a2
( uint8_t x ) {
  return setPin_OD ( GPIOE, 3, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_a3
( uint8_t x ) {
  return setPin_OD ( GPIOE, 4, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_a4
( uint8_t x ) {
  return setPin_OD ( GPIOE, 5, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_a5
( uint8_t x ) {
  return setPin_OD ( GPIOE, 6, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_b1
( uint8_t x ) {
  return setPin_OD ( GPIOD, 6, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_b2
( uint8_t x ) {
  return setPin_OD ( GPIOE, 2, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_b3
( uint8_t x ) {
  return setPin_OD ( GPIOC,13, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_b4
( uint8_t x ) {
  return setPin_OD ( GPIOF, 9, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_b5
( uint8_t x ) {
  return setPin_OD ( GPIOF,10, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_c1
( uint8_t x ) {
  return setPin_OD ( GPIOD, 5, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_c2
( uint8_t x ) {
  return setPin_OD ( GPIOD, 3, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_c3
( uint8_t x ) {
  return setPin_OD ( GPIOD, 2, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_c4
( uint8_t x ) {
  return setPin_OD ( GPIOD, 1, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_c5
( uint8_t x ) {
  return setPin_OD ( GPIOD, 0, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_d1
( uint8_t x ) {
  return setPin_OD ( GPIOD, 4, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_d2
( uint8_t x ) {
  return setPin_OD ( GPIOD,15, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_d3
( uint8_t x ) {
  return setPin_OD ( GPIOD,13, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_d4
( uint8_t x ) {
  return setPin_OD ( GPIOD,12, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_d5
( uint8_t x ) {
  return setPin_OD ( GPIOD,11, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_e1
( uint8_t x ) {
  return setPin_OD ( GPIOA, 8, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_e2
( uint8_t x ) {
  return setPin_OD ( GPIOC, 9, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_e3
( uint8_t x ) {
  return setPin_OD ( GPIOC, 8, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_e4
( uint8_t x ) {
  return setPin_OD ( GPIOC, 7, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_e5
( uint8_t x ) {
  return setPin_OD ( GPIOC, 6, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_LR
( uint8_t x ) {
  return setPin_OD ( GPIOE, 9, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_LG
( uint8_t x ) {
  return setPin_OD ( GPIOE,10, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_LB
( uint8_t x ) {
  return setPin_OD ( GPIOE,11, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_RR
( uint8_t x ) {
  return setPin_OD ( GPIOE,12, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_RG
( uint8_t x ) {
  return setPin_OD ( GPIOE,13, x );
}

__attribute__((always_inline)) 
static inline
uint8_t
led_RB
( uint8_t x ) {
  return setPin_OD ( GPIOE,14, x );
}

void
initLeds
( void ) {
  RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
  RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
  RCC -> AHB2ENR |= RCC_AHB2ENR_GPIODEN;
  RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
  RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOFEN;
  initPin_OD ( GPIOD, 7 ); //а1
  initPin_OD ( GPIOE, 3 ); //a2
  initPin_OD ( GPIOE, 4 ); //a3
  initPin_OD ( GPIOE, 5 ); //a4
  initPin_OD ( GPIOE, 6 ); //a5

  initPin_OD ( GPIOD, 6 ); //b1
  initPin_OD ( GPIOE, 2 ); //b2
  initPin_OD ( GPIOC,13 ); //b3
  initPin_OD ( GPIOF, 9 ); //b4
  initPin_OD ( GPIOF,10 ); //b5

  initPin_OD ( GPIOD, 5 ); //c1
  initPin_OD ( GPIOD, 3 ); //c2
  initPin_OD ( GPIOD, 2 ); //c3
  initPin_OD ( GPIOD, 1 ); //c4
  initPin_OD ( GPIOD, 0 ); //c5

  initPin_OD ( GPIOD, 4 ); //d1
  initPin_OD ( GPIOD,15 ); //d2
  initPin_OD ( GPIOD,13 ); //d3
  initPin_OD ( GPIOD,12 ); //d4
  initPin_OD ( GPIOD,11 ); //d5

  initPin_OD ( GPIOA, 8 ); //e1
  initPin_OD ( GPIOC, 9 ); //e2
  initPin_OD ( GPIOC, 8 ); //e3
  initPin_OD ( GPIOC, 7 ); //e4
  initPin_OD ( GPIOC, 6 ); //e5

  initPin_OD ( GPIOE, 9 ); //LR
  initPin_OD ( GPIOE,10 ); //LG
  initPin_OD ( GPIOE,11 ); //LG

  initPin_OD ( GPIOE,12 ); //RR
  initPin_OD ( GPIOE,13 ); //RG
  initPin_OD ( GPIOE,14 ); //RG

  //ledR(OFF);
  //ledG(OFF);
  //ledB(OFF);
}
/* Вместо этого используется RGB
uint32_t ledRCounter = 0;
uint32_t ledGCounter = 0;
uint32_t ledBCounter = 0;

void
flashR
( uint32_t counter )
{
  ledRCounter = counter;
  ledR(ON);
}

void
flashG
( uint32_t counter )
{
  ledGCounter = counter;
  ledG(ON);

}
void
flashB
( uint32_t counter )
{
  ledBCounter = counter;
  ledB(ON);
}
*/
#endif
