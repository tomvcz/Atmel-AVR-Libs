/* 
* Uart.h
*
* Created: 22. 1. 2015 20:24:47
* Author: Tomáš
*/


#ifndef __UART_H__
#define __UART_H__


class Uart
{
//variables
public:
protected:
private:

//functions
public:
	Uart();
	~Uart();
	void SendByte (unsigned char data);
	void SendString(char str[]);
	void SendStringLn(char str[]);
protected:
private:
	

}; //Uart

#endif //__UART_H__
