#include <REG52.H>

#define pat_delay 15000UL

sbit SW1 = P2^0;
sbit SW2 = P2^1;
sbit SW3 = P2^2;
sbit SW4 = P2^3;

sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;
sbit LED4 = P1^3;

void delay()
{
	volatile unsigned int i;
	for(i = 0; i<1000;i++);
}

void pat1()
{
	volatile unsigned int i;
	volatile unsigned long j;	
	for(i = 0;i <= 7;i++)
	{
		P1 = (1<<i);
		for(j = 0; j<pat_delay;j++);
	}
}

void pat2()
{
	int i;
	volatile unsigned long j;	
	for(i = 7;i >= 0;i--)
	{
		P1 = (1<<i);
		for(j = 0; j<pat_delay;j++);
	}
}

void pat3()
{
	int i;
	volatile unsigned long j;	
	for(i = 0;i <= 4;i++)
	{
		P1 = 0xAA;
		for(j = 0; j<pat_delay;j++);
		P1 = 0x55;
		for(j = 0; j<pat_delay;j++);
	}
}

void switch1(){
	if(SW1 == 0)
	{
		delay();
		if(SW1 == 0)
		{
      pat1();
			while(SW1 == 0);
  		delay();
		}
	}
}

void switch3()
{
	if(SW3 == 0)
	{
		delay();
		if(SW3 == 0)
		{
      pat2();
			while(SW3 == 0);
			delay();
		}
	}
}

void switch4()
{
	if(SW4 == 0)
  {
		delay();
  	if(SW4 == 0)
		{
      pat3();
	  	while(SW4 == 0);
			delay();
		}
	}
}

void main()
{
    P2 = 0xFF;
    P1 = 0x00;
    while(1)
    {
      switch1();
			switch3();
			switch4();        
    }
}
		
