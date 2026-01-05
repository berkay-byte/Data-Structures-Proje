#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void insert(int arr[], int *n, int value) {
    arr[*n] = value;
    *n = *n + 1;

    for (int i = (*n / 2) - 1; i >= 0; i--) {
        heapify(arr, *n, i);
    }
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100];
    int n = 0;

    insert(arr, &n, 10);
    insert(arr, &n, 20);
    insert(arr, &n, 15);
    insert(arr, &n, 30);
    insert(arr, &n, 40);

    printf("Max Heap: ");
    printHeap(arr, n);

    return 0;
}