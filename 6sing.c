#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Create a new node with user input
struct node* createnode() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode;
    return newnode;
}

// Insert at the front
void insertFront(struct node* header) {
    struct node* newnode = createnode();
    struct node*first=header->next;
    newnode->next = first;
    header->next = newnode;
    printf("Inserted %d at front.\n", newnode->data);
}

// Insert at the rear
void insertRear(struct node* header) {
    struct node* newnode = createnode();
    struct node* temp = header;

    // Traverse to the last node (whose next is header)
    while (temp->next != header) {
        temp = temp->next;
    }

   
    newnode->next = header;
    temp->next = newnode;
    printf("Inserted %d at rear.\n", newnode->data);
}

// Delete by key
void deleteByKey(struct node* header) {
    int key;
    printf("Enter key to delete: ");
    scanf("%d", &key);

    struct node* prev = header;
    struct node* curr = header->next;

    while (curr != header) {
        if (curr->data == key) {
            prev->next = curr->next;
            printf("Deleted key %d\n", key);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Key %d not found!\n", key);
}

// Search by position
void searchByPosition(struct node* header) {
    int pos, i = 1;
    printf("Enter position to search: ");
    scanf("%d", &pos);

    struct node* temp = header->next;
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

// Display the list
void display(struct node* header) {
    struct node* temp = header->next;
    if (temp == header) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp != header) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* header = (struct node*)malloc(sizeof(struct node));
    header->data = 0;      // dummy header node
    header->next = header; // circular

    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete by Key\n4. Search by Position\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertFront(header); break;
            case 2: insertRear(header); break;
            case 3: deleteByKey(header); break;
            case 4: searchByPosition(header); break;
            case 5: display(header); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}