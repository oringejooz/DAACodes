#include <stdio.h>
#include <stdlib.h>
int **Matrix(int n){
    int **matrix=(int**)malloc(n * sizeof(int*));
    int num;
    for(int i=0;i<n;i++){
        matrix[i]=(int*)malloc(n * sizeof(int));
        for(int j=0;j<n;j++){
            printf("Enter Element number %d %d - ",i+1,j+1);
            scanf("%d",&num);
            matrix[i][j]=num;
        }
    }
    return matrix;
}

void displayMatrix(int **matrix,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int **matrixMultiplication(int **mat1,int **mat2,int n){
    int **mult=(int **)malloc(n * sizeof(int*));
    for(int i=0;i<n;i++){
        mult[i]=(int *)malloc(n * sizeof(int));
        for(int j=0;j<n;j++){
            mult[i][j]=0;
            for(int k=0;k<n;k++){
                mult[i][j]+=mat1[i][k]+mat2[k][j];
            }
        }
    }
    return mult;
}

int main(){
    int a,b;
    a=2;
    b=2;
    printf("\nEntering Matrix 1 \n");
    int **m1=Matrix(a);
    printf("\nEntering Matrix 2 \n");
    int **m2=Matrix(b);
    displayMatrix(m1,a);
    printf("\n");
    displayMatrix(m2,b);
    
    int **result = matrixMultiplication(m1,m2,a);
    printf("Resultant Matrix after Multiplication \n");
    displayMatrix(result,a);
    return 0;
}