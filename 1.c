#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;
int stackSize = 0;

int isFull();
int isEmpty();
void push(int value);
int pop();
int peek();
void displayStack();

int main() {
    int value;
    int choice;

    printf("Enter the size of the stack (maximum %d): ", MAX);
    scanf("%d", &stackSize);

    if (stackSize > MAX || stackSize <= 0) {
        printf("Invalid stack size! Please restart the program and enter a valid size.\n");
        exit(1);
    }

    while (1) {
        printf("\nStack Operations:\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Peek\n");
        printf("4) Display\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Peeked value is: %d\n", value);
                }
                break;
            case 4:
                displayStack();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input!\n");
        }
    }

    return 0;
}

int isFull() {
    return top == stackSize - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow!\n");
    } else {
        stack[++top] = value;
        printf("Pushed %d onto stack\n", value);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack[top];
    }
}

void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}