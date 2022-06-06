#include<reg51.h>
#include"types.h"

sbit sda=P2^1;//data line
sbit scl=P2^0;//clock line
void i2c_start(void)
{
	scl=0;
	sda=1;
	scl=1;
	sda=0;
}
void i2c_stop(void)
{
	scl=0;
	sda=0;
	scl=1;
	sda=1;
}
void i2c_restart(void)
{
	scl=0;
	sda=1;
	scl=1;
	sda=0;
}
void i2c_byte_write(u8 dat)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
		scl=0;
		sda=(dat>>i)&1?1:0;	//Master is writing on the bus 
		scl=1;	
	}
}

u8 i2c_byte_read(void)
{
	u8 buf=0;
	s8 i;
	for(i=7;i>=0;i--)
	{
		scl=0;//so that slave can write onto the bus
		scl=1;
		if(sda==1)
			buf|=1<<i;
	}
	return buf;
}	
void slave_ack(void)
{
	scl=0;//master maskes the clk low
	scl=1;
	//if(sda==1)
		//i2c_stop();
	while(sda==1);
}	
void master_noack(void)
{
	scl=0;
	sda=1;
	scl=1;
}
void master_ack(void)
{
	scl=0;
	sda=0;//master is pulling the sda line low
	scl=1;
	scl=0;//master should produce clock pulse
	sda=1;//master is releasing the sda lin so that
      	//slave can regain the control
}
