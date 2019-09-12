void pulse(uint8_t duty){
	OCR0=duty;
}

void Forward(void){
	PORTA |=(1<<PA1) | (1<<PA3);
	PORTA &= ~( 1 << PA2 );
	PORTA &= ~( 1 << PA0 );
}

void Left(void){
	PORTA |=(1<<PA1) | (1<<PA2);
	PORTA &= ~( 1 << PA0 );
	PORTA &= ~( 1 << PA3 );
}

void Right(void){
	PORTA |=(1<<PA0) | (1<<PA3);
	PORTA &= ~( 1 << PA2 );
	PORTA &= ~( 1 << PA1 );
}

void Backward(void){
	PORTA |=(1<<PA0) | (1<<PA2);
	PORTA &= ~( 1 << PA3 );
	PORTA &= ~( 1 << PA1 );
}

void Stop(void){
	
	PORTA &= ~( 1 << PA0 );
	PORTA &= ~( 1 << PA1 );
	PORTA &= ~( 1 << PA2 );
	PORTA &= ~( 1 << PA3 );
}

uint16_t GoStraight(uint8_t distance){
	return distance /0.0925;
}

uint16_t Rotation(uint8_t Angle){
	return Angle *3.334;
}

void Regtangle(void){
	for(uint8_t i = 0 ; i < 4 ;i++ ){
		PORTA |=(1<<PA1) | (1<<PA3);
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA0 );
		_delay_ms(GoStraight(42));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(500);
		
		PORTA |=(1<<PA1) | (1<<PA2);
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(Rotation(100));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(500);
	}
}

void Circle(void){
	for (uint8_t i = 0 ; i <35 ; i++)
	{
		PORTA |=(1<<PA1) | (1<<PA3); //front
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA0 );
		_delay_ms(GoStraight(7));
		
		PORTA &= ~( 1 << PA0 ); // stop
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
		
		PORTA |=(1<<PA1) | (1<<PA2); //left
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(Rotation(18));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
	}
}

void Infinty2(void){
	
	for (uint8_t i = 0; i < 12; i++)   //Start with quarter circle from right of the area
	{
		
		PORTA |=(1<<PA1) | (1<<PA3);
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA0 );
		_delay_ms(GoStraight(9));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
		
		PORTA |=(1<<PA1) | (1<<PA2);
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(Rotation(20));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
		
	}
	// then rotate 30 degree left to be ready  to take straight line
	PORTA |=(1<<PA1) | (1<<PA2);
	PORTA &= ~( 1 << PA0 );
	PORTA &= ~( 1 << PA3 );
	_delay_ms(Rotation(80));
	
	PORTA &= ~( 1 << PA0 );
	PORTA &= ~( 1 << PA1 );
	PORTA &= ~( 1 << PA2 );
	PORTA &= ~( 1 << PA3 );
	_delay_ms(10);
	// taking straight line
	for (uint8_t i = 0 ; i <8 ; i++)
	{
		PORTA |=(1<<PA1) | (1<<PA3); //front
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA0 );
		_delay_ms(GoStraight(17));
		
		PORTA &= ~( 1 << PA0 ); // stop
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
		
		PORTA |=(1<<PA1) | (1<<PA2); //left
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(Rotation(16));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
		
	}
	
	
	
	
	PORTA &= ~( 1 << PA0 );
	PORTA &= ~( 1 << PA1 );
	PORTA &= ~( 1 << PA2 );
	PORTA &= ~( 1 << PA3 );
	_delay_ms(10);
	// turn right with 30 degree  to be ready to take half circle
	PORTA |=(1<<PA0) | (1<<PA3);
	PORTA &= ~( 1 << PA1 );
	PORTA &= ~( 1 << PA2 );
	_delay_ms(Rotation(50));
	
	PORTA &= ~( 1 << PA0 );
	PORTA &= ~( 1 << PA1 );
	PORTA &= ~( 1 << PA2 );
	PORTA &= ~( 1 << PA3 );
	_delay_ms(10);
	// taking the half circle
	for (uint8_t i = 0; i < 25; i++)
	{
		
		PORTA |=(1<<PA1) | (1<<PA3);
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA0 );
		_delay_ms(GoStraight(5));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
		
		PORTA |=(1<<PA0) | (1<<PA3);
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		_delay_ms(Rotation(22));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
	}
	
	//turn right with 30 degree to be ready to take the striaght line
	PORTA |=(1<<PA0) | (1<<PA3);
	PORTA &= ~( 1 << PA1 );
	PORTA &= ~( 1 << PA2 );
	_delay_ms(Rotation(75));
	
	PORTA &= ~( 1 << PA0 );
	PORTA &= ~( 1 << PA1 );
	PORTA &= ~( 1 << PA2 );
	PORTA &= ~( 1 << PA3 );
	_delay_ms(10);
	// taking the straight line
	for (uint8_t i = 0 ; i <8; i++)
	{
		PORTA |=(1<<PA1) | (1<<PA3); //front
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA0 );
		_delay_ms(GoStraight(17));
		
		PORTA &= ~( 1 << PA0 ); // stop
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
		
		PORTA |=(1<<PA0) | (1<<PA3); // turn right
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA1 );
		_delay_ms(Rotation(17));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
		
	}
	
	
	
	PORTA &= ~( 1 << PA0 );
	PORTA &= ~( 1 << PA1 );
	PORTA &= ~( 1 << PA2 );
	PORTA &= ~( 1 << PA3 );
	_delay_ms(10);
	// turn left with 30 degree to be ready to take the quarter circle
	PORTA |=(1<<PA1) | (1<<PA2);
	PORTA &= ~( 1 << PA0 );
	PORTA &= ~( 1 << PA3 );
	_delay_ms(Rotation(50));
	
	PORTA &= ~( 1 << PA0 );
	PORTA &= ~( 1 << PA1 );
	PORTA &= ~( 1 << PA2 );
	PORTA &= ~( 1 << PA3 );
	_delay_ms(10);
	// taking the quarter circle
	for (uint8_t i = 0; i < 12; i++)
	{
		
		PORTA |=(1<<PA1) | (1<<PA3);
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA0 );
		_delay_ms(GoStraight(9));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
		
		PORTA |=(1<<PA1) | (1<<PA2);
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(Rotation(22));
		
		PORTA &= ~( 1 << PA0 );
		PORTA &= ~( 1 << PA1 );
		PORTA &= ~( 1 << PA2 );
		PORTA &= ~( 1 << PA3 );
		_delay_ms(10);
		
	}
}