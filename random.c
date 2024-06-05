#ifdef _CODE_RANDOM
#else
#define _CODE_RANDOM

uint8_t seeded = false;

uint32_t seed;

#define RAND_A 1103515245
#define RAND_C 12345
#define RAND_M 2147483648

uint32_t myRandom()
{
  if ( seeded ) {
    seed = ( RAND_A * seed + RAND_C ) % RAND_M;
    return seed;
  }
  else {
    seed = SysTick -> VAL;
    seeded = true;
    myRandom();
  }
}

void
randomMatrix
( void )
{
  for (uint8_t i = 0; i<5; i++ ) {
    for (uint8_t j = 0; j<5; j++ ) {
      //if ( myRandom() > 1073741824 )
      if ( myRandom() > 1273741824 ) //Вероятность зажигания ниже 50%: из-за «зайчиков» она воспринимается повышенной
        matrix[i][j] -> value = 255;
      else
        matrix[i][j] -> value = 0;
    }
  }
}

#endif
