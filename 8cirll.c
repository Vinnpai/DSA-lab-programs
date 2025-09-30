#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node* createnode() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode;
    newnode->prev = newnode;
    return newnode;
}

void insertByOrder(struct node *header) {
    struct node *newnode = createnode(header);
    struct node *temp = header->next;

    while (temp != header && temp->data < newnode->data) {
        temp = temp->next;
    }

    // insert before temp
    newnode->next = temp;
    newnode->prev = temp->prev;
    temp->prev->next = newnode;
    temp->prev = newnode;
}

void deleteRear(struct node *header) {
    if (header->next == header) {
        printf("List empty!\n");
        return;
    }
    struct node *last = header->prev;
    last->prev->next = header;
    header->prev = last->prev;
    printf("Deleted %d from rear.\n", last->data);
    free(last);
}

void deleteFront(struct node *header) {
    if (header->next == header) {
        printf("List empty!\n");
        return;
    }
    struct node *first = header->next;
   first->prev->next = first->next;
    first->next->prev = first->prev;
    printf("Deleted %d from front.\n", first->data);
    free(first);
}

void searchByPosition(struct node *header) {
    int pos, i = 1;
    printf("Enter position to search: ");
    scanf("%d", &pos);

    struct node *temp = header->next;
    while (temp != header && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == header) {
        printf("Invalid position!\n");
    } else {
        printf("Data at position %d = %d\n", pos, temp->data);
    }
}

void display(struct node *header) {
    struct node *temp = header->next;
    while (temp != header) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *header = (struct node*)malloc(sizeof(struct node));
    header->data = 0;
    header->next = header;
    header->prev = header;

    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert by Order\n");
        printf("2. Delete Rear\n");
        printf("3. Delete Front\n");
        printf("4. Search by Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertByOrder(header); break;
            case 2: deleteRear(header); break;
            case 3: deleteFront(header); break;
            case 4: searchByPosition(header); break;
            case 5: display(header); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}