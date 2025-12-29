#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file;
    
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }
    
    fprintf(file, "Hello, World!\n");
    fprintf(file, "C 언어 파일 입출력 예제\n");
    fprintf(file, "숫자: %d\n", 42);
    
    fclose(file);
    printf("파일 쓰기 완료\n");
    
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }
    
    char buffer[100];
    printf("\n파일 내용:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(file);
    
    file = fopen("data.bin", "wb");
    if (file != NULL) {
        int data[] = {10, 20, 30, 40, 50};
        fwrite(data, sizeof(int), 5, file);
        fclose(file);
        printf("\n바이너리 파일 쓰기 완료\n");
    }
    
    file = fopen("data.bin", "rb");
    if (file != NULL) {
        int read_data[5];
        fread(read_data, sizeof(int), 5, file);
        printf("\n바이너리 파일 읽기:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d ", read_data[i]);
        }
        printf("\n");
        fclose(file);
    }
    
    return 0;
}

