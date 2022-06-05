#include<reg51.h>
#include"lcd.h"
#include"keypad.h"
#include"delay.h"

char password[5] = {0};

void main()
{
	int i;
	
	LCD_Init();
	delay_ms(1000);
	//Write_cmd_LCD(0x01);
	Write_cmd_LCD(0x80);
	Write_str_LCD(" press any key ");
	//Write_cmd_LCD(0xc0);
	
		while(1)
		{
			for(i = 0; i < sizeof(password); i++)
			{
				char val = key_val();
				Write_cmd_LCD(val);
			
				password[i] = val;
				
			}
			
		}//while ends
	
}