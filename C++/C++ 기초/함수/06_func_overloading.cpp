/*
 * 06_func_overloading.cpp
 * 
 * 함수 오버로딩 (Function Overloading)
 * - 같은 이름의 함수를 매개변수에 따라 다르게 정의
 * - C에서는 불가능, C++의 강력한 기능
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// ========== 기본 오버로딩 ==========

// 정수 덧셈
int add(int a, int b) {
    cout << "정수 덧셈 호출" << endl;
    return a + b;
}

// 실수 덧셈
double add(double a, double b) {
    cout << "실수 덧셈 호출" << endl;
    return a + b;
}

// 세 개의 정수 덧셈
int add(int a, int b, int c) {
    cout << "세 정수 덧셈 호출" << endl;
    return a + b + c;
}

void basicOverloading() {
    cout << "=== 기본 오버로딩 ===" << endl;
    cout << "add(10, 20) = " << add(10, 20) << endl;
    cout << "add(3.14, 2.71) = " << add(3.14, 2.71) << endl;
    cout << "add(1, 2, 3) = " << add(1, 2, 3) << endl;
}

// ========== 매개변수 개수 차이 ==========

void print() {
    cout << "인자가 없습니다." << endl;
}

void print(int value) {
    cout << "정수: " << value << endl;
}

void print(double value) {
    cout << "실수: " << value << endl;
}

void print(string text) {
    cout << "문자열: " << text << endl;
}

void print(int a, int b) {
    cout << "두 정수: " << a << ", " << b << endl;
}

void parameterCount() {
    cout << "\n=== 매개변수 개수 차이 ===" << endl;
    print();
    print(42);
    print(3.14);
    print(string("Hello"));
    print(10, 20);
}

// ========== 타입 차이 ==========

void display(char c) {
    cout << "문자: " << c << endl;
}

void display(int n) {
    cout << "정수: " << n << endl;
}

void display(float f) {
    cout << "float: " << f << endl;
}

void display(double d) {
    cout << "double: " << d << endl;
}

void typeDifference() {
    cout << "\n=== 타입 차이 ===" << endl;
    display('A');
    display(100);
    display(3.14f);  // f 접미사로 float 명시
    display(3.14);   // double
}

// ========== 참조자와 포인터 오버로딩 ==========

void process(int value) {
    cout << "값으로 전달: " << value << endl;
}

void process(int& ref) {
    cout << "참조자로 전달: " << ref << endl;
}

void process(int* ptr) {
    cout << "포인터로 전달: " << *ptr << endl;
}

void referencePointer() {
    cout << "\n=== 참조자와 포인터 ===" << endl;
    int num = 42;
    
    process(num);      // 값으로 전달
    process(num);     // 참조자로 전달 (같은 호출이지만 컴파일러가 구분)
    process(&num);    // 포인터로 전달
}

// ========== const 오버로딩 ==========

void modify(int& ref) {
    ref = 100;
    cout << "비상수 참조자: 값 변경 가능" << endl;
}

void modify(const int& ref) {
    // ref = 100;  // 오류! const 참조자는 수정 불가
    cout << "상수 참조자: 값 변경 불가, 값 = " << ref << endl;
}

void constOverloading() {
    cout << "\n=== const 오버로딩 ===" << endl;
    int num = 50;
    const int constNum = 100;
    
    modify(num);        // 비상수 참조자 버전 호출
    modify(constNum);   // 상수 참조자 버전 호출
}

// ========== 기본 매개변수와의 차이 ==========

// 오버로딩 사용
int multiply(int a, int b) {
    return a * b;
}

int multiply(int a, int b, int c) {
    return a * b * c;
}

// 기본 매개변수 사용 (다음 파일에서 자세히 학습)
int multiplyWithDefault(int a, int b, int c = 1) {
    return a * b * c;
}

void overloadingVsDefault() {
    cout << "\n=== 오버로딩 vs 기본 매개변수 ===" << endl;
    cout << "오버로딩: multiply(2, 3) = " << multiply(2, 3) << endl;
    cout << "오버로딩: multiply(2, 3, 4) = " << multiply(2, 3, 4) << endl;
    cout << "기본 매개변수: multiplyWithDefault(2, 3) = " 
         << multiplyWithDefault(2, 3) << endl;
    cout << "기본 매개변수: multiplyWithDefault(2, 3, 4) = " 
         << multiplyWithDefault(2, 3, 4) << endl;
}

// ========== 모호성 주의사항 ==========

void ambiguous(int a) {
    cout << "정수: " << a << endl;
}

void ambiguous(double a) {
    cout << "실수: " << a << endl;
}

// void ambiguous(float a) {  // 이렇게 하면 모호함 발생 가능
//     cout << "float: " << a << endl;
// }

void ambiguityWarning() {
    cout << "\n=== 모호성 주의 ===" << endl;
    ambiguous(10);      // OK: int
    ambiguous(3.14);    // OK: double
    // ambiguous(3.14f); // float 버전이 있으면 모호함 발생 가능
}

// ========== 클래스 멤버 함수 오버로딩 ==========

class Calculator {
public:
    int calculate(int a, int b) {
        return a + b;
    }
    
    double calculate(double a, double b) {
        return a + b;
    }
    
    int calculate(int a, int b, int c) {
        return a + b + c;
    }
};

void memberFunctionOverloading() {
    cout << "\n=== 멤버 함수 오버로딩 ===" << endl;
    Calculator calc;
    
    cout << "calc.calculate(10, 20) = " << calc.calculate(10, 20) << endl;
    cout << "calc.calculate(3.14, 2.71) = " << calc.calculate(3.14, 2.71) << endl;
    cout << "calc.calculate(1, 2, 3) = " << calc.calculate(1, 2, 3) << endl;
}

// ========== 연산자 오버로딩 (미리보기) ==========

class Point {
private:
    int x, y;
    
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // 연산자 오버로딩 (나중에 자세히 학습)
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    
    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

void operatorOverloadingPreview() {
    cout << "\n=== 연산자 오버로딩 미리보기 ===" << endl;
    Point p1(10, 20);
    Point p2(30, 40);
    Point p3 = p1 + p2;  // + 연산자 오버로딩
    
    cout << "p1: ";
    p1.display();
    cout << "\np2: ";
    p2.display();
    cout << "\np1 + p2: ";
    p3.display();
    cout << endl;
}

int main() {
    basicOverloading();
    parameterCount();
    typeDifference();
    referencePointer();
    constOverloading();
    overloadingVsDefault();
    ambiguityWarning();
    memberFunctionOverloading();
    operatorOverloadingPreview();
    
    return 0;
}

/*
 * 함수 오버로딩 핵심 정리
 * 
 * 1. 개념
 *    - 같은 이름의 함수를 여러 개 정의
 *    - 매개변수의 개수, 타입, 순서가 달라야 함
 *    - 반환 타입만 다른 것은 오버로딩이 아님!
 * 
 * 2. 오버로딩 조건
 *    - 함수 이름이 같아야 함
 *    - 매개변수가 달라야 함 (개수, 타입, 순서)
 *    - 반환 타입은 오버로딩과 무관
 * 
 * 3. 컴파일러가 함수를 선택하는 방법
 *    - 호출 시 전달된 인자의 타입과 개수로 결정
 *    - 정확한 매칭 우선
 *    - 타입 변환을 통한 매칭
 * 
 * 4. 주의사항
 *    - 모호한 호출 방지 (컴파일 오류)
 *    - 기본 타입 변환 시 주의
 *    - 참조자와 값의 차이
 * 
 * 5. 장점
 *    - 직관적인 함수 이름 사용 가능
 *    - 타입에 따라 자동으로 적절한 함수 호출
 *    - 코드 가독성 향상
 * 
 * 6. 사용 예시
 *    - 같은 연산을 다른 타입에 대해 수행
 *    - 선택적 매개변수 대체
 *    - 편의성 함수 제공
 * 
 * 7. C와의 차이
 *    - C: 같은 이름의 함수 불가능
 *    - C++: 오버로딩 지원으로 유연성 증가
 */

