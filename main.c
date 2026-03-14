#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "lexer.h"
#include "parser.h"

int main() {
    const char* tests[] = {
        "3 + 5",
        "3 + 5 * 2", 
        "(3 + 5) * 2",
        "2 ^ 3",
        "10 / 2 - 3",
		"20.53740 * 3.141297",
        NULL
    };
    
    for (int i = 0; tests[i] != NULL; i++) {
        int count;
        Token* tokens = tokenizer(tests[i], &count);

        if (tokens) {
            double result = parse_expression(tokens, count);
            printf("%s = %f\n", tests[i], result);
            free(tokens);
        }
    }
    
    return 0;
}
