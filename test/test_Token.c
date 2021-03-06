#include "unity.h"
#include "Token.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}

void tearDown(void){}

/**
 *  This test file test the function createIntegerToken & createOperatorToken
 *
 *  Eg, given the argument, the function should create the Token accordingly
 *  createIntegerToken(3) should return an IntegerToken pointer that point to
 *  the integer token that stored value 3.
 *
 *  createOperatorToken("+",INFIX) should return an OperatorToken pointer that
 *  point to the operator token that have symbol + and arity of INFIX
 *
 */

/*  createIntegerToken(2) should create a pointer to IntegerToken
 *    
 *                                    [IntegerToken]
 *  [IntegerToken ptr] -------------> [     2      ]
 */
void test_createIntegerTokens_given_value_2_and_minus_2_return_IntegerTokens(void){
  IntegerToken leftTk   = *(IntegerToken*)createIntegerToken(2);    //dereference IntegerToken's pointer to IntegerToken and assign to leftTk
  IntegerToken rightTk  = *(IntegerToken*)createIntegerToken(-2);   //dereference IntegerToken's pointer to IntegerToken and assign to rightTk

  TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,leftTk.type);
  TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,rightTk.type);
  
  TEST_ASSERT_EQUAL(2,leftTk.value);
  TEST_ASSERT_EQUAL(-2,rightTk.value);
}


/*  createOperatorToken("+", INFIX) should create a pointer to OperatorToken
 *    
 *                                     [OperatorToken]
 *  [OperatorToken ptr] -------------> [      +      ]
 *                                     [    INFIX    ]
 */

void test_createOperatorToken_given_symbol_ADD_and_MUL_should_return_OperatorToken(void){
  OperatorToken* addToken = malloc(sizeof(OperatorToken));
  addToken = (OperatorToken*)createOperatorToken("+",INFIX);
  OperatorToken mulToken = *(OperatorToken*)createOperatorToken("*", INFIX);
  
  TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,addToken->type);
  TEST_ASSERT_EQUAL("+",addToken->symbol);
  TEST_ASSERT_EQUAL(INFIX,addToken->arity);
  
  TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,mulToken.type);
  TEST_ASSERT_EQUAL("*",mulToken.symbol);
  TEST_ASSERT_EQUAL(INFIX,mulToken.arity);
}


/*  createOperatorToken("-", PREFIX) should create a pointer to OperatorToken
 *    
 *                                     [OperatorToken]
 *  [OperatorToken ptr] -------------> [      -      ]
 *                                     [   PREFIX    ]
 */
void test_createOperatorToken_given_Prefix_symbol_SUB_should_return_OperatorToken(void){
  OperatorToken* subToken = malloc(sizeof(OperatorToken));
  subToken = (OperatorToken*)createOperatorToken("-", PREFIX);
  
  TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE, subToken->type);
  TEST_ASSERT_EQUAL("-", subToken->symbol);
  TEST_ASSERT_EQUAL(PREFIX, subToken->arity);
}




