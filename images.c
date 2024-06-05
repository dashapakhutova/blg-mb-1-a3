#ifdef _CODE_IMAGES
#else
#define _CODE_IMAGES

#include "matrix.c"

void
copyMatrix1
( uint8_t ** m )
{
  for (uint8_t i=0;i<5;i++)
    for (uint8_t j=0;j<5;j++) {
      uint8_t v = 0;
      if ( m[j][i] ) v = 255;
      matrix[i][j]->value=v;
    }
}

void
copyMatrix
( uint8_t ** m )
{
  for (uint8_t i=0;i<5;i++)
    for (uint8_t j=0;j<5;j++) {
      matrix[i][j]->value = m[j][i];
    }
}

void
imageNone
( uint8_t x )
{
  uint8_t tmp1[5] = { x,x,x,x,x };
  uint8_t tmp2[5] = { x,x,x,x,x };
  uint8_t tmp3[5] = { x,x,x,x,x };
  uint8_t tmp4[5] = { x,x,x,x,x };
  uint8_t tmp5[5] = { x,x,x,x,x };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix(tmp);
}

void
imageArrowL
( void )
{
  matrix[0][0] -> value = 0;
  matrix[0][1] -> value = 0;
  matrix[0][2] -> value = 255;
  matrix[0][3] -> value = 0;
  matrix[0][4] -> value = 0;

  matrix[1][0] -> value = 0;
  matrix[1][1] -> value = 255;
  matrix[1][2] -> value = 255;
  matrix[1][3] -> value = 255;
  matrix[1][4] -> value = 0;

  matrix[2][0] -> value = 255;
  matrix[2][1] -> value = 0;
  matrix[2][2] -> value = 255;
  matrix[2][3] -> value = 0;
  matrix[2][4] -> value = 255;

  matrix[3][0] -> value = 0;
  matrix[3][1] -> value = 0;
  matrix[3][2] -> value = 255;
  matrix[3][3] -> value = 0;
  matrix[3][4] -> value = 0;

  matrix[4][0] -> value = 0;
  matrix[4][1] -> value = 0;
  matrix[4][2] -> value = 255;
  matrix[4][3] -> value = 0;
  matrix[4][4] -> value = 0;
}

void
imageArrowR
( void )
{
  matrix[4][0] -> value = 0;
  matrix[4][1] -> value = 0;
  matrix[4][2] -> value = 255;
  matrix[4][3] -> value = 0;
  matrix[4][4] -> value = 0;

  matrix[3][0] -> value = 0;
  matrix[3][1] -> value = 255;
  matrix[3][2] -> value = 255;
  matrix[3][3] -> value = 255;
  matrix[3][4] -> value = 0;

  matrix[2][0] -> value = 255;
  matrix[2][1] -> value = 0;
  matrix[2][2] -> value = 255;
  matrix[2][3] -> value = 0;
  matrix[2][4] -> value = 255;

  matrix[1][0] -> value = 0;
  matrix[1][1] -> value = 0;
  matrix[1][2] -> value = 255;
  matrix[1][3] -> value = 0;
  matrix[1][4] -> value = 0;

  matrix[0][0] -> value = 0;
  matrix[0][1] -> value = 0;
  matrix[0][2] -> value = 255;
  matrix[0][3] -> value = 0;
  matrix[0][4] -> value = 0;
}

void
imagePulse
( uint8_t counter
, uint8_t scale
)
{
  uint8_t f ( uint8_t x ) {
    if ( counter < x || counter > (0xff-x)) return 0;
    else return counter-x;
  }
#define D1 f(scale*0)
#define D2 f(scale*1)
#define D3 f(scale*2)
#define D4 f(scale*3)
#define D5 f(scale*4)
  matrix[0][0] -> value = 0;
  matrix[0][1] -> value = D4;
  matrix[0][2] -> value = D3;
  matrix[0][3] -> value = D4;
  matrix[0][4] -> value = 0;

  matrix[1][0] -> value = D4;
  matrix[1][1] -> value = D3;
  matrix[1][2] -> value = D2;
  matrix[1][3] -> value = D3;
  matrix[1][4] -> value = D4;

  matrix[2][0] -> value = D3;
  matrix[2][1] -> value = D2;
  matrix[2][2] -> value = D1;
  matrix[2][3] -> value = D2;
  matrix[2][4] -> value = D3;

  matrix[3][0] -> value = D4;
  matrix[3][1] -> value = D3;
  matrix[3][2] -> value = D2;
  matrix[3][3] -> value = D3;
  matrix[3][4] -> value = D4;

  matrix[4][0] -> value = 0;
  matrix[4][1] -> value = D4;
  matrix[4][2] -> value = D3;
  matrix[4][3] -> value = D4;
  matrix[4][4] -> value = 0;
}

