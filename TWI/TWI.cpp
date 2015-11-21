/*
* TWI.cpp
*
* Created: 22. 1. 2015 20:45:28
* Author: Tomáš
*/


#include "TWI.h"
#include <avr/io.h>

// default constructor
TWI::TWI()
{
	// TWI initialization
	// Bit Rate: 100,000 kHz
	TWBR=0x20;
	// Two Wire Bus Slave Address: 0x0
	// General Call Recognition: Off
	TWAR=0x00;
	// Generate Acknowledge Pulse: Off
	// TWI Interrupt: Off
	TWCR=0x04;
	TWSR=0x00;

} //TWI

// default destructor
TWI::~TWI()
{
} //~TWI

void TWI::Start()
{
	// send START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

	// wait until transmission completed
	while(!(TWCR & (1<<TWINT)));
	
};

void TWI::WriteByte( unsigned char data )
{
	
	// send data to the previously addressed device
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);

	// wait until transmission completed
	while(!(TWCR & (1<<TWINT)));
	};/* i2c_write */

	void TWI::Stop()
	{
		/* send stop condition */
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
		
		// wait until stop condition is executed and bus released
		while(TWCR & (1<<TWSTO));
	};

	unsigned char TWI::ReadByte()
	{
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
		while(!(TWCR & (1<<TWINT)));

		return TWDR;
	}

	unsigned char TWI::ReadByteAck()
	{
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
		while(!(TWCR & (1<<TWINT)));

		return TWDR;

		}/* i2c_readAck */


		/*************************************************************************
		Read one byte from the I2C device, read is followed by a stop condition
		
		Return:  byte read from I2C device
		*************************************************************************/
		unsigned char TWI::ReadByteNack()
		{
			TWCR = (1<<TWINT) | (1<<TWEN);
			while(!(TWCR & (1<<TWINT)));
			
			return TWDR;

			}/* i2c_readNak */