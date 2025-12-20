#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// AST Düğüm Yapısı
struct Node {
    char data;
    struct Node *left, *right;
};

// Yeni bir düğüm oluşturma fonksiyonu
struct Node* newNode(char v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = v;
    return temp;
}

// Postfix ifadeden AST oluşturan fonksiyon
struct Node* constructTree(char postfix[]) {
    struct Node* stack[100];
    int top = -1;
    struct Node *t, *t1, *t2;

    for (int i = 0; i < strlen(postfix); i++) {
        // Eğer karakter bir operand (sayı/harf) ise düğüm oluşturup stack'e at
        if (!ispunct(postfix[i])) {
            t = newNode(postfix[i]);
            stack[++top] = t;
        } 
        // Eğer karakter bir operatör ise
        else {
            t = newNode(postfix[i]);

            // Stack'ten iki eleman çıkar ve operatörün çocukları yap
            t1 = stack[top--];
            t2 = stack[top--];

            t->right = t1;
            t->left = t2;

            // Yeni alt ağacı tekrar stack'e ekle
            stack[++top] = t;
        }
    }
    return stack[top--];
}

// Ağacı kontrol etmek için Inorder (İç-sıralı) yazdırma
void inorder(struct Node* t) {
    if (t) {
        if(t->left) printf("(");
        inorder(t->left);
        printf("%c", t->data);
        inorder(t->right);
        if(t->right) printf(")");
    }
}

int main() {
    char postfix[] = "ab+c*"; // (a+b)*c ifadesinin postfix hali
    printf("Postfix Girdisi: %s\n", postfix);
    
    struct Node* root = constructTree(postfix);
    
    printf("AST üzerinden olusan Infix ifade: ");
    inorder(root);
    printf("\n");

    return 0;
}