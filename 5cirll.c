#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Create a new node with data input from user
struct node* createnode() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode;
    newnode->prev = newnode;
    return newnode;
}

// Insert node in sorted order
void insertByOrder(struct node *header) {
    struct node *newnode = createnode();  // <-- removed 'header' parameter
    struct node *temp = header->next;

    // Traverse to find position
    while (temp != header && temp->data < newnode->data) {
        temp = temp->next;
    }

    // Insert before temp
   
    newnode->prev = temp->prev;
    newnode->next = temp;
    temp->prev->next = newnode;
    temp->prev = newnode;
}

// Delete node by position
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

// Delete node by key
void deleteByKey(struct node *header) {
    int key;
    printf("Enter key to delete: ");
    scanf("%d", &key);

    struct node *temp = header->next;

    // Step 1: Traverse the list to find the node with the key
    while (temp != header) {           // while not back at the header
        if (temp->data == key) {       // key found
            // Step 2: Delete the node
            temp->prev->next = temp->next; // bypass temp from previous node
            temp->next->prev = temp->prev; // bypass temp from next node
            free(temp);                   // free memory
            printf("Node with key %d deleted.\n", key);
            return;                       // exit function after deletion
        }
        temp = temp->next;             // move to next node
    }

    // Step 3: Key not found
    printf("Key not found!\n");
}

// Search by position
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

// Display the list
void display(struct node *header) {
    struct node *temp = header->next;
    if (temp == header) {
        printf("List is empty.\n");
        return;
    }
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
        printf("2. Delete by Position\n");
        printf("3. Delete by Key\n");
        printf("4. Search by Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertByOrder(header); break;
            case 2: deleteByPosition(header); break;
            case 3: deleteByKey(header); break;
            case 4: searchByPosition(header); break;
            case 5: display(header); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}