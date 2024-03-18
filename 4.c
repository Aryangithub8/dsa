#include<stdio.h>
#include<string.h> // Include string.h for strcat function

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    char ret;
    ret = stack[top];
    stack[top] = '\0';
    top--;
    return ret;
}

int inper(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        default:
            return 0; // You need a default case
    }
}

int stper(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '(':
            return 0;
        case '#':
            return -1;
        default:
            return -1; // Default case should return a value (-1) that doesn't conflict with other cases
    }
}

void convert(char *exprn, char *postfix) {
    int i = 0, j = 0;
    char ch;
    ch = exprn[i++];
    while (ch != '#') {
        switch (ch) {
            case '(':
                push(ch);
                break;
            case ')':
                while (stack[top] != '(')
                    postfix[j++] = pop();
                pop(); // Pop '(' from the stack
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (stper(stack[top]) >= inper(ch))
                    postfix[j++] = pop();
                push(ch);
                break;
            default:
                postfix[j++] = ch;
                break;
        }
        ch = exprn[i++];
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char exprn[20] = "", postfix[20] = "";
    printf("\nEnter the infix expression: ");
    scanf("%s", exprn);
    strcat(exprn, "#");
    push('#');
    convert(exprn, postfix);
    printf("\nPostfix expression: %s\n", postfix);
    return 0;
}
