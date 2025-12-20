#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) return;
    stack[++top] = item;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char symbol) {
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return 0;
}

void reverse(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    int i, j = 0;
    reverse(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    for (i = 0; infix[i] != '\0'; i++) {
        char item = infix[i];
        if (isdigit(item) || isalpha(item)) {
            prefix[j++] = item;
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            char x = pop();
            while (x != '(') { prefix[j++] = x; x = pop(); }
        } else {
            while (top != -1 && precedence(stack[top]) > precedence(item)) {
                prefix[j++] = pop();
            }
            push(item);
        }
    }
    while (top != -1) prefix[j++] = pop();
    prefix[j] = '\0';
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Infix ifadeyi girin: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix hali: %s\n", prefix);
    return 0;
}