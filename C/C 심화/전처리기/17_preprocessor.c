#include <stdio.h>

#define PI 3.14159
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SQUARE(x) ((x) * (x))

#define DEBUG

int main() {
    printf("PI = %.5f\n", PI);
    
    int result = MAX(10, 20);
    printf("MAX(10, 20) = %d\n", result);
    
    int square = SQUARE(5);
    printf("SQUARE(5) = %d\n", square);
    
    #ifdef DEBUG
        printf("디버그 모드입니다.\n");
    #endif
    
    #ifndef RELEASE
        printf("릴리즈 모드가 아닙니다.\n");
    #endif
    
    int value = 5;
    #if value > 0
        printf("값이 양수입니다.\n");
    #else
        printf("값이 0 이하입니다.\n");
    #endif
    
    printf("\n__LINE__: %d\n", __LINE__);
    printf("__FILE__: %s\n", __FILE__);
    printf("__DATE__: %s\n", __DATE__);
    printf("__TIME__: %s\n", __TIME__);
    
    return 0;
}

