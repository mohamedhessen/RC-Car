/*
void UART_send_char(char data) // for sending char such as 'A'
{
while( ! (UCSRA & (1<<UDRE) ) );
UDR = data;
}
*/

char UART_receive_char() // for receiving char such as 'A'
{
	while (! (UCSRA & (1 << RXC) ) );
	return UDR;
}

/*
void UART_send_string(char *data) // for sending string such as 'MOHAMED'
{
while(*data > 0)
UART_send_char(*data++);
UART_send_char('\0');
}
*/

void UART_init(uint16_t baud_rate)
{
	
	uint16_t UBRR_Value = lrint ( (F_CPU / (16L * baud_rate) ) -1);
	UBRRL = (uint8_t) UBRR_Value;
	UBRRH = (uint8_t) (UBRR_Value >> 8);
	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC |= (3<<UCSZ0);
}

void init_PWM(void)
{

	//DDRB  |=(1<<PB3	);
	//(1<<PD4)|(1<<PD5)|

	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	// TCNT0(counter) & OCR0(analog value) (1<<COM00)||(1<<WGM01)
	TCCR2 |=(1<<WGM20)|(1<<COM21)|(1<<CS22);  // TCNT2(counter) & OCR2(analog value) |(1<<COM20)|(1<<CS21)
	//TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM10); // TCNT1(counter) & CR1AL(analog value) (1<<COM1B0)|(1<<COM1A0)|

	//Start PWM
	//TCCR1B|=(1<<CS11)|(1<<CS10); //TCNT1(counter) & CR1BL(analog value)
	//TCNT0  =0;
	TCNT2  =0;
	//TCNT1  =0;

}

/*void PWM_PB3(unsigned char pulse_width)
{
OCR0   = pulse_width;
}
*/

void PWM_PD7(unsigned char pulse_width)
{
	OCR2   = pulse_width;
}