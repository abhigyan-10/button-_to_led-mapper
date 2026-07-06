#include <REG52.H>
#define pat_delay 15000UL
#define btn_num 3

void debounce_delay(){
	volatile unsigned int i;
	for(i = 0; i<1000;i++);
}

void pat1(){
	volatile unsigned int i;
	volatile unsigned long j;	
	for(i = 0;i <= 7;i++)
	{
		P1 = (1<<i);
		for(j = 0; j<pat_delay;j++);
	}
}

void pat2(){
	int i;
	volatile unsigned long j;	
	for(i = 7;i >= 0;i--)
	{
		P1 = (1<<i);
		for(j = 0; j<pat_delay;j++);
	}
}

void pat3(){
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

typedef struct{
	unsigned char bits;
	void (*fp)(void);
}ButtonMap;

ButtonMap map[] ={
			{0 , pat1},
			{2 , pat2},
			{3 , pat3}
		};
void main()
{
    P2 = 0xFF;
    P1 = 0x00;
		while(1)
		{
			unsigned char i;
			for(i =0; i<btn_num;i++)
			{
				if((P2 & (1<<map[i].bits)) == 0)
				{
					debounce_delay();
					if((P2 & (1<<map[i].bits)) == 0)
					{
						map[i].fp();
						while((P2 & (1<<map[i].bits)) == 0);
						debounce_delay();
					}
				}
			}
		}
}
		
