#include <stdio.h>

void insertElement(int arr[], int *n, int pos, int x) {
    for (int i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    (*n)++;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;
    int x = 25;
    int pos = 3;

    insertElement(arr, &n, pos, x);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}