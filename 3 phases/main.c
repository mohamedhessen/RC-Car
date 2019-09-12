/*
* 3 phases.c
*
* Created: 2018-06-30 11:17:39 AM
* Author : Mohamed Elwarraky
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "phase3.h"
#include "phase1.h"
#include "phase2.h"


/////////////////////////////////////////////



int main(void)
{
	
	init_PWM();
	DDRA = 0xFF;
	char Received = '0';
	TCCR1A =0;
	uint16_t dis=0;
	UART_init(9600);
	
	

	/* Replace with your application code */
	while (1)
	{   /////////////////////////////////////
		Received =  UART_receive_char();
		switch(Received)
		{
			case '1' :
			{	DDRD |= (1<<PD6) | (1<< PD4);
				DDRD &=~ (1<<PD5);
				while(1){
					
					if ((UDR == '1' )||(UDR == '2' )||(UDR == '3') )
					{
						break;
					}
					
				Controlled_Motion();
					break;
				}
			}
			case '2':
			{
			
				
				while(1){
					
				lineFollower();
				}
				break;
			}
			
			case '3':
			{
				DDRA = 0xFF;
				DDRB |= (1<<PB3);
				
				PORTA |= (1<<PA4);
				_delay_ms(1000);
				pulse(215);
				
				Infinty2();
				PORTA &= ~( 1 << PA0 );
				PORTA &= ~( 1 << PA1 );
				PORTA &= ~( 1 << PA2 );
				PORTA &= ~( 1 << PA3 );
				_delay_ms(25000);
				Regtangle();
				PORTA &= ~( 1 << PA0 );
				PORTA &= ~( 1 << PA1 );
				PORTA &= ~( 1 << PA2 );
				PORTA &= ~( 1 << PA3 );
				_delay_ms(25000);
				Circle();
				PORTA &= ~( 1 << PA0 );
				PORTA &= ~( 1 << PA1 );
				PORTA &= ~( 1 << PA2 );
				PORTA &= ~( 1 << PA3 );
				_delay_ms(25000);
				
			}
			break;
		}
		
		
		
	}

	
}





