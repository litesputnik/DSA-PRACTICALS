#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

/* Function to push element onto stack */
void push(char ch) {
    if (top >= MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        stack[top] = ch;
    }
}

/*Function to pop element from stack */
char pop() {
    if (top == -1) {
        return '\0';
    } else {
        char ch = stack[top];
        top--;
        return ch;
    }
}

/* Function to check matching pair of brackets */
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    else if (open == '{' && close == '}')
        return 1;
    else if (open == '[' && close == ']')
        return 1;
    else
        return 0;
}

/* Function to check if expression is balanced */
int isBalanced(char expr[]) {
    int i;
    char ch, popped;

    for (i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            popped = pop();
            if (!isMatchingPair(popped, ch)) {
                return 0; // not balanced
            }
        }
    }


    if (top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("\nBalanced Parentheses\n");
    else
        printf("\nUnbalanced Parentheses\n");

    return 0;
}