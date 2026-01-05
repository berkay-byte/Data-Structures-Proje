#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }

    struct Node* temp = head;
    printf("Liste Elemanlari: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    if (*head != NULL) {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        newNode->next = newNode;
    }
    *head = newNode;
}

int main() {
    struct Node* head = NULL;

    insert(&head, 30);
    insert(&head, 20);
    insert(&head, 10);

    traverse(head);

    return 0;
}