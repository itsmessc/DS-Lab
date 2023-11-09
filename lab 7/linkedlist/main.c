
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertBefore(struct Node **head, int element, int beforeElement) {
    struct Node *newNode = createNode(element);
    if (*head == NULL) {
        printf("List is empty. Cannot insert before.\n");
        return;
    }

    if ((*head)->data == beforeElement) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL && current->next->data != beforeElement) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element not found in the list.\n");
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}
void insertAfter(struct Node *head, int element, int afterElement) {
    struct Node *newNode = createNode(element);
    struct Node *current = head;

    while (current != NULL && current->data != afterElement) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found in the list.\n");
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}
void deleteElement(struct Node **head, int element) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == element) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found in the list.\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}
void traverse(struct Node *head) {
    struct Node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    *head = prev;
}
void deleteAlternate(struct Node *head) {
    struct Node *current = head;
    while (current != NULL && current->next != NULL) {
        struct Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
}
void insertInSorted(struct Node **head, int element) {
    struct Node *newNode = createNode(element);
    struct Node *current = *head;

    if (*head == NULL || element < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (current->next != NULL && current->next->data < element) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void freeList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;
    int choice, element, beforeElement, afterElement;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an element before another element\n");
        printf("2. Insert an element after another element\n");
        printf("3. Delete a given element from the list\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node in the list\n");
        printf("8. Insert an element in a sorted list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the element before which to insert: ");
                scanf("%d", &beforeElement);
                insertBefore(&head, element, beforeElement);
                break;

            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the element after which to insert: ");
                scanf("%d", &afterElement);
                insertAfter(head, element, afterElement);
                break;

            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteElement(&head, element);
                break;

            case 4:
                traverse(head);
                break;

            case 5:
                reverse(&head);
                break;

            case 6:
                printf("Sorting the list...\n");
                // Add your sorting algorithm here
                break;

            case 7:
                deleteAlternate(head);
                break;

            case 8:
                printf("Enter the element to insert in sorted order: ");
                scanf("%d", &element);
                insertInSorted(&head, element);
                break;

            case 0:
                freeList(head);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
