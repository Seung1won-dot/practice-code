/*
 * 08_inline_func.cpp
 * 
 * 인라인 함수 (Inline Function)
 * - 매크로 함수를 대체
 * - 실행 속도 향상
 * - 함수 호출 오버헤드 제거
 */

#include <iostream>

using std::cout;
using std::endl;

// ========== 기본 인라인 함수 ==========

// 인라인 함수 선언
inline int square(int x) {
    return x * x;
}

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

inline void printMessage(const char* msg) {
    cout << "[메시지] " << msg << endl;
}

void basicInline() {
    cout << "=== 기본 인라인 함수 ===" << endl;
    
    int num = 5;
    cout << "square(5) = " << square(num) << endl;
    cout << "max(10, 20) = " << max(10, 20) << endl;
    printMessage("인라인 함수 테스트");
    
    // 컴파일러가 다음과 같이 확장:
    // cout << "square(5) = " << (5 * 5) << endl;
    // cout << "max(10, 20) = " << ((10 > 20) ? 10 : 20) << endl;
}

// ========== 매크로 vs 인라인 함수 ==========

// 매크로 정의 (C 스타일)
#define SQUARE_MACRO(x) ((x) * (x))
#define MAX_MACRO(a, b) ((a) > (b) ? (a) : (b))

// 인라인 함수 (C++ 스타일)
inline int squareInline(int x) {
    return x * x;
}

inline int maxInline(int a, int b) {
    return (a > b) ? a : b;
}

void macroVsInline() {
    cout << "\n=== 매크로 vs 인라인 함수 ===" << endl;
    
    int a = 5;
    
    // 매크로 사용
    cout << "매크로 SQUARE(5) = " << SQUARE_MACRO(a) << endl;
    cout << "매크로 MAX(10, 20) = " << MAX_MACRO(10, 20) << endl;
    
    // 인라인 함수 사용
    cout << "인라인 square(5) = " << squareInline(a) << endl;
    cout << "인라인 max(10, 20) = " << maxInline(10, 20) << endl;
    
    // 문제가 있는 매크로 예시
    int result1 = SQUARE_MACRO(++a);  // a가 두 번 증가! (문제)
    cout << "매크로 SQUARE(++a) 결과: " << result1 << ", a = " << a << endl;
    
    a = 5;
    int result2 = squareInline(++a);   // a가 한 번만 증가 (정상)
    cout << "인라인 square(++a) 결과: " << result2 << ", a = " << a << endl;
}

// ========== 인라인 함수의 장점 ==========

// 타입 안전성
inline double calculateArea(double radius) {
    return 3.14159 * radius * radius;
}

// 디버깅 가능
inline int add(int a, int b) {
    // 디버거에서 중단점 설정 가능
    return a + b;
}

void inlineAdvantages() {
    cout << "\n=== 인라인 함수의 장점 ===" << endl;
    
    // 1. 타입 검사
    double area = calculateArea(5.0);
    // calculateArea("문자열");  // 컴파일 오류! (매크로는 오류를 못 잡음)
    
    // 2. 네임스페이스 지원
    // 3. 클래스 멤버로 사용 가능
    // 4. 디버깅 가능
    
    cout << "원의 넓이 (반지름 5): " << area << endl;
    cout << "add(10, 20) = " << add(10, 20) << endl;
}

// ========== 클래스 내부 인라인 함수 ==========

class MathUtils {
public:
    // 방법 1: 클래스 내부에 정의 (자동으로 인라인)
    int multiply(int a, int b) {
        return a * b;
    }
    
    // 방법 2: inline 키워드 명시
    inline int divide(int a, int b) {
        return (b != 0) ? a / b : 0;
    }
    
    // 방법 3: 선언만 하고 외부에 정의
    int subtract(int a, int b);
};

// 외부 정의 시 inline 키워드 사용
inline int MathUtils::subtract(int a, int b) {
    return a - b;
}

void classInline() {
    cout << "\n=== 클래스 내부 인라인 함수 ===" << endl;
    MathUtils math;
    
    cout << "multiply(6, 7) = " << math.multiply(6, 7) << endl;
    cout << "divide(20, 4) = " << math.divide(20, 4) << endl;
    cout << "subtract(10, 3) = " << math.subtract(10, 3) << endl;
}

// ========== 인라인 함수 제한사항 ==========

// 복잡한 함수는 인라인화되지 않을 수 있음
inline void complexFunction() {
    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = i;
    }
    // 컴파일러가 인라인화하지 않을 수 있음
}

// 재귀 함수는 인라인화되지 않음
inline int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);  // 재귀는 인라인화 안 됨
}

