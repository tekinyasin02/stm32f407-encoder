#ifndef USART_H
#define USART_H

#include "stm32f4xx.h"

void Usart1_Init();
void USART_Gonder(USART_TypeDef* USARTx,char *s);

#endif