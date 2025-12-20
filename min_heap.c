#include <stdio.h>

int size = 0;
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Min-Heap düzenlemesi
void heapify(int array[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] < array[smallest]) // Tek fark buradaki < isareti
        smallest = l;
    if (r < size && array[r] < array[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&array[i], &array[smallest]);
        heapify(array, size, smallest);
    }
}

void insert(int array[], int newNum) {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
}

int main() {
    int array[10];
    insert(array, 10);
    insert(array, 20);
    insert(array, 5);
    insert(array, 8);

    printf("Min-Heap dizisi: ");
    for (int i = 0; i < size; ++i) printf("%d ", array[i]);
    return 0;
}