void inlineLimitations() {
    cout << "\n=== 인라인 함수 제한사항 ===" << endl;
    cout << "복잡하거나 재귀 함수는 컴파일러가 인라인화하지 않을 수 있습니다." << endl;
    cout << "factorial(5) = " << factorial(5) << endl;
}

// ========== 인라인 함수 사용 가이드 ==========

// 적합한 경우: 작고 자주 호출되는 함수
inline int getSmaller(int a, int b) {
    return (a < b) ? a : b;
}

inline bool isEven(int n) {
    return (n % 2 == 0);
}

// 부적합한 경우: 큰 함수, 복잡한 로직
int largeFunction(int x) {  // inline 없음
    // 많은 코드...
    int result = 0;
    for (int i = 0; i < 10000; i++) {
        result += x * i;
    }
    return result;
}

void usageGuide() {
    cout << "\n=== 인라인 함수 사용 가이드 ===" << endl;
    cout << "getSmaller(10, 20) = " << getSmaller(10, 20) << endl;
    cout << "isEven(8) = " << std::boolalpha << isEven(8) << endl;
    cout << "isEven(7) = " << isEven(7) << endl;
}

// ========== 컴파일러 최적화 ==========

void compilerOptimization() {
    cout << "\n=== 컴파일러 최적화 ===" << endl;
    cout << "인라인은 컴파일러에게 '힌트'일 뿐입니다." << endl;
    cout << "컴파일러가 판단하여 인라인화할지 결정합니다." << endl;
    cout << "- 작은 함수: 인라인화 가능" << endl;
    cout << "- 큰 함수: 인라인화 안 함" << endl;
    cout << "- 재귀 함수: 인라인화 안 함" << endl;
    cout << "- 가상 함수: 인라인화 어려움" << endl;
}

// ========== 인라인 함수와 성능 ==========

// 인라인 함수는 코드 크기를 증가시킬 수 있음
inline void smallTask() {
    int x = 10;
    x *= 2;
    // 작은 함수는 인라인화가 유리
}

void performanceConsideration() {
    cout << "\n=== 성능 고려사항 ===" << endl;
    cout << "장점:" << endl;
    cout << "- 함수 호출 오버헤드 제거" << endl;
    cout << "- 실행 속도 향상" << endl;
    cout << "\n단점:" << endl;
    cout << "- 코드 크기 증가 (여러 곳에서 확장)" << endl;
    cout << "- 캐시 미스 가능성 증가" << endl;
    cout << "\n→ 작고 자주 호출되는 함수에만 사용 권장" << endl;
}

int main() {
    basicInline();
    macroVsInline();
    inlineAdvantages();
    classInline();
    inlineLimitations();
    usageGuide();
    compilerOptimization();
    performanceConsideration();
    
    return 0;
}

/*
 * 인라인 함수 핵심 정리
 * 
 * 1. 개념
 *    - 함수 호출 대신 함수 코드를 직접 삽입
 *    - 함수 호출 오버헤드 제거
 *    - 실행 속도 향상
 * 
 * 2. 문법
 *    inline 반환타입 함수명(매개변수) {
 *        // 함수 본문
 *    }
 * 
 * 3. 매크로 vs 인라인 함수
 *    매크로:
 *    - 전처리기가 처리
 *    - 타입 검사 없음
 *    - 디버깅 어려움
 *    - 부작용 가능 (++a 같은 경우)
 * 
 *    인라인 함수:
 *    - 컴파일러가 처리
 *    - 타입 검사 있음
 *    - 디버깅 가능
 *    - 안전함
 * 
 * 4. 인라인화 조건
 *    - 작은 함수 (몇 줄 정도)
 *    - 자주 호출되는 함수
 *    - 단순한 로직
 * 
 * 5. 인라인화 안 되는 경우
 *    - 재귀 함수
 *    - 가상 함수
 *    - 너무 큰 함수
 *    - 함수 포인터로 사용되는 함수
 * 
 * 6. 클래스 내부 함수
 *    - 클래스 내부에 정의된 함수는 자동으로 인라인 고려
 *    - inline 키워드 명시 가능
 * 
 * 7. 주의사항
 *    - inline은 컴파일러에게 '힌트'일 뿐
 *    - 최종 결정은 컴파일러가 함
 *    - 코드 크기 증가 가능
 *    - 모든 곳에 사용하지 말 것
 * 
 * 8. 사용 권장 사항
 *    - Getter/Setter 함수
 *    - 간단한 수학 연산
 *    - 작은 유틸리티 함수
 */

