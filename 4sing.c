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
    newnode->next = NULL;
    return newnode;
}

// Insert node in sorted order
void insertByOrder(struct node* header) {
    struct node* newnode = createnode();
    struct node* temp = header->next;
    struct node* prev = header;

    // Find the position to insert
    while (temp != header && temp->data < newnode->data) {
        prev = temp;
        temp = temp->next;
    }

    // Insert node
    newnode->next = temp;
    prev->next = newnode;
}

// Delete node by position
void deleteByPosition(struct node* header) {
    int pos, i = 1;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    struct node* temp = header->next;
    struct node* prev = header;

    while (temp != header && i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == header) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted %d from position %d\n", temp->data, pos);
    free(temp);
}

// Search node by key
void searchByKey(struct node* header) {
    int key, pos = 1;
    printf("Enter key to search: ");
    scanf("%d", &key);

    struct node* temp = header->next;

    while (temp != header) {
        if (temp->data == key) {
            printf("Key %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Key %d not found!\n", key);
}

// Delete node by key
void deleteByKey(struct node* header) {
    int key;
    printf("Enter key to delete: ");
    scanf("%d", &key);

    struct node* temp = header->next;
    struct node* prev = header;

    while (temp != header) {
        if (temp->data == key) {
            prev->next = temp->next;
            printf("Deleted key %d\n", key);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Key %d not found!\n", key);
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
    // Create header node
    struct node* header = (struct node*)malloc(sizeof(struct node));
    header->data = 0;   // dummy value
    header->next = header; // points to itself

    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert by Order\n2. Delete by Position\n3. Search by Key\n4. Delete by Key\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertByOrder(header); break;
            case 2: deleteByPosition(header); break;
            case 3: searchByKey(header); break;
            case 4: deleteByKey(header); break;
            case 5: display(header); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}