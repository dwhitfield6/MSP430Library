#include <msp430.h>
#include "RF_a.h"

void resetBuffer(unsigned int* Array, unsigned char amount)
{
	int i ;
	for(i =0; i<=(amount -1);i++)
	{
		Array[i] =0;
	}
}

void resetBufferChar(unsigned char* Array, unsigned char amount)
{
	int i ;
	for(i =0; i<=(amount -1);i++)
	{
		Array[i] =0;
	}
}

void send_rf_conf2(unsigned char pin, unsigned char* data)
{
unsigned char i=0;

for(i=0;i<16;i++)
	{
		if(data[i] == 0)
		{
			zero_conf2(pin);
		}
		else
		{
			one_conf2(pin);
		}
	}

#ifdef trans_polarity
P2OUT &= ~pin;
_delay_cycles(SYNCsyncCONF2);
#else
P2OUT |= pin;
_delay_cycles(SYNCsyncCONF2);
#endif

}

void zero_conf2(unsigned char pin)
{
#ifdef trans_polarity
	P2OUT |= pin;
	_delay_cycles(ZEROshortCONF2);
	P2OUT &= ~pin;
	_delay_cycles(ZEROlongCONF2);
#else
	P2OUT &= ~pin;
	_delay_cycles(ZEROshortCONF2);
	P2OUT |= pin;
	_delay_cycles(ZEROlongCONF2);
#endif



}
void one_conf2(unsigned char pin)
{

#ifdef trans_polarity
	P2OUT |= pin;
	_delay_cycles(ONElongCONF2);
	P2OUT &= ~pin;
	_delay_cycles(ONEshortCONF2);
#else
	P2OUT &= ~pin;
	_delay_cycles(ONElongCONF2);
	P2OUT |= pin;
	_delay_cycles(ONEshortCONF2);
#endif

}

void send_rf(unsigned char pin, unsigned char* data)
{
unsigned char i=0;

for(i=0;i<12;i++)
	{
		if(data[i] == 0)
		{
			zero(pin);
		}
		else if(data[i] ==1)
		{
			one(pin);
		}
		else
		{
			f(pin);
		}
	}

P2OUT |= pin;
_delay_cycles(250);
P2OUT &= ~pin;
_delay_cycles(7000);
}

void zero(unsigned char pin)
{
	P2OUT |= pin;
	_delay_cycles(250);
	P2OUT &= ~pin;
	_delay_cycles(690);
	P2OUT |= pin;
	_delay_cycles(250);
	P2OUT &= ~pin;
	_delay_cycles(690);
}
void one(unsigned char pin)
{
	P2OUT |= pin;
	_delay_cycles(810);
	P2OUT &= ~pin;
	_delay_cycles(210);
	P2OUT |= pin;
	_delay_cycles(810);
	P2OUT &= ~pin;
	_delay_cycles(210);
}
void f(unsigned char pin)
{
	P2OUT |= pin;
	_delay_cycles(250);
	P2OUT &= ~pin;
	_delay_cycles(700);
	P2OUT |= pin;
	_delay_cycles(810);
	P2OUT &= ~pin;
	_delay_cycles(200);
}

unsigned char ArrayCompare(unsigned int* Array1, unsigned int* Array2, int amount, unsigned char characters)
{
	int i;
	unsigned char differences =0;
	for(i=0;i<=(characters -1);i++ )
	{
		if(((int)Array1[i] - (int)Array2[i]) > amount)
		{
		differences++;
		}
		else if(((int)Array2[i] - (int)Array1[i]) > amount)
		{
			differences++;
		}
	}
	return (differences ? 0 : 1);
}

unsigned char ArrayCompareChar(unsigned char* Array1, unsigned char* Array2, int amount, unsigned char characters)
{
	int i;
	unsigned char differences =0;
	for(i=0;i<=(characters -1);i++ )
	{
		if(((int)Array1[i] - (int)Array2[i]) > amount)
		{
		differences++;
		}
		else if(((int)Array2[i] - (int)Array1[i]) > amount)
		{
			differences++;
		}
	}
	return (differences ? 0 : 1);
}

void ArrayCopy(unsigned int* from, unsigned int* to, unsigned char characters)
{
	int i;
	for(i=0;i<=(characters -1);i++ )
	{
		to[i] = from[i];
	}
}

void ArrayCopyChar(unsigned char* from, unsigned char* to, unsigned char characters)
{
	int i;
	for(i=0;i<=(characters -1);i++ )
	{
		to[i] = from[i];
	}
}

unsigned char readSwitchP2(unsigned char bit)
{
	int i =0;
	int count =0;

	for(i=10;i>0;i--)
	             {
	           	    if((P2IN & bit) == bit)
	           	    {
	           	    	count++;
	           	    }
	           	    _delay_cycles(10);
	             }
	if(count > 8)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void BlinkLED(unsigned char bit)
{
	P2OUT |= bit;
	_delay_cycles(100000);
	P2OUT &= ~bit;
	_delay_cycles(100000);
	P2OUT |= bit;
	_delay_cycles(100000);
	P2OUT &= ~bit;
	_delay_cycles(100000);

	P2OUT |= bit;
	_delay_cycles(100000);
	P2OUT &= ~bit;
	_delay_cycles(100000);
	P2OUT |= bit;
	_delay_cycles(100000);
	P2OUT &= ~bit;
	_delay_cycles(100000);

	P2OUT |= bit;
	_delay_cycles(100000);
	P2OUT &= ~bit;
	_delay_cycles(100000);
}
void Blink2LED(unsigned char bit, unsigned char bit2 )
{
	P2OUT |= bit + bit2;
	_delay_cycles(100000);
	P2OUT &= ~(bit + bit2);
	_delay_cycles(100000);
	P2OUT |= bit + bit2;
	_delay_cycles(100000);
	P2OUT &= ~(bit + bit2);
	_delay_cycles(100000);

	P2OUT |= bit + bit2;
	_delay_cycles(100000);
	P2OUT &= ~(bit + bit2);
	_delay_cycles(100000);
	P2OUT |= bit + bit2;
	_delay_cycles(100000);
	P2OUT &= ~(bit + bit2);
	_delay_cycles(100000);

	P2OUT |= bit + bit2;
	_delay_cycles(100000);
	P2OUT &= ~(bit + bit2);
	_delay_cycles(100000);
}

unsigned char readSwitchP1(unsigned char bit)
{
	int i =0;
	int count =0;

	for(i=10;i>0;i--)
	             {
	           	    if((P1IN & bit) == bit)
	           	    {
	           	    	count++;
	           	    }
	           	    _delay_cycles(10);
	             }
	if(count > 8)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
