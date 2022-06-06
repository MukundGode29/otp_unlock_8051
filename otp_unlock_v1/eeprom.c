#include"i2c.h"
#include"delay.h"
#include"types.h"
void random_byte_write(u8 da,u8 buff_addr,u8 dat_byte)
{
	i2c_start();
	i2c_byte_write(da);
	slave_ack();
	i2c_byte_write(buff_addr);
	slave_ack();
	i2c_byte_write(dat_byte);
	slave_ack();
	i2c_stop();
	delay_ms(10);
}
u8 random_byte_read(u8 da,u8 buff_addr)
{
	u8 temp;
	i2c_start();
	i2c_byte_write(da);
	slave_ack();
	i2c_byte_write(buff_addr);
	slave_ack();
	i2c_restart();
	i2c_byte_write(da|0x01);
	slave_ack();
	temp=i2c_byte_read();
	master_noack();
	i2c_stop();
	return(temp);
}
void page_byte_write(u8 da,u8 buff_addr,u8 *p,u8 cnt)
{
	u8 i=0; 	
	i2c_start();
	i2c_byte_write(da);
	slave_ack();
	i2c_byte_write(buff_addr);
	slave_ack();
	for(i=0;i<cnt;i++)
	{
		i2c_byte_write(*(p+i));
		slave_ack();
	}
	i2c_stop();
	delay_ms(10);
}
u8* page_byte_read(u8 da,u8 buff_addr,u8 cnt)
{
	u8 i,a[10];
	i2c_start();
	i2c_byte_write(da);
	slave_ack();
	i2c_byte_write(buff_addr);
	slave_ack();
	i2c_restart();
	i2c_byte_write(da|0x01);
	slave_ack();
	for(i=0;i<(cnt-1);i++)
	{
		a[i]=i2c_byte_read();
		master_ack();
	}
	a[i]=i2c_byte_read();
	master_noack();
	i2c_stop();
	a[i+1]='\0';
	return a;
}
