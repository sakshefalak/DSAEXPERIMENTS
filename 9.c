#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

// Function for in-order traversal of the BST
void inOrderTraversal(struct Node* node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%d ", node->value);
        inOrderTraversal(node->right);
    }
}

// Function to search for a value in the BST
struct Node* search(struct Node* node, int value) {
    if (node == NULL || node->value == value) {
        return node;
    }
    if (value < node->value) {
        return search(node->left, value);
    }
    return search(node->right, value);
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a value\n");
        printf("2. In-order Traversal\n");
        printf("3. Search for a value\n");
        printf("4. Exit\n");
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted into the BST.\n", value);
                break;
            case 2:
                printf("In-order Traversal of the BST:\n");
                inOrderTraversal(root);
                printf("\n");  // for newline
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                struct Node* result = search(root, value);
                if (result) {
                    printf("%d found in the BST.\n", value);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
