// Checks status of push button connected to P2.0  (active low)
// When pushed, LED connected to P1.0 flashes five times
#include "ATSTAMP.h"
#include "IC_DATA.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

//Code Differences between simulation and hardware:
//#error 74243 first 2 cases flipped for simulation (clr then set not set then clr)
//#error 74684 as been altered to 74688 for simulation (Pq should be recovered and remove G)

//542ns is the clock period in our controller
int main(void)
{
	if(!OpenCom(2, 115200))
	{
		exit(0);
	}

	char i = 0;
	char ic_found = 0;
	unsigned char* ICs[NUMBER_OF_ICS] = {"7402","74112","74243","74684","4077"};
	char (*ptr[NUMBER_OF_ICS])(void) = {Test_7402, Test_74112, Test_74243, Test_74684, Test_4077};

	while(1)
	{
		if(!GetBit(START_TEST_PIN)){
		 ic_found = 0;
		 for(i = 0; i < NUMBER_OF_ICS; i++){
			if(ptr[i]()){
				ic_found = 1;
				printf("IC %s is recognised :)\n\r",ICs[i]);
				break;
			}
            Sleep(100);
		 }
		 if(ic_found == 0) printf("No IC has been recognised :(\n\r");
		 Sleep(500);

		}
	}
	  return 0;
}

