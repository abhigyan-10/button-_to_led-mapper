#include <REG52.H>

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
void main()
{
    P2 = 0xFF;
    P1 = 0x00;

    while(1)
    {
			
        if(SW1 == 0)
				{
					delay();
					if(SW1 == 0)
					{
            P1 = 0xAA;
						while(SW1 == 0);
						delay();
					}
				}
				
				if(SW3 == 0)
				{
					delay();
					if(SW3 == 0)
					{
            P1 = 0x55;
						while(SW3 == 0);
						delay();
					}
				}
        
				if(SW4 == 0)
        {
					delay();
					if(SW4 == 0)
					{
            P1 = 0x11;
						while(SW4 == 0);
						delay();
					}
				}
        
    }
}
		
