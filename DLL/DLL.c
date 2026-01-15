#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

// Insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Insert at specific position
struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    if (pos <= 0) {
        printf("Invalid position!\n");
        return head;
    }

    if (pos == 1)
        return insertAtBeginning(head, data);

    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int i;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Delete from beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    return head;
}

// Delete from end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return deleteFromBeginning(head);
    }

    struct Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);

    return head;
}

// Delete from specific position
struct Node* deleteFromPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty, nothing to delete!\n");
        return head;
    }

    if (pos == 1) {
        return deleteFromBeginning(head);
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    int i;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    if (temp->next == NULL) {
        return deleteFromEnd(head);
    }

    prev->next = temp->next;
    temp->next->prev = prev;

    free(temp);
    printf("Deleted node from position %d.\n", pos);

    return head;
}

// Reverse list
struct Node* reverse_list(struct Node* head) {
    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

// Concatenate two lists
struct Node* concat_list(struct Node* head, struct Node* head1) {
    if (head == NULL) {
        return head1;
    }

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head1;
    head1->prev = temp;

    return head;
}

int main() {
    struct Node* head = NULL;
    struct Node* head1 = NULL;

    char ch, ch1;
    int n, i, data, op, op1, pos;

    printf("How many nodes do you want to create: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("Original list:\n");
    displayList(head);

    do {
        printf("\nWhich function would you like to perform?\n");
        printf("1. Insert node\n2. Delete node\n3. Reversal\n4. Concatenate\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                do {
                    printf("\nWhere to insert?\n");
                    printf("1. Beginning\n2. At position\n3. End\n");
                    printf("Enter choice (1-3): ");
                    scanf("%d", &op1);

                    switch (op1) {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &data);
                            head = insertAtBeginning(head, data);
                            break;

                        case 2:
                            printf("Enter value: ");
                            scanf("%d", &data);
                            printf("Enter position: ");
                            scanf("%d", &pos);
                            head = insertAtPosition(head, data, pos);
                            break;

                        case 3:
                            printf("Enter value: ");
                            scanf("%d", &data);
                            head = insertAtEnd(head, data);
                            break;
                    }

                    displayList(head);
                    printf("Continue inserting? (y/n): ");
                    scanf(" %c", &ch);

                } while (ch == 'Y' || ch == 'y');
                break;

            case 2:
                do {
                    printf("\nWhere to delete?\n");
                    printf("1. Beginning\n2. At position\n3. End\n");
                    printf("Enter choice (1-3): ");
                    scanf("%d", &op1);

                    switch (op1) {
                        case 1:
                            head = deleteFromBeginning(head);
                            break;

                        case 2:
                            printf("Enter position: ");
                            scanf("%d", &pos);
                            head = deleteFromPosition(head, pos);
                            break;

                        case 3:
                            head = deleteFromEnd(head);
                            break;
                    }

                    displayList(head);
                    printf("Continue deleting? (y/n): ");
                    scanf(" %c", &ch);

                } while (ch == 'Y' || ch == 'y');
                break;

            case 3:
                head = reverse_list(head);
                printf("Reversed list:\n");
                displayList(head);
                break;

            case 4:
                printf("\nCreating another list for concatenation.\n");
                printf("How many nodes in 2nd list: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter value for node %d: ", i + 1);
                    scanf("%d", &data);
                    head1 = insertAtEnd(head1, data);
                }

                printf("Second list:\n");
                displayList(head1);

                head = concat_list(head, head1);
                printf("After concatenation:\n");
                displayList(head);
                break;
        }

        printf("\nPerform another function? (y/n): ");
        scanf(" %c", &ch1);

    } while (ch1 == 'Y' || ch1 == 'y');

    printf("Program Exits\n");
    return 0;
}

