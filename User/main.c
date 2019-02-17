#include "stm32f10x.h"
#include "led.h"
#include "system.h"
#include "SysTick.h"
#include "USART.h"
#include "key.h"
#include "adc.h"

int main()
{
	u8 i=0;
	u16 AD_Value=0;
	float voltage=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�ж����ȼ�����
	LED_Init();
	USART1_Init(9600);
	ADCp_Init();
	
	while(1)
	{
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		if(i%50==0)
		{
			AD_Value=Get_ADC_Value(ADC_Channel_1,20);  
			printf("���ADֵΪ��%d\r\n",AD_Value);  //��ӡAD��ֵ
			voltage=(float)AD_Value*(3.3/4096);   //��AD��12λת��Ϊ��ѹ��3.3V
		  printf("����ѹֵΪ��%.2fV\r\n",voltage);  //��ӡ��ѹ��ֵ	
		}			
		
		delay_ms(10);
	}
	
	
}

