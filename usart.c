#include "usart.h"

 
void Usart2_Init()           
 {
    GPIO_InitTypeDef   GPIO1_Ayar;
	  USART_InitTypeDef  USART1_Ayar;
	  NVIC_InitTypeDef   NVIC1_Ayar;
	  
	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	 
	 GPIO1_Ayar.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
   GPIO1_Ayar.GPIO_Mode = GPIO_Mode_AF;
   GPIO1_Ayar.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO1_Ayar.GPIO_OType = GPIO_OType_PP;
   GPIO1_Ayar.GPIO_PuPd = GPIO_PuPd_UP;
   GPIO_Init(GPIOA, &GPIO1_Ayar);
	 
	 GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART1);
   GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART1);
   
	 
	 USART1_Ayar.USART_BaudRate = 115200;
   USART1_Ayar.USART_WordLength = USART_WordLength_8b;
   USART1_Ayar.USART_StopBits = USART_StopBits_1;
   USART1_Ayar.USART_Parity = USART_Parity_No;
   USART1_Ayar.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
   USART1_Ayar.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
   USART_Init(USART2, &USART1_Ayar);
 
   USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	 
	 NVIC1_Ayar.NVIC_IRQChannel = USART2_IRQn;
   NVIC1_Ayar.NVIC_IRQChannelPreemptionPriority = 0;
   NVIC1_Ayar.NVIC_IRQChannelSubPriority = 0;
   NVIC1_Ayar.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC1_Ayar);
 
   USART_Cmd(USART2, ENABLE);
 }
  void USART_Gonder(USART_TypeDef* USARTx,char *s)
  {
 
 while(*s)
 { 
   while( !(USARTx->SR & 0x00000040) );
   USART_SendData(USARTx, *s);
   s++;
 }
 
  }