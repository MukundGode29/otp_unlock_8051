#include <reg51.h>

sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;

char key_val()
{
	c1=c2=c3=1;
	r1=r2=r3=r4=0;
	
	if(c1==0)//c1 is pressed
	{
		r1=r2=r3=r4=1;
		c1=c2=c3=0;
		
		if(r1==0)//r1 is pressed
		{
			while(r1 == 0);
			return '1';
		}
		if(r2==0)//r1 is pressed
		{
			while(r2 == 0);
			return '4';
		}
		if(r3==0)//r1 is pressed
		{
			while(r3 == 0);
			return '7';
		}
		if(r4==0)//r1 is pressed
		{
			while(r4 == 0);
			return '*';
		}
	}


	else if(c2==0)//c2 is pressed
	{
		r1=r2=r3=r4=1;
		c1=c2=c3=0;
		
		if(r1==0)//r1 is pressed
		{
			while(r1 == 0);
			return '2';
		}
		if(r2==0)//r2 is pressed
		{
			while(r2 == 0);
			return '5';
		}
		if(r3==0)//r3 is pressed
		{
			while(r3 == 0);
			return '8';
		}
		if(r4==0)//r4 is pressed
		{
			while(r4 == 0);
			return '0';
		}
	}	


	else if(c3==0)//c3 is pressed
	{
		r1=r2=r3=r4=1;
		c1=c2=c3=0;
		
		if(r1==0)//r1 is pressed
		{
			while(r1 == 0);
			return '3';
		}
		if(r2==0)//r2 is pressed
		{
			while(r2 == 0);
			return '6';
		}
		if(r3==0)//r3 is pressed
		{
			while(r3 == 0);
			return '9';
		}
		if(r4==0)//r4 is pressed
		{
			while(r4 == 0);
			return '#';
		}
	}

}