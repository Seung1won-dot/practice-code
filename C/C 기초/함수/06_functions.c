#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

void greet(char name[]) {
    printf("안녕하세요, %s님!\n", name);
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sum_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int result = add(3, 5);
    printf("3 + 5 = %d\n", result);
    
    greet("홍길동");
    
    int fact = factorial(5);
    printf("5! = %d\n", fact);
    
    int larger = max(10, 20);
    printf("max(10, 20) = %d\n", larger);
    
    int x = 10, y = 20;
    printf("교환 전: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("교환 후: x = %d, y = %d\n", x, y);
    
    int numbers[] = {1, 2, 3, 4, 5};
    int total = sum_array(numbers, 5);
    printf("배열의 합: %d\n", total);
    
    return 0;
}

