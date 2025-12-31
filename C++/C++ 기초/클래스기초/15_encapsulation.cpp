/*
 * 15_encapsulation.cpp
 * 
 * 캡슐화와 정보 은닉
 * - Getter/Setter 패턴
 * - 접근 제어를 통한 데이터 보호
 * - 유효성 검사와 안전한 인터페이스
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using std::cout;
using std::endl;
using std::string;

// ========== 기본 캡슐화 ==========

class BankAccount {
private:
    // private: 외부에서 직접 접근 불가
    double balance;
    string accountNumber;
    string ownerName;
    
public:
    // 생성자
    BankAccount(string owner, string account, double initial = 0.0)
        : ownerName(owner), accountNumber(account), balance(initial) {
        if (initial < 0) {
            balance = 0.0;
        }
    }
    
    // Getter 메서드: 읽기 전용 접근
    double getBalance() const {
        return balance;
    }
    
    string getOwner() const {
        return ownerName;
    }
    
    string getAccountNumber() const {
        return accountNumber;
    }
    
    // Setter 메서드: 쓰기 접근 (유효성 검사 포함)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << "원 입금. 잔액: " << balance << "원" << endl;
        } else {
            cout << "입금 금액은 0보다 커야 합니다." << endl;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << "원 출금. 잔액: " << balance << "원" << endl;
            return true;
        } else {
            cout << "출금 실패: 잔액 부족 또는 잘못된 금액" << endl;
            return false;
        }
    }
    
    // balance는 직접 Setter 제공 안 함 (deposit/withdraw로만 변경)
};

void basicEncapsulation() {
    cout << "=== 기본 캡슐화 ===" << endl;
    
    BankAccount account("홍길동", "123-456-789", 10000);
    
    cout << "소유자: " << account.getOwner() << endl;
    cout << "계좌번호: " << account.getAccountNumber() << endl;
    cout << "잔액: " << account.getBalance() << "원" << endl;
    
    account.deposit(5000);
    account.withdraw(3000);
    account.withdraw(20000);  // 실패
    
    // account.balance = 1000000;  // 오류! 직접 접근 불가
}

// ========== 유효성 검사가 있는 Setter ==========

class Person {
private:
    string name;
    int age;
    string email;
    
public:
    // 이름 Setter
    void setName(const string& n) {
        if (!n.empty()) {
            name = n;
        } else {
            throw std::invalid_argument("이름은 비어있을 수 없습니다");
        }
    }
    
    // 나이 Setter (유효성 검사)
    void setAge(int a) {
        if (a >= 0 && a <= 150) {
            age = a;
        } else {
            throw std::out_of_range("나이는 0~150 사이여야 합니다");
        }
    }
    
    // 이메일 Setter (간단한 검증)
    void setEmail(const string& e) {
        if (e.find('@') != string::npos) {
            email = e;
        } else {
            throw std::invalid_argument("올바른 이메일 형식이 아닙니다");
        }
    }
    
    // Getter 메서드들
    string getName() const { return name; }
    int getAge() const { return age; }
    string getEmail() const { return email; }
    
    void display() const {
        cout << "이름: " << name << ", 나이: " << age 
             << ", 이메일: " << email << endl;
    }
};

void validationExample() {
    cout << "\n=== 유효성 검사가 있는 Setter ===" << endl;
    
    Person person;
    
    try {
        person.setName("홍길동");
        person.setAge(25);
        person.setEmail("hong@example.com");
        person.display();
        
        // 잘못된 값 시도
        // person.setAge(200);  // 예외 발생
    }
    catch (const std::exception& e) {
        cout << "오류: " << e.what() << endl;
    }
}

// ========== 읽기 전용 속성 ==========

class Product {
private:
    int id;
    string name;
    double price;
    int stock;
    
public:
    Product(int i, const string& n, double p, int s)
        : id(i), name(n), price(p), stock(s) {}
    
    // 읽기 전용 속성 (Setter 없음)
    int getId() const { return id; }
    string getName() const { return name; }
    
    // 읽기/쓰기 가능
    double getPrice() const { return price; }
    void setPrice(double p) {
        if (p > 0) {
            price = p;
        }
    }
    
    int getStock() const { return stock; }
    void setStock(int s) {
        if (s >= 0) {
            stock = s;
        }
    }
    
    // 비즈니스 로직 메서드
    bool purchase(int quantity) {
        if (quantity > 0 && quantity <= stock) {
            stock -= quantity;
            return true;
        }
        return false;
    }
    
    void display() const {
        cout << "ID: " << id << ", 이름: " << name 
             << ", 가격: " << price << "원, 재고: " << stock << endl;
    }
};

void readOnlyProperties() {
    cout << "\n=== 읽기 전용 속성 ===" << endl;
    
    Product product(1, "노트북", 1000000, 10);
    product.display();
    
    cout << "가격 변경: ";
    product.setPrice(950000);
    product.display();
    
    cout << "구매 시도 (5개): ";
    if (product.purchase(5)) {
        cout << "구매 성공" << endl;
    }
    product.display();
    
    // product.setId(2);  // 오류! Setter 없음
}

// ========== 계산된 속성 (Computed Properties) ==========

class Rectangle {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) {
            throw std::invalid_argument("너비와 높이는 0보다 커야 합니다");
        }
    }
    
    // 기본 속성
    double getWidth() const { return width; }
    void setWidth(double w) {
        if (w > 0) width = w;
    }
    
    double getHeight() const { return height; }
    void setHeight(double h) {
        if (h > 0) height = h;
    }
    
    // 계산된 속성 (Getter만, 저장되지 않음)
    double getArea() const {
        return width * height;
    }
    
    double getPerimeter() const {
        return 2 * (width + height);
    }
    
    double getDiagonal() const {
        return sqrt(width * width + height * height);
    }
    
    bool isSquare() const {
        return width == height;
    }
};

void computedProperties() {
    cout << "\n=== 계산된 속성 ===" << endl;
    
    Rectangle rect(10.0, 5.0);
    cout << "너비: " << rect.getWidth() << ", 높이: " << rect.getHeight() << endl;
    cout << "넓이: " << rect.getArea() << endl;
    cout << "둘레: " << rect.getPerimeter() << endl;
    cout << "대각선: " << rect.getDiagonal() << endl;
    cout << "정사각형 여부: " << std::boolalpha << rect.isSquare() << endl;
}

// ========== 조건부 접근 ==========

class SecureFile {
private:
    string filename;
    string content;
    bool isLocked;
    string password;
    
public:
    SecureFile(const string& name, const string& pwd)
        : filename(name), isLocked(true), password(pwd) {}
    
    bool unlock(const string& pwd) {
        if (pwd == password) {
            isLocked = false;
            return true;
        }
        return false;
    }
    
    void lock() {
        isLocked = true;
    }
    
    // 조건부 접근
    string getContent() const {
        if (isLocked) {
            throw std::runtime_error("파일이 잠겨있습니다");
        }
        return content;
    }
    
    void setContent(const string& text) {
        if (isLocked) {
            throw std::runtime_error("파일이 잠겨있습니다");
        }
        content = text;
    }
    
    string getFilename() const {
        return filename;  // 항상 접근 가능
    }
};

void conditionalAccess() {
    cout << "\n=== 조건부 접근 ===" << endl;
    
    SecureFile file("secret.txt", "password123");
    
    try {
        // file.getContent();  // 오류! 잠겨있음
        
        if (file.unlock("password123")) {
            cout << "파일 잠금 해제 성공" << endl;
            file.setContent("비밀 내용");
            cout << "내용: " << file.getContent() << endl;
        }
        
        file.lock();
        // file.getContent();  // 오류! 다시 잠김
    }
    catch (const std::exception& e) {
        cout << "오류: " << e.what() << endl;
    }
}

// ========== 접근 레벨 제어 ==========

class Employee {
private:
    // 완전히 숨김 (외부 접근 불가)
    double salary;
    string ssn;  // 주민등록번호
    
protected:
    // 파생 클래스에서만 접근 가능
    string department;
    
public:
    // 공개 인터페이스
    string name;
    int employeeId;
    
    Employee(string n, int id, string dept, double sal, string s)
        : name(n), employeeId(id), department(dept), salary(sal), ssn(s) {}
    
    // salary는 Getter만 제공 (읽기 전용)
    double getSalary() const {
        return salary;
    }
    
    // salary 변경은 승인된 메서드로만
    void giveRaise(double amount) {
        if (amount > 0) {
            salary += amount;
        }
    }
    
    // ssn은 완전히 숨김 (Getter도 없음)
    
    void display() const {
        cout << "이름: " << name << ", ID: " << employeeId 
             << ", 부서: " << department << ", 급여: " << salary << "원" << endl;
    }
};

void accessLevels() {
    cout << "\n=== 접근 레벨 제어 ===" << endl;
    
    Employee emp("홍길동", 1001, "개발팀", 5000000, "123456-1234567");
    
    cout << "공개 정보: " << emp.name << ", ID: " << emp.employeeId << endl;
    cout << "급여: " << emp.getSalary() << "원" << endl;
    
    emp.giveRaise(500000);
    cout << "인상 후 급여: " << emp.getSalary() << "원" << endl;
    
    // emp.salary = 10000000;  // 오류! 직접 접근 불가
    // emp.ssn;  // 오류! 접근 불가
}

// ========== 캡슐화의 장점 ==========

void encapsulationBenefits() {
    cout << "\n=== 캡슐화의 장점 ===" << endl;
    cout << "1. 데이터 보호: 잘못된 값 설정 방지" << endl;
    cout << "2. 유효성 검사: Setter에서 검증 가능" << endl;
    cout << "3. 구현 변경: 내부 구현 변경 시 외부 영향 최소화" << endl;
    cout << "4. 인터페이스 통일: 일관된 접근 방법 제공" << endl;
    cout << "5. 디버깅 용이: 접근 지점이 명확함" << endl;
}

int main() {
    basicEncapsulation();
    validationExample();
    readOnlyProperties();
    computedProperties();
    conditionalAccess();
    accessLevels();
    encapsulationBenefits();
    
    return 0;
}

/*
 * 캡슐화와 정보 은닉 핵심 정리
 * 
 * 1. 캡슐화 (Encapsulation)
 *    - 데이터와 함수를 하나의 단위로 묶음
 *    - 내부 구현을 숨기고 인터페이스만 공개
 *    - 접근 지정자로 제어
 * 
 * 2. 접근 지정자
 *    - private: 클래스 내부만
 *    - protected: 클래스 내부 + 파생 클래스
 *    - public: 어디서나 접근 가능
 * 
 * 3. Getter/Setter 패턴
 *    - Getter: private 멤버 읽기
 *    - Setter: private 멤버 쓰기 (유효성 검사)
 *    - 데이터 보호와 제어 제공
 * 
 * 4. 정보 은닉 (Information Hiding)
 *    - 내부 구현 세부사항 숨김
 *    - 공개 인터페이스만 제공
 *    - 변경에 대한 영향 최소화
 * 
 * 5. 유효성 검사
 *    - Setter에서 입력값 검증
 *    - 잘못된 데이터 방지
 *    - 예외 처리 가능
 * 
 * 6. 읽기 전용 속성
 *    - Getter만 제공, Setter 없음
 *    - 생성자에서만 설정
 *    - 불변성 보장
 * 
 * 7. 계산된 속성
 *    - 저장되지 않는 값
 *    - Getter에서 계산하여 반환
 *    - 메모리 효율적
 * 
 * 8. 조건부 접근
 *    - 상태에 따라 접근 제어
 *    - 보안과 안전성 향상
 * 
 * 9. 캡슐화의 장점
 *    - 데이터 보호
 *    - 유지보수성 향상
 *    - 코드 안정성 증가
 *    - 인터페이스 명확화
 * 
 * 10. 설계 원칙
 *     - 최소 권한 원칙: 필요한 만큼만 공개
 *     - 단일 책임: 클래스는 하나의 책임만
 *     - 인터페이스 분리: 명확한 인터페이스 제공
 */

