// lab-4 Q2. Find the value of  (1+i) n where i = sqrt (-1) in O(log2n) time and O(log2n) space.
// Input: n
// Output: (1+i) n




#include <stdio.h>

// Function to multiply two complex numbers
void multiply(int a[2], int b[2], int result[2]) {
    result[0] = a[0] * b[0] - a[1] * b[1];
    result[1] = a[0] * b[1] + a[1] * b[0];
}

// Function to raise (1+i) to the power n
void power(int n, int result[2]) {
    int base[2] = {1, 1};  // (1+i)
    result[0] = 1;
    result[1] = 0;

    while (n > 0) {
        if (n % 2 == 1) {
            multiply(result, base, result);
        }
        multiply(base, base, base);
        n /= 2;
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result[2];
    power(n, result);

    printf("(1+i)^%d = %d + %di\n", n, result[0], result[1]);

    return 0;
}