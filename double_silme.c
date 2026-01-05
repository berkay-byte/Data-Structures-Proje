#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteNode(struct Node** head, struct Node* del) {
    if (*head == NULL || del == NULL) return;

    if (*head == del) *head = del->next;

    if (del->next != NULL) del->next->prev = del->prev;

    if (del->prev != NULL) del->prev->next = del->next;

    free(del);
}

void deleteAtPosition(struct Node** head, int n) {
    if (*head == NULL || n <= 0) return;

    struct Node* current = *head;
    for (int i = 1; current != NULL && i < n; i++) {
        current = current->next;
    }

    if (current == NULL) return;

    deleteNode(head, current);
}

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;
    if ((*head) != NULL) (*head)->prev = newNode;
    (*head) = newNode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insert(&head, 40);
    insert(&head, 30);
    insert(&head, 20);
    insert(&head, 10);

    printf("Liste: ");
    printList(head);

    deleteAtPosition(&head, 2);
    printf("2. eleman silindikten sonra: ");
    printList(head);

    return 0;
}