#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    printf("배열 요소:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    int arr2[] = {10, 20, 30};
    int size = sizeof(arr2) / sizeof(arr2[0]);
    printf("\n배열 크기: %d\n", size);
    
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("\n2차원 배열:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int arr3[5];
    printf("\n배열 초기화:\n");
    for (int i = 0; i < 5; i++) {
        arr3[i] = (i + 1) * 10;
        printf("arr3[%d] = %d\n", i, arr3[i]);
    }
    
    int max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("\n최대값: %d\n", max);
    
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    printf("합계: %d\n", sum);
    printf("평균: %.2f\n", (float)sum / 5);
    
    return 0;
}

