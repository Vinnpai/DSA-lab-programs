#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node * createnode(struct node *header)
{
  printf("Enter data: ");

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);
    newnode->next =header;
    newnode->prev =header;

    return newnode;
}

void insertAtBeginning(struct node *header) 
{
    struct node *newnode,*first,*last;
    newnode = createnode(header);
    first = header->next;
    last = header->prev;
   
    newnode->next = first;
    first->prev = newnode;

    newnode->prev=header;
    header->next = newnode;
    
}


void insertAtEnd(struct node *header)
{
    struct node *newnode,*first,*last;
    newnode = createnode(header);
    first = header->next;
    last = header->prev;
   
    newnode->next = header;
    header->prev = newnode;

    newnode->prev=last;
    last->next = newnode;

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
    // Creating header node
    struct node *header = (struct node *)malloc(sizeof(struct node));
    header->data = 0; // dummy value
    header->next = header;
    header->prev = header;

    int choice;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insertAtBeginning(header);
                break;
            case 2:
                insertAtEnd(header);
                break;
            case 3:
                display(header);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
