/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (*top == NULL) {
        printf("Error\n");
        exit(1);
    }
    Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int isOperator(char* token) {
    return (strcmp(token, "+") == 0 ||
            strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0);
}

int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    char* token = strtok(expr, " ");
    while (token != NULL) {
        if (!isOperator(token)) {
            push(&stack, atoi(token));
        } else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;
            if (strcmp(token, "+") == 0) result = a + b;
            else if (strcmp(token, "-") == 0) result = a - b;
            else if (strcmp(token, "*") == 0) result = a * b;
            else result = a / b;
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

int main() {
    char expr[256];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;
    int result = evaluatePostfix(expr);
    printf("%d\n", result);
    return 0;
}