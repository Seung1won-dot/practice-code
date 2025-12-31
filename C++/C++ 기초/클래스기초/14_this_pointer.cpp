/*
 * 14_this_pointer.cpp
 * 
 * this 포인터
 * - 객체 자신을 가리키는 포인터
 * - 멤버 함수 내에서 사용
 * - 메서드 체이닝과 자기 참조에 활용
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// ========== this 포인터 기본 ==========

class Person {
private:
    string name;
    int age;
    
public:
    // this를 사용하여 매개변수와 멤버 변수 구분
    void setName(string name) {
        this->name = name;  // this->name은 멤버 변수, name은 매개변수
    }
    
    void setAge(int age) {
        this->age = age;  // 명확하게 멤버 변수임을 표시
    }
    
    // this를 명시적으로 사용하지 않아도 됨 (컴파일러가 자동 처리)
    void display() {
        cout << "이름: " << name << ", 나이: " << age << endl;
        // 위 코드는 실제로는 다음과 같음:
        // cout << "이름: " << this->name << ", 나이: " << this->age << endl;
    }
    
    Person* getThis() {
        return this;  // 자기 자신의 포인터 반환
    }
};

void basicThis() {
    cout << "=== this 포인터 기본 ===" << endl;
    
    Person p1;
    p1.setName("홍길동");
    p1.setAge(25);
    p1.display();
    
    Person* ptr = p1.getThis();
    cout << "this 포인터 주소: " << ptr << endl;
}

// ========== 매개변수와 멤버 변수 이름이 같을 때 ==========

class Point {
private:
    int x;
    int y;
    
public:
    // 매개변수 이름이 멤버 변수와 같을 때 this 사용
    void setX(int x) {
        this->x = x;  // this->x는 멤버 변수, x는 매개변수
    }
    
    void setY(int y) {
        this->y = y;
    }
    
    // 다른 이름 사용 (this 불필요)
    void setCoordinates(int newX, int newY) {
        x = newX;  // this-> 생략 가능
        y = newY;
    }
    
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

void nameCollision() {
    cout << "\n=== 이름 충돌 해결 ===" << endl;
    
    Point p;
    p.setX(10);
    p.setY(20);
    p.display();
    
    p.setCoordinates(30, 40);
    p.display();
}

// ========== 메서드 체이닝 ==========

class StringBuilder {
private:
    string text;
    
public:
    // this를 반환하여 메서드 체이닝 가능
    StringBuilder& append(const string& str) {
        text += str;
        return *this;  // 자기 자신의 참조자 반환
    }
    
    StringBuilder& append(int num) {
        text += std::to_string(num);
        return *this;
    }
    
    StringBuilder& clear() {
        text.clear();
        return *this;
    }
    
    StringBuilder& toUpper() {
        for (char& c : text) {
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
            }
        }
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
    
    sb.clear().append("새로운").append(" ").append("텍스트").toUpper();
    cout << "결과: " << sb.toString() << endl;
}

// ========== 자기 자신과의 비교 ==========

class Student {
private:
    string name;
    int score;
    
public:
    Student(string n, int s) : name(n), score(s) {}
    
    // 자기 자신과의 비교 (대입 연산자 등에서 사용)
    bool isSame(const Student& other) const {
        return this == &other;  // 같은 객체인지 포인터 비교
    }
    
    bool operator==(const Student& other) const {
        if (this == &other) {
            return true;  // 같은 객체면 true
        }
        return name == other.name && score == other.score;
    }
    
    // 대입 연산자 (자기 할당 체크)
    Student& operator=(const Student& other) {
        if (this != &other) {  // 자기 할당 방지
            name = other.name;
            score = other.score;
        }
        return *this;
    }
    
    void display() const {
        cout << name << ": " << score << endl;
    }
};

void selfComparison() {
    cout << "\n=== 자기 자신과의 비교 ===" << endl;
    
    Student s1("홍길동", 90);
    Student s2("홍길동", 90);
    Student s3 = s1;  // 복사
    
    cout << "s1 == s2: " << std::boolalpha << (s1 == s2) << endl;
    cout << "s1.isSame(s2): " << s1.isSame(s2) << endl;
    cout << "s1.isSame(s3): " << s1.isSame(s3) << endl;
}

// ========== this를 다른 객체에 전달 ==========

class Manager;

class Employee {
private:
    string name;
    Manager* manager;
    
public:
    Employee(string n) : name(n), manager(nullptr) {}
    
    void setManager(Manager* mgr);
    
    void display() const {
        cout << "직원: " << name;
        if (manager) {
            cout << " (관리자 있음)";
        }
        cout << endl;
    }
};

class Manager {
private:
    string name;
    Employee* employee;
    
public:
    Manager(string n) : name(n), employee(nullptr) {}
    
    void setEmployee(Employee* emp) {
        employee = emp;
        if (emp) {
            emp->setManager(this);  // this를 전달
        }
    }
    
    void display() const {
        cout << "관리자: " << name;
        if (employee) {
            cout << " (직원 있음)";
        }
        cout << endl;
    }
};

// 전방 선언 후 정의
void Employee::setManager(Manager* mgr) {
    manager = mgr;
}

void thisPassing() {
    cout << "\n=== this 전달 ===" << endl;
    
    Manager mgr("김관리");
    Employee emp("이직원");
    
    mgr.setEmployee(&emp);
    
    mgr.display();
    emp.display();
}

// ========== const 멤버 함수에서의 this ==========

class Counter {
private:
    mutable int count;  // mutable: const 함수에서도 수정 가능
    
public:
    Counter() : count(0) {}
    
    // const 멤버 함수에서 this는 const 포인터
    int getCount() const {
        // this는 const Counter* 타입
        return this->count;  // 읽기 가능
        // this->count = 10;  // 오류! const 함수에서는 수정 불가
    }
    
    void increment() {
        // 비const 멤버 함수에서 this는 Counter* 타입
        this->count++;  // 수정 가능
    }
    
    // const 함수에서도 mutable 멤버는 수정 가능
    int getCountWithLog() const {
        // count는 mutable이므로 수정 가능 (예시)
        return count;
    }
};

void constThis() {
    cout << "\n=== const 멤버 함수에서의 this ===" << endl;
    
    Counter counter;
    counter.increment();
    counter.increment();
    
    const Counter constCounter;
    cout << "카운트: " << constCounter.getCount() << endl;
    // constCounter.increment();  // 오류!
}

// ========== this와 상속 ==========

class Base {
protected:
    int value;
    
public:
    Base(int v) : value(v) {}
    
    Base* getBaseThis() {
        return this;  // Base* 반환
    }
    
    void display() const {
        cout << "Base value: " << value << endl;
    }
};

class Derived : public Base {
public:
    Derived(int v) : Base(v) {}
    
    Derived* getDerivedThis() {
        return this;  // Derived* 반환
    }
    
    void display() const {
        cout << "Derived value: " << value << endl;
    }
};

void inheritanceThis() {
    cout << "\n=== this와 상속 ===" << endl;
    
    Derived d(100);
    d.display();
    
    Base* basePtr = d.getBaseThis();
    basePtr->display();
    
    Derived* derivedPtr = d.getDerivedThis();
    derivedPtr->display();
}

// ========== this 반환 패턴 ==========

class BankAccount {
private:
    double balance;
    
public:
    BankAccount(double initial = 0.0) : balance(initial) {}
    
    // 참조자 반환 (메서드 체이닝)
    BankAccount& deposit(double amount) {
        balance += amount;
        return *this;
    }
    
    BankAccount& withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        }
        return *this;
    }
    
    // 포인터 반환
    BankAccount* getAccount() {
        return this;
    }
    
    double getBalance() const {
        return balance;
    }
};

void returnPatterns() {
    cout << "\n=== this 반환 패턴 ===" << endl;
    
    BankAccount account(1000);
    account.deposit(500).withdraw(200).deposit(100);
    cout << "잔액: " << account.getBalance() << "원" << endl;
    
    BankAccount* ptr = account.getAccount();
    cout << "계좌 포인터를 통한 잔액: " << ptr->getBalance() << "원" << endl;
}

int main() {
    basicThis();
    nameCollision();
    methodChaining();
    selfComparison();
    thisPassing();
    constThis();
    inheritanceThis();
    returnPatterns();
    
    return 0;
}

/*
 * this 포인터 핵심 정리
 * 
 * 1. 개념
 *    - 객체 자신을 가리키는 포인터
 *    - 모든 멤버 함수에 암시적으로 전달됨
 *    - 명시적으로 사용 가능
 * 
 * 2. 사용 목적
 *    - 매개변수와 멤버 변수 이름이 같을 때 구분
 *    - 자기 자신의 주소 반환
 *    - 메서드 체이닝 (참조자 반환)
 *    - 자기 할당 체크
 * 
 * 3. 문법
 *    - this: 현재 객체의 포인터
 *    - *this: 현재 객체의 참조자
 *    - this->멤버: 멤버 접근
 * 
 * 4. const 멤버 함수
 *    - const 함수에서 this는 const 포인터
 *    - const Counter* this 형태
 *    - 객체 수정 불가
 * 
 * 5. 비const 멤버 함수
 *    - this는 일반 포인터
 *    - Counter* this 형태
 *    - 객체 수정 가능
 * 
 * 6. 메서드 체이닝
 *    - 참조자 반환: return *this;
 *    - 연속적인 메서드 호출 가능
 *    - 유창한 인터페이스 제공
 * 
 * 7. 자기 할당 체크
 *    - 대입 연산자 등에서 사용
 *    - if (this != &other) 패턴
 * 
 * 8. 주의사항
 *    - 정적 멤버 함수에는 this 없음
 *    - this는 포인터이므로 &this는 불가능
 *    - this는 rvalue (우측값)
 * 
 * 9. 실제 사용 예시
 *    - Setter 메서드
 *    - 빌더 패턴
 *    - 연산자 오버로딩
 *    - 자기 참조 구조
 */

