/*
 * 22_exception_handling.cpp
 * 
 * 예외 처리 (Exception Handling)
 * - try-catch 블록
 * - 예외 타입
 * - 예외 전파
 * - 사용자 정의 예외
 * - RAII와 예외 안전성
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include <cmath>
#include <vector>

using std::cout;
using std::endl;
using std::string;

// ========== 기본 예외 처리 ==========

void basicExceptionHandling() {
    cout << "=== 기본 예외 처리 ===" << endl;
    
    try {
        int a = 10, b = 0;
        
        if (b == 0) {
            throw std::runtime_error("0으로 나눌 수 없습니다!");
        }
        
        int result = a / b;
        cout << "결과: " << result << endl;
        
    } catch (const std::runtime_error& e) {
        cout << "예외 발생: " << e.what() << endl;
    }
    
    cout << "프로그램 계속 실행" << endl;
}

// ========== 여러 예외 타입 처리 ==========

void multipleExceptionTypes() {
    cout << "\n=== 여러 예외 타입 처리 ===" << endl;
    
    try {
        int choice;
        cout << "예외 타입 선택 (1: runtime_error, 2: logic_error, 3: 기타): ";
        // 시뮬레이션을 위해 choice = 1로 설정
        choice = 1;
        
        if (choice == 1) {
            throw std::runtime_error("런타임 오류 발생!");
        } else if (choice == 2) {
            throw std::logic_error("로직 오류 발생!");
        } else {
            throw 42;  // 정수 예외
        }
        
    } catch (const std::runtime_error& e) {
        cout << "런타임 예외: " << e.what() << endl;
    } catch (const std::logic_error& e) {
        cout << "로직 예외: " << e.what() << endl;
    } catch (int errorCode) {
        cout << "정수 예외: " << errorCode << endl;
    } catch (...) {
        cout << "알 수 없는 예외 발생" << endl;
    }
}

// ========== 표준 예외 클래스 ==========

void standardExceptions() {
    cout << "\n=== 표준 예외 클래스 ===" << endl;
    
    // std::exception: 모든 예외의 기본 클래스
    // std::runtime_error: 런타임 오류
    // std::logic_error: 로직 오류
    // std::invalid_argument: 잘못된 인수
    // std::out_of_range: 범위 초과
    // std::bad_alloc: 메모리 할당 실패
    
    try {
        std::vector<int> vec(5);
        vec.at(10) = 100;  // out_of_range 예외 발생
        
    } catch (const std::out_of_range& e) {
        cout << "범위 초과 예외: " << e.what() << endl;
    }
    
    try {
        int* ptr = new int[1000000000000];  // 메모리 할당 실패 가능
        delete[] ptr;
        
    } catch (const std::bad_alloc& e) {
        cout << "메모리 할당 실패: " << e.what() << endl;
    }
}

// ========== 사용자 정의 예외 ==========

// 사용자 정의 예외 클래스
class DivisionByZeroException : public std::exception {
private:
    string message;
    
public:
    DivisionByZeroException(const string& msg = "0으로 나눌 수 없습니다")
        : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class NegativeNumberException : public std::exception {
private:
    string message;
    
public:
    NegativeNumberException(const string& msg = "음수는 허용되지 않습니다")
        : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

double safeDivide(double a, double b) {
    if (b == 0) {
        throw DivisionByZeroException("나누는 수가 0입니다!");
    }
    return a / b;
}

double safeSquareRoot(double x) {
    if (x < 0) {
        throw NegativeNumberException("음수의 제곱근은 계산할 수 없습니다!");
    }
    return sqrt(x);
}

void customExceptions() {
    cout << "\n=== 사용자 정의 예외 ===" << endl;
    
    try {
        double result = safeDivide(10, 0);
        cout << "결과: " << result << endl;
        
    } catch (const DivisionByZeroException& e) {
        cout << "예외: " << e.what() << endl;
    }
    
    try {
        double result = safeSquareRoot(-5);
        cout << "결과: " << result << endl;
        
    } catch (const NegativeNumberException& e) {
        cout << "예외: " << e.what() << endl;
    }
}

// ========== 예외 전파 ==========

void function3() {
    throw std::runtime_error("function3에서 예외 발생!");
}

void function2() {
    function3();  // 예외가 전파됨
}

void function1() {
    try {
        function2();
    } catch (const std::runtime_error& e) {
        cout << "function1에서 예외 처리: " << e.what() << endl;
        throw;  // 예외를 다시 던짐
    }
}

void exceptionPropagation() {
    cout << "\n=== 예외 전파 ===" << endl;
    
    try {
        function1();
    } catch (const std::runtime_error& e) {
        cout << "최종 예외 처리: " << e.what() << endl;
    }
}

// ========== noexcept 지정자 ==========

void noThrowFunction() noexcept {
    // 이 함수는 예외를 던지지 않음을 보장
    cout << "예외를 던지지 않는 함수" << endl;
}

void mayThrowFunction() {
    throw std::runtime_error("예외 발생 가능");
}

void noexceptSpecifier() {
    cout << "\n=== noexcept 지정자 ===" << endl;
    
    noThrowFunction();
    
    try {
        mayThrowFunction();
    } catch (...) {
        cout << "예외 처리됨" << endl;
    }
}

// ========== RAII와 예외 안전성 ==========

class Resource {
private:
    int* data;
    
public:
    Resource() : data(new int[100]) {
        cout << "리소스 할당" << endl;
    }
    
    ~Resource() {
        delete[] data;
        cout << "리소스 해제" << endl;
    }
    
    void use() {
        throw std::runtime_error("리소스 사용 중 예외 발생!");
    }
};

void raiiExample() {
    cout << "\n=== RAII와 예외 안전성 ===" << endl;
    
    try {
        Resource res;  // 스택에 할당 (자동 해제 보장)
        res.use();
        
    } catch (const std::runtime_error& e) {
        cout << "예외 발생: " << e.what() << endl;
        // Resource의 소멸자가 자동으로 호출됨 (메모리 누수 없음)
    }
    
    cout << "리소스가 안전하게 해제되었습니다" << endl;
}

// ========== 스마트 포인터와 예외 ==========

void smartPointerException() {
    cout << "\n=== 스마트 포인터와 예외 ===" << endl;
    
    try {
        // std::unique_ptr: 예외 발생 시 자동 해제
        std::unique_ptr<int[]> arr(new int[1000]);
        
        // 예외 발생 가능한 작업
        throw std::runtime_error("작업 중 예외 발생!");
        
        // 예외가 발생해도 unique_ptr이 자동으로 메모리 해제
        
    } catch (const std::runtime_error& e) {
        cout << "예외 처리: " << e.what() << endl;
        cout << "메모리는 자동으로 해제되었습니다" << endl;
    }
}

// ========== 예외 안전성 보장 ==========

class SafeArray {
private:
    int* data;
    size_t size;
    
public:
    SafeArray(size_t s) : size(s) {
        data = new int[size];
        // 예외 발생 시 생성자가 완료되지 않으면 소멸자가 호출되지 않음
        // 하지만 이미 할당된 메모리는 누수됨
        // 스마트 포인터 사용 권장
    }
    
    ~SafeArray() {
        delete[] data;
    }
    
    int& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("인덱스가 범위를 벗어났습니다");
        }
        return data[index];
    }
};

void exceptionSafety() {
    cout << "\n=== 예외 안전성 보장 ===" << endl;
    
    try {
        SafeArray arr(10);
        arr[5] = 100;
        cout << "arr[5] = " << arr[5] << endl;
        
        arr[20] = 200;  // 예외 발생
        
    } catch (const std::out_of_range& e) {
        cout << "예외: " << e.what() << endl;
    }
}

int main() {
    basicExceptionHandling();
    multipleExceptionTypes();
    standardExceptions();
    customExceptions();
    exceptionPropagation();
    noexceptSpecifier();
    raiiExample();
    smartPointerException();
    exceptionSafety();
    
    return 0;
}

/*
 * 예외 처리 핵심 정리
 * 
 * 1. 예외 처리의 개념
 *    - 프로그램 실행 중 오류 처리
 *    - 정상적인 제어 흐름과 분리
 *    - 오류 정보 전달
 * 
 * 2. try-catch 블록
 *    try {
 *        // 예외 발생 가능 코드
 *    } catch (예외타입& e) {
 *        // 예외 처리
 *    }
 * 
 * 3. 예외 타입
 *    - std::exception: 기본 예외 클래스
 *    - std::runtime_error: 런타임 오류
 *    - std::logic_error: 로직 오류
 *    - 사용자 정의 예외 클래스
 * 
 * 4. 예외 전파
 *    - 예외는 호출 스택을 따라 전파
 *    - 적절한 catch 블록을 찾을 때까지
 *    - throw로 예외 재전파 가능
 * 
 * 5. noexcept 지정자
 *    - 함수가 예외를 던지지 않음을 보장
 *    - 컴파일러 최적화 가능
 *    - 예외 발생 시 std::terminate 호출
 * 
 * 6. RAII (Resource Acquisition Is Initialization)
 *    - 리소스 획득을 초기화와 연결
 *    - 소멸자에서 자동 해제
 *    - 예외 안전성 보장
 * 
 * 7. 예외 안전성 보장
 *    - 기본 보장: 객체 상태 유지
 *    - 강한 보장: 작업 완전 성공 또는 실패
 *    - 예외 중립: 예외 전파
 * 
 * 8. 스마트 포인터와 예외
 *    - unique_ptr, shared_ptr 사용
 *    - 자동 메모리 관리
 *    - 예외 발생 시에도 안전
 * 
 * 9. 예외 처리 모범 사례
 *    - 구체적인 예외 타입 사용
 *    - 예외는 예외적인 상황에만 사용
 *    - RAII 패턴 활용
 *    - 스마트 포인터 사용
 *    - 예외 안전성 고려
 * 
 * 10. 주의사항
 *     - 예외 처리 오버헤드
 *     - 모든 예외 처리 (catch(...))는 신중하게
 *     - 소멸자에서 예외 던지기 금지
 */

