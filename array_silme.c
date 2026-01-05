#include <stdio.h>

void deleteElement(int arr[], int *n, int pos) {
    if (pos > *n || pos <= 0) return;

    for (int i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 2;

    deleteElement(arr, &n, pos);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}