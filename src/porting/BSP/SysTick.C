#include "main.h"
 __IO uint32_t TimingDelay;
unsigned char time_flag = 0;

  
//SysTick��ʱ������1�����ж�һ��
void SysTick_Configuration(void)
{
	if (SysTick_Config(SystemCoreClock / 1000))
	{ 
		/* Capture error */ 
		while (1);
	}
}


//��ʱ���� ��λ������
void Delay(__IO uint32_t nTime)
{ 
	TimingDelay = nTime;
	while(TimingDelay != 0);
}
//��ʱ����
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
	}
}
//SysTick�жϺ���
void SysTick_Handler(void)
{	
	TimingDelay_Decrement();//������ʱ
}