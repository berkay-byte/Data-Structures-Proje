#include <stdio.h>
#include <ctype.h>
#include <string.h>

int precedence(char obj) {
    if (obj == '+' || obj == '-') return 1;
    if (obj == '*' || obj == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix) {
    char stack[100];
    int top = -1;
    char postfix[100];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            stack[++top] = token;
        } else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = token;
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);
}

int main() {
    char expression[] = "A*(B+C)/D";
    printf("Infix: %s\n", expression);
    infixToPostfix(expression);
    return 0;
}