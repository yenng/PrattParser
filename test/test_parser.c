#include "unity.h"
#include "parser.h"
#include "Token.h"
#include "mock_getToken.h"
#include "customAssertion.h"
#include <stdlib.h>
#include <stdio.h>
OperatorToken* mul;
char multiply = '*';
IntegerToken* value_3;
IntegerToken* value_4;
void setUp(void){}

void tearDown(void){}

/**
 *
 *  Obtain tokens of 2 , + , 3
 *
 *  The parser should linked up and form a token tree as follow
 *
 *      (+)
 *      / \
 *    (2) (3)
 *
 *  Note: Symbol "$" was used here to indicate the end of Token
 */
void test_parser_with_2_ADD_3_EOT(void){
  OperatorToken* testOprToken = (OperatorToken*)createOperatorToken("+",INFIX);
  OperatorToken* lastOprToken = (OperatorToken*)createOperatorToken("$",POSTFIX);
  IntegerToken* testIntToken = (IntegerToken*)createIntegerToken(2);
  IntegerToken* lastIntToken = (IntegerToken*)createIntegerToken(3);

//MOCK peepToken and getToken
  peepToken_ExpectAndReturn((Token*)testIntToken);
  getToken_ExpectAndReturn((Token*)testIntToken);
  peepToken_ExpectAndReturn((Token*)testOprToken);
  getToken_ExpectAndReturn((Token*)testOprToken);
  peepToken_ExpectAndReturn((Token*)lastIntToken);
  getToken_ExpectAndReturn((Token*)lastIntToken);
  peepToken_ExpectAndReturn((Token*)lastOprToken);  
  peepToken_ExpectAndReturn((Token*)lastOprToken);    
 
  Token* testToken = malloc(sizeof(Token*));
  testToken = parser(0);
//********************************************* START TEST  
  TEST_ASSERT_NOT_NULL(testToken);
  TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,((IntegerToken*)testToken)->type);
  
  TEST_ASSERT_EQUAL('+', *((OperatorToken*)testToken)->symbol);
  TEST_ASSERT_EQUAL(2,((IntegerToken*)((OperatorToken*)testToken)->token[0])->value);
  TEST_ASSERT_EQUAL(3,((IntegerToken*)((OperatorToken*)testToken)->token[1])->value);
}

/**
 *
 *  Obtain tokens of 2 , + , 3 , * , 4
 *
 *  The parser should linked up and form a token tree as follow
 *
 *      (+)
 *      / \
 *    (2) (*)
 *        / \
 *      (3) (4)
 *
 *  Note: Symbol "$" was used here to indicate the end of Token
 */
void test_parser_with_2_ADD_3_MUL_4_EOT(void){
  IntegerToken* testIntToken_1 = (IntegerToken*)createIntegerToken(2);
  OperatorToken* testOprToken_1 = (OperatorToken*)createOperatorToken("+",INFIX);
  IntegerToken* testIntToken_2 = (IntegerToken*)createIntegerToken(3);
  OperatorToken* testOprToken_2 = (OperatorToken*)createOperatorToken("*",INFIX);
  IntegerToken* lastIntToken = (IntegerToken*)createIntegerToken(4);
  OperatorToken* lastOprToken = (OperatorToken*)createOperatorToken("$",POSTFIX);

//MOCK peepToken and getToken
//In the first parser
  peepToken_ExpectAndReturn((Token*)testIntToken_1);
  getToken_ExpectAndReturn((Token*)testIntToken_1);
  peepToken_ExpectAndReturn((Token*)testOprToken_1);
  getToken_ExpectAndReturn((Token*)testOprToken_1);
//Entered the second call of parser
  peepToken_ExpectAndReturn((Token*)testIntToken_2);
  getToken_ExpectAndReturn((Token*)testIntToken_2);
  peepToken_ExpectAndReturn((Token*)testOprToken_2);
  getToken_ExpectAndReturn((Token*)testOprToken_2);
//Entered the third call of parser
  peepToken_ExpectAndReturn((Token*)lastIntToken);
  getToken_ExpectAndReturn((Token*)lastIntToken);
  peepToken_ExpectAndReturn((Token*)lastOprToken);  
  peepToken_ExpectAndReturn((Token*)lastOprToken);    
  peepToken_ExpectAndReturn((Token*)lastOprToken);    
 
  Token* testToken = malloc(sizeof(Token*));
  testToken = parser(0);
//********************************************* START TEST  
  TEST_ASSERT_NOT_NULL(testToken);
  TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,((IntegerToken*)testToken)->type);
  TEST_ASSERT_EQUAL('+', *((OperatorToken*)testToken)->symbol);
  TEST_ASSERT_EQUAL(2,((IntegerToken*)((OperatorToken*)testToken)->token[0])->value);
  
  
  mul = (OperatorToken*)((OperatorToken*)testToken)->token[1];
  TEST_ASSERT_EQUAL_OPERATOR(&multiply, 3, 4, mul);  

}



