void
imageBeatingHeart
( uint8_t counter )
{
  uint8_t f ( uint8_t x ) {
    if ( counter < x || counter > (0xff-x)) return 0;
    else return counter-x;
  }
#define A f(0)
#define B f(36)
#define C f(72)
#define D f(108)
#define E f(144)
#define F 0
  uint8_t tmp1[5] = { 0,D,0,D,0 };
  uint8_t tmp2[5] = { D,B,D,B,D };
  uint8_t tmp3[5] = { D,B,A,B,D };
  uint8_t tmp4[5] = { 0,D,B,D,0 };
  uint8_t tmp5[5] = { 0,0,D,0,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

uint64_t
pwr
( uint64_t x, uint8_t y )
{
  uint64_t result = 1;
  for (uint8_t i=0; i<y; i++)
    result *= x;
  return result;
}

uint8_t
powScale
( uint8_t x
, uint8_t p
) {
  uint64_t tmp1 = pwr(x,p);
  uint64_t tmp2 = pwr(0xff,p-1);
  uint64_t tmp = tmp1/tmp2;
  if ( tmp ) return tmp; else return 0;
}

void
imageCross
( uint8_t x )
{
  uint8_t val = powScale(x,3);
  matrix[4][0] -> value = val;
  matrix[4][1] -> value = 0;
  matrix[4][2] -> value = 0;
  matrix[4][3] -> value = 0;
  matrix[4][4] -> value = val;

  matrix[3][0] -> value = 0;
  matrix[3][1] -> value = val;
  matrix[3][2] -> value = 0;
  matrix[3][3] -> value = val;
  matrix[3][4] -> value = 0;

  matrix[2][0] -> value = 0;
  matrix[2][1] -> value = 0;
  matrix[2][2] -> value = val;
  matrix[2][3] -> value = 0;
  matrix[2][4] -> value = 0;

  matrix[1][0] -> value = 0;
  matrix[1][1] -> value = val;
  matrix[1][2] -> value = 0;
  matrix[1][3] -> value = val;
  matrix[1][4] -> value = 0;

  matrix[0][0] -> value = val;
  matrix[0][1] -> value = 0;
  matrix[0][2] -> value = 0;
  matrix[0][3] -> value = 0;
  matrix[0][4] -> value = val;
}

void
imageRomb
( void )
{
  matrix[4][0] -> value = 0;
  matrix[4][1] -> value = 0;
  matrix[4][2] -> value = 255;
  matrix[4][3] -> value = 0;
  matrix[4][4] -> value = 0;

  matrix[3][0] -> value = 0;
  matrix[3][1] -> value = 255;
  matrix[3][2] -> value = 0;
  matrix[3][3] -> value = 255;
  matrix[3][4] -> value = 0;

  matrix[2][0] -> value = 255;
  matrix[2][1] -> value = 0;
  matrix[2][2] -> value = 255;
  matrix[2][3] -> value = 0;
  matrix[2][4] -> value = 255;

  matrix[1][0] -> value = 0;
  matrix[1][1] -> value = 255;
  matrix[1][2] -> value = 0;
  matrix[1][3] -> value = 255;
  matrix[1][4] -> value = 0;

  matrix[0][0] -> value = 0;
  matrix[0][1] -> value = 0;
  matrix[0][2] -> value = 255;
  matrix[0][3] -> value = 0;
  matrix[0][4] -> value = 0;
}

void
imageSpiral
( uint16_t scale
, uint16_t value )
{
  uint8_t f ( uint16_t x ) {
    if ( value >= ( x*scale)) {
      if ( value >= (x+1) * scale) {
        return 255;
      }
      else {
        uint32_t tmp1 = value - x * scale;
        uint32_t tmp2 = powScale(( 0xff * tmp1 )/ scale, 3 );
        return tmp2;
      }
    }
    else return 0;
  }
  uint8_t tmp1[5] = { f(19),f(20),f(21),f(22),f(23) };
  uint8_t tmp2[5] = { f(18), f(5), f(6), f(7), f(8) };
  uint8_t tmp3[5] = { f(17), f(4), 0xff, f(0), f(9) };
  uint8_t tmp4[5] = { f(16), f(3), f(2), f(1),f(10) };
  uint8_t tmp5[5] = { f(15),f(14),f(13),f(12),f(11) };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix(tmp);
}

void
image1
( void )
{
  matrix[0][0] -> value = 0;
  matrix[0][1] -> value = 0;
  matrix[0][2] -> value = 0;
  matrix[0][3] -> value = 0;
  matrix[0][4] -> value = 0;

  matrix[1][0] -> value = 0;
  matrix[1][1] -> value = 255;
  matrix[1][2] -> value = 0;
  matrix[1][3] -> value = 0;
  matrix[1][4] -> value = 255;

  matrix[2][0] -> value = 255;
  matrix[2][1] -> value = 255;
  matrix[2][2] -> value = 255;
  matrix[2][3] -> value = 255;
  matrix[2][4] -> value = 255;

  matrix[3][0] -> value = 0;
  matrix[3][1] -> value = 0;
  matrix[3][2] -> value = 0;
  matrix[3][3] -> value = 0;
  matrix[3][4] -> value = 255;

  matrix[4][0] -> value = 0;
  matrix[4][1] -> value = 0;
  matrix[4][2] -> value = 0;
  matrix[4][3] -> value = 0;
  matrix[4][4] -> value = 0;
}

void
image2
( void )
{
  matrix[0][0] -> value = 0;
  matrix[0][1] -> value = 0;
  matrix[0][2] -> value = 0;
  matrix[0][3] -> value = 0;
  matrix[0][4] -> value = 0;

  matrix[1][0] -> value = 0;
  matrix[1][1] -> value = 255;
  matrix[1][2] -> value = 0;
  matrix[1][3] -> value = 0;
  matrix[1][4] -> value = 255;

  matrix[2][0] -> value = 255;
  matrix[2][1] -> value = 0;
  matrix[2][2] -> value = 0;
  matrix[2][3] -> value = 255;
  matrix[2][4] -> value = 255;

  matrix[3][0] -> value = 0;
  matrix[3][1] -> value = 255;
  matrix[3][2] -> value = 255;
  matrix[3][3] -> value = 0;
  matrix[3][4] -> value = 255;

  matrix[4][0] -> value = 0;
  matrix[4][1] -> value = 0;
  matrix[4][2] -> value = 0;
  matrix[4][3] -> value = 0;
  matrix[4][4] -> value = 0;
}

void
image3
( void )
{
  matrix[0][0] -> value = 0;
  matrix[0][1] -> value = 0;
  matrix[0][2] -> value = 0;
  matrix[0][3] -> value = 0;
  matrix[0][4] -> value = 0;

  matrix[1][0] -> value = 255;
  matrix[1][1] -> value = 0;
  matrix[1][2] -> value = 0;
  matrix[1][3] -> value = 0;
  matrix[1][4] -> value = 255;

  matrix[2][0] -> value = 255;
  matrix[2][1] -> value = 0;
  matrix[2][2] -> value = 255;
  matrix[2][3] -> value = 0;
  matrix[2][4] -> value = 255;

  matrix[3][0] -> value = 0;
  matrix[3][1] -> value = 255;
  matrix[3][2] -> value = 0;
  matrix[3][3] -> value = 255;
  matrix[3][4] -> value = 0;

  matrix[4][0] -> value = 0;
  matrix[4][1] -> value = 0;
  matrix[4][2] -> value = 0;
  matrix[4][3] -> value = 0;
  matrix[4][4] -> value = 0;
}

void
image4
( void )
{
  uint8_t tmp1[5] = { 0,0,0,1,0 };
  uint8_t tmp2[5] = { 0,0,1,0,0 };
  uint8_t tmp3[5] = { 0,1,0,1,0 };
  uint8_t tmp4[5] = { 0,1,1,1,1 };
  uint8_t tmp5[5] = { 0,0,0,1,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
image5
( void )
{
  uint8_t tmp1[5] = { 0,1,1,1,0 };
  uint8_t tmp2[5] = { 0,1,0,0,0 };
  uint8_t tmp3[5] = { 0,1,1,1,0 };
  uint8_t tmp4[5] = { 0,0,0,1,0 };
  uint8_t tmp5[5] = { 0,1,1,0,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
image6
( void )
{
  uint8_t tmp1[5] = { 0,0,1,1,0 };
  uint8_t tmp2[5] = { 0,1,0,0,0 };
  uint8_t tmp3[5] = { 0,1,1,1,0 };
  uint8_t tmp4[5] = { 0,1,0,0,1 };
  uint8_t tmp5[5] = { 0,0,1,1,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
image7
( void )
{
  uint8_t tmp1[5] = { 0,1,1,1,1 };
  uint8_t tmp2[5] = { 0,1,0,0,1 };
  uint8_t tmp3[5] = { 0,0,0,1,0 };
  uint8_t tmp4[5] = { 0,0,1,0,0 };
  uint8_t tmp5[5] = { 0,0,1,0,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
image8
( void )
{
  uint8_t tmp1[5] = { 0,0,1,1,0 };
  uint8_t tmp2[5] = { 0,1,0,0,1 };
  uint8_t tmp3[5] = { 0,0,1,1,0 };
  uint8_t tmp4[5] = { 0,1,0,0,1 };
  uint8_t tmp5[5] = { 0,0,1,1,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
image9
( void )
{
  uint8_t tmp1[5] = { 0,0,1,1,0 };
  uint8_t tmp2[5] = { 0,1,0,0,1 };
  uint8_t tmp3[5] = { 0,0,1,1,1 };
  uint8_t tmp4[5] = { 0,0,0,0,1 };
  uint8_t tmp5[5] = { 0,0,1,1,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
image0
( void )
{
  uint8_t tmp1[5] = { 0,0,1,1,0 };
  uint8_t tmp2[5] = { 0,1,0,0,1 };
  uint8_t tmp3[5] = { 0,1,1,1,1 };
  uint8_t tmp4[5] = { 0,1,0,0,1 };
  uint8_t tmp5[5] = { 0,0,1,1,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
imageA
( void )
{
  uint8_t tmp1[5] = { 0,0,0,0,1 };
  uint8_t tmp2[5] = { 0,0,0,1,1 };
  uint8_t tmp3[5] = { 0,0,1,0,1 };
  uint8_t tmp4[5] = { 0,1,1,1,1 };
  uint8_t tmp5[5] = { 1,0,0,0,1 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
imageB
( void )
{
  uint8_t tmp1[5] = { 1,1,0,0,0 };
  uint8_t tmp2[5] = { 1,0,1,0,0 };
  uint8_t tmp3[5] = { 1,1,1,0,0 };
  uint8_t tmp4[5] = { 1,0,0,1,0 };
  uint8_t tmp5[5] = { 1,1,1,0,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
imageC
( void )
{
  uint8_t tmp1[5] = { 0,1,1,0,0 };
  uint8_t tmp2[5] = { 1,0,0,1,0 };
  uint8_t tmp3[5] = { 1,0,0,0,0 };
  uint8_t tmp4[5] = { 1,0,0,0,0 };
  uint8_t tmp5[5] = { 0,1,1,1,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
imageD
( void )
{
  uint8_t tmp1[5] = { 1,1,0,0,0 };
  uint8_t tmp2[5] = { 1,0,1,0,0 };
  uint8_t tmp3[5] = { 1,0,0,1,0 };
  uint8_t tmp4[5] = { 1,0,0,1,0 };
  uint8_t tmp5[5] = { 1,1,1,0,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
imageE
( void )
{
  uint8_t tmp1[5] = { 1,1,1,1,0 };
  uint8_t tmp2[5] = { 1,0,0,1,0 };
  uint8_t tmp3[5] = { 1,1,0,0,0 };
  uint8_t tmp4[5] = { 1,0,0,1,0 };
  uint8_t tmp5[5] = { 1,1,1,1,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
imageF
( void )
{
  uint8_t tmp1[5] = { 1,1,1,1,0 };
  uint8_t tmp2[5] = { 1,0,0,0,0 };
  uint8_t tmp3[5] = { 1,1,1,0,0 };
  uint8_t tmp4[5] = { 1,0,0,0,0 };
  uint8_t tmp5[5] = { 1,0,0,0,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix1(tmp);
}

void
imageExclamation
( uint8_t x )
{
  uint8_t tmp1[5] = { 0,0,x,0,0 };
  uint8_t tmp2[5] = { 0,x,x,x,0 };
  uint8_t tmp3[5] = { 0,0,x,0,0 };
  uint8_t tmp4[5] = { 0,0,0,0,0 };
  uint8_t tmp5[5] = { 0,0,x,0,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix(tmp);
}

void
imageSmile
( uint8_t x )
{
  uint8_t tmp1[5] = { 0,x,0,x,0 };
  uint8_t tmp2[5] = { 0,0,0,0,0 };
  uint8_t tmp3[5] = { x,0,0,0,x };
  uint8_t tmp4[5] = { 0,x,x,x,0 };
  uint8_t tmp5[5] = { 0,0,0,0,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix(tmp);
}

void
imageHeart
( uint8_t x )
{
  uint8_t tmp1[5] = { 0,x,0,x,0 };
  uint8_t tmp2[5] = { x,x,x,x,x };
  uint8_t tmp3[5] = { x,x,x,x,x };
  uint8_t tmp4[5] = { 0,x,x,x,0 };
  uint8_t tmp5[5] = { 0,0,x,0,0 };
  uint8_t * tmp[5] = { tmp1, tmp2, tmp3, tmp4, tmp5 };
  copyMatrix(tmp);
}

void
imageMusic
( void )
{
  matrix[0][0] -> value = 0;
  matrix[0][1] -> value = 0;
  matrix[0][2] -> value = 0;
  matrix[0][3] -> value = 255;
  matrix[0][4] -> value = 0;

  matrix[1][0] -> value = 0;
  matrix[1][1] -> value = 0;
  matrix[1][2] -> value = 0;
  matrix[1][3] -> value = 255;
  matrix[1][4] -> value = 255;

  matrix[2][0] -> value = 255;
  matrix[2][1] -> value = 255;
  matrix[2][2] -> value = 255;
  matrix[2][3] -> value = 255;
  matrix[2][4] -> value = 255;

  matrix[3][0] -> value = 0;
  matrix[3][1] -> value = 255;
  matrix[3][2] -> value = 0;
  matrix[3][3] -> value = 0;
  matrix[3][4] -> value = 0;

  matrix[4][0] -> value = 0;
  matrix[4][1] -> value = 0;
  matrix[4][2] -> value = 0;
  matrix[4][3] -> value = 0;
  matrix[4][4] -> value = 0;
}

void
imageDigit
( uint16_t n )
{
  switch ( n % 11 ) {
    case 0: imageHeart(255); break;
    case 1: image1(); break;
    case 2: image2(); break;
    case 3: image3(); break;
    case 4: image4(); break;
    case 5: image5(); break;
    case 6: image6(); break;
    case 7: image7(); break;
    case 8: image8(); break;
    case 9: image9(); break;
    case 10: image0(); break;
    //case 10: imageA(); break;
    case 11: imageB(); break;
    case 12: imageC(); break;
    case 13: imageD(); break;
    case 14: imageE(); break;
    case 15: imageF(); break;
    default: break;
  }
}

void
imageCountdown
( uint16_t counter )
{
  switch ( counter / 100 ) {
    case 0: image3(); break;
    case 1: image2(); break;
    case 2: image1(); break;
    // case 3: image2(); break;
    // case 4: image1(); break;
    case 5: imageMusic(); break;
    default: randomMatrix(); break;
  }
}

#endif
