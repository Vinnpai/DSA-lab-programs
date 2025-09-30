#include <stdio.h>
#include <stdlib.h>

// Global sizes
int csize, dsize;

// Queue structure
struct Queue {
    int *queue;
    int front;
    int rear;
}CQ,DQ;

// Two Queues: Circular Queue and Deque


// -------------------- CIRCULAR QUEUE FUNCTIONS --------------------
void pushrearCQ() {
    int val;
    printf("Enter value (Circular Queue): ");
    scanf("%d", &val);

    if (CQ.front == -1) {
        CQ.front = CQ.rear = 0;
    } 
    else  if ((CQ.rear + 1) % csize == CQ.front) { 
        printf("Circular Queue is Full\nReallocating Memory...\n");
        csize++;
        CQ.queue = (int *)realloc(CQ.queue, csize * sizeof(int));
        CQ.rear = (CQ.rear + 1) % csize;
        
    }
  
    else {
        CQ.rear = (CQ.rear + 1) % csize;
    }

    CQ.queue[CQ.rear] = val;
    printf("Inserted %d at Rear (CQ)\n", val);
}

void popfrontCQ() {
    if (CQ.front == -1) {
        printf("Circular Queue is Empty\n");
    } 
    else if (CQ.front == CQ.rear) {
        printf("Deleted Element (CQ): %d\n", CQ.queue[CQ.front]);
        CQ.front = CQ.rear = -1;
    } 
    else {
        printf("Deleted Element (CQ): %d\n", CQ.queue[CQ.front]);
        CQ.front = (CQ.front + 1) % csize;
    }
}

void displayCQ() {
    
        if (CQ.front == -1) {
            printf("Deque is Empty\n");
            return;
        }
    
       if(CQ.front<=CQ.rear)
       {
         for(int i=CQ.front;i<=CQ.rear;i++)
         {
            printf("%d ", CQ.queue[i]);
         }
       }
       else{
       
    
        for(int i=CQ.front;i<csize;i++)
        {
            printf("%d ", CQ.queue[i]);
        }
        for(int i=0;i<=CQ.rear;i++)
        {
            printf("%d ", CQ.queue[i]);
        }
    
       }
        printf("\n");
    }


// -------------------- DEQUE FUNCTIONS --------------------
void pushrearDQ() {
    int val;
    printf("Enter value (Deque - Rear): ");
    scanf("%d", &val);

    if ((DQ.rear + 1) % dsize == DQ.front) {
        printf("Deque is Full\nReallocating Memory...\n");
        dsize++;
        DQ.queue = (int *)realloc(DQ.queue, dsize * sizeof(int));
    }

    if (DQ.front == -1) {
        DQ.front = DQ.rear = 0;
    } 
    else {
        DQ.rear = (DQ.rear + 1) % dsize;
    }

    DQ.queue[DQ.rear] = val;
    printf("Inserted %d at Rear (DQ)\n", val);
}

void pushfrontDQ() {
    int val;
    printf("Enter value (Deque - Front): ");
    scanf("%d", &val);

    if (DQ.front == -1) {  // empty
        DQ.front = DQ.rear = 0;
    } 
    else if ((DQ.rear + 1) % dsize == DQ.front) {  // full
        printf("Deque is Full\nReallocating Memory...\n");
        dsize++;
        DQ.queue = (int *)realloc(DQ.queue, dsize * sizeof(int));
        // now treat as normal insertion after realloc
        DQ.front = (DQ.front - 1 + dsize) % dsize;
    } 
    else {  // normal
        DQ.front = (DQ.front - 1 + dsize) % dsize;
    }

    DQ.queue[DQ.front] = val;
    printf("Inserted %d at Front (DQ)\n", val);
}

void popfrontDQ() {
    if (DQ.front == -1) {
        printf("Deque is Empty\n");
    } 
    else if (DQ.front == DQ.rear) {
        printf("Deleted Element (DQ Front): %d\n", DQ.queue[DQ.front]);
        DQ.front = DQ.rear = -1;
    } 
    else {
        printf("Deleted Element (DQ Front): %d\n", DQ.queue[DQ.front]);
        DQ.front = (DQ.front + 1) % dsize;
    }
}

void poprearDQ() {
    if (DQ.front == -1) {
        printf("Deque is Empty\n");
    } 
    else if (DQ.front == DQ.rear) {
        printf("Deleted Element (DQ Rear): %d\n", DQ.queue[DQ.rear]);
        DQ.front = DQ.rear = -1;
    } 
    else {
        printf("Deleted Element (DQ Rear): %d\n", DQ.queue[DQ.rear]);
        DQ.rear = (DQ.rear - 1 + dsize) % dsize;
    }
}

void displayDQ() {
    if (DQ.front == -1) {
        printf("Deque is Empty\n");
        return;
    }

   if(DQ.front<DQ.rear)
   {
     for(int i=DQ.front;i<=DQ.rear;i++)
     {
        printf("%d ", DQ.queue[i]);
     }
   }
   else{
    

    for(int i=DQ.front;i<csize;i++)
    {
        printf("%d ", DQ.queue[i]);
    }
    for(int i=0;i<=DQ.rear;i++)
    {
        printf("%d ", DQ.queue[i]);
    }

   }
    printf("\n");
}
// -------------------- MAIN --------------------
int main() {
    

    printf("Enter Circular Queue size: ");
    scanf("%d", &csize);
    CQ.queue = (int *)malloc(csize * sizeof(int));
    CQ.front = CQ.rear = -1;
   

    printf("Enter Deque size: ");
    scanf("%d", &dsize);
    DQ.queue = (int *)malloc(dsize * sizeof(int));
    DQ.front = DQ.rear = -1;

    int choice;
    do {
        printf("\n========= MENU =========\n");
        printf("1. Push Rear (Circular Queue)\n");
        printf("2. Pop Front (Circular Queue)\n");
        printf("3. Display (Circular Queue)\n");
        printf("4. Push Rear (Deque)\n");
        printf("5. Push Front (Deque)\n");
        printf("6. Pop Front (Deque)\n");
        printf("7. Pop Rear (Deque)\n");
        printf("8. Display (Deque)\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: pushrearCQ(); break;
            case 2: popfrontCQ(); break;
            case 3: displayCQ(); break;
            case 4: pushrearDQ(); break;
            case 5: pushfrontDQ(); break;
            case 6: popfrontDQ(); break;
            case 7: poprearDQ(); break;
            case 8: displayDQ(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 9);

    free(CQ.queue);
    free(DQ.queue);
    return 0;
}