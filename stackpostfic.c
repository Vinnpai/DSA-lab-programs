#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//isdigit()
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

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    CharStack s;
    s.top = -1;  // Initialize the stack to empty
    int j = 0;
    
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[j++] = ch;
        } 
        else if (ch == '(') {
            pushChar(&s, ch);
        } 
        else if (ch == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(') {
                postfix[j++] = popChar(&s);
            }
            popChar(&s); // Remove '('
        } 
        else if (isOperator(ch)) {
            while (!isEmptyChar(&s) && precedence(peekChar(&s)) >= precedence(ch)) {
                postfix[j++] = popChar(&s);
            }
            pushChar(&s, ch);
        }
    }

    // Pop any remaining operators
    while (!isEmptyChar(&s)) {
        postfix[j++] = popChar(&s);
    }

    postfix[j] = '\0';
}
        
// Evaluate postfix
double evaluatePostfix(char postfix[]) {
    DoubleStack s;
    s.top = -1;


    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];
        
        if (isdigit(ch)) {
            pushDouble(&s, ch - '0');
        } else if (isOperator(ch)) {
            double b = popDouble(&s);
            double a = popDouble(&s);
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

int main() {
    int choice;
    char infix[100], postfix[100];

    do {
        printf("\nMENU:\n1. Infix to Postfix\n2. Evaluate Postfix\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix: %s\n", postfix);
                break;

            case 2:
                printf("Enter postfix: ");
                scanf("%s", postfix);
                printf("Result: %.2f\n", evaluatePostfix(postfix));
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