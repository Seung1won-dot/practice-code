/*
 * 17_polymorphism.cpp
 * 
 * 다형성 (Polymorphism)
 * - 가상 함수 (Virtual Function)
 * - 추상 클래스 (Abstract Class)
 * - 순수 가상 함수 (Pure Virtual Function)
 * - 동적 바인딩 (Dynamic Binding)
 */

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// ========== 가상 함수 기본 ==========

class Animal {
protected:
    string name;
    
public:
    Animal(string n = "동물") : name(n) {}
    
    // 가상 함수: 파생 클래스에서 재정의 가능
    virtual void makeSound() {
        cout << name << "이(가) 소리를 냅니다." << endl;
    }
    
    // 일반 함수: 오버라이딩해도 기본 클래스 버전 호출
    void eat() {
        cout << name << "이(가) 먹습니다." << endl;
    }
    
    virtual ~Animal() {  // 가상 소멸자 (중요!)
        cout << name << " 소멸" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n = "강아지") : Animal(n) {}
    
    // 가상 함수 재정의
    void makeSound() override {  // C++11: override 키워드 (권장)
        cout << name << "이(가) 멍멍 짖습니다!" << endl;
    }
    
    void eat() {  // 일반 함수 재정의 (오버라이딩)
        cout << name << "이(가) 사료를 먹습니다." << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n = "고양이") : Animal(n) {}
    
    void makeSound() override {
        cout << name << "이(가) 야옹 웁니다!" << endl;
    }
};

void virtualFunction() {
    cout << "=== 가상 함수 ===" << endl;
    
    Dog dog("뽀삐");
    Cat cat("나비");
    
    // 직접 호출
    dog.makeSound();
    cat.makeSound();
    
    cout << "\n--- 포인터를 통한 호출 ---" << endl;
    Animal* animal1 = &dog;
    Animal* animal2 = &cat;
    
    // 가상 함수: 실제 객체 타입에 따라 호출 (동적 바인딩)
    animal1->makeSound();  // Dog의 makeSound() 호출
    animal2->makeSound();  // Cat의 makeSound() 호출
    
    // 일반 함수: 포인터 타입에 따라 호출 (정적 바인딩)
    animal1->eat();  // Animal의 eat() 호출 (Dog의 eat() 아님!)
    animal2->eat();  // Animal의 eat() 호출
}

// ========== 추상 클래스 ==========

// 추상 클래스: 순수 가상 함수를 가진 클래스
class Shape {
protected:
    string name;
    
public:
    Shape(string n = "도형") : name(n) {}
    
    // 순수 가상 함수: 구현이 없음 (= 0)
    virtual double getArea() = 0;  // 파생 클래스에서 반드시 구현해야 함
    virtual double getPerimeter() = 0;
    
    // 일반 가상 함수: 기본 구현 제공
    virtual void display() {
        cout << name << " - ";
    }
    
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r = 1.0) : Shape("원"), radius(r) {}
    
    // 순수 가상 함수 구현 필수
    double getArea() override {
        return 3.14159 * radius * radius;
    }
    
    double getPerimeter() override {
        return 2 * 3.14159 * radius;
    }
    
    void display() override {
        Shape::display();
        cout << "반지름: " << radius 
             << ", 넓이: " << getArea()
             << ", 둘레: " << getPerimeter() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w = 1.0, double h = 1.0) 
        : Shape("직사각형"), width(w), height(h) {}
    
    double getArea() override {
        return width * height;
    }
    
    double getPerimeter() override {
        return 2 * (width + height);
    }
    
    void display() override {
        Shape::display();
        cout << "가로: " << width << ", 세로: " << height
             << ", 넓이: " << getArea()
             << ", 둘레: " << getPerimeter() << endl;
    }
};

void abstractClass() {
    cout << "\n=== 추상 클래스 ===" << endl;
    
    // Shape shape;  // 오류! 추상 클래스는 객체 생성 불가
    
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    
    circle.display();
    rectangle.display();
    
    // 추상 클래스 포인터로 사용
    Shape* shapes[] = {&circle, &rectangle};
    
    cout << "\n--- 다형성 활용 ---" << endl;
    for (int i = 0; i < 2; i++) {
        shapes[i]->display();
    }
}

// ========== 다형성의 실전 활용 ==========

class Employee {
protected:
    string name;
    double salary;
    
public:
    Employee(string n = "직원", double s = 0) : name(n), salary(s) {}
    
    virtual double calculatePay() = 0;  // 순수 가상 함수
    
    virtual void display() {
        cout << "이름: " << name << ", 급여: " << salary << endl;
    }
    
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
private:
    double bonus;
    
public:
    FullTimeEmployee(string n = "정규직", double s = 0, double b = 0)
        : Employee(n, s), bonus(b) {}
    
    double calculatePay() override {
        return salary + bonus;
    }
    
