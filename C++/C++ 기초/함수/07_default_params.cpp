/*
 * 07_default_params.cpp
 * 
 * 기본 매개변수 (Default Parameters)
 * - 함수 매개변수에 기본값을 부여
 * - 호출 편의성 향상
 * - 함수 오버로딩의 대안
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// ========== 기본 사용법 ==========

// 기본 매개변수는 오른쪽부터 지정해야 함
void greet(string name, string greeting = "Hello") {
    cout << greeting << ", " << name << "!" << endl;
}

// 여러 기본 매개변수
void printInfo(string name, int age = 0, string city = "Unknown") {
    cout << "이름: " << name << ", 나이: " << age 
         << ", 도시: " << city << endl;
}

void basicUsage() {
    cout << "=== 기본 사용법 ===" << endl;
    
    greet("홍길동");                    // greeting 기본값 사용
    greet("김철수", "안녕하세요");       // 둘 다 지정
    
    printInfo("이영희");                // age, city 기본값 사용
    printInfo("박민수", 25);            // city만 기본값 사용
    printInfo("최지영", 30, "서울");    // 모두 지정
}

// ========== 수학 함수 예제 ==========

// 거듭제곱 함수 (기본 지수는 2)
double power(double base, int exponent = 2) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

void mathExample() {
    cout << "\n=== 수학 함수 예제 ===" << endl;
    cout << "power(5) = " << power(5) << " (5의 제곱)" << endl;
    cout << "power(5, 3) = " << power(5, 3) << " (5의 세제곱)" << endl;
    cout << "power(2, 10) = " << power(2, 10) << " (2의 10제곱)" << endl;
}

// ========== 로그 함수 예제 ==========

void logMessage(string message, int level = 1, bool timestamp = true) {
    if (timestamp) {
        cout << "[LOG] ";
    }
    
    string levelStr;
    switch (level) {
        case 0: levelStr = "DEBUG"; break;
        case 1: levelStr = "INFO"; break;
        case 2: levelStr = "WARNING"; break;
        case 3: levelStr = "ERROR"; break;
        default: levelStr = "INFO"; break;
    }
    
    cout << "[" << levelStr << "] " << message << endl;
}

void loggingExample() {
    cout << "\n=== 로그 함수 예제 ===" << endl;
    logMessage("프로그램 시작");
    logMessage("데이터 로드 완료", 0);
    logMessage("경고 발생", 2, false);
    logMessage("오류 발생", 3);
}

// ========== 선언과 정의 분리 ==========

// 선언부에 기본값 지정 (헤더 파일에 보통 작성)
void drawRectangle(int width, int height = 10, char fill = '*');

// 정의부에는 기본값을 다시 쓰지 않음
void drawRectangle(int width, int height, char fill) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << fill;
        }
        cout << endl;
    }
}

void declarationDefinition() {
    cout << "\n=== 선언과 정의 분리 ===" << endl;
    cout << "기본값 사용:" << endl;
    drawRectangle(5);
    
    cout << "\n높이 지정:" << endl;
    drawRectangle(5, 3);
    
    cout << "\n모두 지정:" << endl;
    drawRectangle(5, 3, '#');
}

// ========== 클래스 멤버 함수 ==========

class BankAccount {
private:
    string owner;
    double balance;
    
public:
    BankAccount(string name, double initialBalance = 0.0) 
        : owner(name), balance(initialBalance) {}
    
    void deposit(double amount, string note = "입금") {
        balance += amount;
        cout << note << ": " << amount << "원" << endl;
    }
    
    void withdraw(double amount, bool showBalance = true) {
        if (balance >= amount) {
            balance -= amount;
            if (showBalance) {
                cout << "출금: " << amount << "원, 잔액: " << balance << "원" << endl;
            }
        } else {
            cout << "잔액 부족!" << endl;
        }
    }
    
    void display() const {
        cout << owner << "의 잔액: " << balance << "원" << endl;
    }
};

void classMemberFunction() {
    cout << "\n=== 클래스 멤버 함수 ===" << endl;
    BankAccount account("홍길동", 10000);
    
    account.display();
    account.deposit(5000);
    account.deposit(2000, "급여");
    account.withdraw(3000);
    account.withdraw(1000, false);  // 잔액 표시 안 함
    account.display();
}

// ========== 기본 매개변수와 오버로딩 ==========

// 기본 매개변수로 오버로딩 대체 가능
void process(int a, int b = 0, int c = 0) {
    cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
}

// 하지만 때로는 오버로딩이 더 명확할 수 있음
void processOverloaded(int a) {
    cout << "단일 인자: " << a << endl;
}

void processOverloaded(int a, int b) {
    cout << "두 인자: " << a << ", " << b << endl;
}

void overloadingComparison() {
    cout << "\n=== 기본 매개변수 vs 오버로딩 ===" << endl;
    
    cout << "기본 매개변수 사용:" << endl;
    process(10);
    process(10, 20);
    process(10, 20, 30);
    
    cout << "\n오버로딩 사용:" << endl;
    processOverloaded(10);
    processOverloaded(10, 20);
}

// ========== 주의사항 ==========

void warningExample() {
    cout << "\n=== 주의사항 ===" << endl;
    
    // 1. 기본 매개변수는 오른쪽부터 지정
    // void wrong(int a = 10, int b);  // 오류!
    
    // 2. 중간 매개변수만 기본값 지정 불가
    // void wrong(int a, int b = 10, int c);  // 오류!
    
    // 3. 함수 포인터와 함께 사용 시 주의
    void (*funcPtr)(string, string) = greet;
    funcPtr("테스트", "Hi");  // 기본값 무시됨
    
    cout << "함수 포인터 사용 시 기본값은 무시됩니다." << endl;
}

// ========== 템플릿과 기본 매개변수 ==========

template<typename T>
void printValue(T value, int precision = 2) {
    cout << "값: " << value << " (정밀도: " << precision << ")" << endl;
}

void templateExample() {
    cout << "\n=== 템플릿과 기본 매개변수 ===" << endl;
    printValue(3.14159);
    printValue(3.14159, 5);
    printValue(string("Hello"));
}

int main() {
    basicUsage();
    mathExample();
    loggingExample();
    declarationDefinition();
    classMemberFunction();
    overloadingComparison();
    warningExample();
    templateExample();
    
    return 0;
}

/*
 * 기본 매개변수 핵심 정리
 * 
 * 1. 개념
 *    - 함수 매개변수에 기본값을 지정
 *    - 호출 시 해당 인자를 생략 가능
 *    - 함수 오버로딩의 대안으로 사용
 * 
 * 2. 문법
 *    반환타입 함수명(타입1 매개변수1, 타입2 매개변수2 = 기본값) {
 *        // 함수 본문
 *    }
 * 
 * 3. 규칙
 *    - 기본 매개변수는 오른쪽부터 지정
 *    - 중간 매개변수만 기본값 지정 불가
 *    - 선언부에 기본값 지정 (헤더 파일)
 *    - 정의부에는 기본값 다시 쓰지 않음
 * 
 * 4. 사용 시기
 *    - 선택적 매개변수가 있을 때
 *    - 대부분의 호출에서 같은 값을 사용할 때
 *    - 함수 오버로딩을 줄이고 싶을 때
 * 
 * 5. 장점
 *    - 함수 호출이 간결해짐
 *    - 코드 중복 감소
 *    - 유지보수 용이
 * 
 * 6. 단점
 *    - 함수 포인터와 함께 사용 시 기본값 무시
 *    - 헤더 파일 수정 시 재컴파일 필요
 * 
 * 7. 주의사항
 *    - 기본값 변경 시 모든 호출부에 영향
 *    - 모호한 호출 방지
 *    - 문서화 중요 (기본값이 무엇인지 명확히)
 */

