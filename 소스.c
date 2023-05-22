#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data, int position, int* moves) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
        (*moves)++;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    (*moves)++;
}

void deleteNode(struct Node** head, int position, int* moves) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
        (*moves)++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    (*moves)++;
}

void displayList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void menu() {
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    int moves = 0;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("Exiting program.\n");
            return 0;
        case 1:
            printf("Enter the number to be inserted: ");
            scanf("%d", &data);
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            insert(&head, data, position, &moves);
            printf("Number of moves when inserting: %d\n", moves);
            break;
        case 2:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteNode(&head, position, &moves);
            printf("Number of moves when deleting: %d\n", moves);
            break;
        case 3:
            displayList(head);
            break;
        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    }

    return 0;
}