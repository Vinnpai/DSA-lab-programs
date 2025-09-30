#include <stdio.h>
#include <stdlib.h>

// Display the array
void display(int *arr, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Insert value at given position
void insertByPosition(int **arr, int *size, int pos, int val) {
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }

    *arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = *size - 1; i >= pos; i--)
        (*arr)[i + 1] = (*arr)[i];

    (*arr)[pos] = val;
    (*size)++;

    printf("Inserted %d at position %d.\n", val, pos);
}

// Delete element by key
void deleteByKey(int **arr, int *size, int key) {
    int pos = -1;

    // Step 1: Find position of the key
    for (int i = 0; i < *size; i++) {
        if ((*arr)[i] == key) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Key %d not found in the array.\n", key);
        return;
    }

    // Step 2: Shift left
    for (int j = pos + 1; j < *size; j++) {
        (*arr)[j - 1] = (*arr)[j];
    }

    // Step 3: Resize
    (*size)--;
    *arr = (int *)realloc(*arr, (*size) * sizeof(int));
    printf("Deleted key %d from array.\n", key);
}

// Search by position
void searchByPosition(int *arr, int size, int pos) {
    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
    } else {
        printf("Element at position %d is %d\n", pos, arr[pos]);
    }
}

// Reverse the array
void reverse(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    printf("Array reversed.\n");
}

int main() {
    int *array = NULL;
    int size = 0;
    int choice, val, pos;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert by Position\n");
        printf("2. Delete by Key\n");
        printf("3. Search by Position\n");
        printf("4. Reverse Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &pos);
                insertByPosition(&array, &size, pos, val);
                display(array, size);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &val);
                deleteByKey(&array, &size, val);
                display(array, size);
                break;

            case 3:
                printf("Enter position to search (0 to %d): ", size - 1);
                scanf("%d", &pos);
                searchByPosition(array, size, pos);
                break;

            case 4:
                reverse(array, size);
                display(array, size);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    free(array);
    return 0;
}