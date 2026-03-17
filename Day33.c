/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void push(Node** top, char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

char pop(Node** top) {
    if (*top == NULL) {
        return '\0';
    }
    Node* temp = *top;
    char val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

char peek(Node* top) {
    if (top == NULL) return '\0';
    return top->data;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infixToPostfix(char* infix, char* postfix) {
    Node* stack = NULL;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (peek(stack) != '(' && stack != NULL) {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        } else if (isOperator(c)) {
            while (stack != NULL && precedence(peek(stack)) >= precedence(c)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }
    while (stack != NULL) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[256], postfix[256];
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0;
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}