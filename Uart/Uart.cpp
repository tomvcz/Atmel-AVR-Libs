/* 
* Uart.cpp
*
* Created: 22. 1. 2015 20:24:47
* Author: Tomáš
*/


#include "Uart.h"
#include <avr/io.h>
#include <string.h>


Uart::Uart(){
	// USART initialization
	// Communication Parameters: 8 Data, 1 Stop, No Parity
	// USART Receiver: On
	// USART Transmitter: On
	// USART Mode: Asynchronous
	// USART Baud Rate: 9600
	UCSRA=0x00;
	UCSRB = (1<<RXCIE) | (1<<RXEN) | (1<<TXEN); //rx preruseni, rx enabled, tx enabled
	UCSRC=0x06;
	UBRRH=0x00;
	UBRRL=0x33;
} 

// default destructor
Uart::~Uart()
{
} //~Uart



void Uart::SendByte (unsigned char data)
{
	/* Wait for empty transmit buffer */
	while (!(UCSRA & (1 << UDRE)));

	/* Start transmittion */
	UDR = data;
}

void Uart::SendString(char str[]){
	for (unsigned int i=0; i<strlen(str);i++)
	{
		SendByte(str[i]);
	}
	
}

void Uart::SendStringLn(char str[]){
	SendString(str);
	SendByte('\n');
}