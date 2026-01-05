#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev;

    if (curr->data == key && curr->next == *head) {
        free(curr);
        *head = NULL;
        return;
    }

    if (curr->data == key) {
        while (curr->next != *head) curr = curr->next;
        curr->next = (*head)->next;
        free(*head);
        *head = curr->next;
        return;
    }

    curr = *head;
    while (curr->next != *head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    }
}

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    if (*head != NULL) {
        struct Node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = newNode;
    } else {
        newNode->next = newNode;
    }
    *head = newNode;
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

    insert(&head, 30);
    insert(&head, 20);
    insert(&head, 10);

    printf("Liste: ");
    printList(head);

    deleteNode(&head, 20);
    printf("20 silindikten sonra: ");
    printList(head);

    return 0;
}