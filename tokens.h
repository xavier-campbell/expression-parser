#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
	TOKEN_NUMBER,

	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_POWER,

	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_ERROR,
	TOKEN_END
} TokenType;

typedef struct {
	TokenType type;
	double value;
	int column;
} Token;

const char* token_type_to_string(TokenType type);
int operator_precedence(TokenType token);
TokenType get_token_type(char c);

#endif
