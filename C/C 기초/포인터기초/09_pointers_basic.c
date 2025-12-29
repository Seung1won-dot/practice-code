#include <stdio.h>

int main() {
    int num = 10;
    int* ptr = &num;
    
    printf("num의 값: %d\n", num);
    printf("num의 주소: %p\n", &num);
    printf("ptr이 가리키는 값: %d\n", *ptr);
    printf("ptr의 값 (주소): %p\n", ptr);
    
    *ptr = 20;
    printf("\n포인터를 통해 값 변경 후:\n");
    printf("num의 값: %d\n", num);
    
    int arr[] = {10, 20, 30, 40, 50};
    int* arr_ptr = arr;
    
    printf("\n배열과 포인터:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d (주소: %p)\n", i, *(arr_ptr + i), arr_ptr + i);
    }
    
    printf("\n포인터 산술 연산:\n");
    int* p = arr;
    printf("*p = %d\n", *p);
    p++;
    printf("*p = %d (다음 요소)\n", *p);
    p += 2;
    printf("*p = %d (2칸 이동)\n", *p);
    
    int a = 5, b = 10;
    int* ptr1 = &a;
    int* ptr2 = &b;
    
    printf("\n포인터 비교:\n");
    printf("ptr1이 가리키는 값: %d\n", *ptr1);
    printf("ptr2가 가리키는 값: %d\n", *ptr2);
    
    if (ptr1 < ptr2) {
        printf("ptr1이 ptr2보다 앞에 있습니다.\n");
    }
    
    int value = 100;
    int* ptr3 = &value;
    int** ptr_to_ptr = &ptr3;
    
    printf("\n이중 포인터:\n");
    printf("value = %d\n", value);
    printf("*ptr3 = %d\n", *ptr3);
    printf("**ptr_to_ptr = %d\n", **ptr_to_ptr);
    
    return 0;
}

