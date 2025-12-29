#include <stdio.h>

int main() {
    printf("=== while 문 ===\n");
    int count = 0;
    while (count < 5) {
        printf("카운트: %d\n", count);
        count++;
    }
    
    printf("\n=== do-while 문 ===\n");
    int num = 0;
    do {
        printf("num: %d\n", num);
        num++;
    } while (num < 3);
    
    printf("\n=== for 문 ===\n");
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }
    
    printf("\n=== 중첩 반복문 ===\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
    }
    
    printf("\n=== break 문 ===\n");
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break;
        }
        printf("%d ", i);
    }
    printf("\n");
    
    printf("\n=== continue 문 ===\n");
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    
    printf("\n=== 무한 루프 ===\n");
    int sum = 0;
    int n = 1;
    while (1) {
        sum += n;
        n++;
        if (n > 10) {
            break;
        }
    }
    printf("1부터 10까지의 합: %d\n", sum);
    
    printf("\n=== 배열 순회 ===\n");
    int arr[] = {10, 20, 30, 40, 50};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < len; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}

