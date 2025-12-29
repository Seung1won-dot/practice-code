#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;
    
    printf("포인터 배열:\n");
    int* ptr_array[5];
    for (int i = 0; i < 5; i++) {
        ptr_array[i] = &arr[i];
        printf("ptr_array[%d] = %d\n", i, *ptr_array[i]);
    }
    
    printf("\n함수 포인터:\n");
    int add(int a, int b) { return a + b; }
    int multiply(int a, int b) { return a * b; }
    
    int (*func_ptr)(int, int);
    func_ptr = add;
    printf("add(5, 3) = %d\n", func_ptr(5, 3));
    
    func_ptr = multiply;
    printf("multiply(5, 3) = %d\n", func_ptr(5, 3));
    
    printf("\nvoid 포인터:\n");
    int num = 100;
    float fnum = 3.14f;
    void* vptr;
    
    vptr = &num;
    printf("정수: %d\n", *(int*)vptr);
    
    vptr = &fnum;
    printf("실수: %.2f\n", *(float*)vptr);
    
    printf("\n포인터와 const:\n");
    int value = 42;
    const int* ptr1 = &value;
    int* const ptr2 = &value;
    const int* const ptr3 = &value;
    
    printf("const int*: 값 변경 불가, 주소 변경 가능\n");
    printf("int* const: 값 변경 가능, 주소 변경 불가\n");
    printf("const int* const: 값과 주소 모두 변경 불가\n");
    
    return 0;
}

