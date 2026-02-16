#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, i;
    int *arr;             
    int comparisons = 0;
    int foundIndex = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++;       

        if (arr[i] == k) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
