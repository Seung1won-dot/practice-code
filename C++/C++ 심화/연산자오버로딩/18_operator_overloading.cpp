/*
 * 18_operator_overloading.cpp
 * 
 * 연산자 오버로딩 (Operator Overloading)
 * - 사용자 정의 타입에 연산자 정의
 * - 단항/이항 연산자 오버로딩
 * - 전역 함수 vs 멤버 함수
 * - 특수 연산자 (++, --, [], (), ->)
 */

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

// ========== 기본 연산자 오버로딩 ==========

class Point {
private:
    int x, y;
    
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // 멤버 함수로 연산자 오버로딩
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
    
    // 비교 연산자
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }
    
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
    
    // 출력 연산자 (friend 함수 필요)
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    
    // 접근자
    int getX() const { return x; }
    int getY() const { return y; }
};

// 출력 연산자 오버로딩 (전역 함수)
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

void basicOperatorOverloading() {
    cout << "=== 기본 연산자 오버로딩 ===" << endl;
    
    Point p1(10, 20);
    Point p2(30, 40);
    
    Point p3 = p1 + p2;  // operator+ 호출
    Point p4 = p2 - p1;  // operator- 호출
    
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p1 + p2: " << p3 << endl;
    cout << "p2 - p1: " << p4 << endl;
    
    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;
}

// ========== 단항 연산자 ==========

class Counter {
private:
    int count;
    
public:
    Counter(int c = 0) : count(c) {}
    
    // 전위 증가 (++counter)
    Counter& operator++() {
        ++count;
        return *this;
    }
    
    // 후위 증가 (counter++)
    Counter operator++(int) {  // int는 더미 매개변수
        Counter temp = *this;
        ++count;
        return temp;
    }
    
    // 전위 감소
    Counter& operator--() {
        --count;
        return *this;
    }
    
    // 후위 감소
    Counter operator--(int) {
        Counter temp = *this;
        --count;
        return temp;
    }
    
    // 단항 마이너스
    Counter operator-() const {
        return Counter(-count);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Counter& c);
};

std::ostream& operator<<(std::ostream& os, const Counter& c) {
    os << c.count;
    return os;
}

void unaryOperators() {
    cout << "\n=== 단항 연산자 ===" << endl;
    
    Counter c(5);
    cout << "초기값: " << c << endl;
    
    cout << "++c: " << ++c << endl;  // 전위 증가
    cout << "현재값: " << c << endl;
    
    cout << "c++: " << c++ << endl;  // 후위 증가
    cout << "현재값: " << c << endl;
    
    cout << "--c: " << --c << endl;
    cout << "c--: " << c-- << endl;
    cout << "현재값: " << c << endl;
    
    Counter c2 = -c;
    cout << "-c: " << c2 << endl;
}

// ========== 대입 연산자 ==========

class String {
private:
    char* data;
    size_t length;
    
public:
    String(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }
    
    // 복사 생성자
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }
    
    // 대입 연산자
    String& operator=(const String& other) {
        if (this != &other) {  // 자기 자신 대입 방지
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
    
    // 이동 대입 연산자 (C++11)
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }
    
    ~String() {
        delete[] data;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const String& s);
};

std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.data;
    return os;
}

void assignmentOperator() {
    cout << "\n=== 대입 연산자 ===" << endl;
    
    String s1("Hello");
    String s2("World");
    
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    
    s2 = s1;  // 대입 연산자 호출
    cout << "s2 = s1 후 s2: " << s2 << endl;
}

// ========== 배열 인덱스 연산자 ==========

