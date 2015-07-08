#ifndef Token_H
#define Token_H

#include <stdint.h>

#define SUB 20
#define ADD 20
#define MUL 30
#define DIV 30
#define EOT 0

// Token *nud(){
  // if
    // return
  // else
    // return 
// }


typedef enum {
	TOKEN_UNKNOWN_TYPE,
	TOKEN_INTEGER_TYPE,
	TOKEN_OPERATOR_TYPE,
	TOKEN_FLOAT_TYPE,
	TOKEN_STRING_TYPE,
	TOKEN_IDENTIFIER_TYPE,
} TokenType;

typedef enum {
	PREFIX, //-2
	INFIX,	//2*2
	POSTFIX	//x++
} Arity;

typedef enum {
	NONE,
	LEFT_TO_RIGHT,
	RIGHT_TO_LEFT,
} Associativity;

typedef struct Token_t Token;
struct Token_t{
	TokenType type;
  uint32_t startColumn;
  uint32_t length;
  Token* (*nud)(Token*);
  Token* (*led)(Token*);
};

typedef struct {
	TokenType type;
  uint32_t startColumn;
  uint32_t length;
	int value;
} IntegerToken;

typedef struct {
	TokenType type;
  uint32_t startColumn;
  uint32_t length;
	double value;
} FloatToken;

typedef struct {
	TokenType type;
  uint32_t startColumn;
  uint32_t length;
	char *name;
} IdentifierToken, StringToken;

typedef struct {
	TokenType type;
  uint32_t startColumn;
  uint32_t length;
	char *symbol;
  int bindingPower;
	Arity arity;
	Token *token[0];
  Token* (*nud)(Token*);
  Token* (*led)(Token*);
} OperatorToken;

Token *createOperatorToken(char *symbol, Arity AR);
Token *createIntegerToken(int value);

Token* infixNud(Token* myself);
Token* infixLed(Token* myself);

#endif // Token_H

