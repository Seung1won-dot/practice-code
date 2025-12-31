# 객체지향 프로그래밍 (OOP) 개념

## 객체지향 프로그래밍이란?

객체지향 프로그래밍(Object-Oriented Programming, OOP)은 프로그램을 객체(Object)들의 집합으로 모델링하는 프로그래밍 패러다임입니다. 각 객체는 데이터(속성)와 그 데이터를 조작하는 함수(메서드)를 포함합니다.

## 절차지향 vs 객체지향

### 절차지향 프로그래밍 (Procedural Programming)

#### 특징
- 프로그램을 함수들의 집합으로 구성
- 데이터와 함수가 분리되어 있음
- 순차적인 실행 흐름
- C 언어가 대표적

#### 예시
```c
// C 스타일 (절차지향)
struct Point {
    int x;
    int y;
};

void movePoint(struct Point* p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

void printPoint(struct Point* p) {
    printf("(%d, %d)\n", p->x, p->y);
}
```

#### 장점
- 단순하고 직관적
- 작은 프로그램에 적합
- 실행 속도가 빠름

#### 단점
- 대규모 프로젝트에서 관리 어려움
- 데이터와 함수의 연관성이 약함
- 코드 재사용이 어려움

### 객체지향 프로그래밍 (Object-Oriented Programming)

#### 특징
- 프로그램을 객체들의 집합으로 구성
- 데이터와 함수가 하나의 객체에 캡슐화
- 객체 간 상호작용으로 프로그램 동작
- C++, Java, Python 등이 지원

#### 예시
```cpp
// C++ 스타일 (객체지향)
class Point {
private:
    int x;
    int y;
    
public:
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    
    void print() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};
```

#### 장점
- 코드 재사용성 높음
- 유지보수가 쉬움
- 대규모 프로젝트에 적합
- 확장성이 좋음

#### 단점
- 학습 곡선이 가파름
- 작은 프로그램에는 오버헤드
- 설계가 복잡할 수 있음

## OOP의 핵심 개념

### 1. 캡슐화 (Encapsulation)

#### 정의
- 데이터와 그 데이터를 조작하는 함수를 하나의 단위(클래스)로 묶는 것
- 내부 구현을 숨기고 외부 인터페이스만 제공

#### 예시
```cpp
class BankAccount {
private:
    double balance;  // 외부에서 직접 접근 불가
    
public:
    void deposit(double amount) {  // 공개 인터페이스
        if (amount > 0) {
            balance += amount;
        }
    }
    
    double getBalance() {  // 공개 인터페이스
        return balance;
    }
};
```

#### 장점
- 데이터 보호
- 구현 변경이 쉬움
- 인터페이스와 구현 분리

### 2. 상속 (Inheritance)

#### 정의
- 기존 클래스의 속성과 메서드를 새로운 클래스가 물려받는 것
- 코드 재사용성과 계층 구조 표현

#### 예시
```cpp
// 부모 클래스 (기본 클래스)
class Animal {
public:
    void eat() {
        std::cout << "먹는다" << std::endl;
    }
};

// 자식 클래스 (파생 클래스)
class Dog : public Animal {
public:
    void bark() {
        std::cout << "멍멍" << std::endl;
    }
};
```

#### 장점
- 코드 재사용
- 계층적 구조 표현
- 다형성 구현 기반

### 3. 다형성 (Polymorphism)

#### 정의
- 같은 인터페이스로 다양한 형태의 동작을 수행
- "하나의 인터페이스, 여러 구현"

#### 종류

##### 컴파일 타임 다형성 (정적 다형성)
- 함수 오버로딩
- 연산자 오버로딩
- 템플릿

##### 런타임 다형성 (동적 다형성)
- 가상 함수 (virtual function)
- 함수 오버라이딩

#### 예시
```cpp
class Shape {
public:
    virtual void draw() {  // 가상 함수
        std::cout << "도형 그리기" << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {  // 오버라이딩
        std::cout << "원 그리기" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "사각형 그리기" << std::endl;
    }
};
```

#### 장점
- 유연한 코드
- 확장성
- 인터페이스 통일

