#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Top of the stack
struct Node* top = NULL;

// Push function
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

// Pop function
void pop() {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        struct Node* temp = top;
        printf("Popped: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

// Display stack
void displayStack() {
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main
int main() {
    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    displayStack();
    push(40);
    displayStack();
    return 0;
}