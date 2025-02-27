#include <reg51.h>
#include "IC_DATA.h"

char Test_7402(void){
    setb(NOR_VCC_02); clr(NOR_GND_02);
	//Test the IC with the 4 possiblities to all gates
	clr(NOR_A1); clr(NOR_B1); clr(NOR_A2); clr(NOR_B2); clr(NOR_A3); clr(NOR_B3); clr(NOR_A4); clr(NOR_B4);
	if((GetBit(NOR_Y1)&GetBit(NOR_Y2)&GetBit(NOR_Y3)&GetBit(NOR_Y4)) == 0) return 0;
	setb(NOR_A1); clr(NOR_B1); setb(NOR_A2); clr(NOR_B2); setb(NOR_A3); clr(NOR_B3); setb(NOR_A4); clr(NOR_B4);
	if((GetBit(NOR_Y1)|GetBit(NOR_Y1)|GetBit(NOR_Y1)|GetBit(NOR_Y1)) == 1) return 0;
	clr(NOR_A1); setb(NOR_B1); clr(NOR_A2); setb(NOR_B2); clr(NOR_A3); setb(NOR_B3); clr(NOR_A4); setb(NOR_B4);
	if((GetBit(NOR_Y1)|GetBit(NOR_Y1)|GetBit(NOR_Y1)|GetBit(NOR_Y1)) == 1) return 0;
	setb(NOR_A1); setb(NOR_B1); setb(NOR_A2); setb(NOR_B2); setb(NOR_A3); setb(NOR_B3); setb(NOR_A4); setb(NOR_B4);
	if((GetBit(NOR_Y1)|GetBit(NOR_Y1)|GetBit(NOR_Y1)|GetBit(NOR_Y1)) == 1) return 0;

	return 1;
}