### 4. 추상화 (Abstraction)

#### 정의
- 복잡한 시스템을 단순화하여 표현
- 필요한 부분만 보여주고 나머지는 숨김

#### 예시
```cpp
// 추상 클래스
class Vehicle {
public:
    virtual void start() = 0;  // 순수 가상 함수
    virtual void stop() = 0;
    
    void honk() {  // 공통 기능
        std::cout << "빵빵" << std::endl;
    }
};

class Car : public Vehicle {
public:
    void start() override {
        std::cout << "자동차 시동" << std::endl;
    }
    
    void stop() override {
        std::cout << "자동차 정지" << std::endl;
    }
};
```

#### 장점
- 복잡성 감소
- 핵심에 집중
- 재사용성 향상

## 객체와 클래스

### 클래스 (Class)
- 객체를 만들기 위한 설계도(템플릿)
- 데이터 멤버와 멤버 함수로 구성
- 정의만 있고 메모리를 차지하지 않음

### 객체 (Object)
- 클래스를 기반으로 생성된 실제 인스턴스
- 메모리를 차지함
- 각 객체는 독립적인 데이터를 가짐

### 예시
```cpp
// 클래스 정의 (설계도)
class Car {
private:
    string brand;
    int speed;
    
public:
    void accelerate() {
        speed += 10;
    }
};

// 객체 생성 (실제 자동차)
Car myCar;      // 객체 1
Car yourCar;    // 객체 2
```

## 접근 지정자 (Access Specifiers)

### public
- 클래스 외부에서 접근 가능
- 인터페이스 역할

### private
- 클래스 내부에서만 접근 가능
- 기본 접근 지정자 (명시하지 않으면 private)

### protected
- 클래스 내부와 파생 클래스에서 접근 가능
- 상속과 관련

## OOP의 장점

### 1. 코드 재사용성
- 기존 클래스를 상속하거나 포함하여 재사용
- 라이브러리 형태로 제공 가능

### 2. 유지보수성
- 관련된 데이터와 함수가 한 곳에 모여있음
- 수정이 필요할 때 해당 클래스만 수정

### 3. 확장성
- 기존 코드를 수정하지 않고 새로운 기능 추가
- 상속과 다형성 활용

### 4. 모델링 용이성
- 현실 세계의 개념을 코드로 표현하기 쉬움
- 직관적인 구조

### 5. 데이터 보호
- 캡슐화를 통한 데이터 보호
- 잘못된 접근 방지

## OOP의 단점

### 1. 복잡성
- 작은 프로그램에는 오버헤드
- 설계가 복잡해질 수 있음

### 2. 성능
- 함수 호출 오버헤드
- 가상 함수 테이블 등 추가 메모리

### 3. 학습 곡선
- 개념 이해가 필요
- 설계 능력 필요

## 실생활 예시

### 은행 시스템
```cpp
class Account {
    // 계좌 정보와 기능
};

class SavingsAccount : public Account {
    // 적금 계좌 특화 기능
};

class CheckingAccount : public Account {
    // 당좌 계좌 특화 기능
};
```

### 게임 캐릭터
```cpp
class Character {
    // 기본 캐릭터 속성과 기능
};

class Warrior : public Character {
    // 전사 특화 기능
};

class Mage : public Character {
    // 마법사 특화 기능
};
```

## 다음 단계

1. **클래스 기본**: 클래스 선언, 객체 생성, 접근 지정자
2. **멤버 메서드**: 클래스 내부의 함수 정의
3. **생성자와 소멸자**: 객체 초기화와 정리
4. **this 포인터**: 객체 자신을 가리키는 포인터
5. **캡슐화**: Getter/Setter 패턴과 정보 은닉

## 결론

객체지향 프로그래밍은 현대 소프트웨어 개발의 핵심 패러다임입니다. 캡슐화, 상속, 다형성, 추상화의 네 가지 핵심 개념을 이해하고 활용하면 더 나은 코드를 작성할 수 있습니다. C++는 이러한 OOP 개념을 완전히 지원하며, 효율적인 객체지향 프로그램을 작성할 수 있게 해줍니다.

