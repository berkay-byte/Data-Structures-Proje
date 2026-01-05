#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtPosition(struct Node** head, int data, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 1) {
        if (*head == NULL) {
            *head = newNode;
            newNode->next = *head;
        } else {
            struct Node* temp = *head;
            while (temp->next != *head) temp = temp->next;
            newNode->next = *head;
            temp->next = newNode;
            *head = newNode;
        }
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtPosition(&head, 10, 1);
    insertAtPosition(&head, 30, 2);
    insertAtPosition(&head, 20, 2);

    printf("Liste: ");
    printList(head);

    return 0;
}