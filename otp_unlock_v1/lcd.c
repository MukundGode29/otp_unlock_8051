#include<reg51.h>
#include"delay.h"
#include"lcd.h"

#define LCD_DAT P0
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;


void LCD_Init(void)
{
	delay_ms(16);	
	Write_cmd_LCD(0x30);
	delay_ms(6);	
	Write_cmd_LCD(0x30);
	delay_ms(1);	
	Write_cmd_LCD(0x30);
	delay_ms(1);
	Write_cmd_LCD(0x30);//8-bit interface 
				//5X7 font and 1-line disp
	Write_cmd_LCD(0x10);//To turn off the disp
	Write_cmd_LCD(0x01);//To clear the disp
	Write_cmd_LCD(0x06);//Inc the cursor
				//after writing each byte on to the disp
	Write_cmd_LCD(0x0f);//Disp ON cur ON with blinking
}
void Write_cmd_LCD(unsigned char cmd)
{
	rs=0;
	disp_LCD(cmd);
}
void Write_dat_LCD(unsigned char dat)
{
	rs=1;
	disp_LCD(dat);
}
void disp_LCD(unsigned char ch)
{
	LCD_DAT=ch;
	rw=0;
	en=1;
	en=0;
	delay_ms(2);

}
void Write_str_LCD(char *ptr)
{
	while(*ptr!='\0')
		Write_dat_LCD(*ptr++);		
}
char code a[]={0x1f,0x11,0x11,0x11,0x11,0x1f,0x1f,0x00};
void store_font_CGRAM(void)
{
	char i;
	Write_cmd_LCD(0x40);//Placing the cursor in CGRAM
	for(i=0;i<=7;i++)
		Write_dat_LCD(a[i]);	
}