char Test_74112(void){
	setb(FLIP_VCC_112); clr(FLIP_GND_112);
	setb(FLIP_Q1); setb(FLIP_Q2); setb(FLIP_Q_1); setb(FLIP_Q_2); //Set as input
	clr(FLIP_K1); clr(FLIP_J1); clr(FLIP_K2); clr(FLIP_J2);
	setb(FLIP_CK1); setb(FLIP_CK2); setb(FLIP_CLR1); setb(FLIP_CLR2); setb(FLIP_PR1); setb(FLIP_PR2);

	//Check the Clear functionality
	//Drive the CLR bits LOW then return them to HIGH
	//Then start Testing Q for LOW and Q' for HIGH
	clr(FLIP_CLR1); clr(FLIP_CLR2);
	setb(FLIP_CLR1); setb(FLIP_CLR2);
    //printf("%d,%d,%d,%d\n",GetBit(FLIP_Q1),GetBit(FLIP_Q2),GetBit(FLIP_Q_1),GetBit(FLIP_Q_2));
	if((GetBit(FLIP_Q1)!=0)||(GetBit(FLIP_Q2)!=0)||(GetBit(FLIP_Q_1)!=1)||(GetBit(FLIP_Q_2)!=1)) return 0;

	//Check the Preset functionality
	//Drive the PR bits LOW then return them to HIGH
	//Then start Testing Q for HIGH and Q' for LOW
	clr(FLIP_PR1); clr(FLIP_PR2);
	setb(FLIP_PR1); setb(FLIP_PR2);
	//printf("%d,%d,%d,%d\n",GetBit(FLIP_Q1),GetBit(FLIP_Q2),GetBit(FLIP_Q_1),GetBit(FLIP_Q_2));
	if((GetBit(FLIP_Q1)!=1)||(GetBit(FLIP_Q2)!=1)||(GetBit(FLIP_Q_1)!=0)||(GetBit(FLIP_Q_2)!=0)) return 0;

	//Check the Reset functionality
	//Drive the K bits HIGH to "Reset" then LOW to "No change"
	//Then start Testing Q for LOW and Q' for HIGH
	setb(FLIP_K1); setb(FLIP_K2);
	clr(FLIP_CK1); clr(FLIP_CK2);
	setb(FLIP_CK1); setb(FLIP_CK2);
	//printf("%d,%d,%d,%d\n",GetBit(FLIP_Q1),GetBit(FLIP_Q2),GetBit(FLIP_Q_1),GetBit(FLIP_Q_2));
	//if((GetBit(FLIP_Q1)!=0)||(GetBit(FLIP_Q2)!=0)||(GetBit(FLIP_Q_1)!=1)||(GetBit(FLIP_Q_2)!=1)) return 0;
	clr(FLIP_K1); clr(FLIP_K2);
	clr(FLIP_CK1); clr(FLIP_CK2);
	setb(FLIP_CK1); setb(FLIP_CK2);
	//printf("%d,%d,%d,%d\n",GetBit(FLIP_Q1),GetBit(FLIP_Q2),GetBit(FLIP_Q_1),GetBit(FLIP_Q_2));
	if((GetBit(FLIP_Q1)!=0)||(GetBit(FLIP_Q2)!=0)||(GetBit(FLIP_Q_1)!=1)||(GetBit(FLIP_Q_2)!=1)) return 0;

	//Check the Set functionality
	//Drive the J bits HIGH to "Set" then LOW to "No change"
	//Then start Testing Q for HIGH and Q' for LOW
	setb(FLIP_J1); setb(FLIP_J2);
	clr(FLIP_CK1); clr(FLIP_CK2);
	setb(FLIP_CK1); setb(FLIP_CK2);
	//printf("%d,%d,%d,%d\n",GetBit(FLIP_Q1),GetBit(FLIP_Q2),GetBit(FLIP_Q_1),GetBit(FLIP_Q_2));
	if((GetBit(FLIP_Q1)!=1)||(GetBit(FLIP_Q2)!=1)||(GetBit(FLIP_Q_1)!=0)||(GetBit(FLIP_Q_2)!=0)) return 0;
	clr(FLIP_J1); clr(FLIP_J2);
	clr(FLIP_CK1); clr(FLIP_CK2);
	setb(FLIP_CK1); setb(FLIP_CK2);
	//printf("%d,%d,%d,%d\n",GetBit(FLIP_Q1),GetBit(FLIP_Q2),GetBit(FLIP_Q_1),GetBit(FLIP_Q_2));
	if((GetBit(FLIP_Q1)!=1)||(GetBit(FLIP_Q2)!=1)||(GetBit(FLIP_Q_1)!=0)||(GetBit(FLIP_Q_2)!=0)) return 0;

	//Check the Toggle functionality
	//Drive the J and K bits HIGH
	//Then start Testing Q for LOW and Q' for HIGH
	setb(FLIP_J1); setb(FLIP_J2); setb(FLIP_K1); setb(FLIP_K2);
	clr(FLIP_CK1); clr(FLIP_CK2);
	setb(FLIP_CK1); setb(FLIP_CK2);
	//printf("%d,%d,%d,%d\n",GetBit(FLIP_Q1),GetBit(FLIP_Q2),GetBit(FLIP_Q_1),GetBit(FLIP_Q_2));
	if((GetBit(FLIP_Q1)!=0)||(GetBit(FLIP_Q2)!=0)||(GetBit(FLIP_Q_1)!=1)||(GetBit(FLIP_Q_2)!=1)) return 0;

	return 1;
}

