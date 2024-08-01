#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int data;
} Node;

void insert_max_pq(Node* pq, int* front, int* rear, int value) {
    if (*rear == MAX_SIZE - 1) {
        printf("Priority queue overflow\n");
        return;
    }

    (*rear)++;
    pq[*rear].data = value;

    int child_index = *rear;
    int parent_index = (child_index - 1) / 2;

    while (child_index > 0 && pq[child_index].data > pq[parent_index].data) {
        Node temp = pq[child_index];
        pq[child_index] = pq[parent_index];
        pq[parent_index] = temp;

        child_index = parent_index;
        parent_index = (child_index - 1) / 2;
    }
}

int delete_max_pq(Node* pq, int* front, int* rear) {
    if (*front == -1 && *rear == -1) {
        printf("Priority queue underflow\n");
        return -1;
    }

    int max_value = pq[*front].data;

    if (*front == *rear) {
        *front = *rear = -1;
    } else {
        pq[*front] = pq[*rear];
        (*rear)--;

        int parent_index = *front;
        int left_child_index = 2 * parent_index + 1;
        int right_child_index = 2 * parent_index + 2;

        while (left_child_index <= *rear) {
            int larger_child_index = left_child_index;

            if (right_child_index <= *rear && pq[right_child_index].data > pq[left_child_index].data) {
                larger_child_index = right_child_index;
            }

            if (pq[parent_index].data >= pq[larger_child_index].data) {
                break;
            }

            Node temp = pq[parent_index];
            pq[parent_index] = pq[larger_child_index];
            pq[larger_child_index] = temp;

            parent_index = larger_child_index;
            left_child_index = 2 * parent_index + 1;
            right_child_index = 2 * parent_index + 2;
        }
    }

    return max_value;
}

void display_max_pq(Node* pq, int* front, int* rear) {
    if (*front == -1 && *rear == -1) {
        printf("Priority queue is empty\n");
    } else {
        for (int i = *front; i <= *rear; i++) {
            printf("%d ", pq[i].data);
        }
        printf("\n");
    }
}

int main() {
    Node pq[MAX_SIZE];
    int front = -1, rear = -1;

    // Example usage
    insert_max_pq(pq, &front, &rear, 10);
    insert_max_pq(pq, &front, &rear, 20);
    insert_max_pq(pq, &front, &rear, 5);

    printf("Max Priority Queue: ");
    display_max_pq(pq, &front, &rear);

    int deleted_value = delete_max_pq(pq, &front, &rear);
    printf("\nDeleted value: %d\n", deleted_value);

    printf("Max Priority Queue after deletion: ");
    display_max_pq(pq, &front, &rear);

    return 0;
}
