#include <stdio.h>

int main() {
    int age = 20;
    
    if (age >= 18) {
        printf("성인입니다.\n");
    }
    
    int score = 85;
    if (score >= 60) {
        printf("합격입니다!\n");
    } else {
        printf("불합격입니다.\n");
    }
    
    int grade = 92;
    if (grade >= 90) {
        printf("등급: A\n");
    } else if (grade >= 80) {
        printf("등급: B\n");
    } else if (grade >= 70) {
        printf("등급: C\n");
    } else if (grade >= 60) {
        printf("등급: D\n");
    } else {
        printf("등급: F\n");
    }
    
    int num = 5;
    if (num > 0) {
        if (num % 2 == 0) {
            printf("양수이면서 짝수\n");
        } else {
            printf("양수이면서 홀수\n");
        }
    }
    
    int a = 10, b = 20;
    if (a > 0 && b > 0) {
        printf("둘 다 양수\n");
    }
    
    if (a > 0 || b < 0) {
        printf("적어도 하나는 양수\n");
    }
    
    if (!(a < 0)) {
        printf("a는 음수가 아님\n");
    }
    
    int day = 3;
    switch (day) {
        case 1:
            printf("월요일\n");
            break;
        case 2:
            printf("화요일\n");
            break;
        case 3:
            printf("수요일\n");
            break;
        case 4:
            printf("목요일\n");
            break;
        case 5:
            printf("금요일\n");
            break;
        default:
            printf("주말\n");
    }
    
    char op = '+';
    int x = 10, y = 5, result;
    switch (op) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        default:
            result = 0;
    }
    printf("%d %c %d = %d\n", x, op, y, result);
    
    return 0;
}

