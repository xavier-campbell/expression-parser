#ifndef stack_utils
#define stack_utils

#include "tokens.h"

typedef struct {
	double* value_array;
	int capacity;
	int top;
} Value_Stack;

typedef struct {
	TokenType* type_array;
	int capacity;
	int top;
} Operator_Stack;

Value_Stack* initialise_value_stack(int capacity);
void push_value(Value_Stack* value_stack, double token);
double pop_value(Value_Stack* value_stack);
double peek_value(Value_Stack*);

Operator_Stack* initialise_operator_stack(int capacity);
void push_operator(Operator_Stack* operator_stack, TokenType token);
TokenType pop_operator(Operator_Stack* operator_stack);
TokenType peek_operator(Operator_Stack* operator_stack);

#endif
