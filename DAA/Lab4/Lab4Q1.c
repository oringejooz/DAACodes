//Starting from F(1)=1,F(2)=2,find the nth fibonacci number F(n)=F(n-1)+F(n-2) in O(n) time and theta(1) space
#include <stdio.h>

int findFibonacci(int n) {
    if (n <= 2) {
        return n;
    }

    int prev1 = 1;
    int prev2 = 2;
    int current = 0;

    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }

    return current;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result = findFibonacci(n);

    printf("F(%d) = %d\n", n, result);

    return 0;
}