//Third case should be revised
char Test_74243(void){
	setb(BUS_VCC_243); clr(BUS_GND_243);

	//Check A to B functionality
	//Drive GAB and GBA to LOW
	//Then start testing 0101 and 1010 passing from A to B
	setb(BUS_B1); setb(BUS_B2); setb(BUS_B3); setb(BUS_B4); //Set as input
	setb(BUS_GAB); setb(BUS_GBA);
	clr(BUS_A1); setb(BUS_A2); clr(BUS_A3); setb(BUS_A4);
	//printf("%d,%d,%d,%d\n",GetBit(BUS_B1),GetBit(BUS_B2),GetBit(BUS_B3),GetBit(BUS_B4));
	if((GetBit(BUS_B1)!=0)||(GetBit(BUS_B2)!=1)||(GetBit(BUS_B3)!=0)||(GetBit(BUS_B4)!=1)) return 0;
	setb(BUS_A1); clr(BUS_A2); setb(BUS_A3); clr(BUS_A4);
	//printf("%d,%d,%d,%d\n",GetBit(BUS_B1),GetBit(BUS_B2),GetBit(BUS_B3),GetBit(BUS_B4));
	if((GetBit(BUS_B1)!=1)||(GetBit(BUS_B2)!=0)||(GetBit(BUS_B3)!=1)||(GetBit(BUS_B4)!=0)) return 0;

	//Check B to A functionality
	//Drive GAB and GBA to HIGH
	//Then start testing 0101 and 1010 passing from B to A
	setb(BUS_A1); setb(BUS_A2); setb(BUS_A3); setb(BUS_A4); //Set as input
	clr(BUS_GAB); clr(BUS_GBA);
	clr(BUS_B1); setb(BUS_B2); clr(BUS_B3); setb(BUS_B4);
	//printf("%d,%d,%d,%d\n",GetBit(BUS_A1),GetBit(BUS_A2),GetBit(BUS_A3),GetBit(BUS_A4));
	if((GetBit(BUS_A1)!=0)||(GetBit(BUS_A2)!=1)||(GetBit(BUS_A3)!=0)||(GetBit(BUS_A4)!=1)) return 0;
	setb(BUS_B1); clr(BUS_B2); setb(BUS_B3); clr(BUS_B4);
	//printf("%d,%d,%d,%d\n",GetBit(BUS_A1),GetBit(BUS_A2),GetBit(BUS_A3),GetBit(BUS_A4));
	if((GetBit(BUS_A1)!=1)||(GetBit(BUS_A2)!=0)||(GetBit(BUS_A3)!=1)||(GetBit(BUS_A4)!=0)) return 0;

	//Check Isolation functionality
	//Drive GAB to HIGH and GBA to LOW
	//Then start A and B whether they are isolated or not

	//Maybe High impedence should be examined as HIGH ! ISOLATION MODE !!!
	//#error NEED TO BE SEARCHED WELL OR EXPERIMENTED FIRST WITH AVO
	setb(BUS_B1); setb(BUS_B2); setb(BUS_B3); setb(BUS_B4); //Set as input
	setb(BUS_GAB); clr(BUS_GBA);
	clr(BUS_A1); clr(BUS_A2); clr(BUS_A3); clr(BUS_A4);
	//printf("%d,%d,%d,%d\n",GetBit(BUS_B1),GetBit(BUS_B2),GetBit(BUS_B3),GetBit(BUS_B4));
	if((GetBit(BUS_B1)!=1)||(GetBit(BUS_B2)!=1)||(GetBit(BUS_B3)!=1)||(GetBit(BUS_B4)!=1)) return 0;

	setb(BUS_A1); setb(BUS_A2); setb(BUS_A3); setb(BUS_A4); //Set as input
	setb(BUS_GAB); clr(BUS_GBA);
	clr(BUS_B1); clr(BUS_B2); clr(BUS_B3); clr(BUS_B4);
	//printf("%d,%d,%d,%d\n",GetBit(BUS_A1),GetBit(BUS_A2),GetBit(BUS_A3),GetBit(BUS_A4));
	if((GetBit(BUS_A1)!=1)||(GetBit(BUS_A2)!=1)||(GetBit(BUS_A3)!=1)||(GetBit(BUS_A4)!=1)) return 0;

	return 1;
}

