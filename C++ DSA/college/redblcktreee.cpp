#include <stdio.h>
#include <stdlib.h>

// Red-Black Tree Node Structure
typedef enum { RED, BLACK } Color;
typedef struct Node {
    int data;
    Color color;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;

// Function to create a new Red-Black Tree Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED;  // By default, new node is always red
    newNode->parent = newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform left rotation
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Function to perform right rotation
void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

// Function to fix violations after insertion
void fixInsertion(Node** root, Node* z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

// Function to insert a node into the Red-Black Tree
void insert(Node** root, int data) {
    Node* z = createNode(data);
    Node* y = NULL;
    Node* x = *root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsertion(root, z);
}

// Function to print the Red-Black Tree in-order
void inOrder(Node* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("(%d, %s) ", root->data, (root->color == RED) ? "RED" : "BLACK");
    inOrder(root->right);
}

// Function to display the menu
void displayMenu() {
    printf("\nRed-Black Tree Menu\n");
    printf("1. Insert an element\n");
    printf("2. Print the tree structure\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, data;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                printf("Element %d inserted.\n", data);
                break;
            case 2:
                printf("Tree structure (in-order): ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}