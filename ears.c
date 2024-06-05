#ifdef _CODE_EARS
#else
#define _CODE_EARS

#include "nose.c"

void
initOPAMP2
( void )
{
  RCC -> APB2ENR |= RCC_APB2ENR_SYSCFGEN;
  initPin_Analog(GPIOA,5);
  initPin_Analog(GPIOA,7);
  OPAMP2 -> CSR |= (0b10 << OPAMP_CSR_VMSEL_Pos);
  OPAMP2 -> CSR |= ( 0b01100 << OPAMP_CSR_PGGAIN_Pos );
  OPAMP2 -> CSR |= OPAMP_CSR_OPAMPINTEN;
  OPAMP2 -> CSR |= (0b00 << OPAMP_CSR_VPSEL_Pos);
  OPAMP2 -> CSR |= OPAMP_CSR_OPAMPxEN;
}

void
initADC2
( void )
{
  ADC2 -> CR |= ADC_CR_ADDIS;
  ADC2 -> CR &= ~ADC_CR_DEEPPWD;
  ADC2 -> CR |= ADC_CR_ADVREGEN;
  delay(3); //p277 s14.3.2 RM0454
  ADC2 -> CFGR |= ADC_CFGR_CONT; //Непрерывный режим. Не забыть ADSTART
  ADC2 -> SMPR1 = ( 0b101 << ADC_SMPR1_SMP3_Pos ); //Частота сэмплирования. Торопиться некуда. Около 17 микросекунд
  ADC2 -> CFGR &= ~ ADC_CFGR_RES_Msk; //Разрешение 12 бит.
  ADC2 -> CFGR &= ~ ADC_CFGR_ALIGN; //Выравнивание вправо, для 12 бит самое то.
  ADC2 -> CFGR |= ADC_CFGR_OVRMOD; //Перезаписывание непрочтённых данных
  //ADC2 -> DIFSEL |= ADC_DIFSEL_DIFSEL_3;
  ADC2 -> SQR1 = ((1-1) << ADC_SQR1_L_Pos )
               | ( 16 << ADC_SQR1_SQ1_Pos ) //RM0440 p392 t69
               ;
  //Калибровка
  calibrateADC(ADC2);
  enableADC(ADC2);
  ADC2 -> CR |= ADC_CR_ADSTART;
}

uint16_t
senseEarLeft
( void )
{
  return ADC2->DR;
}

#endif
