/*
 * 13_constructor.cpp
 * 
 * 생성자(Constructor)와 소멸자(Destructor)
 * - 객체 생성 시 자동 호출되는 생성자
 * - 객체 소멸 시 자동 호출되는 소멸자
 * - 초기화 리스트와 다양한 생성자 패턴
 */

#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

// ========== 기본 생성자 ==========

class Person {
private:
    string name;
    int age;
    
public:
    // 기본 생성자 (매개변수 없음)
    Person() {
        name = "Unknown";
        age = 0;
        cout << "기본 생성자 호출" << endl;
    }
    
    // 매개변수 있는 생성자
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "매개변수 생성자 호출: " << name << endl;
    }
    
    void display() const {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

void basicConstructor() {
    cout << "=== 기본 생성자 ===" << endl;
    
    Person p1;  // 기본 생성자 호출
    p1.display();
    
    Person p2("홍길동", 25);  // 매개변수 생성자 호출
    p2.display();
}

// ========== 초기화 리스트 ==========

class Point {
private:
    int x;
    int y;
    const int id;  // const 멤버는 초기화 리스트로만 초기화 가능
    
public:
    // 초기화 리스트 사용 (권장!)
    Point(int xVal, int yVal, int idVal) : x(xVal), y(yVal), id(idVal) {
        cout << "Point 생성: (" << x << ", " << y << "), ID: " << id << endl;
    }
    
    // 기본 생성자
    Point() : x(0), y(0), id(0) {
        cout << "Point 기본 생성자" << endl;
    }
    
    void display() const {
        cout << "(" << x << ", " << y << "), ID: " << id << endl;
    }
};

void initializationList() {
    cout << "\n=== 초기화 리스트 ===" << endl;
    
    Point p1(10, 20, 1);
    Point p2;  // 기본 생성자
    p1.display();
    p2.display();
}

// ========== 복사 생성자 ==========

class Student {
private:
    string name;
    int* scores;  // 동적 할당
    int numScores;
    
public:
    // 일반 생성자
    Student(string n, int* s, int num) : name(n), numScores(num) {
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = s[i];
        }
        cout << "일반 생성자: " << name << endl;
    }
    
    // 복사 생성자
    Student(const Student& other) : name(other.name), numScores(other.numScores) {
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = other.scores[i];
        }
        cout << "복사 생성자: " << name << endl;
    }
    
    // 소멸자
    ~Student() {
        delete[] scores;
        cout << "소멸자 호출: " << name << endl;
    }
    
    void display() const {
        cout << name << "의 점수: ";
        for (int i = 0; i < numScores; i++) {
            cout << scores[i] << " ";
        }
        cout << endl;
    }
    
    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] scores;
            name = other.name;
            numScores = other.numScores;
            scores = new int[numScores];
            for (int i = 0; i < numScores; i++) {
                scores[i] = other.scores[i];
            }
        }
        return *this;
    }
};

void copyConstructor() {
    cout << "\n=== 복사 생성자 ===" << endl;
    
    int scores1[] = {90, 85, 95};
    Student s1("홍길동", scores1, 3);
    
    Student s2(s1);  // 복사 생성자 호출
    s1.display();
    s2.display();
}

// ========== 소멸자 ==========

class Resource {
private:
    string name;
    int* data;
    
public:
    Resource(string n, int size) : name(n) {
        data = new int[size];
        cout << "리소스 생성: " << name << endl;
    }
    
    // 소멸자: ~클래스명()
    ~Resource() {
        delete[] data;
        cout << "리소스 해제: " << name << endl;
    }
    
    void use() {
        cout << "리소스 사용: " << name << endl;
    }
};

void destructor() {
    cout << "\n=== 소멸자 ===" << endl;
    
    {
        Resource res("리소스1", 100);
        res.use();
    }  // 여기서 소멸자 자동 호출
    
    cout << "블록 종료" << endl;
}

// ========== 생성자 오버로딩 ==========

class Rectangle {
private:
    double width;
    double height;
    
public:
    // 기본 생성자
    Rectangle() : width(1.0), height(1.0) {
        cout << "기본 생성자: 1x1" << endl;
    }
    
    // 정사각형 생성자
    Rectangle(double size) : width(size), height(size) {
        cout << "정사각형 생성자: " << size << "x" << size << endl;
    }
    
    // 일반 사각형 생성자
    Rectangle(double w, double h) : width(w), height(h) {
        cout << "사각형 생성자: " << w << "x" << h << endl;
    }
    
    double getArea() const {
        return width * height;
    }
};

void constructorOverloading() {
    cout << "\n=== 생성자 오버로딩 ===" << endl;
    
    Rectangle r1;           // 기본 생성자
    Rectangle r2(5.0);      // 정사각형
    Rectangle r3(10.0, 5.0); // 일반 사각형
    
    cout << "r1 넓이: " << r1.getArea() << endl;
    cout << "r2 넓이: " << r2.getArea() << endl;
    cout << "r3 넓이: " << r3.getArea() << endl;
}

// ========== 위임 생성자 (C++11) ==========

class Time {
private:
    int hour;
    int minute;
    int second;
    
public:
    // 위임 생성자: 다른 생성자를 호출
    Time() : Time(0, 0, 0) {
        cout << "기본 시간: 00:00:00" << endl;
    }
    
    Time(int h) : Time(h, 0, 0) {
        cout << "시간만 지정: " << h << ":00:00" << endl;
    }
    
