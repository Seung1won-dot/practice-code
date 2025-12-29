#include <stdio.h>

int main() {
    int age = 25;
    float height = 175.5f;
    char name[] = "홍길동";
    
    printf("이름: %s, 나이: %d, 키: %.1f\n", name, age, height);
    
    printf("정수: %d\n", 42);
    printf("8진수: %o\n", 42);
    printf("16진수: %x\n", 42);
    printf("16진수(대문자): %X\n", 42);
    
    printf("실수: %f\n", 3.14159);
    printf("과학 표기법: %e\n", 1234.567);
    printf("짧은 형식: %g\n", 1234.567);
    
    printf("문자: %c\n", 'A');
    printf("문자열: %s\n", "Hello");
    
    printf("너비 지정: %5d\n", 42);
    printf("0으로 채우기: %05d\n", 42);
    printf("왼쪽 정렬: %-5d\n", 42);
    
    printf("소수점 자리수: %.2f\n", 3.14159);
    printf("너비와 소수점: %8.2f\n", 3.14159);
    
    int num;
    float fnum;
    char ch;
    char str[20];
    
    printf("정수 입력: ");
    scanf("%d", &num);
    printf("입력한 정수: %d\n", num);
    
    printf("실수 입력: ");
    scanf("%f", &fnum);
    printf("입력한 실수: %.2f\n", fnum);
    
    printf("문자 입력: ");
    scanf(" %c", &ch);
    printf("입력한 문자: %c\n", ch);
    
    printf("문자열 입력: ");
    scanf("%s", str);
    printf("입력한 문자열: %s\n", str);
    
    return 0;
}

