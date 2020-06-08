#ifndef __IC_DATA_H
#define __IC_DATA_H

#define NUMBER_OF_ICS 5
#define setb(x) (x = 1)
#define clr(x) (x = 0)
#define GetBit(x) (x)

sbit START_TEST_PIN = P1^0;
sbit TEST_INFO_PIN = P3^7;

///////////////////////////////////////////////////////////////////////////////
//IC: 7402
sbit NOR_Y1 = P0^0;
sbit NOR_A1 = P0^1;
sbit NOR_B1 = P0^2;
sbit NOR_Y2 = P0^3;
sbit NOR_A2 = P0^4;
sbit NOR_B2 = P0^5;
sbit NOR_GND_02 = P0^6;
sbit NOR_VCC_02 = P2^0;
sbit NOR_Y4 = P2^1;
sbit NOR_B4 = P2^2;
sbit NOR_A4 = P2^3;
sbit NOR_Y3 = P2^4;
sbit NOR_B3 = P2^5;
sbit NOR_A3 = P2^6;
//Truth Table
/*
	0 0 : 1
	0 1 : 0
	1 0 : 0
	1 1 : 0
*/

///////////////////////////////////////////////////////////////////////////////
//IC: 74112
sbit FLIP_CK1 = P0^0;
sbit FLIP_K1 = P0^1;
sbit FLIP_J1 = P0^2;
sbit FLIP_PR1 = P0^3;
sbit FLIP_Q1 = P0^4;
sbit FLIP_Q_1 = P0^5;
sbit FLIP_Q_2 = P0^6;
sbit FLIP_GND_112 = P0^7;
sbit FLIP_VCC_112 = P2^0;
sbit FLIP_CLR1 = P2^1;
sbit FLIP_CLR2 = P2^2;
sbit FLIP_CK2 = P2^3;
sbit FLIP_K2 = P2^4;
sbit FLIP_J2 = P2^5;
sbit FLIP_PR2 = P2^6;
sbit FLIP_Q2 = P2^7;
//Truth Table
/*
CLR	 PR  J	K  CK	 Q	 Q
L 	 H   X 	X  X     L 	 H 		CLEAR
H 	 L   X 	X  X 	 H 	 L 		PRESET
L 	 L   X  X  X 	 H 	 H      ---
H 	 H   L  L  Fall	 Qn  Qn 	NO CHANGE
H 	 H   H  L  Fall	 H 	 L      ---
H 	 H   L  H  Fall	 L 	 H      ---
H 	 H   H  H  Fall	 Qn  Qn 	TOGGLE
H 	 H   X  X  Rise  Qn  Qn 	NO CHANGE
*/

///////////////////////////////////////////////////////////////////////////////
//IC: 74243
sbit BUS_GAB = P0^0;
sbit BUS_NC1 = P0^1;
sbit BUS_A1 = P0^2;
sbit BUS_A2 = P0^3;
sbit BUS_A3 = P0^4;
sbit BUS_A4 = P0^5;
sbit BUS_GND_243 = P0^6;
sbit BUS_VCC_243 = P2^0;
sbit BUS_GBA = P2^1;
sbit BUS_NC2 = P2^2;
sbit BUS_B1 = P2^3;
sbit BUS_B2 = P2^4;
sbit BUS_B3 = P2^5;
sbit BUS_B4 = P2^6;

//Truth Table
/*
GAB GBA   Function
L 	L 	  A to B
H 	H 	  B to A
H 	L 	  Isolation
L 	H 	  Latch A and B (A = B)
*/

///////////////////////////////////////////////////////////////////////////////
//IC: 74684
sbit COMP_Pq = P0^0;
sbit COMP_G = P0^0;

sbit COMP_P0 = P0^1;
sbit COMP_Q0 = P0^2;
sbit COMP_P1 = P0^3;
sbit COMP_Q1 = P0^4;
sbit COMP_P2 = P0^5;
sbit COMP_Q2 = P0^6;
sbit COMP_P3 = P0^7;

sbit COMP_Q3 = P1^1;
sbit COMP_GND_684 = P1^2;
sbit COMP_P4 = P1^3;
sbit COMP_Q4 = P1^4;

sbit COMP_VCC_684 = P2^0;
sbit COMP_PQ = P2^1;
sbit COMP_Q7 = P2^2;
sbit COMP_P7 = P2^3;
sbit COMP_Q6 = P2^4;
sbit COMP_P6 = P2^5;
sbit COMP_Q5 = P2^6;
sbit COMP_P5 = P2^7;
//Truth Table
/*
   INPUTS 		  	OUTPUTS
DATA   ENABLES
P^Q    G^GT  G2 	P=Q  P>Q
P=Q    L     L      L    H
P>Q    L     L      H    L
P<Q    L     L      H    H
X      H     H      H    H
*/

///////////////////////////////////////////////////////////////////////////////
//IC: 4077
sbit XNOR_A = P0^0;
sbit XNOR_B = P0^1;
sbit XNOR_J = P0^2;
sbit XNOR_K = P0^3;
sbit XNOR_C = P0^4;
sbit XNOR_D = P0^5;
sbit XNOR_GND_77 = P0^6;
sbit XNOR_VCC_77 = P2^0;
sbit XNOR_H = P2^1;
sbit XNOR_G = P2^2;
sbit XNOR_M = P2^3;
sbit XNOR_L = P2^4;
sbit XNOR_F = P2^5;
sbit XNOR_E = P2^6;
//Truth Table
/*
A  B  J
0  0  1
1  0  0
0  1  0
1  1  1
*/

///////////////////////////////////////////////////////////////////////////////

char Test_7402(void);
char Test_74112(void);
char Test_74243(void);
char Test_74684(void);
char Test_4077(void);

#endif
