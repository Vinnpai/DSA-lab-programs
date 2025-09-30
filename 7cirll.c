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

void insertFront(struct node *header) {
    struct node *newnode = createnode();
    struct node *first = header->next;

    newnode->next = first;
    newnode->prev = header;
    first->prev = newnode;
    header->next = newnode;
}

void insertRear(struct node *header) {
    struct node *newnode = createnode();
    struct node *last = header->prev;

    newnode->next = header;
    newnode->prev = last;
    last->next = newnode;
    header->prev = newnode;
}

void deleteByPosition(struct node *header) {
    int pos, i = 1;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    struct node *temp = header->next;
    while (temp != header && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == header) {
        printf("Invalid position!\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    printf("Node at position %d deleted.\n", pos);
}

void searchByKey(struct node *header) {
    int key, pos = 1;
    printf("Enter key to search: ");
    scanf("%d", &key);

    struct node *temp = header->next;
    while (temp != header) {
        if (temp->data == key) {
            printf("Key %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Key not found!\n");
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
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete by Position\n");
        printf("4. Search by Key\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertFront(header); break;
            case 2: insertRear(header); break;
            case 3: deleteByPosition(header); break;
            case 4: searchByKey(header); break;
            case 5: display(header); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}