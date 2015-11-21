/* 
* TWI.h
*
* Created: 22. 1. 2015 20:45:28
* Author: Tomáš
*/


#ifndef __TWI_H__
#define __TWI_H__


class TWI
{
//variables
public:
protected:
private:

//functions
public:
	TWI();
	~TWI();
	void Start();
	void Stop();
	void WriteByte(unsigned char);
	unsigned char ReadByte();
	unsigned char ReadByteAck();
	unsigned char ReadByteNack();
protected:
private:
	

}; //TWI

#endif //__TWI_H__
