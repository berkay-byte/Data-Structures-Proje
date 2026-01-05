#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

int main() {
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 0, 0, 0},
        {0, 5, 0, 0, 0},
        {0, 0, 0, 0, 6}
    };

    int size = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] != 0) {
                size++;
            }
        }
    }

    struct Element sparse[size];
    int k = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }

    printf("Row\tCol\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0;
}