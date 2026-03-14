#include "stack_utils.h"
#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>

Value_Stack* initialise_value_stack(int capacity) {
	if (capacity <= 0) return NULL;

	Value_Stack* stack = malloc(sizeof(Value_Stack));
	if (stack == NULL) return NULL;

	stack -> value_array = malloc(sizeof(double) * capacity);
	if (stack->value_array == NULL) {
		free(stack);
		return NULL;
	}

	stack -> capacity = capacity;
	stack -> top = -1;
	return stack;
}

void destroy_value_stack(Value_Stack* value_stack) {
	if (value_stack == NULL) {
		return;
	}
	free(value_stack->value_array);
	free(value_stack);
}

Operator_Stack* initialise_operator_stack(int capacity) {
	if (capacity <= 0) return NULL;

	Operator_Stack* stack = malloc(sizeof(Operator_Stack));
	if (stack == NULL) return NULL;

	stack -> type_array = malloc(sizeof(TokenType) * capacity);
	if (stack->type_array == NULL){
		free(stack);
		return NULL;
	}

	stack -> capacity = capacity;
	stack -> top = -1;
	return stack;
}

void destroy_operator_stack(Operator_Stack* operator_stack) {
	if (operator_stack == NULL) {
		return;
	}
	free(operator_stack->type_array);
	free(operator_stack);
}


void push_value(Value_Stack* value_stack, double token) {
	if (value_stack->top < value_stack->capacity - 1){ 
		value_stack -> value_array[++value_stack->top] = token;
	}
	else {
		printf("STACK OVERFLOW \n");
	}
}

double pop_value(Value_Stack* value_stack) {
	if (value_stack->top >= 0) {
		return value_stack->value_array[value_stack->top--];
	}
	else {
		printf("STACK UNDERFLOW \n");
		return 0;
	}
}

double peek_value(Value_Stack* value_stack) {
	if (value_stack->top != -1){
		return value_stack -> value_array[value_stack->top];
	}
	else {
		printf("VALUE STACK IS EMPTY \n");
		return 0;
	}
}

void push_operator(Operator_Stack* operator_stack, TokenType token) {
	if (operator_stack->top < operator_stack->capacity - 1){ 
		operator_stack -> type_array[++operator_stack->top] = token;
	}
	else {
		printf("STACK OVERFLOW \n");
	}
}

TokenType pop_operator(Operator_Stack* operator_stack) {
	if (operator_stack->top >= 0) {
		return operator_stack->type_array[operator_stack->top--];
	}
	else {
		printf("STACK UNDERFLOW \n");
		return 0;
	}
}

TokenType peek_operator(Operator_Stack* operator_stack) {
	if (operator_stack->top != -1){
		return operator_stack -> type_array[operator_stack->top];
	}
	else {
		printf("OPERATOR STACK IS EMPTY \n");
		return 0;
	}
}
