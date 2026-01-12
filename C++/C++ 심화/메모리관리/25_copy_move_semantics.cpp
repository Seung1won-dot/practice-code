/*
 * 25_copy_move_semantics.cpp
 * 
 * 복사/이동 의미론 (Copy/Move Semantics)
 * - 복사 생성자와 복사 대입 연산자
 * - 이동 생성자와 이동 대입 연산자
 * - lvalue와 rvalue
 * - std::move
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

using std::cout;
using std::endl;

// ========== 복사 의미론 ==========

class String {
private:
    char* data;
    size_t length;
    
public:
    // 생성자
    String(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
        cout << "생성자 호출: " << data << endl;
    }
    
    // 복사 생성자
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        cout << "복사 생성자 호출: " << data << endl;
    }
    
    // 복사 대입 연산자
    String& operator=(const String& other) {
        if (this != &other) {  // 자기 자신 대입 방지
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
            cout << "복사 대입 연산자 호출: " << data << endl;
        }
        return *this;
    }
    
    // 소멸자
    ~String() {
        if (data) {
            cout << "소멸자 호출: " << data << endl;
            delete[] data;
        }
    }
    
    const char* c_str() const {
        return data;
    }
};

void copySemantics() {
    cout << "=== 복사 의미론 ===" << endl;
    
    String str1("Hello");
    
    // 복사 생성자 호출
    String str2 = str1;  // String str2(str1)와 동일
    
    // 복사 대입 연산자 호출
    String str3("World");
    str3 = str1;
    
    cout << "str1: " << str1.c_str() << endl;
    cout << "str2: " << str2.c_str() << endl;
    cout << "str3: " << str3.c_str() << endl;
}

// ========== 이동 의미론 ==========

class MovableString {
private:
    char* data;
    size_t length;
    
public:
    // 생성자
    MovableString(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
        cout << "생성자 호출: " << data << endl;
    }
    
    // 복사 생성자
    MovableString(const MovableString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        cout << "복사 생성자 호출: " << data << endl;
    }
    
    // 이동 생성자 (C++11)
    MovableString(MovableString&& other) noexcept {
        // 리소스 훔치기 (steal)
        data = other.data;
        length = other.length;
        
        // 원본 객체 초기화
        other.data = nullptr;
        other.length = 0;
        
        cout << "이동 생성자 호출: " << data << endl;
    }
    
    // 복사 대입 연산자
    MovableString& operator=(const MovableString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
            cout << "복사 대입 연산자 호출: " << data << endl;
        }
        return *this;
    }
    
    // 이동 대입 연산자 (C++11)
    MovableString& operator=(MovableString&& other) noexcept {
        if (this != &other) {
            delete[] data;
            
            // 리소스 훔치기
            data = other.data;
            length = other.length;
            
            // 원본 객체 초기화
            other.data = nullptr;
            other.length = 0;
            
            cout << "이동 대입 연산자 호출: " << data << endl;
        }
        return *this;
    }
    
    ~MovableString() {
        if (data) {
            cout << "소멸자 호출: " << data << endl;
            delete[] data;
        } else {
            cout << "소멸자 호출: (null)" << endl;
        }
    }
    
    const char* c_str() const {
        return data ? data : "(null)";
    }
};

void moveSemantics() {
    cout << "\n=== 이동 의미론 ===" << endl;
    
    MovableString str1("Hello");
    
    // 이동 생성자 호출 (임시 객체)
    MovableString str2 = MovableString("World");
    
    // std::move로 명시적 이동
    MovableString str3 = std::move(str1);
    
    cout << "str1: " << str1.c_str() << endl;  // 이동 후 비어있음
    cout << "str2: " << str2.c_str() << endl;
    cout << "str3: " << str3.c_str() << endl;
    
    // 이동 대입 연산자
    MovableString str4("Test");
    str4 = std::move(str2);
    cout << "str2: " << str2.c_str() << endl;  // 이동 후 비어있음
    cout << "str4: " << str4.c_str() << endl;
}

// ========== lvalue와 rvalue ==========

void lvalueRvalue() {
    cout << "\n=== lvalue와 rvalue ===" << endl;
    
    int a = 10;  // a는 lvalue
    
    int& ref = a;  // lvalue 참조
    // int& ref2 = 10;  // 오류! rvalue는 lvalue 참조 불가
    
    const int& constRef = 10;  // const lvalue 참조는 rvalue도 가능
    
    // rvalue 참조 (C++11)
    int&& rvalueRef = 10;  // rvalue 참조는 rvalue만 가능
    // int&& rvalueRef2 = a;  // 오류! lvalue는 rvalue 참조 불가
    
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;
    cout << "rvalueRef = " << rvalueRef << endl;
}

// ========== std::move ==========

void stdMoveExample() {
    cout << "\n=== std::move ===" << endl;
    
    MovableString str1("Original");
    MovableString str2("Target");
    
    cout << "이동 전:" << endl;
    cout << "str1: " << str1.c_str() << endl;
    cout << "str2: " << str2.c_str() << endl;
    
    // std::move: lvalue를 rvalue로 변환
    str2 = std::move(str1);
    
    cout << "\n이동 후:" << endl;
    cout << "str1: " << str1.c_str() << endl;  // 비어있음
    cout << "str2: " << str2.c_str() << endl;
}

// ========== 이동과 벡터 ==========

void moveWithVector() {
    cout << "\n=== 이동과 벡터 ===" << endl;
    
    std::vector<MovableString> vec;
    
    MovableString str("Hello");
    
    // push_back: 복사 (C++11 이전)
    // vec.push_back(str);  // 복사 생성자 호출
    
    // emplace_back: 직접 생성 (이동 또는 복사)
    vec.emplace_back("World");  // 생성자만 호출
    
    // 이동으로 추가
    vec.push_back(std::move(str));
    
    cout << "벡터 크기: " << vec.size() << endl;
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "vec[" << i << "]: " << vec[i].c_str() << endl;
    }
    
    cout << "str: " << str.c_str() << endl;  // 이동 후 비어있음
}

// ========== 완벽한 전달 (Perfect Forwarding) ==========

template<typename T>
void forwardExample(T&& arg) {
    // std::forward: 완벽한 전달
    // lvalue는 lvalue로, rvalue는 rvalue로 전달
    process(std::forward<T>(arg));
}

void process(const MovableString& str) {
    cout << "lvalue 처리: " << str.c_str() << endl;
}

void process(MovableString&& str) {
    cout << "rvalue 처리: " << str.c_str() << endl;
    MovableString moved = std::move(str);
}

void perfectForwarding() {
    cout << "\n=== 완벽한 전달 ===" << endl;
    
    MovableString str("Test");
    
    forwardExample(str);           // lvalue 전달
    forwardExample(MovableString("Temp"));  // rvalue 전달
}

// ========== Rule of Five ==========

class RuleOfFive {
private:
    int* data;
    
public:
    // 생성자
    RuleOfFive(int value = 0) : data(new int(value)) {
        cout << "생성자" << endl;
    }
    
    // 복사 생성자
    RuleOfFive(const RuleOfFive& other) : data(new int(*other.data)) {
        cout << "복사 생성자" << endl;
    }
    
    // 이동 생성자
    RuleOfFive(RuleOfFive&& other) noexcept : data(other.data) {
        other.data = nullptr;
        cout << "이동 생성자" << endl;
    }
    
    // 복사 대입 연산자
    RuleOfFive& operator=(const RuleOfFive& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
            cout << "복사 대입" << endl;
        }
        return *this;
    }
    
    // 이동 대입 연산자
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
            cout << "이동 대입" << endl;
        }
        return *this;
    }
    
    // 소멸자
    ~RuleOfFive() {
        delete data;
        cout << "소멸자" << endl;
    }
};

void ruleOfFive() {
    cout << "\n=== Rule of Five ===" << endl;
    cout << "동적 메모리를 관리하는 클래스는 다음 5가지를 정의해야 함:" << endl;
    cout << "1. 복사 생성자" << endl;
    cout << "2. 이동 생성자" << endl;
    cout << "3. 복사 대입 연산자" << endl;
    cout << "4. 이동 대입 연산자" << endl;
    cout << "5. 소멸자" << endl;
    
    RuleOfFive obj1(10);
    RuleOfFive obj2 = obj1;        // 복사 생성자
    RuleOfFive obj3 = std::move(obj1);  // 이동 생성자
    obj2 = obj3;                   // 복사 대입
    obj3 = std::move(obj2);        // 이동 대입
}

int main() {
    copySemantics();
    moveSemantics();
    lvalueRvalue();
    stdMoveExample();
    moveWithVector();
    perfectForwarding();
    ruleOfFive();
    
    return 0;
}

/*
 * 복사/이동 의미론 핵심 정리
 * 
 * 1. 복사 의미론
 *    - 복사 생성자: 객체 복사
 *    - 복사 대입 연산자: 객체 대입
 *    - 깊은 복사 (deep copy) 구현
 *    - 리소스 중복 할당
 * 
 * 2. 이동 의미론 (C++11)
 *    - 이동 생성자: 리소스 이동
 *    - 이동 대입 연산자: 리소스 이동 대입
 *    - 얕은 복사 후 원본 무효화
 *    - 성능 향상 (불필요한 복사 방지)
 * 
 * 3. lvalue와 rvalue
 *    - lvalue: 이름이 있는 객체 (변수)
 *    - rvalue: 임시 객체, 리터럴
 *    - lvalue 참조: &
 *    - rvalue 참조: &&
 * 
 * 4. std::move
 *    - lvalue를 rvalue로 변환
 *    - 실제로 이동하지 않음 (이동 생성자/대입 연산자 호출 유도)
 *    - 이동 후 원본 객체는 사용하지 않아야 함
 * 
 * 5. 이동 생성자/대입 연산자 특징
 *    - noexcept 지정 권장 (성능)
 *    - 원본 객체 초기화 필수
 *    - 리소스 훔치기 (steal) 패턴
 * 
 * 6. Rule of Five
 *    - 동적 메모리 관리 클래스는 5가지 정의
 *    - 복사 생성자, 이동 생성자
 *    - 복사 대입, 이동 대입
 *    - 소멸자
 * 
 * 7. 완벽한 전달 (Perfect Forwarding)
 *    - std::forward 사용
 *    - 템플릿에서 lvalue/rvalue 구분 전달
 *    - 이동 의미론 최대 활용
 * 
 * 8. 성능 향상
 *    - 불필요한 복사 방지
 *    - 임시 객체 최적화
 *    - 컨테이너에 이동으로 추가
 * 
 * 9. 사용 시나리오
 *    - 큰 객체 전달 시 이동 사용
 *    - 컨테이너에 추가 시 이동
 *    - 팩토리 함수 반환 시 이동
 * 
 * 10. 주의사항
 *     - 이동 후 원본 사용 금지
 *     - noexcept 지정 권장
 *     - 기본 이동 의미론 활용 가능
 */

