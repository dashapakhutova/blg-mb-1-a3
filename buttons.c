#ifdef _CODE_BUTTONS
#else
#define _CODE_BUTTONS

uint8_t
isPressedLeft
( void )
{
  return (( GPIOA -> IDR ) & GPIO_IDR_ID0 ) == 0;
}

uint8_t
isPressedRight
( void )
{
  return (( GPIOB -> IDR ) & GPIO_IDR_ID13 ) == 0;
}

// 0b00 (0) : не нажаты
// 0b01 (1) : левая
// 0b10 (2) : правая
// 0b11 (3) : обе
uint8_t
checkButtons
( void )
{
  uint8_t btnL = (( GPIOA -> IDR ) & GPIO_IDR_ID0 ) == 0;
  uint8_t btnR = (( GPIOB -> IDR ) & GPIO_IDR_ID13 ) == 0;
  return ( btnL | ( btnR << 1 ));
}

#endif
