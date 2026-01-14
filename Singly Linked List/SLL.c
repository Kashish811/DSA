#include <stdio.h>
#include <stdlib.h>

// Defining structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Insert at beginning
struct Node* insert_begin(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;   // new node becomes new head
}

// Insert at given position
struct Node* insert_pos(struct Node* head, int value, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    int i;
    struct Node* temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Insert at end
struct Node* insert_end(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Delete at beginning
struct Node* delete_begin(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete!\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning.\n");
    return head;
}

// Delete at specific position
struct Node* delete_pos(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty, nothing to delete!\n");
        return NULL;
    }

    struct Node* temp = head;

    if (pos == 1) {
        head = head->next;
        free(temp);
        printf("Node deleted from position 1.\n");
        return head;
    }

    struct Node* prev = NULL;
    int i;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", pos);

    return head;
}

// Delete at end
struct Node* delete_end(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete!\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        printf("Last node deleted, list is now empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Node deleted from end.\n");
    return head;
}

// Reverse list
struct Node* reverse_list(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;   // new head
}

// Concatenating two lists
struct Node* concat_lists(struct Node* head, struct Node* head1) {
    if (head == NULL)
        return head1;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head1;
    return head;
}

// Printing Linked List
void printList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
        head = insert_end(head, data);
    }

    printf("Original list:\n");
    printList(head);

    do {
        printf("\nWhich function would you like to perform?\n");
        printf("1. Insert node\n2. Delete node\n3. Reverse List\n4. Concatenate Lists\n");
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
                            head = insert_begin(head, data);
                            break;

                        case 2:
                            printf("Enter value: ");
                            scanf("%d", &data);
                            printf("Enter position: ");
                            scanf("%d", &pos);
                            head = insert_pos(head, data, pos);
                            break;

                        case 3:
                            printf("Enter value: ");
                            scanf("%d", &data);
                            head = insert_end(head, data);
                            break;
                    }

                    printList(head);
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
                            head = delete_begin(head);
                            break;

                        case 2:
                            printf("Enter position: ");
                            scanf("%d", &pos);
                            head = delete_pos(head, pos);
                            break;

                        case 3:
                            head = delete_end(head);
                            break;
                    }

                    printList(head);
                    printf("Continue deleting? (y/n): ");
                    scanf(" %c", &ch);

                } while (ch == 'Y' || ch == 'y');
                break;

            case 3:
                head = reverse_list(head);
                printf("Reversed list:\n");
                printList(head);
                break;

            case 4:
                printf("\nCreating another list for concatenation.\n");
                printf("How many nodes in 2nd list: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter value for node %d: ", i + 1);
                    scanf("%d", &data);
                    head1 = insert_end(head1, data);
                }

                printf("Second list:\n");
                printList(head1);

                head = concat_lists(head, head1);
                printf("After concatenation:\n");
                printList(head);
                break;
        }

        printf("\nPerform another function? (y/n): ");
        scanf(" %c", &ch1);

    } while (ch1 == 'Y' || ch1 == 'y');

    printf("Program Exits\n");
    return 0;
}

