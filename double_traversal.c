#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void traverseForward(struct Node* head) {
    struct Node* temp = head;
    printf("Ileri Yonlu: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverseBackward(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) return;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Geri Yonlu: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) (*head)->prev = newNode;
    *head = newNode;
}

int main() {
    struct Node* head = NULL;
    insert(&head, 30);
    insert(&head, 20);
    insert(&head, 10);

    traverseForward(head);
    traverseBackward(head);

    return 0;
}