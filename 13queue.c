#include <stdio.h>
#include <stdlib.h>

int csize, psize; // Global sizes for circular and priority queues

// Circular Queue
struct Queue {
    int *queue;
    int front;
    int rear;
} CQ;

// Priority Queue
struct Queue PQ;

// Insert in Circular Queue (Push Rear)
void pushRear() {
    int val;
    printf("Enter the Element to Insert (Circular Queue - Rear): ");
    scanf("%d", &val);

    if (CQ.front == -1) { 
        CQ.front = CQ.rear = 0;
    } 
    else if ((CQ.rear + 1) % csize == CQ.front) { 
        printf("Queue is Full\nReallocating Memory\n");
        csize++;
        CQ.queue = (int *)realloc(CQ.queue, csize * sizeof(int));
        CQ.rear = (CQ.rear + 1) % csize;
    } 
    else {
        CQ.rear = (CQ.rear + 1) % csize;
    }

    CQ.queue[CQ.rear] = val;
    printf("Insertion Successful\n");
}

// Delete from front (Circular Queue)
void popFront() {
    if (CQ.front == -1) {
        printf("Queue is Empty\n");
    } 
    else if (CQ.front == CQ.rear) {
        printf("Deleted Element: %d\n", CQ.queue[CQ.front]);
        CQ.front = CQ.rear = -1;
    } 
    else {
        printf("Deleted Element: %d\n", CQ.queue[CQ.front]);
        CQ.front = (CQ.front + 1) % csize;
    }
}

// Insert in Priority Queue (Ascending Order)
void priorityInsert() {
    int val, i;
    printf("Enter the Element to Insert (Priority Queue): ");
    scanf("%d", &val);

    if (PQ.front == -1) {  
        PQ.front = PQ.rear = 0;
        PQ.queue[PQ.rear] = val;
    } 
    else {  
        if (PQ.rear == psize - 1) {  
            printf("Queue is Full\nReallocating Memory\n");
            psize++;
            PQ.queue = (int *)realloc(PQ.queue, psize * sizeof(int));
        }

        for (i = PQ.rear; i >= PQ.front && PQ.queue[i] > val; i--) {
            PQ.queue[i + 1] = PQ.queue[i];
        }
        PQ.queue[i + 1] = val;
        PQ.rear++;
    }

    printf("Priority Insertion Successful\n");
}

// Delete from front (Priority Queue)
/*void priorityDelete() {
    if (PQ.front == -1) {
        printf("Queue is Empty\n");
    } 
    else if (PQ.front == PQ.rear) {
        printf("Deleted Element: %d\n", PQ.queue[PQ.front]);
        PQ.front = PQ.rear = -1;
    } 
    else {
        printf("Deleted Element: %d\n", PQ.queue[PQ.front]);
        for (int i = PQ.front; i < PQ.rear; i++) {
            PQ.queue[i] = PQ.queue[i + 1];
        }
        PQ.rear--;
    }
}*/
// Function to delete from front (Priority Queue)
void priorityDelete() {
    if (PQ.front == -1) { // Check if queue is empty
        printf("Queue is Empty\n");
    } 
    else if (PQ.front == PQ.rear) { // Single element case
        printf("Deleted Element: %d\n", PQ.queue[PQ.front]);
        PQ.front = PQ.rear = -1;
    } 
    else {
        printf("Deleted Element: %d\n", PQ.queue[PQ.front]);
        PQ.front++;
    }
}


// Display Circular Queue
void displayCircular() {
    if (CQ.front == -1) {
        printf("Circular Queue is Empty\n");
        return;
    }

    printf("Circular Queue: ");

    if (CQ.front <= CQ.rear) {
        // No wrap
        for (int i = CQ.front; i <= CQ.rear; i++) {
            printf("%d ", CQ.queue[i]);
        }
    } else {
        // Wrapped around
        for (int i = CQ.front; i < csize; i++) {
            printf("%d ", CQ.queue[i]);
        }
        for (int i = 0; i <= CQ.rear; i++) {
            printf("%d ", CQ.queue[i]);
        }
    }

    printf("\n");
}

// Display Priority Queue
void displayPriority() {
    if (PQ.front == -1) {
        printf("Priority Queue is Empty\n");
    } 
    else {
        printf("Priority Queue: ");
        for (int i = PQ.front; i <= PQ.rear; i++) {
            printf("%d ", PQ.queue[i]);
        }
        printf("\n");
    }
}

// Main
int main() {
    int choice;

    CQ.front = CQ.rear = -1;
    PQ.front = PQ.rear = -1;

    printf("Enter Circular Queue Size: ");
    scanf("%d", &csize);
    CQ.queue = (int *)malloc(csize * sizeof(int));

    printf("Enter Priority Queue Size: ");
    scanf("%d", &psize);
    PQ.queue = (int *)malloc(psize * sizeof(int));

    do {
        printf("\n========= MENU =========\n");
        printf("1. Circular Queue - Push Rear\n");
        printf("2. Circular Queue - Pop Front\n");
        printf("3. Display Circular Queue\n");
        printf("4. Priority Queue - Insert\n");
        printf("5. Priority Queue - Delete\n");
        printf("6. Display Priority Queue\n");
        printf("7. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: pushRear(); break;
            case 2: popFront(); break;
            case 3: displayCircular(); break;
            case 4: priorityInsert(); break;
            case 5: priorityDelete(); break;
            case 6: displayPriority(); break;
            case 7:
                free(CQ.queue);
                free(PQ.queue);
                printf("!! THANK YOU !!\n");
                exit(0);
            default: printf("Invalid Choice\n");
        }
    } while (1);

    return 0;
}