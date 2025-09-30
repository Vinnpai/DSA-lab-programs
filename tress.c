#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

/* Create new node */
struct node* createnode(int key) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

/* Insert into BST */
struct node* insert(struct node *root, int key) {
    if (root == NULL) 
        return createnode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

/* Traversals */
void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(struct node *root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}
/* BFS (Level Order Traversal) */
void bfs(struct node* root) {
    if (root == NULL)
     return;

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct node* cur = queue[front++];
        printf("%d ", cur->key);

        if (cur->left) 
        queue[rear++] = cur->left;
        if (cur->right)
         queue[rear++] = cur->right;
    }
}


/* Count all nodes */
int countnodes(struct node *root) {
    if (root == NULL) return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
}

/* Height of tree (edges) */
int height(struct node *root) {
    if (root == NULL) return -1;  
    int hl = height(root->left);
    int hr = height(root->right);
    return (hl > hr ? hl : hr) + 1;
}

/* Recursive Search with Parent (like notebook) */
void search(struct node *root, int key, struct node *parent) {
    if (root == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (key < root->key) {
        search(root->left, key, root);
    }
    else if (key > root->key) {
        search(root->right, key, root);
    }
    else { // found
        if (parent)
            printf("Parent key = %d , Node = %d\n", parent->key, root->key);
        else
            printf("Parent = None , Node = %d\n", root->key);
    }
}

/* Recursive Find Maximum Node with Parent (like notebook) */
void findmax(struct node *root, struct node *parent) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    if (root->right != NULL) {
        findmax(root->right, root);
    }
    else {
        if (parent)
            printf("Parent key = %d , Maxnode = %d\n", parent->key, root->key);
        else
            printf("Parent = None (Root) , Maxnode = %d\n", root->key);
    }
}

/* Find minimum (helper for deletion) */
struct node* findmin(struct node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

/* Delete a node */
struct node* delete(struct node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->key) {
        root->left = delete(root->left, key);
    } 
    else if (key > root->key) {
        root->right = delete(root->right, key);
    } 
    else {  // Node found
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Two children
        struct node* succ = findmin(root->right);
        root->key = succ->key;
        root->right = delete(root->right, succ->key);
    }
    return root;
}

/* ---------------- MAIN MENU ---------------- */
int main() {
    struct node *root = NULL;
    int choice, key, n, i;

while(1){
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert (Construction)\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search a key and show info with parent\n");
        printf("6. Count all nodes\n");
        printf("7. Height of tree\n");
        printf("8. Find MAX node with parent\n");
        printf("9. Search and DELETE a key\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
       
        switch(choice) {
            case 1:
    
                    printf("Enter key :");
                    scanf("%d", &key);
                    root = insert(root, key);
                break;

            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(root, key, NULL);
                break;

            case 6:
                printf("Total nodes = %d\n", countnodes(root));
                break;

            case 7:
                printf("Height = %d\n", height(root));
                break;

            case 8:
                findmax(root, NULL);
                break;

            case 9:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = delete(root, key);
                printf("Key deleted if existed.\n");
                break;

            case 0:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}