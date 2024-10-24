#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

// Stack functions
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

bool isEmpty() {
    return top == -1;
}

// Function to check if the parentheses are valid
bool isValid(char* s) {
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        } else {
            char topChar = pop();
            if ((s[i] == ')' && topChar != '(') ||
                (s[i] == '}' && topChar != '{') ||
                (s[i] == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    
    return isEmpty();
}

int main() {
    char str[MAX];
    printf("Enter parentheses: ");
    scanf("%s", str);

    if (isValid(str)) {
        printf("Valid parentheses.\n");
    } else {
        printf("Invalid parentheses.\n");
    }

    return 0;
}
