#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int n) {
    if(top < MAX - 1)
        stack[++top] = n;
}

int pop() {
    if(top >= 0)
        return stack[top--];
    return -1;
}

void decimalToBinary(int num) {
    while(num > 0) {
        push(num % 2);
        num /= 2;
    }
    printf("Binary: ");
    while(top != -1)
        printf("%d", pop());
    printf("\n");
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    if(num == 0)
        printf("Binary: 0\n");
    else
        decimalToBinary(num);
    return 0;
}
