#include <stdio.h>
#include <stdlib.h>

int findDuplicate(int arr[], int n) {
    int a1 = arr[0];
    int a2 = arr[0];

    // Phase 1: Detect if there is a cycle
    do {
        a1 = arr[a1];
        a2 = arr[arr[a2]];
    } while (a1 != a2);

    // Phase 2: Find the starting point of the cycle
    a1 = arr[0];
    while (a1 != a2) {
        a1 = arr[a1];
        a2 = arr[a2];
    }

    // At this point, a1 or a2 is the starting point of the cycle

    return a2; // The element that appears three times
}

int main() {
    int n, i;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Dynamic allocation of memory for an array of size (n + 3)
    int *arr = (int *)malloc((n + 3) * sizeof(int));

    printf("Enter the elements of the sequence: \n");
    for (i = 0; i < n + 3; i++)
        scanf("%d", &arr[i]);

    // Call the function to find the element that appears thrice
    int duplicate = findDuplicate(arr, n + 3);

    // Print the result
    printf("The element that appears thrice is: %d\n", duplicate);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
