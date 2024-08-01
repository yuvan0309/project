#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() { return rear == MAX_SIZE - 1; }

int isEmpty() { return front == -1 || front > rear; }

void enqueue(int data) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = data;
    printf("Inserted %d\n", data);
}

int dequeue() {
    if (isEmpty()) {
        printf("Underflow\n");
        return -1;
    }
    int data = queue[front++];
    if (front > rear) front = rear = -1;
    printf("Deleted %d\n", data);
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}
