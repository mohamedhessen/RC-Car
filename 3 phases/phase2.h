	DDRD  |=(1<<PD7);
	uint8_t pressed = 10;
	DDRB = 0;
	PORTB = 0xFF;
void lineFollower(){

		if((PINB == 0b11111011) || (PINB == 0b11100000)) // go forward
		{
			pressed = 0;
			PWM_PD7(150);
			
			PORTA |=(1<<PA1) | (1<<PA3);
			PORTA &= ~( 1 << PA2 );
			PORTA &= ~( 1 << PA0 );
		}
		else if ((PINB == 0b11111100) || (PINB == 0b11111110)|| (PINB == 0b11111101))  // go RIGHT
		{
			pressed = 1;
			PWM_PD7(150);
			
			PORTA |= ( 1 << PA1 ) | ( 1 << PA2 );
			PORTA &= ~( 1 << PA0 );
			PORTA &= ~( 1 << PA3 );
			
		}
		
		else if ((PINB == 0b11100111) || (PINB == 0b11101111)|| (PINB == 0b11110111)) // go Left
		{
			pressed = 2;
			PWM_PD7(150);
			
			PORTA |= ( 1 << PA0 ) | ( 1 << PA3 );
			PORTA &= ~( 1 << PA1 );
			PORTA &= ~( 1 << PA2 );
		}
		else if (PINB == 0b11111111)  //
		{
			if(pressed == 0)
			{
				PWM_PD7(150);
				
				PORTA |=(1<<PA2) | (1<<PA0);
				PORTA &= ~( 1 << PA1 );
				PORTA &= ~( 1 << PA3 );

			}
			else if(pressed == 1)
			{
				PWM_PD7(150);
				
				PORTA |= ( 1 << PA1 ) | ( 1 << PA2 );
				PORTA &= ~( 1 << PA0 );
				PORTA &= ~( 1 << PA3 );
			}
			else if(pressed == 2)
			{
				PWM_PD7(150);
				
				PORTA |= ( 1 << PA0 ) | ( 1 << PA3 );
				PORTA &= ~( 1 << PA1 );
				PORTA &= ~( 1 << PA2 );
				
				
			}
			else{
			pressed = 10;
		
			}
		}
}