/*
 * 02_variables_types.cpp
 * 
 * C++의 변수와 자료형
 * - auto 키워드: 타입 자동 추론
 * - bool 타입: true/false 값
 * - 자료형 초기화 방식: {} (uniform initialization)
 */

#include <iostream>
#include <typeinfo>  // 타입 정보 확인용

using std::cout;
using std::endl;

int main() {
    // ========== 기본 자료형 ==========
    
    // 정수형
    int integer = 42;
    short shortInt = 10;
    long longInt = 1000000L;
    long long veryLong = 10000000000LL;
    
    // 실수형
    float floatNum = 3.14f;
    double doubleNum = 3.141592;
    long double longDouble = 3.141592653589793L;
    
    // 문자형
    char character = 'A';
    wchar_t wideChar = L'가';  // 유니코드 문자
    
    // 불리언 (C++에서 직접 지원)
    bool isTrue = true;
    bool isFalse = false;
    
    cout << "정수: " << integer << endl;
    cout << "실수: " << doubleNum << endl;
    cout << "문자: " << character << endl;
    cout << "불리언: " << std::boolalpha << isTrue << ", " << isFalse << endl;
    
    // ========== auto 키워드 (C++11) ==========
    
    // auto: 컴파일러가 타입을 자동으로 추론
    auto num = 10;           // int로 추론
    auto pi = 3.14;          // double로 추론
    auto name = "홍길동";     // const char*로 추론
    auto flag = true;        // bool로 추론
    
    cout << "\n=== auto 키워드 사용 ===" << endl;
    cout << "num 타입: " << typeid(num).name() << ", 값: " << num << endl;
    cout << "pi 타입: " << typeid(pi).name() << ", 값: " << pi << endl;
    cout << "name 타입: " << typeid(name).name() << ", 값: " << name << endl;
    cout << "flag 타입: " << typeid(flag).name() << ", 값: " << std::boolalpha << flag << endl;
    
    // auto와 반복자
    int arr[] = {1, 2, 3, 4, 5};
    for (auto element : arr) {  // auto로 타입 추론
        cout << element << " ";
    }
    cout << endl;
    
    // ========== bool 타입 ==========
    
    bool condition1 = true;
    bool condition2 = false;
    bool condition3 = 1;   // 정수 1은 true로 변환
    bool condition4 = 0;   // 정수 0은 false로 변환
    bool condition5 = 100; // 0이 아닌 값은 true로 변환
    
    cout << "\n=== bool 타입 ===" << endl;
    cout << std::boolalpha;  // true/false로 출력
    cout << "condition1: " << condition1 << endl;
    cout << "condition2: " << condition2 << endl;
    cout << "condition3: " << condition3 << endl;
    cout << "condition4: " << condition4 << endl;
    cout << "condition5: " << condition5 << endl;
    
    // bool 타입의 크기
    cout << "\nbool 타입 크기: " << sizeof(bool) << " bytes" << endl;
    
    // ========== 초기화 방식 비교 ==========
    
    // 방법 1: 전통적인 초기화 (=)
    int a = 10;
    int b = 20;
    
    // 방법 2: 괄호 초기화 (C++98)
    int c(30);
    int d(40);
    
    // 방법 3: 중괄호 초기화 (Uniform Initialization, C++11) - 권장!
    int e{50};
    int f{60};
    int g{};  // 0으로 초기화
    
    // 중괄호 초기화의 장점: 타입 안전성
    // int h{3.14};  // 컴파일 오류! 타입 불일치
    
    cout << "\n=== 초기화 방식 ===" << endl;
    cout << "a = " << a << " (전통적)" << endl;
    cout << "c = " << c << " (괄호)" << endl;
    cout << "e = " << e << " (중괄호)" << endl;
    cout << "g = " << g << " (중괄호, 기본값)" << endl;
    
    // ========== 배열 초기화 ==========
    
    // 전통적인 방식
    int arr1[5] = {1, 2, 3, 4, 5};
    
    // 중괄호 초기화
    int arr2[]{10, 20, 30, 40, 50};  // 크기 자동 추론
    int arr3[5]{};  // 모두 0으로 초기화
    
    cout << "\n=== 배열 초기화 ===" << endl;
    cout << "arr2: ";
    for (auto val : arr2) {
        cout << val << " ";
    }
    cout << endl;
    
    // ========== 구조체 초기화 ==========
    
    struct Point {
        int x;
        int y;
    };
    
    // 전통적인 방식
    Point p1;
    p1.x = 10;
    p1.y = 20;
    
    // 중괄호 초기화
    Point p2{30, 40};  // 멤버 순서대로 초기화
    Point p3{};        // 모두 0으로 초기화
    
    cout << "\n=== 구조체 초기화 ===" << endl;
    cout << "p2: (" << p2.x << ", " << p2.y << ")" << endl;
    cout << "p3: (" << p3.x << ", " << p3.y << ")" << endl;
    
    // ========== const와 constexpr ==========
    
    const int constant = 100;  // 실행 시 상수
    constexpr int compileTime = 200;  // 컴파일 시 상수 (C++11)
    
    // constexpr은 컴파일 타임에 값이 결정되어야 함
    constexpr int square = compileTime * 2;  // OK
    
    cout << "\n=== 상수 ===" << endl;
    cout << "constant: " << constant << endl;
    cout << "compileTime: " << compileTime << endl;
    cout << "square: " << square << endl;
    
    // ========== 타입 변환 ==========
    
    int intVal = 65;
    char charVal = static_cast<char>(intVal);  // C++ 스타일 캐스팅
    double doubleVal = static_cast<double>(intVal);
    
    cout << "\n=== 타입 변환 ===" << endl;
    cout << "intVal: " << intVal << endl;
    cout << "charVal: " << charVal << endl;
    cout << "doubleVal: " << doubleVal << endl;
    
    return 0;
}

/*
 * 주요 개념 정리
 * 
 * 1. auto 키워드
 *    - 컴파일러가 타입을 자동으로 추론
 *    - 복잡한 타입을 간단하게 표현 가능
 *    - 템플릿과 함께 사용 시 매우 유용
 * 
 * 2. bool 타입
 *    - true/false 값을 가짐
 *    - C에서는 int를 사용했지만, C++에서는 직접 지원
 *    - 크기는 보통 1 byte
 * 
 * 3. 중괄호 초기화 (Uniform Initialization)
 *    - C++11에서 도입
 *    - 모든 타입에 일관된 초기화 방식 제공
 *    - 타입 안전성 향상 (축소 변환 방지)
 *    - 예: int x{10};  // 권장 방식
 * 
 * 4. 초기화 방식 비교
 *    - int a = 10;     // 전통적 방식
 *    - int b(10);      // 함수 스타일
 *    - int c{10};      // 중괄호 초기화 (권장)
 * 
 * 5. 타입 변환
 *    - C 스타일: (type)value
 *    - C++ 스타일: static_cast<type>(value) (권장)
 */

