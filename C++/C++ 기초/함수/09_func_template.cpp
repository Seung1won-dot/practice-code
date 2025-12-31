/*
 * 09_func_template.cpp
 * 
 * 함수 템플릿 (Function Template)
 * - 자료형에 구애받지 않는 제네릭 함수
 * - 타입 안전성과 코드 재사용성
 * - C++ 템플릿 프로그래밍의 기초
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// ========== 기본 함수 템플릿 ==========

// 템플릿 선언
template<typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// 여러 타입 매개변수
template<typename T1, typename T2>
void printPair(T1 first, T2 second) {
    cout << "(" << first << ", " << second << ")" << endl;
}

void basicTemplate() {
    cout << "=== 기본 함수 템플릿 ===" << endl;
    
    // 정수형
    cout << "getMax(10, 20) = " << getMax(10, 20) << endl;
    
    // 실수형
    cout << "getMax(3.14, 2.71) = " << getMax(3.14, 2.71) << endl;
    
    // 문자형
    cout << "getMax('A', 'B') = " << getMax('A', 'B') << endl;
    
    // 문자열
    cout << "getMax(\"apple\", \"banana\") = " 
         << getMax(string("apple"), string("banana")) << endl;
    
    // 다른 타입 쌍
    printPair(10, 3.14);
    printPair(string("홍길동"), 25);
}

// ========== 템플릿 특수화 ==========

// 일반 템플릿
template<typename T>
T add(T a, T b) {
    return a + b;
}

// 특수화: 문자열의 경우
template<>
string add<string>(string a, string b) {
    return a + " " + b;  // 공백 추가
}

void templateSpecialization() {
    cout << "\n=== 템플릿 특수화 ===" << endl;
    
    cout << "add(10, 20) = " << add(10, 20) << endl;
    cout << "add(3.5, 2.5) = " << add(3.5, 2.5) << endl;
    cout << "add(\"Hello\", \"World\") = " 
         << add(string("Hello"), string("World")) << endl;
}

// ========== 명시적 타입 지정 ==========

template<typename T>
T multiply(T a, T b) {
    return a * b;
}

void explicitType() {
    cout << "\n=== 명시적 타입 지정 ===" << endl;
    
    // 컴파일러가 자동으로 타입 추론
    cout << "multiply(5, 3) = " << multiply(5, 3) << endl;
    
    // 명시적으로 타입 지정
    cout << "multiply<double>(5, 3) = " << multiply<double>(5, 3) << endl;
    cout << "multiply<int>(5.5, 3.3) = " << multiply<int>(5.5, 3.3) << endl;
}

// ========== 템플릿과 오버로딩 ==========

// 일반 함수
void process(int value) {
    cout << "일반 함수: " << value << endl;
}

// 템플릿 함수
template<typename T>
void process(T value) {
    cout << "템플릿 함수: " << value << endl;
}

void templateOverloading() {
    cout << "\n=== 템플릿과 오버로딩 ===" << endl;
    
    process(10);        // 일반 함수 우선
    process(3.14);      // 템플릿 함수
    process(string("템플릿"));  // 템플릿 함수
}

// ========== 클래스 템플릿과의 연동 ==========

template<typename T>
class Array {
private:
    T* data;
    int size;
    
public:
    Array(int s) : size(s) {
        data = new T[size];
    }
    
    ~Array() {
        delete[] data;
    }
    
    T& operator[](int index) {
        return data[index];
    }
    
    int getSize() const { return size; }
};

// 템플릿 함수로 배열 출력
template<typename T>
void printArray(const Array<T>& arr) {
    cout << "배열: ";
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void classTemplateIntegration() {
    cout << "\n=== 클래스 템플릿과 연동 ===" << endl;
    
    Array<int> intArr(5);
    for (int i = 0; i < 5; i++) {
        intArr[i] = i * 10;
    }
    printArray(intArr);
    
    Array<double> doubleArr(3);
    doubleArr[0] = 1.1;
    doubleArr[1] = 2.2;
    doubleArr[2] = 3.3;
    printArray(doubleArr);
}

// ========== 템플릿 매개변수 ==========

// 비타입 템플릿 매개변수
template<typename T, int N>
T multiplyByConstant(T value) {
    return value * N;
}

void nonTypeParameter() {
    cout << "\n=== 비타입 템플릿 매개변수 ===" << endl;
    
    cout << "multiplyByConstant<int, 5>(10) = " 
         << multiplyByConstant<int, 5>(10) << endl;
    cout << "multiplyByConstant<double, 3>(2.5) = " 
         << multiplyByConstant<double, 3>(2.5) << endl;
}

// ========== 템플릿과 기본 매개변수 ==========

template<typename T = int>
T getDefault() {
    return T{};
}

template<typename T = double>
void printValue(T value = T{}) {
    cout << "값: " << value << endl;
}

void templateDefaultParam() {
    cout << "\n=== 템플릿 기본 매개변수 ===" << endl;
    
    cout << "getDefault() = " << getDefault() << endl;
    cout << "getDefault<double>() = " << getDefault<double>() << endl;
    
    printValue();
    printValue(42);
    printValue(3.14);
}

// ========== 템플릿 메타프로그래밍 기초 ==========

// 컴파일 타임 팩토리얼
template<int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

void templateMetaprogramming() {
    cout << "\n=== 템플릿 메타프로그래밍 ===" << endl;
    cout << "Factorial<5>::value = " << Factorial<5>::value << endl;
    cout << "Factorial<10>::value = " << Factorial<10>::value << endl;
}

// ========== 실용적인 예제 ==========

// 배열 정렬 (버블 정렬)
template<typename T, int N>
void bubbleSort(T (&arr)[N]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 배열 출력
template<typename T, int N>
void printArray(T (&arr)[N]) {
    cout << "배열: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void practicalExample() {
    cout << "\n=== 실용적인 예제 ===" << endl;
    
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    double doubleArr[] = {3.14, 2.71, 1.41, 1.73};
    
    cout << "정렬 전:" << endl;
    printArray(intArr);
    printArray(doubleArr);
    
    bubbleSort(intArr);
    bubbleSort(doubleArr);
    
    cout << "\n정렬 후:" << endl;
    printArray(intArr);
    printArray(doubleArr);
}

// ========== 템플릿 제약사항 ==========

void templateConstraints() {
    cout << "\n=== 템플릿 제약사항 ===" << endl;
    cout << "1. 템플릿은 헤더 파일에 정의해야 함" << endl;
    cout << "2. 모든 타입에 대해 작동하지 않을 수 있음" << endl;
    cout << "3. 컴파일 타임에 타입이 결정됨" << endl;
    cout << "4. 컴파일 시간이 길어질 수 있음" << endl;
    cout << "5. 에러 메시지가 복잡할 수 있음" << endl;
}

int main() {
    basicTemplate();
    templateSpecialization();
    explicitType();
    templateOverloading();
    classTemplateIntegration();
    nonTypeParameter();
    templateDefaultParam();
    templateMetaprogramming();
    practicalExample();
    templateConstraints();
    
    return 0;
}

/*
 * 함수 템플릿 핵심 정리
 * 
 * 1. 개념
 *    - 타입에 독립적인 제네릭 함수
 *    - 컴파일 타임에 타입이 결정됨
 *    - 코드 재사용성과 타입 안전성 제공
 * 
 * 2. 문법
 *    template<typename T>
 *    반환타입 함수명(매개변수) {
 *        // 함수 본문
 *    }
 * 
 * 3. 타입 추론
 *    - 컴파일러가 자동으로 타입 추론
 *    - 명시적 타입 지정도 가능: 함수명<타입>(인자)
 * 
 * 4. 템플릿 특수화
 *    - 특정 타입에 대해 다른 구현 제공
 *    - template<> 로 시작
 * 
 * 5. 비타입 매개변수
 *    - 타입이 아닌 값도 템플릿 매개변수로 사용 가능
 *    - 예: template<typename T, int N>
 * 
 * 6. 장점
 *    - 코드 중복 제거
 *    - 타입 안전성
 *    - 유연성
 *    - 성능 (컴파일 타임 결정)
 * 
 * 7. 단점
 *    - 컴파일 시간 증가
 *    - 에러 메시지 복잡
 *    - 헤더 파일에 정의 필요
 *    - 모든 타입에 작동하지 않을 수 있음
 * 
 * 8. 사용 시기
 *    - 여러 타입에 대해 같은 로직 적용
 *    - STL 알고리즘 구현
 *    - 제네릭 유틸리티 함수
 * 
 * 9. 템플릿 메타프로그래밍
 *    - 컴파일 타임 계산
 *    - 타입 조작
 *    - 고급 최적화
 * 
 * 10. C++20 Concepts
 *     - 템플릿 타입 제약 (향후 학습)
 *     - 더 명확한 에러 메시지
 *     - 타입 요구사항 명시
 */

