#include "main.h"
#include "stdbool.h"

long int counter = 0;
char veri[10];
int oldCounter = 0;
char karakter;
bool durum = true;
float adim = 0.2735;
int metre=0;

void USART2_IRQHandler()
{
  while(USART_GetITStatus(USART2, USART_IT_RXNE))
{

   karakter = USART2->DR; 
    if(karakter != '\0')    
  {    
    karakterAl(karakter);    
  }        
}
}

void karakterAl(char data)
{
  if(data=='b')
  {
      durum=false;
      Encoder_Config();
      Encoder_Set(0);
  }
  else if (data=='d')
  {
    Encoder_Set(0);
    durum=true;
  }
  else if(data=='m')
  {
    counter=Read_Encoder_Value();
    metre = adim*counter ;
    sprintf(veri,"%d",metre);
    USART_Gonder(USART2,"*");
    USART_Gonder(USART2,veri);
    USART_Gonder(USART2,"&");
  }

}

int main()
{
  Usart2_Init();
  Encoder_Config();
  Encoder_Set(0);
  USART_Gonder(USART2,"Usart2 Hazir\n\r");


   while(1)
   {
      if(durum==true)
      {
      Encoder_Set(0);
      }     
//      counter=Read_Encoder_Value();
//      if(oldCounter != counter)
//      {
////      metre = adim*counter;
//      sprintf(veri,"%d\n",counter);
//      USART_Gonder(USART2,veri);
//      oldCounter=counter;  
//     }    
   }

}


