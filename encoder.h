#ifndef ENCODER_H
#define ENCODER_H

#include "stm32f4xx.h"

void Encoder_Config(void);
void Encoder_Set(int deger);
int  Read_Encoder_Value(void);
  
#endif