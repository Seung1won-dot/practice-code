/*
 * 12_member_methods.cpp
 * 
 * 멤버 메서드 (Member Methods)
 * - 클래스 내부의 멤버 변수를 조작하는 함수
 * - 메서드 정의 방법
 * - 오버로딩과 오버라이딩
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// ========== 기본 멤버 메서드 ==========

class Rectangle {
private:
    double width;
    double height;
    
public:
    // Setter 메서드
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        }
    }
    
    void setHeight(double h) {
        if (h > 0) {
            height = h;
        }
    }
    
    // Getter 메서드
    double getWidth() const {
        return width;
    }
    
    double getHeight() const {
        return height;
    }
    
    // 계산 메서드
    double getArea() const {
        return width * height;
    }
    
    double getPerimeter() const {
        return 2 * (width + height);
    }
    
    // 정보 출력 메서드
    void display() const {
        cout << "너비: " << width << ", 높이: " << height << endl;
        cout << "넓이: " << getArea() << ", 둘레: " << getPerimeter() << endl;
    }
};

void basicMemberMethods() {
    cout << "=== 기본 멤버 메서드 ===" << endl;
    
    Rectangle rect;
    rect.setWidth(10.0);
    rect.setHeight(5.0);
    rect.display();
}

// ========== 메서드 오버로딩 ==========

class Calculator {
public:
    // 정수 덧셈
    int add(int a, int b) {
        cout << "정수 덧셈: ";
        return a + b;
    }
    
    // 실수 덧셈
    double add(double a, double b) {
        cout << "실수 덧셈: ";
        return a + b;
    }
    
    // 세 개의 정수
    int add(int a, int b, int c) {
        cout << "세 정수 덧셈: ";
        return a + b + c;
    }
    
    // 배열 합계
    int add(int arr[], int size) {
        cout << "배열 합계: ";
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

void methodOverloading() {
    cout << "\n=== 메서드 오버로딩 ===" << endl;
    
    Calculator calc;
    cout << calc.add(10, 20) << endl;
    cout << calc.add(3.14, 2.71) << endl;
    cout << calc.add(1, 2, 3) << endl;
    
    int arr[] = {1, 2, 3, 4, 5};
    cout << calc.add(arr, 5) << endl;
}

// ========== const 메서드 ==========

class Counter {
private:
    mutable int count;  // mutable: const 메서드에서도 수정 가능
    int maxCount;
    
public:
    Counter(int max = 100) : count(0), maxCount(max) {}
    
    void increment() {
        if (count < maxCount) {
            count++;
        }
    }
    
    int getCount() const {
        // const 메서드: 객체를 수정하지 않음
        return count;
    }
    
    void reset() {
        count = 0;
    }
    
    // mutable 멤버는 const 메서드에서도 수정 가능
    int getCountWithLog() const {
        // count++;  // 일반 멤버는 수정 불가
        // 하지만 mutable이면 가능 (예시용, 실제로는 로깅 등에 사용)
        return count;
    }
};

void constMethods() {
    cout << "\n=== const 메서드 ===" << endl;
    
    Counter counter(50);
    counter.increment();
    counter.increment();
    
    const Counter constCounter(100);
    // constCounter.increment();  // 오류!
    cout << "카운트: " << constCounter.getCount() << endl;
}

// ========== 인라인 메서드 ==========

class MathHelper {
public:
    // 클래스 내부 정의: 자동으로 인라인 고려
    int square(int x) {
        return x * x;
    }
    
    // inline 명시
    inline int cube(int x) {
        return x * x * x;
    }
    
    // 외부 정의
    double power(double base, int exponent);
};

// 외부 정의 (인라인 가능)
inline double MathHelper::power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

void inlineMethods() {
    cout << "\n=== 인라인 메서드 ===" << endl;
    
    MathHelper math;
    cout << "square(5) = " << math.square(5) << endl;
    cout << "cube(3) = " << math.cube(3) << endl;
    cout << "power(2, 10) = " << math.power(2, 10) << endl;
}

// ========== 정적 메서드 ==========

class StringUtils {
public:
    // 정적 메서드: 객체 없이 호출 가능
    static string toUpper(string str) {
        for (char& c : str) {
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
            }
        }
        return str;
    }
    
    static string toLower(string str) {
        for (char& c : str) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
        }
        return str;
    }
    
    static bool isEmpty(const string& str) {
        return str.empty();
    }
};

void staticMethods() {
    cout << "\n=== 정적 메서드 ===" << endl;
    
    // 객체 없이 호출
    cout << "toUpper(\"hello\") = " << StringUtils::toUpper("hello") << endl;
    cout << "toLower(\"WORLD\") = " << StringUtils::toLower("WORLD") << endl;
    cout << "isEmpty(\"\") = " << std::boolalpha 
         << StringUtils::isEmpty("") << endl;
}

// ========== 메서드 체이닝 ==========

class StringBuilder {
private:
    string text;
    
public:
    // 참조자 반환으로 체이닝 가능
    StringBuilder& append(const string& str) {
        text += str;
        return *this;  // 자기 자신 반환
    }
    
    StringBuilder& append(int num) {
        text += std::to_string(num);
        return *this;
    }
    
    StringBuilder& clear() {
        text.clear();
        return *this;
    }
    
    string toString() const {
        return text;
    }
};

void methodChaining() {
    cout << "\n=== 메서드 체이닝 ===" << endl;
    
    StringBuilder sb;
    sb.append("Hello").append(" ").append("World").append(" ").append(2024);
    cout << "결과: " << sb.toString() << endl;
    
    sb.clear().append("새로운").append(" ").append("텍스트");
    cout << "결과: " << sb.toString() << endl;
}

// ========== 재귀 메서드 ==========

class MathRecursive {
public:
    // 팩토리얼 (재귀)
    int factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }
    
    // 피보나치 수열 (재귀)
    int fibonacci(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
    // 거듭제곱 (재귀)
    double power(double base, int exponent) {
        if (exponent == 0) {
            return 1.0;
        }
        if (exponent < 0) {
            return 1.0 / power(base, -exponent);
        }
        return base * power(base, exponent - 1);
    }
};

void recursiveMethods() {
    cout << "\n=== 재귀 메서드 ===" << endl;
    
    MathRecursive math;
    cout << "factorial(5) = " << math.factorial(5) << endl;
    cout << "fibonacci(10) = " << math.fibonacci(10) << endl;
    cout << "power(2, 8) = " << math.power(2, 8) << endl;
}

// ========== 템플릿 메서드 ==========

class ArrayUtils {
public:
    // 템플릿 메서드
    template<typename T>
    static T findMax(T arr[], int size) {
        T max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
    
    template<typename T>
    static void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
};

void templateMethods() {
    cout << "\n=== 템플릿 메서드 ===" << endl;
    
    int intArr[] = {3, 7, 2, 9, 1};
    cout << "정수 배열 최댓값: " << ArrayUtils::findMax(intArr, 5) << endl;
    
    double doubleArr[] = {3.14, 2.71, 1.41, 1.73};
    cout << "실수 배열 최댓값: " << ArrayUtils::findMax(doubleArr, 4) << endl;
    
    int a = 10, b = 20;
    ArrayUtils::swap(a, b);
    cout << "swap 후: a=" << a << ", b=" << b << endl;
}

// ========== 가상 메서드 (미리보기) ==========

class Shape {
public:
    // 가상 함수 (나중에 자세히 학습)
    virtual double getArea() const {
        return 0.0;
    }
    
    virtual void draw() const {
        cout << "도형 그리기" << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
    
    void draw() const override {
        cout << "원 그리기 (반지름: " << radius << ")" << endl;
    }
};

void virtualMethods() {
    cout << "\n=== 가상 메서드 미리보기 ===" << endl;
    
    Circle circle(5.0);
    cout << "원의 넓이: " << circle.getArea() << endl;
    circle.draw();
}

int main() {
    basicMemberMethods();
    methodOverloading();
    constMethods();
    inlineMethods();
    staticMethods();
    methodChaining();
    recursiveMethods();
    templateMethods();
    virtualMethods();
    
    return 0;
}

/*
 * 멤버 메서드 핵심 정리
 * 
 * 1. 개념
 *    - 클래스 내부에 정의된 함수
 *    - 멤버 변수를 조작하는 기능 제공
 *    - 객체의 행동(behavior)을 정의
 * 
 * 2. 메서드 종류
 *    - 일반 메서드: 객체를 통해 호출
 *    - 정적 메서드: 클래스명::메서드로 호출
 *    - const 메서드: 객체를 수정하지 않음
 *    - 가상 메서드: 다형성 구현
 * 
 * 3. Getter/Setter 패턴
 *    - Getter: private 멤버 읽기
 *    - Setter: private 멤버 쓰기 (유효성 검사 가능)
 * 
 * 4. 메서드 오버로딩
 *    - 같은 이름, 다른 매개변수
 *    - 타입에 따라 자동 선택
 * 
 * 5. const 메서드
 *    - 객체를 수정하지 않음을 보장
 *    - const 객체에서 호출 가능
 *    - const 키워드를 함수 뒤에 붙임
 * 
 * 6. 인라인 메서드
 *    - 작은 함수는 인라인화 고려
 *    - 클래스 내부 정의는 자동 인라인 고려
 * 
 * 7. 메서드 체이닝
 *    - 참조자 반환으로 연속 호출
 *    - 유창한 인터페이스 제공
 * 
 * 8. 템플릿 메서드
 *    - 타입에 독립적인 메서드
 *    - 제네릭 프로그래밍
 * 
 * 9. 가상 메서드
 *    - 다형성 구현
 *    - 파생 클래스에서 오버라이딩
 *    - virtual 키워드 사용
 */

