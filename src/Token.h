#ifndef Token_H
#define Token_H
#define MUL 30
#define DIV 30
#define SUB 20
#define ADD 20

typedef enum {
  TOKEN_INTEGER_TYPE,
  TOKEN_OPERATOR_TYPE,
}TokenType;

typedef enum {
  PREFIX,
  INFIX,
  POSTFIX,
} Arity;

typedef enum {
  NONE,
  LEFT_TO_RIGHT,
  RIGHT_TO_LEFT,
}Associativity;


typedef struct {
  TokenType type;
}Token;

typedef struct{
  TokenType type;
  int value;
}IntegerToken;

typedef struct{
  TokenType type;
  char *symbol;
  Arity arity;
  int bindingPower;
//  Associativity assoc;
  Token *token[0];
} OperatorToken;


// Symbol can be "++", "*", "[", ":"
OperatorToken *createOperatorToken(char *symbol, Arity arity);
IntegerToken *createIntegerToken(int value);

#endif // Token_H
