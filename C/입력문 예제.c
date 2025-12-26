#include <stdio.h>

int main() {
    int age;
    float height;
    char name[20];
    
    printf("이름을 입력하세요: ");
    scanf("%s", name);  // 문자열은 &를 붙이지 않음
    
    printf("나이를 입력하세요: ");
    scanf("%d", &age);
    
    printf("키를 입력하세요: ");
    scanf("%f", &height);
    
    printf("\n입력 정보\n");
    printf("이름: %s\n", name);
    printf("나이: %d\n", age);
    printf("키: %.1f\n", height);
    
    return 0;
}