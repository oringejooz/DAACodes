//In Insertion sort use names in place of integers and sort in descending alphabetical order
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(char **arr, int size) {
    for (int i = 1; i < size; i++) {
        char *key = arr[i];
        int j = i - 1;

        while (j >= 0 && strcmp(arr[j], key) < 0) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    char **ptr;
    int size;
    printf("Enter number of names in Array - ");
    scanf("%d", &size);

    ptr = (char **)malloc(size * sizeof(char *));

    if (ptr == NULL) {
        printf("Memory not allocated\n");
        exit(1);
    }

    for (int j = 0; j < size; j++) {
        char name[100];
        printf("Enter name %d - ", j + 1);
        scanf("%s", name);

        
        ptr[j] = (char *)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(ptr[j], name);
    }

    printf("The names in the array are\n ");
    for (int k = 0; k < size; k++) {
        printf("%s ", ptr[k]);
    }

    insertionSort(ptr, size);
    printf("\nSorted names in descending alphabetical order:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", ptr[i]);
    }

    
    for (int i = 0; i < size; i++) {
        free(ptr[i]);
    }
    free(ptr);

    return 0;
}
