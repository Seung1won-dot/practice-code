#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void increment(int* num) {
    (*num)++;
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find_max(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void modify_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

int main() {
    int x = 10, y = 20;
    printf("교환 전: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("교환 후: x = %d, y = %d\n", x, y);
    
    int num = 5;
    printf("\n증가 전: %d\n", num);
    increment(&num);
    printf("증가 후: %d\n", num);
    
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("\n배열 출력:\n");
    print_array(arr, size);
    
    int max_val = find_max(arr, size);
    printf("최대값: %d\n", max_val);
    
    printf("\n배열 수정 (각 요소를 2배):\n");
    modify_array(arr, size);
    print_array(arr, size);
    
    return 0;
}

