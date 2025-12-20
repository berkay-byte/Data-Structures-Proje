#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısı
struct Node {
    int data;
    struct Node* next;
};

// Listenin başına eleman ekleme (Test için)
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Bağlı listeden bir anahtar (key) değerini silen fonksiyon
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    // 1. Durum: Silinecek eleman listenin başındaysa
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Başı bir sonrakine kaydır
        free(temp);             // Eski başı serbest bırak
        return;
    }

    // 2. Durum: Silinecek elemanı ararken önceki düğümü takip et
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Eğer değer listede yoksa
    if (temp == NULL) return;

    // Düğümü listeden kopar ve belleği boşalt
    prev->next = temp->next;
    free(temp);
}

// Listeyi ekrana yazdıran fonksiyon
void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    printf("Silme oncesi liste: ");
    printList(head);

    deleteNode(&head, 3); // 3 değerini sil

    printf("3 silindikten sonra liste: ");
    printList(head);

    return 0;
}