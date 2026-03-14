#include "tokens.h"
#include <ctype.h>
#include <stdlib.h>

Token* tokenizer(const char* input, int* token_count) {
	int token_capacity = 100;
	Token* tokens = malloc(sizeof(Token) * token_capacity);
	int token_counter = 0;
	int i = 0;


	while(input[i] != '\0'){
		
		if (token_counter >= token_capacity - 1) {
			token_capacity += 50;
			Token* new_tokens = realloc(tokens, sizeof(Token) * token_capacity);

			if (new_tokens == NULL) {
				free(tokens);
				*token_count = 0;
				return NULL;
			}
			tokens = new_tokens;
		}

		if (isspace(input[i])) {
			i++;
			continue;
		}

		if(isdigit(input[i]) || input[i] == '.') {
			char* end;
			double value = strtod(&input[i], &end);
			tokens[token_counter].type = TOKEN_NUMBER;
			tokens[token_counter].value = value;
			tokens[token_counter].column = i;
			token_counter ++;
			i = end - input;
			continue;
		}

		TokenType token_type = get_token_type(input[i]);
		if(token_type != TOKEN_ERROR) {
			tokens[token_counter].type = token_type;
			tokens[token_counter].value = 0;
			tokens[token_counter].column = i;
			token_counter++;
			i++;
		}
		else{
			tokens[token_counter].type = TOKEN_ERROR;
			tokens[token_counter].value = 0;
			tokens[token_counter].column = i;
			token_counter++;
			i++;
		}
	}

	tokens[token_counter].type = TOKEN_END;
	token_counter++;
	
	*token_count = token_counter;	
	return tokens;
}
