#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int stack1[MAX], stack2[MAX];
void push_stack1(int *top1, int val) {
    if (*top1 == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack1[++(*top1)] = val;
    printf("\n%d pushed onto stack1", stack1[*top1]);
}

// Pop operation for stack1
int pop_stack1(int *top1) {
    if (*top1 == -1) {
        printf("Stack1 Underflow\n");
        return -1;
    }
    return stack1[(*top1)--];
}
void push_stack2(int *top2, int val) {
    if (*top2 == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack2[++(*top2)] = val;
    printf("\n%d pushed onto stack2", stack2[*top2]);
}
int pop_stack2(int *top2) {
    if (*top2 == -1) {
        printf("Stack2 Underflow\n");
        return -1;
    }
    return stack2[(*top2)--];
}
void enqueue(int *top1, int val) {
    push_stack1(top1, val);
}
void dequeue(int *top1, int *top2) {
    if (*top2 == -1) {  // If stack2 is empty
        while (*top1 != -1) {
            push_stack2(top2, pop_stack1(top1)); 
        }
    }
    if (*top2 == -1) {
        printf("Queue is empty\n");
    } else {
        printf("\n%d dequeued from the queue", pop_stack2(top2));
    }
}

int main() {
    int top1 = -1, top2 = -1;
    int choice, val;

    while (1) {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &val);
                enqueue(&top1, val);
                break;
            case 2:
                dequeue(&top1, &top2);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
