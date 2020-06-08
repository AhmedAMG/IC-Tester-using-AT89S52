
#include <reg51.h>
#include "IC_DATA.h"

//Timer 0 for Delay(Sleep)
//Timer 1 for UART baud rate(4800)
//tick = 1 / 1.8432 = 0.5425347us

//22.1184/12 = 1.8432MHz
//1.8432 / 32 = 57.6KHz
//57.6 / 12 = 4800
//-12 -> 0xF4

//Code Differences between simulation and hardware:
//#error 74243 first 2 cases flipped for simulation (clr then set not set then clr)
//#error 74684 as been altered to 74688 for simulation (Pq should be recovered and remove G)

void Sleep(int ms);
void UART_SendString(char* str);

void main(void){
	char i = 0;
	char ic_found = 0;
	unsigned char* ICs[NUMBER_OF_ICS] = {"7402","74112","74243","74684","4077"};
	char (*ptr[NUMBER_OF_ICS])(void) = {Test_7402, Test_74112, Test_74243, Test_74684, Test_4077};
	
	TMOD=0x20; //use Timer 1, mode 2
	TH1=0xF4; //4800 baud rate
	SCON=0x50;
	TR1=1; //start timer
	
	Sleep(1000);
	while (1) {
		ic_found = 0;
		for(i = 0; i < NUMBER_OF_ICS; i++){
			if(ptr[i]()){
				ic_found = 1;
				UART_SendString("IC "); UART_SendString(ICs[i]); UART_SendString(" is recognised :)\n\r");
				break;
			}
		}
		if(ic_found == 0){
			UART_SendString("No IC has been recognised :(\n\r");
		}
		Sleep(1000);
		
	}
}

void Sleep(int ms){
	unsigned int i = 0;
	TMOD |= 0x01;           // Timer0 mode1
	
	for(i = 0; i < ms; i++){
		TH0=0xF8;              //initial value for 1ms
		TL0=0xCB;
		TR0 = 1;               // timer0 start
		while (TF0 == 0);      // check overflow condition
		TR0 = 0;               // Stop Timer
		TF0 = 0;               // Clear flag
	}
}

void UART_SendString(char* str){
	short int i = 0;
	while(str[i] != 0){
		TI=0;
		SBUF = str[i]; //place value in buffer
		while (TI==0); //wait until transmitted
		i++;
	}
}