    void display() override {
        Employee::display();
        cout << "  보너스: " << bonus << ", 실수령액: " << calculatePay() << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hours;
    double hourlyRate;
    
public:
    PartTimeEmployee(string n = "알바", int h = 0, double hr = 0)
        : Employee(n, 0), hours(h), hourlyRate(hr) {}
    
    double calculatePay() override {
        return hours * hourlyRate;
    }
    
    void display() override {
        cout << "이름: " << name << ", 근무시간: " << hours 
             << ", 시급: " << hourlyRate 
             << ", 실수령액: " << calculatePay() << endl;
    }
};

void polymorphismExample() {
    cout << "\n=== 다형성 실전 예제 ===" << endl;
    
    vector<Employee*> employees;
    
    employees.push_back(new FullTimeEmployee("홍길동", 3000000, 500000));
    employees.push_back(new PartTimeEmployee("김철수", 20, 15000));
    employees.push_back(new FullTimeEmployee("이영희", 2500000, 300000));
    employees.push_back(new PartTimeEmployee("박민수", 15, 12000));
    
    double totalPay = 0;
    for (Employee* emp : employees) {
        emp->display();
        totalPay += emp->calculatePay();
    }
    
    cout << "\n총 급여 지출: " << totalPay << "원" << endl;
    
    // 메모리 해제
    for (Employee* emp : employees) {
        delete emp;
    }
}

// ========== 가상 소멸자의 중요성 ==========

class Base {
public:
    Base() {
        cout << "Base 생성자" << endl;
    }
    
    // 가상 소멸자가 없으면 파생 클래스 소멸자가 호출되지 않음!
    virtual ~Base() {
        cout << "Base 소멸자" << endl;
    }
};

class Derived : public Base {
private:
    int* data;
    
public:
    Derived() : data(new int[100]) {
        cout << "Derived 생성자" << endl;
    }
    
    ~Derived() {
        delete[] data;
        cout << "Derived 소멸자" << endl;
    }
};

void virtualDestructor() {
    cout << "\n=== 가상 소멸자 ===" << endl;
    
    cout << "Base 포인터로 Derived 객체 생성:" << endl;
    Base* ptr = new Derived();
    
    cout << "delete 호출:" << endl;
    delete ptr;  // 가상 소멸자가 있어야 Derived 소멸자도 호출됨
}

// ========== final 키워드 (C++11) ==========

class BaseClass {
public:
    virtual void func() {
        cout << "BaseClass::func()" << endl;
    }
};

class DerivedClass : public BaseClass {
public:
    // final: 더 이상 오버라이딩 불가
    void func() override final {
        cout << "DerivedClass::func()" << endl;
    }
};

// class FurtherDerived : public DerivedClass {
// public:
//     void func() override {  // 오류! final로 선언되어 오버라이딩 불가
//         cout << "FurtherDerived::func()" << endl;
//     }
// };

void finalKeyword() {
    cout << "\n=== final 키워드 ===" << endl;
    DerivedClass obj;
    obj.func();
}

int main() {
    virtualFunction();
    abstractClass();
    polymorphismExample();
    virtualDestructor();
    finalKeyword();
    
    return 0;
}

/*
 * 다형성 핵심 정리
 * 
 * 1. 다형성의 개념
 *    - 같은 인터페이스로 다른 동작 수행
 *    - "하나의 인터페이스, 여러 구현"
 *    - 런타임에 실제 객체 타입에 따라 함수 호출
 * 
 * 2. 가상 함수 (Virtual Function)
 *    - virtual 키워드 사용
 *    - 파생 클래스에서 재정의 가능
 *    - 동적 바인딩 (런타임에 결정)
 *    - 포인터나 참조자를 통한 호출 시 중요
 * 
 * 3. 순수 가상 함수 (Pure Virtual Function)
 *    - virtual 함수() = 0;
 *    - 구현이 없음
 *    - 파생 클래스에서 반드시 구현해야 함
 * 
 * 4. 추상 클래스 (Abstract Class)
 *    - 순수 가상 함수를 가진 클래스
 *    - 객체 생성 불가
 *    - 인터페이스 역할
 *    - 포인터/참조자로만 사용
 * 
 * 5. override 키워드 (C++11)
 *    - 함수 오버라이딩 명시
 *    - 컴파일 타임에 오류 검출
 *    - 가독성 향상
 * 
 * 6. final 키워드 (C++11)
 *    - 더 이상 오버라이딩 불가
 *    - 클래스에도 사용 가능 (상속 불가)
 * 
 * 7. 가상 소멸자
 *    - 기본 클래스에 virtual ~클래스명() 필수!
 *    - 파생 클래스 소멸자가 제대로 호출되도록 보장
 *    - 메모리 누수 방지
 * 
 * 8. 정적 vs 동적 바인딩
 *    - 정적 바인딩: 컴파일 타임에 결정 (일반 함수)
 *    - 동적 바인딩: 런타임에 결정 (가상 함수)
 * 
 * 9. 다형성의 장점
 *    - 코드 재사용성 향상
 *    - 유지보수 용이
 *    - 확장성 향상
 *    - 인터페이스와 구현 분리
 */

