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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //中断优先级分组
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
			printf("检测AD值为：%d\r\n",AD_Value);  //打印AD的值
			voltage=(float)AD_Value*(3.3/4096);   //将AD的12位转换为电压的3.3V
		  printf("检测电压值为：%.2fV\r\n",voltage);  //打印电压的值	
		}			
		
		delay_ms(10);
	}
	
	
}

