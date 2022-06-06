#include<reg51.h>
sbit r0=P1^0;
sbit r1=P1^1;
sbit r2=P1^2;
sbit r3=P1^3;
sbit c0=P1^4;
sbit c1=P1^5;
sbit c2=P1^6;
sbit c3=P1^7;
char code LUT[][4]={'0','1','2','3',
				'4','5','6','7',
				'8','9','+','-',
				'/','=',' ', ' '};
void row_Init(void)
{
	r0=r1=r2=r3=0;
}
bit col_stat(void)
{
	return(c0&&c1&&c2&&c3);
}
char key_val(void)
{
	char col_num,row_num;
	r0=0;r1=r2=r3=1;
		if(!col_stat())
		{
			row_num=0;
			goto col_check;
		}
		r1=0;r0=r2=r3=1;
		if(!col_stat())
		{
			row_num=1;
			goto col_check;
		}
		r2=0;r0=r1=r3=1;
		if(!col_stat())
		{
			row_num=2;
			goto col_check;
		}
		r3=0;r0=r1=r1=1;
		if(!col_stat())
			row_num=3;
 col_check:
		if(c0==0)
			col_num=0;
		else if(c1==0)
			col_num=1;
		else if(c2==0)
			col_num=2;
		else 
			col_num=3;
		while(!col_stat());//waiting for keyrelease
	return(LUT[row_num][col_num]);
}
