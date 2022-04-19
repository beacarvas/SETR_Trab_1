/* ***************************************************** */
/* SETR 21/22, Paulo Pedreiras                           */
/* Base code for Unit Testing                            */
/*   A few tests to the cmdProcessor                     */
/*      just to illustrate how it works                  */
/*   Shoud be improved (e.g. test more cases)            */
/*                                                       */
/* Compile with: gcc cmdproc.c main.c -o main            */
/*                                                       */
/* ***************************************************** */
#include <stdio.h>
#include "cmdproc.h"
#include <unity.h>

extern char Kp, Ti, Td;


void setUp(void)
{
	return;
}
void tearDown(void)
{
	return;
}

void test_res_1(void)
{
	TEST_ASSERT_EQUAL_INT(0, cmdProcessor());

}
int main(void) 
{
	UNITY_BEGIN();

	int res;
	
	/* Segmento 1 */
	printf("Command processor test app\n\r");
	resetCmdString();
	newCmdChar('*');
	newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('2');
	newCmdChar('3');
	newCmdChar((unsigned char)('P'+'1'+'2'+'3'));
	newCmdChar('!');
	RUN_TEST(test_res_1);
	
	/* Segmento 2 */ 
	resetCmdString();
	newCmdChar('#');
	newCmdChar('D');
	newCmdChar('!');
	/* res=cmdProcessor(); */
	RUN_TEST(test_res_1);
	/* printf("cmdProcessor output to D (typo, should be S): % d\n\r", res); */
	
	/* Segmento 3 */ 
	resetCmdString();
	newCmdChar('*');
	newCmdChar('S');
	newCmdChar('!');
	newCmdChar('#');
	newCmdChar('!');
	RUN_TEST(test_res_1);

	/* Segmento 4 */ 
	resetCmdString();
	newCmdChar('*');
	newCmdChar('S');
	newCmdChar('!');
	newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('2');
	newCmdChar('3');
	newCmdChar('!');
	RUN_TEST(test_res_1);

	/* Segmento 5 */ 
	resetCmdString();
	newCmdChar('#');
	newCmdChar('P');
	newCmdChar('S');
	newCmdChar('!');
	RUN_TEST(test_res_1);

	/* Segmento 6 */ 
	resetCmdString();
	newCmdChar('#');
	newCmdChar('S');
	newCmdChar('P');
	newCmdChar('!');
	RUN_TEST(test_res_1);
	
	/* Segmento 7 */ 
	resetCmdString();
	newCmdChar('#');
	newCmdChar('P');
	newCmdChar('!');
	RUN_TEST(test_res_1);
	
	return UNITY_END();
}
