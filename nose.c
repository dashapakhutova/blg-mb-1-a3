#ifdef _CODE_NOSE
#else
#define _CODE_NOSE

static
inline
void
enableADC
( ADC_TypeDef * adc )
{
  adc -> ISR |= ADC_ISR_EOC;
  adc -> ISR |= ADC_ISR_ADRDY; //Сброс флага готовности
  adc -> CR |= ADC_CR_ADEN; //Запуск АЦП
  while (( adc -> ISR & ADC_ISR_ADRDY ) == 0); //Ждём окончания инициализации АЦП
  adc -> ISR |= ADC_ISR_ADRDY; //Сброс флага готовности
}

static
inline
void
disableADC
( ADC_TypeDef * adc )
{
  adc -> CR |= ADC_CR_ADSTP; //Останавливаем идущие измерения
  while ((adc -> CR) & ADC_CR_ADSTP);
  adc -> CR |= ADC_CR_ADDIS; //Запускаем отключение АЦП
  while ((adc -> CR) & ADC_CR_ADEN); //Ждём, пока не отключится
}

void
calibrateADC
( ADC_TypeDef * adc )
{
  disableADC(adc);
  adc -> CR |= ADC_CR_ADCAL; //Запускаем процедуру калибровки
  while((adc -> CR ) & ADC_CR_ADCAL); //Ждём окончания процедуры калибровки
}

inline static void confADCpins(void) {
  RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
  initPin_Analog(GPIOB,14); //1+
}

void
initADC_Common
( void )
{
  RCC -> AHB2ENR |= RCC_AHB2ENR_ADC12EN; //Затактовать АЦП
  RCC -> CCIPR |= ( 0b11 << RCC_CCIPR_ADC12SEL_Pos);
  ADC12_COMMON -> CCR |= ( 0b1000 << ADC_CCR_PRESC_Pos );
  ADC12_COMMON -> CCR |= ( 0b01 << ADC_CCR_CKMODE_Pos );
  confADCpins();
}

void
initADC1
( void )
{
  ADC1 -> CR |= ADC_CR_ADDIS;
  ADC1 -> CR &= ~ADC_CR_DEEPPWD;
  ADC1 -> CR |= ADC_CR_ADVREGEN;
  delay(3); //p277 s14.3.2 RM0454
  ADC1 -> CFGR |= ADC_CFGR_CONT; //Непрерывный режим. Не забыть ADSTART
  ADC1 -> SMPR1 = ( 0b101 << ADC_SMPR1_SMP3_Pos ); //Частота сэмплирования. Торопиться некуда. Около 17 микросекунд
  ADC1 -> CFGR &= ~ ADC_CFGR_RES_Msk; //Разрешение 12 бит.
  ADC1 -> CFGR &= ~ ADC_CFGR_ALIGN; //Выравнивание вправо, для 12 бит самое то.
  ADC1 -> CFGR |= ADC_CFGR_OVRMOD; //Перезаписывание непрочтённых данных
  //ADC1 -> DIFSEL |= ADC_DIFSEL_DIFSEL_1;
  ADC1 -> SQR1 = ( 0 << ADC_SQR1_L_Pos )
               | ( 5 << ADC_SQR1_SQ1_Pos ) //RM0440 p392 t69
               ;
  //Калибровка
  calibrateADC(ADC1);
  enableADC(ADC1);
  ADC1 -> CR |= ADC_CR_ADSTART;
}

uint16_t
senseNose
( void )
{
  return ADC1->DR;
}

#endif
