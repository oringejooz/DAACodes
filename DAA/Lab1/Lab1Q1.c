#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr,int size)
{
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


int main(){
    int *ptr;
    int size;
    printf("Enter number of elements in Array -");
    scanf("%d",&size);

    ptr=(int*)malloc(size * sizeof(int));

    if(ptr==NULL){
        printf("Memory not allocated\n");
        exit(1);
    }
    
    for (int j = 0; j < size; j++) {
            int n;
            printf("Enter element number %d - ",j+1);
            scanf("%d",&n);
            ptr[j] = n;
    }
    
    printf("The elements of the array are\n ");
        for (int k = 0; k < size; k++) {
            printf("%d ", ptr[k]);
        }
    
    insertionSort(ptr,size);
    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }

    free(ptr);

    return 0;
    
}