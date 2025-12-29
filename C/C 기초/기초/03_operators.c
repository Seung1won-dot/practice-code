#include <stdio.h>

int main() {
    int a = 10, b = 3;
    
    printf("=== 산술 연산자 ===\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);
    
    printf("\n=== 증감 연산자 ===\n");
    int x = 5;
    printf("x = %d\n", x);
    printf("++x = %d\n", ++x);
    printf("x++ = %d\n", x++);
    printf("x = %d\n", x);
    
    printf("\n=== 비교 연산자 ===\n");
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a < b: %d\n", a < b);
    printf("a > b: %d\n", a > b);
    printf("a <= b: %d\n", a <= b);
    printf("a >= b: %d\n", a >= b);
    
    printf("\n=== 논리 연산자 ===\n");
    int p = 1, q = 0;
    printf("p && q: %d\n", p && q);
    printf("p || q: %d\n", p || q);
    printf("!p: %d\n", !p);
    
    printf("\n=== 비트 연산자 ===\n");
    int m = 5, n = 3;
    printf("m & n = %d\n", m & n);
    printf("m | n = %d\n", m | n);
    printf("m ^ n = %d\n", m ^ n);
    printf("~m = %d\n", ~m);
    printf("m << 1 = %d\n", m << 1);
    printf("m >> 1 = %d\n", m >> 1);
    
    printf("\n=== 할당 연산자 ===\n");
    int num = 10;
    printf("초기값: %d\n", num);
    num += 5;
    printf("num += 5: %d\n", num);
    num -= 3;
    printf("num -= 3: %d\n", num);
    num *= 2;
    printf("num *= 2: %d\n", num);
    num /= 4;
    printf("num /= 4: %d\n", num);
    
    printf("\n=== 삼항 연산자 ===\n");
    int age = 20;
    char* status = (age >= 18) ? "성인" : "미성년자";
    printf("나이: %d, 상태: %s\n", age, status);
    
    return 0;
}

