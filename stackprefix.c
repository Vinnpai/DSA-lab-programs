#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // isdigit()
#include <math.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} CharStack;

typedef struct {
    double data[MAX];
    int top;
} DoubleStack;

// Stack operations
void pushChar(CharStack *s, char val) { s->data[++(s->top)] = val; }
char popChar(CharStack *s) { return s->data[(s->top)--]; }
char peekChar(CharStack *s) { return s->data[s->top]; }
int isEmptyChar(CharStack *s) { return s->top == -1; }

void pushDouble(DoubleStack *s, double val) { s->data[++(s->top)] = val; }
double popDouble(DoubleStack *s) { return s->data[(s->top)--]; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Reverse string
void reverseStr(char infix[]) {
    int n = strlen(infix);
    for (int i = 0; i < n / 2; i++) {
        char temp = infix[i];
        infix[i] =infix[n - i - 1];
    infix[n - i - 1] = temp;
    }
}

// Infix → Prefix (direct, not using infix→postfix)
void infixToPrefix(char infix[], char prefix[]) {
    CharStack s;
    s.top = -1;
    int j = 0;

    // Step 1: reverse infix and swap brackets
    reverseStr(infix);
    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Step 2: process like postfix on reversed infix
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            prefix[j++] = ch;
        } else if (ch == '(') {
            pushChar(&s, ch);
        } else if (ch == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(')
                prefix[j++] = popChar(&s);
            popChar(&s); // remove '('
        } else if (isOperator(ch)) {
            while (!isEmptyChar(&s) && precedence(peekChar(&s)) > precedence(ch))
                prefix[j++] = popChar(&s);
            pushChar(&s, ch);
        }
    }

    while (!isEmptyChar(&s))
        prefix[j++] = popChar(&s);

    prefix[j] = '\0';

    // Step 3: reverse prefix
    reverseStr(prefix);
}

// Evaluate Prefix
double evaluatePrefix(char prefix[]) {
    DoubleStack s;
    s.top = -1;
    int n = strlen(prefix);

    // Scan from right to left
    for (int i = n - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {
            pushDouble(&s, ch - '0');
        } else if (isOperator(ch)) {
            double a = popDouble(&s);
            double b = popDouble(&s);
            switch (ch) {
                case '+': pushDouble(&s, a + b); break;
                case '-': pushDouble(&s, a - b); break;
                case '*': pushDouble(&s, a * b); break;
                case '/': pushDouble(&s, a / b); break;
                case '^': pushDouble(&s, pow(a, b)); break;
            }
        }
    }

    return popDouble(&s);
}

// Main
int main() {
    int choice;
    char infix[100], prefix[100];

    do {
        printf("\nMENU:\n1. Infix to Prefix\n2. Evaluate Prefix\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix: ");
                scanf("%s", infix);
                infixToPrefix(infix, prefix);
                printf("Prefix: %s\n", prefix);
                break;

            case 2:
                printf("Enter prefix: ");
                scanf("%s", prefix);
                printf("Result: %.2f\n", evaluatePrefix(prefix));
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}