class Array {
private:
    int* arr;
    size_t size;
    
public:
    Array(size_t s = 10) : size(s) {
        arr = new int[size];
        for (size_t i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    
    ~Array() {
        delete[] arr;
    }
    
    // 배열 인덱스 연산자 (일반 버전)
    int& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    
    // const 버전 (읽기 전용)
    const int& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    
    size_t getSize() const { return size; }
};

void indexOperator() {
    cout << "\n=== 배열 인덱스 연산자 ===" << endl;
    
    Array arr(5);
    
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    
    for (size_t i = 0; i < arr.getSize(); i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

// ========== 함수 호출 연산자 ==========

class Multiplier {
private:
    int factor;
    
public:
    Multiplier(int f = 1) : factor(f) {}
    
    // 함수 호출 연산자: 객체를 함수처럼 사용 가능
    int operator()(int value) const {
        return value * factor;
    }
    
    int operator()(int a, int b) const {
        return (a + b) * factor;
    }
};

void functionCallOperator() {
    cout << "\n=== 함수 호출 연산자 ===" << endl;
    
    Multiplier mult(5);
    
    cout << "mult(10) = " << mult(10) << endl;
    cout << "mult(3, 7) = " << mult(3, 7) << endl;
    
    // 함수 객체 (Functor)로 사용
    Multiplier doubleIt(2);
    cout << "doubleIt(15) = " << doubleIt(15) << endl;
}

// ========== 멤버 접근 연산자 ==========

class SmartPointer {
private:
    int* ptr;
    
public:
    SmartPointer(int* p = nullptr) : ptr(p) {}
    
    ~SmartPointer() {
        delete ptr;
    }
    
    // 역참조 연산자
    int& operator*() {
        return *ptr;
    }
    
    // 멤버 접근 연산자
    int* operator->() {
        return ptr;
    }
    
    // bool 변환 연산자
    explicit operator bool() const {
        return ptr != nullptr;
    }
};

void memberAccessOperator() {
    cout << "\n=== 멤버 접근 연산자 ===" << endl;
    
    SmartPointer sp(new int(42));
    
    if (sp) {  // bool 변환 연산자 사용
        cout << "*sp = " << *sp << endl;
        cout << "sp-> (주소) = " << sp.operator->() << endl;
    }
}

// ========== 전역 함수로 연산자 오버로딩 ==========

class Complex {
private:
    double real, imag;
    
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    
    double getReal() const { return real; }
    double getImag() const { return imag; }
    
    // 전역 함수로 오버로딩하기 위해 friend 선언
    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

// 전역 함수로 연산자 오버로딩
Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator*(const Complex& a, const Complex& b) {
    return Complex(a.real * b.real - a.imag * b.imag,
                   a.real * b.imag + a.imag * b.real);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i";
    } else {
        os << " - " << -c.imag << "i";
    }
    return os;
}

void globalOperatorOverloading() {
    cout << "\n=== 전역 함수로 연산자 오버로딩 ===" << endl;
    
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c1 + c2: " << (c1 + c2) << endl;
    cout << "c1 * c2: " << (c1 * c2) << endl;
}

int main() {
    basicOperatorOverloading();
    unaryOperators();
    assignmentOperator();
    indexOperator();
    functionCallOperator();
    memberAccessOperator();
    globalOperatorOverloading();
    
    return 0;
}

/*
 * 연산자 오버로딩 핵심 정리
 * 
 * 1. 연산자 오버로딩의 개념
 *    - 사용자 정의 타입에 연산자 의미 부여
 *    - 직관적인 코드 작성 가능
 *    - 기존 연산자 우선순위 유지
 * 
 * 2. 오버로딩 가능한 연산자
 *    - 산술: +, -, *, /, %
 *    - 비교: ==, !=, <, >, <=, >=
 *    - 논리: &&, ||, !
 *    - 대입: =, +=, -=, *=, /=, %=
 *    - 증감: ++, --
 *    - 특수: [], (), ->, *, &, <<, >>
 * 
 * 3. 오버로딩 불가능한 연산자
 *    - . (멤버 접근)
 *    - .* (멤버 포인터 접근)
 *    - :: (범위 지정)
 *    - ?: (조건 연산자)
 *    - sizeof
 *    - typeid
 * 
 * 4. 멤버 함수 vs 전역 함수
 *    - 멤버 함수: 첫 번째 피연산자가 객체
 *    - 전역 함수: 두 피연산자 모두 매개변수
 *    - =, [], (), -> 는 반드시 멤버 함수
 *    - <<, >> 는 보통 전역 함수
 * 
 * 5. 단항 연산자
 *    - 전위: operator++(), operator--()
 *    - 후위: operator++(int), operator--(int)
 *    - int는 더미 매개변수 (구분용)
 * 
 * 6. 대입 연산자
 *    - 자기 자신 대입 체크 필수
 *    - 반환 타입: 참조자 (체이닝 가능)
 *    - 깊은 복사 구현 필요
 * 
 * 7. 배열 인덱스 연산자
 *    - operator[](size_t index)
 *    - const 버전도 제공 권장
 *    - 범위 체크 권장
 * 
 * 8. 함수 호출 연산자
 *    - operator()(...)
 *    - 함수 객체 (Functor) 구현
 *    - STL 알고리즘과 함께 사용
 * 
 * 9. 주의사항
 *    - 직관적인 의미 유지
 *    - 기존 연산자 의미와 일관성 유지
 *    - 성능 고려
 *    - 예외 안전성 고려
 */

