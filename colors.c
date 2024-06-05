#ifdef _CODE_COLORS
#else
#define _CODE_COLORS

#include "leds.c"
#include "matrix.c"

typedef struct Color {
  uint16_t red; //Duration of red shining
  uint16_t green; //Duration of green shining
  uint16_t blue; //Duration of blue shining
  uint16_t black; //Duration of darkness (to reduce brightness)
} Color;
// Чем меньше сумма значений, тем меньше мерцания

struct Color ColorRed    = { 14,  0,  0,  0 };
struct Color ColorReddish= { 1,  0,  0,  50 };
struct Color ColorOrange = { 8, 2,  0,  0 }; //+-
struct Color ColorGreen  = {  0, 10,  0,  0 };
struct Color ColorLime   = {  4,  10,  0,  0 }; //+
struct Color ColorBlue   = {  0,  0, 10,  0 };
struct Color ColorCyan   = {  0,  9, 10,  0 };
struct Color ColorPink   = { 7,  0,  1,  0 }; //+
struct Color ColorPurple = { 7,  0, 4,  0 }; //+-
struct Color ColorYellow = { 3,  2,  0,  0 }; //-
struct Color ColorWhite  = { 5,  12,  5,  0 }; //+
struct Color ColorBlack  = {  0,  0,  0, 99 }; 
struct Color ColorPerfectWhite = { 10,  10,  10,  0 };

typedef struct RgbController {
  uint8_t counter; //Internal use, state
  Color   (*color); //Current color, used as constant
  uint8_t (*red)(uint8_t); //Action for red color
  uint8_t (*green)(uint8_t); //Action for green color
  uint8_t (*blue)(uint8_t); //Action for blue color
} RgbController;

RgbController eyeL = { 0, &ColorBlack, &led_LR,  &led_LG,  &led_LB  };
RgbController eyeR = { 0, &ColorBlack, &led_RR,  &led_RG,  &led_RB  };

void processRgb ( struct RgbController *x ) {
  /*Counter reached end of red zone*/
  if ( x->counter == x->color->red ) {
    x->red(OFF);
    if (x->color->green)
      x->green(ON);
  };
  /*Counter reached end of green zone*/
  if ( x->counter == ( x->color->green
                     + x->color->red)) {
    x->green(OFF);
    if (x->color->blue)
      x->blue(ON);
  };
  /*Counter reached end of blue zone*/
  if ( x->counter == ( x->color->blue
                     + x->color->green
                     + x->color->red)) {
    x->blue(OFF);
  };
  /*Counter reached end. Entering red zone*/
  if ( x->counter >= ( x->color->blue
                     + x->color->green
                     + x->color->red
                     + x->color->black)) {
    if (x->color->red)
      x->red(ON);
    x->counter = 0;
    return;
  }
  x->counter++;
}

void
initEyes
( void ) {
  RCC -> APB1ENR1 |= RCC_APB1ENR1_TIM2EN;

  TIM2 -> ARR = 144;
  TIM2 -> PSC = 9;
  TIM2 -> DIER |= TIM_DIER_UIE;
  TIM2 -> CR1 |= TIM_CR1_CEN;
  NVIC_SetPriority(TIM2_IRQn,0);
  NVIC_EnableIRQ(TIM2_IRQn);
}

void
TIM2_IRQHandler
( void )
{
  TIM2 -> CR1 &= ~TIM_CR1_CEN;
  TIM2 -> SR &= ~TIM_SR_UIF;
  processRgb(&eyeL);
  processRgb(&eyeR);
  processMatrix();
  TIM2 -> CR1 |= TIM_CR1_CEN;
}
#endif
