#include <stdio.h>

int main() {
    int num1 = 10;
    int num2 = -5;
    int num3 = 0;
    
    printf("정수형: %d, %d, %d\n", num1, num2, num3);
    
    float pi = 3.14159f;
    double e = 2.71828;
    printf("실수형: %.5f, %.5lf\n", pi, e);
    
    char ch = 'A';
    printf("문자형: %c\n", ch);
    
    char str[] = "Hello";
    printf("문자열: %s\n", str);
    
    int size_int = sizeof(int);
    int size_float = sizeof(float);
    int size_double = sizeof(double);
    int size_char = sizeof(char);
    
    printf("int 크기: %d bytes\n", size_int);
    printf("float 크기: %d bytes\n", size_float);
    printf("double 크기: %d bytes\n", size_double);
    printf("char 크기: %d bytes\n", size_char);
    
    unsigned int positive = 100;
    printf("unsigned int: %u\n", positive);
    
    short sh = 32767;
    long lg = 2147483647L;
    printf("short: %hd, long: %ld\n", sh, lg);
    
    return 0;
}

