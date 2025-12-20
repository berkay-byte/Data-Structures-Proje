#include <stdio.h>

#define MAX_NODES 15 // 4 derinlikli tam bir ağaç için (2^4 - 1)
char tree[MAX_NODES];

// Ağacı boş karakterlerle başlatma
void init_tree() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i] = '\0';
    }
}

// Kök düğümü ekleme
void set_root(char key) {
    tree[0] = key;
}

// Belirtilen ebeveynin soluna eleman ekleme
void set_left(char key, int parent) {
    if (tree[parent] == '\0') {
        printf("\nHata: %d indisinde ebeveyn yok!", parent);
    } else {
        tree[(2 * parent) + 1] = key;
    }
}

// Belirtilen ebeveynin sağına eleman ekleme
void set_right(char key, int parent) {
    if (tree[parent] == '\0') {
        printf("\nHata: %d indisinde ebeveyn yok!", parent);
    } else {
        tree[(2 * parent) + 2] = key;
    }
}

void print_tree() {
    for (int i = 0; i < MAX_NODES; i++) {
        if (tree[i] != '\0')
            printf("%c ", tree[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int main() {
    init_tree();
    set_root('A');
    set_left('B', 0);   // A'nın soluna B
    set_right('C', 0);  // A'nın sağına C
    set_left('D', 1);   // B'nin soluna D
    set_right('E', 1);  // B'nin sağına E

    printf("Agac yapisi (Dizi hali): ");
    print_tree();

    return 0;
}