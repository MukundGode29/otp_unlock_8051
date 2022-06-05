#include"delay.h"
void delay_ms(unsigned int i)
{
	int j;
	for(;i>0;i--)
		for(j=122;j>0;j--);
}