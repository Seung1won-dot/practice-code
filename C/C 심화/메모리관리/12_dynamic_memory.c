#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = (int*)malloc(5 * sizeof(int));
    
    if (ptr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    
    for (int i = 0; i < 5; i++) {
        ptr[i] = (i + 1) * 10;
    }
    
    printf("동적 할당된 배열:\n");
    for (int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    free(ptr);
    ptr = NULL;
    
    int* ptr2 = (int*)calloc(5, sizeof(int));
    printf("\ncalloc으로 할당 (0으로 초기화):\n");
    for (int i = 0; i < 5; i++) {
        printf("ptr2[%d] = %d\n", i, ptr2[i]);
    }
    
    ptr2 = (int*)realloc(ptr2, 10 * sizeof(int));
    printf("\nrealloc으로 크기 확장:\n");
    for (int i = 5; i < 10; i++) {
        ptr2[i] = (i + 1) * 10;
    }
    
    for (int i = 0; i < 10; i++) {
        printf("ptr2[%d] = %d\n", i, ptr2[i]);
    }
    
    free(ptr2);
    
    char* str = (char*)malloc(20 * sizeof(char));
    if (str != NULL) {
        sprintf(str, "Hello, World!");
        printf("\n동적 할당된 문자열: %s\n", str);
        free(str);
    }
    
    return 0;
}

