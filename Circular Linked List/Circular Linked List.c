#include <stdio.h>
#include <stdlib.h>

// Defining structure for circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Insert at beginning
struct Node* insert_begin(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (!newNode) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    last->next = newNode;
    newNode->next = head;
    return newNode;
}

// Insert at end
struct Node* insert_end(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (!newNode) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    last->next = newNode;
    newNode->next = head;
    return head;
}

// Insert at given position
struct Node* insert_pos(struct Node* head, int value, int pos) {
    if (pos == 1) {
        return insert_begin(head, value);
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;

    struct Node* temp = head;
    int i;

    for (i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && i < pos - 1) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete at beginning
struct Node* delete_begin(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    struct Node* temp = head;
    head = head->next;
    last->next = head;
    free(temp);

    return head;
}

// Delete at end
struct Node* delete_end(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* last = head;
    struct Node* prev = NULL;

    while (last->next != head) {
        prev = last;
        last = last->next;
    }

    prev->next = head;
    free(last);
    return head;
}

// Delete at given position
struct Node* delete_pos(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (pos == 1) {
        return delete_begin(head);
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    int i;

    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head && i < pos) {
        printf("Position out of range!\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// Reverse circular linked list
struct Node* reverse_list(struct Node* head) {
    if (head == NULL || head->next == head) {
        return head;
    }

    struct Node* prev = head;
    struct Node* current = head->next;
    struct Node* next_node;

    while (current != head) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    head->next = prev;
    head = prev;
    return head;
}

// Concatenate two lists
struct Node* concat_list(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* tail1 = head1;
    while (tail1->next != head1) {
        tail1 = tail1->next;
    }

    struct Node* tail2 = head2;
    while (tail2->next != head2) {
        tail2 = tail2->next;
    }

    tail1->next = head2;
    tail2->next = head1;
    return head1;
}

// Print circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Main function (menu driven)
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
        printf("1. Insert node\n2. Delete node\n3. Reverse\n4. Concatenate\n");
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

                head = concat_list(head, head1);
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

