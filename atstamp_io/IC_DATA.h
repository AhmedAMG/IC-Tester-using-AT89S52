#ifndef __IC_DATA_H
#define __IC_DATA_H

#define START_TEST_PIN P1,0
#define TEST_INFO_PIN P1,7

#define NUMBER_OF_ICS 5

///////////////////////////////////////////////////////////////////////////////
//IC: 7402
#define NOR_Y1 P0,0
#define NOR_A1 P0,1
#define NOR_B1 P0,2
#define NOR_Y2 P0,3
#define NOR_A2 P0,4
#define NOR_B2 P0,5
#define NOR_GND_02 P0,6
#define NOR_VCC_02 P2,0
#define NOR_Y4 P2,1
#define NOR_B4 P2,2
#define NOR_A4 P2,3
#define NOR_Y3 P2,4
#define NOR_B3 P2,5
#define NOR_A3 P2,6
//Truth Table
/*
	0 0 : 1
	0 1 : 0
	1 0 : 0
	1 1 : 0
*/

///////////////////////////////////////////////////////////////////////////////
//IC: 74112
#define FLIP_CK1 P0,0
#define FLIP_K1 P0,1
#define FLIP_J1 P0,2
#define FLIP_PR1 P0,3
#define FLIP_Q1 P0,4
#define FLIP_Q_1 P0,5
#define FLIP_Q_2 P0,6
#define FLIP_GND_112 P0,7
#define FLIP_VCC_112 P2,0
#define FLIP_CLR1 P2,1
#define FLIP_CLR2 P2,2
#define FLIP_CK2 P2,3
#define FLIP_K2 P2,4
#define FLIP_J2 P2,5
#define FLIP_PR2 P2,6
#define FLIP_Q2 P2,7
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
#define BUS_GAB P0,0
#define BUS_NC1 P0,1
#define BUS_A1 P0,2
#define BUS_A2 P0,3
#define BUS_A3 P0,4
#define BUS_A4 P0,5
#define BUS_GND_243 P0,6
#define BUS_VCC_243 P2,0
#define BUS_GBA P2,1
#define BUS_NC2 P2,2
#define BUS_B1 P2,3
#define BUS_B2 P2,4
#define BUS_B3 P2,5
#define BUS_B4 P2,6

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
#define COMP_Pq P0,0
#define COMP_G P0,0

#define COMP_P0 P0,1
#define COMP_Q0 P0,2
#define COMP_P1 P0,3
#define COMP_Q1 P0,4
#define COMP_P2 P0,5
#define COMP_Q2 P0,6
#define COMP_P3 P0,7

#define COMP_Q3 P1,1
#define COMP_GND_684 P1,2
#define COMP_P4 P1,3
#define COMP_Q4 P1,4

#define COMP_VCC_684 P2,0
#define COMP_PQ P2,1
#define COMP_Q7 P2,2
#define COMP_P7 P2,3
#define COMP_Q6 P2,4
#define COMP_P6 P2,5
#define COMP_Q5 P2,6
#define COMP_P5 P2,7
//Truth Table
/*
   INPUTS 		  	OUTPUTS
DATA   ENABLES
P,Q    G,GT  G2 	P=Q  P>Q
P=Q    L     L      L    H
P>Q    L     L      H    L
P<Q    L     L      H    H
X      H     H      H    H
*/

///////////////////////////////////////////////////////////////////////////////
//IC: 4077
#define XNOR_A P0,0
#define XNOR_B P0,1
#define XNOR_J P0,2
#define XNOR_K P0,3
#define XNOR_C P0,4
#define XNOR_D P0,5
#define XNOR_GND_77 P0,6
#define XNOR_VCC_77 P2,0
#define XNOR_H P2,1
#define XNOR_G P2,2
#define XNOR_M P2,3
#define XNOR_L P2,4
#define XNOR_F P2,5
#define XNOR_E P2,6
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

