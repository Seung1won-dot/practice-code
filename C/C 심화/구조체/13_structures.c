#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float score;
};

struct Point {
    int x;
    int y;
};

struct Rectangle {
    struct Point top_left;
    struct Point bottom_right;
};

void print_student(struct Student s) {
    printf("이름: %s, 나이: %d, 점수: %.2f\n", s.name, s.age, s.score);
}

int main() {
    struct Student student1;
    strcpy(student1.name, "홍길동");
    student1.age = 20;
    student1.score = 85.5;
    
    print_student(student1);
    
    struct Student student2 = {"김철수", 21, 92.0};
    print_student(student2);
    
    struct Point p1 = {10, 20};
    struct Point p2 = {30, 40};
    
    printf("\n점 p1: (%d, %d)\n", p1.x, p1.y);
    printf("점 p2: (%d, %d)\n", p2.x, p2.y);
    
    struct Rectangle rect;
    rect.top_left = p1;
    rect.bottom_right = p2;
    
    int width = rect.bottom_right.x - rect.top_left.x;
    int height = rect.bottom_right.y - rect.top_left.y;
    int area = width * height;
    
    printf("\n사각형 넓이: %d\n", area);
    
    struct Student* ptr = &student1;
    printf("\n구조체 포인터:\n");
    printf("이름: %s\n", ptr->name);
    printf("나이: %d\n", ptr->age);
    printf("점수: %.2f\n", ptr->score);
    
    struct Student students[3] = {
        {"이영희", 19, 78.5},
        {"박민수", 20, 88.0},
        {"최지영", 21, 95.5}
    };
    
    printf("\n구조체 배열:\n");
    for (int i = 0; i < 3; i++) {
        print_student(students[i]);
    }
    
    return 0;
}

