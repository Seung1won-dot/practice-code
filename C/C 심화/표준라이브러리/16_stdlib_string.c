#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("=== stdlib.h 함수들 ===\n");
    
    char str1[] = "123";
    char str2[] = "45.67";
    
    int num = atoi(str1);
    double dnum = atof(str2);
    
    printf("atoi(\"123\") = %d\n", num);
    printf("atof(\"45.67\") = %.2f\n", dnum);
    
    int* arr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;
    }
    
    printf("\n동적 할당된 배열:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    
    printf("\n=== string.h 함수들 ===\n");
    
    char s1[20] = "Hello";
    char s2[20] = "World";
    char s3[20];
    
    strcpy(s3, s1);
    printf("strcpy: %s\n", s3);
    
    strcat(s1, " ");
    strcat(s1, s2);
    printf("strcat: %s\n", s1);
    
    int len = strlen(s1);
    printf("strlen: %d\n", len);
    
    int cmp = strcmp("apple", "banana");
    printf("strcmp: %d\n", cmp);
    
    char* found = strchr(s1, 'o');
    if (found != NULL) {
        printf("strchr('o'): %s\n", found);
    }
    
    printf("\n=== ctype.h 함수들 ===\n");
    
    char ch = 'A';
    printf("isupper('%c'): %d\n", ch, isupper(ch));
    printf("islower('%c'): %d\n", ch, islower(ch));
    printf("tolower('%c'): %c\n", ch, tolower(ch));
    
    char digit = '5';
    printf("isdigit('%c'): %d\n", digit, isdigit(digit));
    
    char space = ' ';
    printf("isspace('%c'): %d\n", space, isspace(space));
    
    return 0;
}