//This function may be need some of "Sleep(1);"
char Test_74684(void){
	setb(COMP_VCC_684); clr(COMP_GND_684);
	setb(COMP_Pq); setb(COMP_PQ); //Set as input
	clr(COMP_G); //Enable
	//Check P = Q functionality
	//Drive Ps and Qs to ZERO
	//Then check the COMP_PQ pin for LOW and Pq for HIGH
	clr(COMP_P0); clr(COMP_P1); clr(COMP_P2); clr(COMP_P3); clr(COMP_P4); clr(COMP_P5); clr(COMP_P6); clr(COMP_P7);
	clr(COMP_Q0); clr(COMP_Q1); clr(COMP_Q2); clr(COMP_Q3); clr(COMP_Q4); clr(COMP_Q5); clr(COMP_Q6); clr(COMP_Q7);
	if((GetBit(COMP_PQ)!=0)) return 0;

	//loop on var, 0 < var < 8 , (P or Q) = (1<<var)
	//P > Q then P = Q then P < Q then P = Q

	//C = 0
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); setb(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=1)) return 0;
	//C = 0
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); setb(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); setb(COMP_Q0);
	if((GetBit(COMP_PQ)!=0)) return 0;
	//C = 1
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); setb(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); setb(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=1)) return 0;
	//C = 1
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); clr(COMP_P2); setb(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); setb(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=0)) return 0;
	////////////////////////////////////////////////////////////////////////
	//C = 2
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); setb(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=1)) return 0;
	//C = 2
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); setb(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); setb(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=0)) return 0;
	//C = 3
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); setb(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); setb(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=1)) return 0;
	//C = 3
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); clr(COMP_P4); setb(COMP_P3); clr(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); setb(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=0)) return 0;
	////////////////////////////////////////////////////////////////////////
	//C = 4
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); setb(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=1)) return 0;
	//C = 4
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); setb(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); setb(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=0)) return 0;
	//C = 5
	clr(COMP_P7); clr(COMP_P6); clr(COMP_P5); setb(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); setb(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=1)) return 0;
	//C = 5
	clr(COMP_P7); clr(COMP_P6); setb(COMP_P5); clr(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); setb(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=0)) return 0;
  ////////////////////////////////////////////////////////////////////////
	//C = 6
	clr(COMP_P7); setb(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=1)) return 0;
	//C = 6
	clr(COMP_P7); setb(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	clr(COMP_Q7); setb(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=0)) return 0;
	//C = 7
	clr(COMP_P7); setb(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	setb(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=1)) return 0;
	//C = 7
	setb(COMP_P7); clr(COMP_P6); clr(COMP_P5); clr(COMP_P4); clr(COMP_P3); clr(COMP_P2); clr(COMP_P1); clr(COMP_P0);
	setb(COMP_Q7); clr(COMP_Q6); clr(COMP_Q5); clr(COMP_Q4); clr(COMP_Q3); clr(COMP_Q2); clr(COMP_Q1); clr(COMP_Q0);
	if((GetBit(COMP_PQ)!=0)) return 0;
  ////////////////////////////////////////////////////////////////////////

	return 1;
}

char Test_4077(void){
	setb(XNOR_VCC_77); clr(XNOR_GND_77);
	setb(XNOR_J); setb(XNOR_K); setb(XNOR_L); setb(XNOR_M); //Set as input
	//Test the IC with the 4 possiblities to all gates
	clr(XNOR_A); clr(XNOR_B); clr(XNOR_C); clr(XNOR_D); clr(XNOR_E); clr(XNOR_F); clr(XNOR_G); clr(XNOR_H);
	if((GetBit(XNOR_J)&GetBit(XNOR_K)&GetBit(XNOR_L)&GetBit(XNOR_M)) == 0) return 0;
	setb(XNOR_A); clr(XNOR_B); setb(XNOR_C); clr(XNOR_D); setb(XNOR_E); clr(XNOR_F); setb(XNOR_G); clr(XNOR_H);
	if((GetBit(XNOR_J)|GetBit(XNOR_K)|GetBit(XNOR_L)|GetBit(XNOR_M)) == 1) return 0;
	clr(XNOR_A); setb(XNOR_B); clr(XNOR_C); setb(XNOR_D); clr(XNOR_E); setb(XNOR_F); clr(XNOR_G); setb(XNOR_H);
	if((GetBit(XNOR_J)|GetBit(XNOR_K)|GetBit(XNOR_L)|GetBit(XNOR_M)) == 1) return 0;
	setb(XNOR_A); setb(XNOR_B); setb(XNOR_C); setb(XNOR_D); setb(XNOR_E); setb(XNOR_F); setb(XNOR_G); setb(XNOR_H);
	if((GetBit(XNOR_J)&GetBit(XNOR_K)&GetBit(XNOR_L)&GetBit(XNOR_M)) == 0) return 0;

	return 1;
}

