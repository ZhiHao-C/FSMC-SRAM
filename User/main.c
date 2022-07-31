#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "bps_usart.h"
#include <stdio.h>
#include "FSMC_SRAM.h"
//在SRAM_BASE_ADDR地址上存储一个值为testvalue的数据（只能定义为全局变量，括号不能少）
uint8_t testvalue __attribute__ ((at(SRAM_BASE_ADDR)));
//uint8_t a[10]={1,2,3,4,5,6,7,8,9,10};

void delay_ms(int n)//延时函数
{
	int i;
	while (n--)
	{
		for(i=0;i<5520;i++);
	}
}



int main()
{
	uint8_t *p;
	uint16_t *p16;
	USART_Config();
	FSMC_SRAM_Init();
	//往SRAM写入数据
	p=(uint8_t *)SRAM_BASE_ADDR;
	*p=0xab;
	printf("读出的数据内容为 0x=%x",*p);
	
	
	p16=(uint16_t *)(SRAM_BASE_ADDR+10);
	*p16=0xabcd;
	printf("读出的数据内容为 0x=%x",*p16);
	
	
}


////接收触发中断函数
//void DEBUG_USART_IRQHandler(void)
//{
//	uint8_t temp;
//	if((USART1->SR&0x20)==0x20)
//	{
//		temp=USART_ReceiveData(USART1);
//		USART_SendData(USART1,temp);
//		while (!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
//	}
//}	



