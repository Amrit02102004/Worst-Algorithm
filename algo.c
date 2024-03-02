#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int checkArray(int arr[], int n) {

    for (int i = 1 ; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
    }
    return 1;
}

void shuffleArray(int arr[], int n) {
    srand(time(NULL));

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int worstSort(int arr[] ,  int n ){
    int count = 0;
    while(checkArray(arr,n) == 0){
        count++;
        shuffleArray(arr,n);
    }
    return count;
}

int main() {
    int arr[] = {4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);
    clock_t start_time = clock(); 

    int count = worstSort(arr, n);

    clock_t end_time = clock(); 

    printf("Sorted array: ");
    printArray(arr, n);
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    printf("Number of shuffles: %d\n", count);
    return 0;
}
