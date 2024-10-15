#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

typedef struct Node* NODE;
NODE top = NULL;

void push(int ele) {
    NODE newNode = (NODE)malloc(sizeof(struct Node)); 
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->info = ele;
    newNode->link = top;
    top = newNode;
}

void pop() { 
    if (top == NULL) {
        printf("Empty Stack\n");
        return;
    } else {
        NODE temp = top;
        int data = top->info;
        printf("Popped out element is %d\n", data);
        top = top->link;
        free(temp);
    }
}

int viewTop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->info;
}

void displayStack() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    NODE temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    push(100);
    push(200);
    push(500);
    displayStack();
    pop();
    displayStack();
    printf("Top of the stack is %d\n", viewTop());
    
    return 0;
}
