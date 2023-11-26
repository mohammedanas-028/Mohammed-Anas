#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
    } else {
        stack[++top] = value;
        printf("Element %d pushed onto the stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
    } else {
        printf("Element %d popped from the stack.\n", stack[top--]);
    }
}

void checkPalindrome() {
    // Implement palindrome checking using the stack
}

void displayStatus() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else if (top == MAX - 1) {
        printf("Stack is full.\n");
    } else {
        printf("Stack contains %d elements.\n", top + 1);
    }
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                displayStatus();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (1); // Infinite loop until user chooses to exit

    return 0;
}
