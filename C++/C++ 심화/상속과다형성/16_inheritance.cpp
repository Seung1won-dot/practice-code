/*
 * 16_inheritance.cpp
 * 
 * 상속 (Inheritance)
 * - 클래스 간의 상속 관계
 * - 기본 클래스와 파생 클래스
 * - 접근 지정자와 상속
 * - 생성자/소멸자 호출 순서
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// ========== 기본 상속 ==========

// 기본 클래스 (Base Class)
class Animal {
protected:
    string name;
    int age;
    
public:
    Animal(string n = "동물", int a = 0) : name(n), age(a) {
        cout << "Animal 생성자 호출: " << name << endl;
    }
    
    ~Animal() {
        cout << "Animal 소멸자 호출: " << name << endl;
    }
    
    void eat() {
        cout << name << "이(가) 먹고 있습니다." << endl;
    }
    
    void sleep() {
        cout << name << "이(가) 잠을 자고 있습니다." << endl;
    }
    
    void display() {
        cout << "이름: " << name << ", 나이: " << age << "세" << endl;
    }
};

// 파생 클래스 (Derived Class) - public 상속
class Dog : public Animal {
private:
    string breed;  // 개만의 특별한 속성
    
public:
    Dog(string n = "강아지", int a = 0, string b = "믹스") 
        : Animal(n, a), breed(b) {
        cout << "Dog 생성자 호출: " << name << endl;
    }
    
    ~Dog() {
        cout << "Dog 소멸자 호출: " << name << endl;
    }
    
    void bark() {
        cout << name << "이(가) 멍멍 짖습니다!" << endl;
    }
    
    void display() {  // 함수 오버라이딩 (재정의)
        Animal::display();  // 기본 클래스의 함수 호출
        cout << "품종: " << breed << endl;
    }
};

void basicInheritance() {
    cout << "=== 기본 상속 ===" << endl;
    
    Dog myDog("뽀삐", 3, "골든 리트리버");
    myDog.eat();      // 상속받은 함수
    myDog.sleep();    // 상속받은 함수
    myDog.bark();     // Dog만의 함수
    myDog.display();  // 오버라이딩된 함수
    
    cout << "\n--- Animal 포인터로 사용 ---" << endl;
    Animal* animalPtr = &myDog;
    animalPtr->eat();
    animalPtr->sleep();
    // animalPtr->bark();  // 오류! Animal에는 bark()가 없음
}

// ========== 접근 지정자와 상속 ==========

class Base {
private:
    int privateVar;
    
protected:
    int protectedVar;
    
public:
    int publicVar;
    
    Base() : privateVar(1), protectedVar(2), publicVar(3) {}
};

// public 상속: 접근 권한 유지
class PublicDerived : public Base {
public:
    void test() {
        // privateVar = 10;  // 오류! private은 접근 불가
        protectedVar = 20;   // OK! protected는 파생 클래스에서 접근 가능
        publicVar = 30;      // OK! public은 어디서나 접근 가능
    }
};

// protected 상속: public -> protected로 변경
class ProtectedDerived : protected Base {
public:
    void test() {
        protectedVar = 20;   // OK
        publicVar = 30;      // OK (내부에서는)
    }
};

// private 상속: public, protected -> private으로 변경
class PrivateDerived : private Base {
public:
    void test() {
        protectedVar = 20;   // OK
        publicVar = 30;      // OK (내부에서는)
    }
};

void accessSpecifiers() {
    cout << "\n=== 접근 지정자와 상속 ===" << endl;
    
    PublicDerived pub;
    pub.publicVar = 100;  // OK: public 상속이므로 public 유지
    
    ProtectedDerived prot;
    // prot.publicVar = 100;  // 오류! protected 상속으로 public이 protected가 됨
    
    PrivateDerived priv;
    // priv.publicVar = 100;  // 오류! private 상속으로 모두 private이 됨
}

// ========== 다중 상속 ==========

class Flyable {
public:
    void fly() {
        cout << "날고 있습니다!" << endl;
    }
};

class Swimmable {
public:
    void swim() {
        cout << "수영하고 있습니다!" << endl;
    }
};

// 다중 상속: 여러 클래스를 동시에 상속
class Duck : public Animal, public Flyable, public Swimmable {
public:
    Duck(string n = "오리", int a = 0) : Animal(n, a) {}
    
    void display() {
        Animal::display();
        cout << "오리는 날 수도 있고 수영도 할 수 있습니다." << endl;
    }
};

void multipleInheritance() {
    cout << "\n=== 다중 상속 ===" << endl;
    
    Duck duck("도날드", 2);
    duck.eat();    // Animal에서 상속
    duck.fly();    // Flyable에서 상속
    duck.swim();   // Swimmable에서 상속
    duck.display();
}

// ========== 생성자/소멸자 호출 순서 ==========

class Parent {
public:
    Parent() {
        cout << "Parent 생성자" << endl;
    }
    
    ~Parent() {
        cout << "Parent 소멸자" << endl;
    }
};

class Child : public Parent {
public:
    Child() {
        cout << "Child 생성자" << endl;
    }
    
    ~Child() {
        cout << "Child 소멸자" << endl;
    }
};

void constructorDestructorOrder() {
    cout << "\n=== 생성자/소멸자 호출 순서 ===" << endl;
    cout << "객체 생성:" << endl;
    Child child;
    
    cout << "\n객체 소멸:" << endl;
    // 소멸자는 자동으로 호출됨
}

// ========== 함수 오버라이딩 vs 오버로딩 ==========

class Shape {
public:
    void draw() {
        cout << "도형을 그립니다." << endl;
    }
    
    void draw(int x, int y) {  // 오버로딩
        cout << "(" << x << ", " << y << ") 위치에 도형을 그립니다." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {  // 오버라이딩 (재정의)
        cout << "원을 그립니다." << endl;
    }
    
    void draw(int radius) {  // 오버로딩 (새로운 함수)
        cout << "반지름 " << radius << "인 원을 그립니다." << endl;
    }
};

void overridingVsOverloading() {
    cout << "\n=== 오버라이딩 vs 오버로딩 ===" << endl;
    
    Circle circle;
    circle.draw();        // Circle의 draw() 호출 (오버라이딩)
    circle.draw(10);     // Circle의 draw(int) 호출 (오버로딩)
    // circle.draw(10, 20);  // 오류! Circle에는 draw(int, int)가 없음
    
    Shape* shapePtr = &circle;
    shapePtr->draw();     // Shape의 draw() 호출 (오버라이딩이 아님!)
    // 가상 함수를 사용해야 오버라이딩이 제대로 작동 (다음 파일에서 학습)
}

// ========== 상속 체인 ==========

class Vehicle {
protected:
    string brand;
    int year;
    
public:
    Vehicle(string b = "알 수 없음", int y = 2020) : brand(b), year(y) {}
    
    void start() {
        cout << brand << " 차량이 시동을 겁니다." << endl;
    }
};

class Car : public Vehicle {
protected:
    int doors;
    
public:
    Car(string b = "알 수 없음", int y = 2020, int d = 4) 
        : Vehicle(b, y), doors(d) {}
    
    void openDoor() {
        cout << doors << "개 문 중 하나를 엽니다." << endl;
    }
};

class SportsCar : public Car {
private:
    int maxSpeed;
    
public:
    SportsCar(string b = "알 수 없음", int y = 2020, int d = 2, int ms = 200)
        : Car(b, y, d), maxSpeed(ms) {}
    
    void display() {
        cout << "브랜드: " << brand << ", 연식: " << year 
             << ", 문 개수: " << doors << ", 최고속도: " << maxSpeed << "km/h" << endl;
    }
};

void inheritanceChain() {
    cout << "\n=== 상속 체인 ===" << endl;
    
    SportsCar sportsCar("페라리", 2023, 2, 350);
    sportsCar.start();      // Vehicle에서 상속
    sportsCar.openDoor();   // Car에서 상속
    sportsCar.display();    // SportsCar 자체 함수
}

int main() {
    basicInheritance();
    accessSpecifiers();
    multipleInheritance();
    constructorDestructorOrder();
    overridingVsOverloading();
    inheritanceChain();
    
    return 0;
}

/*
 * 상속 핵심 정리
 * 
 * 1. 상속의 개념
 *    - 기존 클래스의 속성과 기능을 재사용
 *    - 코드 중복 제거 및 확장성 향상
 *    - "is-a" 관계 (Dog is an Animal)
 * 
 * 2. 상속 문법
 *    class 파생클래스 : 접근지정자 기본클래스 {
 *        // ...
 *    };
 * 
 * 3. 접근 지정자와 상속
 *    - public 상속: 접근 권한 유지 (가장 많이 사용)
 *    - protected 상속: public -> protected
 *    - private 상속: public, protected -> private
 * 
 * 4. 접근 권한
 *    - private: 클래스 내부만
 *    - protected: 클래스 내부 + 파생 클래스
 *    - public: 어디서나
 * 
 * 5. 생성자/소멸자 호출 순서
 *    생성자: 기본 클래스 -> 파생 클래스
 *    소멸자: 파생 클래스 -> 기본 클래스
 * 
 * 6. 함수 오버라이딩
 *    - 파생 클래스에서 기본 클래스의 함수를 재정의
 *    - 함수 시그니처가 동일해야 함
 *    - 가상 함수를 사용해야 제대로 작동 (다음 파일에서 학습)
 * 
 * 7. 다중 상속
 *    - 여러 클래스를 동시에 상속 가능
 *    - 다이아몬드 문제 주의 (가상 상속으로 해결)
 * 
 * 8. 상속의 장점
 *    - 코드 재사용
 *    - 유지보수 용이
 *    - 확장성 향상
 *    - 다형성 구현 기반
 */

