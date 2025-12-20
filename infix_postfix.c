#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack yapısı ve yardımcı fonksiyonlar
char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

// Operatörlerin öncelik sırasını belirleyen fonksiyon
int precedence(char symbol) {
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return 0;
}

// Dönüştürme fonksiyonu
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item, x;

    push('(');          // Stack'e başlangıç parantezi at
    strcat(infix, ")"); // İfadenin sonuna bitiş parantezi ekle

    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];

        if (item == '(') {
            push(item);
        } else if (isdigit(item) || isalpha(item)) {
            postfix[j++] = item; // Sayı veya harfse direkt yaz
        } else if (precedence(item) > 0) {
            // Operatörse, stack'teki önceliği kontrol et
            x = pop();
            while (precedence(x) >= precedence(item)) {
                postfix[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        } else if (item == ')') {
            // Kapanan parantezse, açılan paranteze kadar her şeyi çıkar
            x = pop();
            while (x != '(') {
                postfix[j++] = x;
                x = pop();
            }
        }
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Infix ifadeyi girin (Ornegin: a+b*c): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix hali: %s\n", postfix);

    return 0;
}