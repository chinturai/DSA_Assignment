#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

typedef struct Node* NODE;
NODE front = NULL;
NODE rear = NULL;

// Function to add an element to the queue
void enqueue(int ele) {
    NODE newNode = (NODE)malloc(sizeof(struct Node)); 
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->info = ele;
    newNode->link = NULL;

    if (rear == NULL) {
        // If queue is empty
        front = rear = newNode;
    } else {
        rear->link = newNode;
        rear = newNode;
    }
    printf("%d enqueued\n", ele);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    NODE temp = front;
    int data = front->info;
    printf("Dequeued element is %d\n", data);
    
    front = front->link;
    
    if (front == NULL) {
        rear = NULL; // If the queue becomes empty
    }
    free(temp);
}

// Function to view the element at the front of the queue
int viewFront() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->info;
}

// Function to display all elements in the queue
void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    NODE temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    enqueue(100);
    enqueue(200);
    enqueue(300);
    dequeue();
    printf("Front of the queue is %d\n", viewFront());
    displayQueue();
    
    return 0;
}
