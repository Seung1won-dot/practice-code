/*
 * 11_class_basic.cpp
 * 
 * 클래스 기초
 * - 클래스 선언과 객체 생성
 * - 접근 지정자 (public, private, protected)
 * - 멤버 변수와 멤버 함수
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// ========== 기본 클래스 정의 ==========

class Person {
    // private: 기본 접근 지정자 (명시하지 않으면 private)
    string name;
    int age;
    
public:
    // public: 외부에서 접근 가능
    void setName(string n) {
        name = n;
    }
    
    void setAge(int a) {
        if (a > 0) {  // 유효성 검사
            age = a;
        }
    }
    
    void display() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

void basicClass() {
    cout << "=== 기본 클래스 ===" << endl;
    
    Person person1;  // 객체 생성
    person1.setName("홍길동");
    person1.setAge(25);
    person1.display();
    
    // person1.name = "김철수";  // 오류! private 멤버에 직접 접근 불가
}

// ========== 접근 지정자 ==========

class BankAccount {
private:
    // private: 클래스 내부에서만 접근 가능
    double balance;
    string accountNumber;
    
protected:
    // protected: 클래스 내부와 파생 클래스에서 접근 가능
    string ownerName;
    
public:
    // public: 어디서나 접근 가능
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << "원 입금. 잔액: " << balance << "원" << endl;
        }
    }
    
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << "원 출금. 잔액: " << balance << "원" << endl;
        } else {
            cout << "출금 실패!" << endl;
        }
    }
    
    double getBalance() {
        return balance;  // private 멤버를 public 메서드로 접근
    }
    
    void setOwner(string name) {
        ownerName = name;  // protected 멤버 접근
    }
};

void accessSpecifiers() {
    cout << "\n=== 접근 지정자 ===" << endl;
    
    BankAccount account;
    account.deposit(10000);
    account.withdraw(3000);
    cout << "현재 잔액: " << account.getBalance() << "원" << endl;
    
    // account.balance = 1000000;  // 오류! private 멤버 접근 불가
    // account.ownerName = "홍길동";  // 오류! protected 멤버 접근 불가
}

// ========== 구조체 vs 클래스 ==========

// 구조체: 기본 접근 지정자가 public
struct Point {
    int x;  // public (기본)
    int y;  // public (기본)
    
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};

// 클래스: 기본 접근 지정자가 private
class Point2 {
    int x;  // private (기본)
    int y;  // private (기본)
    
public:
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() const { return x; }
    int getY() const { return y; }
};

void structVsClass() {
    cout << "\n=== 구조체 vs 클래스 ===" << endl;
    
    // 구조체: 직접 접근 가능
    Point p1;
    p1.x = 10;
    p1.y = 20;
    p1.move(5, 5);
    cout << "Point: (" << p1.x << ", " << p1.y << ")" << endl;
    
    // 클래스: 메서드를 통한 접근
    Point2 p2;
    p2.setX(10);
    p2.setY(20);
    cout << "Point2: (" << p2.getX() << ", " << p2.getY() << ")" << endl;
    // p2.x = 10;  // 오류! private 멤버 접근 불가
}

// ========== 인라인 멤버 함수 ==========

class Calculator {
public:
    // 클래스 내부에 정의된 함수는 자동으로 인라인 고려
    int add(int a, int b) {
        return a + b;
    }
    
    // inline 키워드 명시 가능
    inline int multiply(int a, int b) {
        return a * b;
    }
    
    // 선언만 하고 외부에 정의
    int subtract(int a, int b);
};

// 외부 정의
int Calculator::subtract(int a, int b) {
    return a - b;
}

void inlineMemberFunction() {
    cout << "\n=== 인라인 멤버 함수 ===" << endl;
    Calculator calc;
    cout << "add(10, 20) = " << calc.add(10, 20) << endl;
    cout << "multiply(5, 6) = " << calc.multiply(5, 6) << endl;
    cout << "subtract(20, 10) = " << calc.subtract(20, 10) << endl;
}

// ========== const 멤버 함수 ==========

class Counter {
private:
    int count;
    
public:
    Counter() : count(0) {}
    
    void increment() {
        count++;  // 비상수 멤버 함수: 객체 수정 가능
    }
    
    int getCount() const {
        // const 멤버 함수: 객체를 수정하지 않음
        // count++;  // 오류! const 함수에서는 수정 불가
        return count;
    }
    
    void reset() {
        count = 0;
    }
};

void constMemberFunction() {
    cout << "\n=== const 멤버 함수 ===" << endl;
    Counter counter;
    
    counter.increment();
    counter.increment();
    cout << "카운트: " << counter.getCount() << endl;
    
    const Counter constCounter;  // const 객체
    // constCounter.increment();  // 오류! const 객체는 비상수 함수 호출 불가
    cout << "const 카운트: " << constCounter.getCount() << endl;  // OK
}

// ========== 정적 멤버 (Static Member) ==========

class MathUtils {
public:
    // 정적 멤버 함수: 객체 없이 호출 가능
    static int add(int a, int b) {
        return a + b;
    }
    
    static double pi() {
        return 3.14159;
    }
    
    // 정적 멤버 변수 (선언)
    static int count;
};

// 정적 멤버 변수 정의 (클래스 외부)
int MathUtils::count = 0;

void staticMember() {
    cout << "\n=== 정적 멤버 ===" << endl;
    
    // 객체 없이 호출
    cout << "MathUtils::add(10, 20) = " << MathUtils::add(10, 20) << endl;
    cout << "MathUtils::pi() = " << MathUtils::pi() << endl;
    
    // 객체를 통해서도 호출 가능
    MathUtils math;
    cout << "math.add(5, 3) = " << math.add(5, 3) << endl;
    
    // 정적 멤버 변수
    MathUtils::count = 10;
    cout << "MathUtils::count = " << MathUtils::count << endl;
}

// ========== 객체 배열 ==========

void objectArray() {
    cout << "\n=== 객체 배열 ===" << endl;
    
    Person people[3];  // 객체 배열
    
    people[0].setName("홍길동");
    people[0].setAge(25);
    
    people[1].setName("김철수");
    people[1].setAge(30);
    
    people[2].setName("이영희");
    people[2].setAge(28);
    
    for (int i = 0; i < 3; i++) {
        people[i].display();
    }
}

// ========== 포인터로 객체 사용 ==========

void objectPointer() {
    cout << "\n=== 포인터로 객체 사용 ===" << endl;
    
    Person* ptr = new Person();  // 동적 할당
    
    ptr->setName("박민수");  // -> 연산자 사용
    ptr->setAge(35);
    ptr->display();
    
    delete ptr;
    ptr = nullptr;
}

// ========== 참조자로 객체 사용 ==========

void printPerson(Person& person) {
    person.display();
}

void objectReference() {
    cout << "\n=== 참조자로 객체 사용 ===" << endl;
    
    Person person;
    person.setName("최지영");
    person.setAge(22);
    
    printPerson(person);  // 참조자로 전달
}

int main() {
    basicClass();
    accessSpecifiers();
    structVsClass();
    inlineMemberFunction();
    constMemberFunction();
    staticMember();
    objectArray();
    objectPointer();
    objectReference();
    
    return 0;
}

/*
 * 클래스 기초 핵심 정리
 * 
 * 1. 클래스 정의
 *    class 클래스명 {
 *        접근지정자:
 *            멤버;
 *    };
 * 
 * 2. 접근 지정자
 *    - private: 클래스 내부만 (기본값)
 *    - protected: 클래스 내부 + 파생 클래스
 *    - public: 어디서나 접근 가능
 * 
 * 3. 객체 생성
 *    클래스명 객체명;  // 스택에 생성
 *    클래스명* ptr = new 클래스명();  // 힙에 생성
 * 
 * 4. 멤버 접근
 *    객체.멤버        // 직접 접근
 *    포인터->멤버     // 포인터를 통한 접근
 * 
 * 5. 구조체 vs 클래스
 *    - 구조체: 기본 접근 지정자 public
 *    - 클래스: 기본 접근 지정자 private
 *    - 기능적으로는 동일 (C++에서는)
 * 
 * 6. const 멤버 함수
 *    - 객체를 수정하지 않음을 보장
 *    - const 객체에서 호출 가능
 *    - const 키워드를 함수 뒤에 붙임
 * 
 * 7. 정적 멤버
 *    - static 키워드 사용
 *    - 객체 없이 클래스명::멤버로 접근
 *    - 모든 객체가 공유
 * 
 * 8. 캡슐화
 *    - 데이터를 private으로 보호
 *    - public 메서드로 접근 제어
 *    - 정보 은닉 구현
 */