    // 실제 초기화를 수행하는 생성자
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {
        cout << "전체 시간: " << hour << ":" << minute << ":" << second << endl;
    }
};

void delegatingConstructor() {
    cout << "\n=== 위임 생성자 ===" << endl;
    
    Time t1;
    Time t2(10);
    Time t3(10, 30, 45);
}

// ========== 기본 생성자와 명시적 생성자 ==========

class Number {
private:
    int value;
    
public:
    // 명시적 생성자: 암시적 변환 방지
    explicit Number(int v) : value(v) {
        cout << "Number 생성: " << value << endl;
    }
    
    int getValue() const {
        return value;
    }
};

void explicitConstructor() {
    cout << "\n=== explicit 생성자 ===" << endl;
    
    Number n1(10);  // OK
    // Number n2 = 20;  // 오류! explicit 때문에 암시적 변환 불가
    Number n2 = Number(20);  // OK: 명시적 변환
}

// ========== 생성자와 예외 처리 ==========

class SafeArray {
private:
    int* data;
    int size;
    
public:
    SafeArray(int s) : size(s) {
        if (size <= 0) {
            throw std::invalid_argument("크기는 0보다 커야 합니다");
        }
        data = new int[size];
        cout << "SafeArray 생성: 크기 " << size << endl;
    }
    
    ~SafeArray() {
        delete[] data;
        cout << "SafeArray 소멸" << endl;
    }
    
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("인덱스 범위 초과");
        }
        return data[index];
    }
};

void constructorException() {
    cout << "\n=== 생성자와 예외 처리 ===" << endl;
    
    try {
        SafeArray arr(5);
        arr[0] = 10;
        arr[1] = 20;
        cout << "arr[0] = " << arr[0] << endl;
        
        // SafeArray bad(-1);  // 예외 발생
    }
    catch (const std::exception& e) {
        cout << "예외: " << e.what() << endl;
    }
}

// ========== 정적 멤버 초기화 ==========

class Counter {
private:
    static int totalCount;  // 정적 멤버 변수
    
public:
    Counter() {
        totalCount++;
        cout << "Counter 생성. 총 개수: " << totalCount << endl;
    }
    
    ~Counter() {
        totalCount--;
        cout << "Counter 소멸. 총 개수: " << totalCount << endl;
    }
    
    static int getTotalCount() {
        return totalCount;
    }
};

// 정적 멤버 변수 정의 및 초기화
int Counter::totalCount = 0;

void staticMemberInit() {
    cout << "\n=== 정적 멤버 초기화 ===" << endl;
    
    Counter c1;
    Counter c2;
    Counter c3;
    
    cout << "총 Counter 개수: " << Counter::getTotalCount() << endl;
}

// ========== 생성자 호출 순서 ==========

class Base {
public:
    Base() {
        cout << "Base 생성자" << endl;
    }
    
    ~Base() {
        cout << "Base 소멸자" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived 생성자" << endl;
    }
    
    ~Derived() {
        cout << "Derived 소멸자" << endl;
    }
};

void constructorOrder() {
    cout << "\n=== 생성자/소멸자 호출 순서 ===" << endl;
    
    Derived d;  // Base 생성자 → Derived 생성자
    // 소멸자: Derived 소멸자 → Base 소멸자 (역순)
}

int main() {
    basicConstructor();
    initializationList();
    copyConstructor();
    destructor();
    constructorOverloading();
    delegatingConstructor();
    explicitConstructor();
    constructorException();
    staticMemberInit();
    constructorOrder();
    
    return 0;
}

/*
 * 생성자와 소멸자 핵심 정리
 * 
 * 1. 생성자 (Constructor)
 *    - 객체 생성 시 자동 호출
 *    - 클래스명과 동일한 이름
 *    - 반환 타입 없음
 *    - 오버로딩 가능
 * 
 * 2. 소멸자 (Destructor)
 *    - 객체 소멸 시 자동 호출
 *    - ~클래스명()
 *    - 매개변수 없음
 *    - 오버로딩 불가
 *    - 동적 할당 메모리 해제에 사용
 * 
 * 3. 초기화 리스트
 *    - 생성자: 멤버(값), 멤버(값) 형식
 *    - const 멤버 초기화에 필수
 *    - 참조자 멤버 초기화에 필수
 *    - 성능상 이점 (대입보다 효율적)
 * 
 * 4. 복사 생성자
 *    - 같은 타입의 객체로 초기화
 *    - 깊은 복사 vs 얕은 복사
 *    - 동적 할당 시 주의 필요
 * 
 * 5. 생성자 종류
 *    - 기본 생성자: 매개변수 없음
 *    - 매개변수 생성자: 초기값 전달
 *    - 복사 생성자: 객체 복사
 *    - 위임 생성자: 다른 생성자 호출
 * 
 * 6. 생성자 호출 순서
 *    - 부모 클래스 → 자식 클래스
 *    - 멤버 변수는 선언 순서대로
 * 
 * 7. 소멸자 호출 순서
 *    - 자식 클래스 → 부모 클래스 (역순)
 * 
 * 8. explicit 키워드
 *    - 암시적 변환 방지
 *    - 명시적 생성만 허용
 * 
 * 9. RAII 패턴
 *    - Resource Acquisition Is Initialization
 *    - 생성자에서 획득, 소멸자에서 해제
 *    - 예외 안전성 보장
 * 
 * 10. 주의사항
 *     - 동적 할당은 반드시 소멸자에서 해제
 *     - 복사 생성자와 대입 연산자 구현
 *     - 얕은 복사 문제 주의
 */

