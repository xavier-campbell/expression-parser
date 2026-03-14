#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack_utils.h"
#include "tokens.h"

double apply_operator(TokenType operator, double left, double right){
	switch(operator){
		case TOKEN_PLUS: return left + right;
		case TOKEN_MINUS: return left - right;
		case TOKEN_MULTIPLY: return left * right;
		case TOKEN_DIVIDE: return left / right;
		case TOKEN_POWER: return pow(left, right);
		default: return 0;
	}
}

double parse_expression(Token* tokens, int token_count){

	Value_Stack* value_stack = initialise_value_stack(token_count);
	Operator_Stack* operator_stack = initialise_operator_stack(token_count);

	for (int i = 0; i < token_count; i++) {
		Token token = tokens[i];

		switch(token.type){
			case TOKEN_NUMBER: {
				push_value(value_stack, token.value);
				break;
			}

			case TOKEN_PLUS:
			case TOKEN_MINUS:
			case TOKEN_MULTIPLY:
			case TOKEN_DIVIDE:
			case TOKEN_POWER: {
				while (operator_stack->top >= 0) {
					TokenType top_operator = peek_operator(operator_stack);
					
					if (top_operator == TOKEN_LPAREN) {
						break;
					}

					if (operator_precedence(top_operator) >= operator_precedence(token.type)) {
						pop_operator(operator_stack);
						double right = pop_value(value_stack);
						double left = pop_value(value_stack);
						double result = apply_operator(top_operator, left, right);
						push_value(value_stack, result);
					}
					else {
						break;
					}
				}  
				push_operator(operator_stack, token.type);	
				break;
			}
			case TOKEN_LPAREN: {
				push_operator(operator_stack, token.type);
				break;
			}
			case TOKEN_RPAREN: {
				while (operator_stack->top >= 0 && peek_operator(operator_stack) != TOKEN_LPAREN) {
						TokenType operator = pop_operator(operator_stack);
						double right = pop_value(value_stack);
						double left = pop_value(value_stack);
						double result = apply_operator(operator, left, right);
						push_value(value_stack, result);
				}
				if (operator_stack->top >= 0 && peek_operator(operator_stack) == TOKEN_LPAREN) {
					pop_operator(operator_stack);
					break;
				}
				break;
			}
			case TOKEN_ERROR: {
				printf("ERROR: Unrecognised input at %d \n", token.column);
				free(value_stack->value_array);
				free(value_stack);
				free(operator_stack->type_array);
				free(operator_stack);
				return 0;
			}
			case TOKEN_END: break;
		}
	}

	while (operator_stack->top >= 0) {
		TokenType operator = pop_operator(operator_stack);
		double right = pop_value(value_stack);
		double left = pop_value(value_stack);
		double result = apply_operator(operator, left, right);
		push_value(value_stack, result);
	}

	double result = pop_value(value_stack);

	free(value_stack->value_array);
	free(value_stack);
	free(operator_stack->type_array);
	free(operator_stack);

	return result;
} 
