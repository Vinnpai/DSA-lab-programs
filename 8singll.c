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

// Insert by position
void insertByPosition(struct node* header) {
    int pos, i = 1;
    printf("Enter position to insert: ");
    scanf("%d", &pos);

    struct node* newnode = createnode();
    struct node* prev = header;         // previous node
    struct node* temp = header->next;   // start at first real node

    while (i < pos && temp != header) {
        prev = temp;
        temp = temp->next;
        i++;
    }

   // After the while loop
if (i != pos) {
    printf("Invalid position!\n");
    free(newnode);
    return;
}

    newnode->next = temp;
    prev->next = newnode;

    printf("Inserted %d at position %d\n", newnode->data, pos);
}

// Delete rear
void deleteRear(struct node* header) {
    if (header->next == header) {
        printf("List empty!\n");
        return;
    }

    struct node* prev = header;
    struct node* temp = header->next;

    // Traverse to the last node
    while (temp->next != header) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = header;
    printf("Deleted %d from rear.\n", temp->data);
    free(temp);
}

// Delete front
void deleteFront(struct node* header) {
    if (header->next == header) {
        printf("List empty!\n");
        return;
    }

    struct node* temp = header->next;
    header->next = temp->next;
    printf("Deleted %d from front.\n", temp->data);
    free(temp);
}

// Search by value
void searchByValue(struct node* header) {
    if (header->next == header) {
        printf("List empty!\n");
        return;
    }

    int value, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &value);

    struct node* temp = header->next;
    while (temp != header) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Value %d not found!\n", value);
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
        printf("1. Insert by Position\n2. Delete Rear\n3. Delete Front\n4. Search by Value\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertByPosition(header); break;
            case 2: deleteRear(header); break;
            case 3: deleteFront(header); break;
            case 4: searchByValue(header); break;
            case 5: display(header); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}