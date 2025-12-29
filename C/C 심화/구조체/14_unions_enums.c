#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

enum Color {
    RED,
    GREEN,
    BLUE
};

enum Status {
    PENDING = 1,
    PROCESSING = 2,
    COMPLETED = 3,
    FAILED = 4
};

int main() {
    union Data data;
    
    data.i = 10;
    printf("정수 값: %d\n", data.i);
    
    data.f = 3.14f;
    printf("실수 값: %.2f\n", data.f);
    
    strcpy(data.str, "Hello");
    printf("문자열 값: %s\n", data.str);
    
    printf("\n공용체 크기: %zu bytes\n", sizeof(union Data));
    printf("(가장 큰 멤버의 크기)\n");
    
    enum Color color = RED;
    printf("\n열거형:\n");
    printf("현재 색상: %d\n", color);
    
    if (color == RED) {
        printf("색상이 빨강입니다.\n");
    }
    
    enum Status status = PROCESSING;
    printf("\n상태: %d\n", status);
    
    switch (status) {
        case PENDING:
            printf("대기 중\n");
            break;
        case PROCESSING:
            printf("처리 중\n");
            break;
        case COMPLETED:
            printf("완료\n");
            break;
        case FAILED:
            printf("실패\n");
            break;
    }
    
    return 0;
}

