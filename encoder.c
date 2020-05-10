#include "encoder.h"


void Encoder_Config(void)
{
 GPIO_InitTypeDef phaseGpio;
 
 
 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
 phaseGpio.GPIO_Mode = GPIO_Mode_AF; 
 phaseGpio.GPIO_PuPd = GPIO_PuPd_UP; 
 phaseGpio.GPIO_Pin = GPIO_Pin_15;
 GPIO_Init(GPIOA, &phaseGpio);
 phaseGpio.GPIO_Pin = GPIO_Pin_3;
 GPIO_Init(GPIOB, &phaseGpio);
 
 GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_TIM2);
 GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_TIM2);
 
 TIM_SetAutoreload (TIM2, 0xffffffff);
  
 TIM_EncoderInterfaceConfig(TIM2,TIM_EncoderMode_TI1,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);  

 TIM_Cmd (TIM2, ENABLE);
}
void Encoder_Set(int deger)
{
 TIM_SetCounter (TIM2, deger);
}
int  Read_Encoder_Value(void)
{
 return TIM_GetCounter (TIM2);
}
