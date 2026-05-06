#include <stdio.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2, temp;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        temp = a[i]; a[i] = a[largest]; a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    int temp;
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        temp = a[0]; a[0] = a[i]; a[i] = temp;
        heapify(a, i, 0);
    }
}

int main() {
    int n, a[1000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    clock_t start = clock();

    heapSort(a, n);

    clock_t end = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}