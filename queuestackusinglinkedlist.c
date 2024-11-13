#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}
int isStackEmpty(struct Node* top) {
    return top == NULL;
}
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}
int dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    free(temp);
    return data;
}
int front(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}
int isQueueEmpty(struct Node* front) {
    return front == NULL;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;
    int choice, value;
    printf("Stack Operations (Enter 0 to stop)\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display Stack\n5. Check if Stack is Empty\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stackTop, value);
                break;
            case 2:
                value = pop(&stackTop);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(stackTop);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                printf("Stack: ");
                display(stackTop);
                break;
            case 5:
                if (isStackEmpty(stackTop)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    printf("\nQueue Operations (Enter 0 to stop)\n");
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display Queue\n5. Check if Queue is Empty\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queueFront, &queueRear, value);
                break;
            case 2:
                value = dequeue(&queueFront);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                value = front(queueFront);
                if (value != -1) {
                    printf("Front value: %d\n", value);
                }
                break;
            case 4:
                printf("Queue: ");
                display(queueFront);
                break;
            case 5:
                if (isQueueEmpty(queueFront)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

Thanks a lot for sharing.Thanks a lot.This is great, thank you so much!
