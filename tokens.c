#include "tokens.h"

const char* token_type_to_string(TokenType type) {
	switch(type) {
		case TOKEN_NUMBER: return "number";
		case TOKEN_PLUS: return "plus";
		case TOKEN_MINUS: return "minus";
		case TOKEN_MULTIPLY: return "multiply";
		case TOKEN_DIVIDE: return "divide";
		case TOKEN_POWER: return "power";
		case TOKEN_LPAREN: return "left paren";
		case TOKEN_RPAREN: return "right paren";
		case TOKEN_END: return "end";
		case TOKEN_ERROR: return "ERROR";
		default: return "UNKNOWN";
	}
}

int operator_precedence(TokenType type) {
	int precedence = 0;
	
	switch(type) {
		case TOKEN_PLUS:
		case TOKEN_MINUS:
			precedence = 1;
			return precedence;

		case TOKEN_MULTIPLY:
		case TOKEN_DIVIDE:
			precedence = 2;
			return precedence;

		case TOKEN_POWER:
			precedence = 3;
			return precedence;

		default:
			precedence = 0;
	}
	return precedence;
}

TokenType get_token_type(char c) {
	switch (c) {
		case '+': return TOKEN_PLUS;
        case '-': return TOKEN_MINUS;
        case '*': return TOKEN_MULTIPLY;
        case '/': return TOKEN_DIVIDE;
		case '^': return TOKEN_POWER;
        case '(': return TOKEN_LPAREN;
        case ')': return TOKEN_RPAREN;
        default:  return TOKEN_ERROR;
	}
}
