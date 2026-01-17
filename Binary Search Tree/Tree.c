#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node with the given value
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a value into the binary search tree (BST)
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        printf(
            "Value %d is less than %d, inserting in the left subtree.\n",
            data, root->data
        );
        root->left = insert(root->left, data);
    } 
    else if (data > root->data) {
        printf(
            "Value %d is greater than %d, inserting in the right subtree.\n",
            data, root->data
        );
        root->right = insert(root->right, data);
    } 
    else {
        printf(
            "Value %d already exists in the BST. No duplicates allowed.\n",
            data
        );
    }

    return root;
}

// Inorder traversal: Left, Root, Right
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal: Root, Left, Right
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal: Left, Right, Root
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search for a key in the BST
struct node* Search(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == key) {
        return root;
    }

    if (key < root->data) {
        return Search(root->left, key);
    } 
    else {
        return Search(root->right, key);
    }
}

int main() {
    struct node* root = NULL;
    struct node* result = NULL;
    int choice, value, key, a;
    char ans;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert a new node\n");
        printf("2. Traversal of tree\n");
        printf("3. Search for an element\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("\nTraversal Options:\n");
                printf("1. Inorder Traversal\n");
                printf("2. Preorder Traversal\n");
                printf("3. Postorder Traversal\n");
                printf("Enter your choice: ");
                scanf("%d", &a);

                switch (a) {
                    case 1:
                        inorder(root);
                        printf("\n");
                        break;

                    case 2:
                        preorder(root);
                        printf("\n");
                        break;

                    case 3:
                        postorder(root);
                        printf("\n");
                        break;

                    default:
                        printf("Invalid traversal choice.\n");
                }
                break;

            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                result = Search(root, key);

                if (result != NULL)
                    printf("Element %d found in BST.\n", key);
                else
                    printf("Element %d not found in BST.\n", key);
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ans);

    } while (ans == 'y' || ans == 'Y');

    return 0;
}

