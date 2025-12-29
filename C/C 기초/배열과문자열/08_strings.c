#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[20] = "World";
    
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    
    int len1 = strlen(str1);
    printf("str1 길이: %d\n", len1);
    
    char str3[20];
    strcpy(str3, str1);
    printf("복사된 문자열: %s\n", str3);
    
    strcat(str2, "!");
    printf("연결된 문자열: %s\n", str2);
    
    int cmp = strcmp(str1, str2);
    if (cmp == 0) {
        printf("문자열이 같습니다.\n");
    } else if (cmp < 0) {
        printf("str1이 str2보다 작습니다.\n");
    } else {
        printf("str1이 str2보다 큽니다.\n");
    }
    
    char str4[] = "Programming";
    char* pos = strchr(str4, 'g');
    if (pos != NULL) {
        printf("'g' 문자의 위치: %ld\n", pos - str4);
    }
    
    char str5[] = "Hello World";
    char* token = strtok(str5, " ");
    while (token != NULL) {
        printf("토큰: %s\n", token);
        token = strtok(NULL, " ");
    }
    
    char str6[20];
    sprintf(str6, "숫자: %d, 실수: %.2f", 42, 3.14);
    printf("%s\n", str6);
    
    char str7[] = "123";
    int num = atoi(str7);
    printf("문자열을 정수로: %d\n", num);
    
    return 0;
}

