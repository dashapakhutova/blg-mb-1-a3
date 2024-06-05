#ifdef _CODE_UART
#else
#define _CODE_UART

#define BAUDRATE_DEFAULT 115200
#define COMMAND_BUFFER_SIZE 20
#define OUTPUT_BUFFER_SIZE 20
#define PRIORITY_UART_SEND 10
#define PRIORITY_UART_COMMAND 11

volatile uint16_t inputSwitch1 = 0;
volatile uint16_t inputSwitch2 = 0;

uint8_t
initUART
( uint32_t rate ) {
  //RCC -> APB2RSTR |= RCC_APB2RSTR_USART1RST;
  //RCC -> APB2RSTR &= ~RCC_APB2RSTR_USART1RST;
  uint8_t result = 0;

  RCC -> APB2ENR |= RCC_APB2ENR_USART1EN;
  USART1 -> CR1 &= ~USART_CR1_UE;
  RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
  //RCC -> AHB1ENR |= RCC_AHB1ENR_DMA1EN;
  USART1 -> CR1 &= ~USART_CR1_UE;
  USART1 -> CR1 &= ~USART_CR1_FIFOEN;
  USART1 -> CR2 |= ( 0b10 << USART_CR2_STOP_Pos );
  initPin_AF_PP ( GPIOC, 4, 7 );
  initPin_AF_PP ( GPIOC, 5, 7 );

  //Бит M не настраиваем (вроде умолчание хорошее)
  USART1 -> BRR = (uint32_t)(PCLK/rate);
  //Число стоповых бит не настраиваем (вроде умолчание хорошее)
  //NB CR1_CMIE
  //USART1 -> CR2 |= USART_CR2_SWAP; //Меняем местами ноги
  //USART1 -> PRESC |= 0b0110/*12*/;

  USART1 -> CR1 |= USART_CR1_RXNEIE;

  USART1 -> CR1 |= USART_CR1_UE;
  USART1 -> CR1 |= USART_CR1_RE;
  USART1 -> CR1 |= USART_CR1_TE;

  NVIC_EnableIRQ(USART1_IRQn);
  return result;
}

__attribute__((optimize("O0"))) 
void putChar (uint8_t x) {
  while ((USART1 -> ISR & USART_ISR_TXE_TXFNF)==0);
  USART1 -> TDR = x;
}

// Это отладочная функция, чтобы делать putString("Hell, o world!")
void putString (char *x) {
  int i=0;
  while (x[i] != 0)
    putChar(x[i++]);
}

void USART1_IRQHandler (void) {
  if (( USART1 -> ISR && USART_ISR_RXNE_RXFNE ) > 0 ) {
    //processByteDirectly(USART1->RDR);
    if (( USART1->RDR ) == '!' ) {
      scHeartExclamation = 1;
      scHeartCounter = 255;
    }
    else {
      scHeartExclamation = 0;
      scHeartCounter = 255;
    }
  }
  USART1 -> RQR |= USART_RQR_RXFRQ; //Не нужно, этот флаг сбрасывается сразу при чтении из RDR
}

#endif
