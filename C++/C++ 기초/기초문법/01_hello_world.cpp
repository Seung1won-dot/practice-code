/*
 * 01_hello_world.cpp
 * 
 * C++ 입출력과 네임스페이스 기초
 * - std::cout, std::cin을 이용한 입출력
 * - 네임스페이스(namespace) 개념과 사용법
 */

#include <iostream>  // 입출력 스트림 라이브러리
#include <string>     // 문자열 클래스

// 방법 1: 네임스페이스 전체 사용 (권장하지 않음)
// using namespace std;

// 방법 2: 특정 요소만 사용 (권장)
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    // ========== 출력 (std::cout) ==========
    
    // 기본 출력
    cout << "Hello, World!" << endl;
    
    // 여러 값 출력
    int age = 25;
    string name = "홍길동";
    cout << "이름: " << name << ", 나이: " << age << endl;
    
    // 숫자 출력
    int num1 = 10, num2 = 20;
    cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
    
    // ========== 입력 (std::cin) ==========
    
    int userAge;
    string userName;
    
    cout << "이름을 입력하세요: ";
    cin >> userName;  // 공백 전까지만 입력받음
    
    cout << "나이를 입력하세요: ";
    cin >> userAge;
    
    cout << "입력하신 정보: " << userName << ", " << userAge << "세" << endl;
    
    // ========== 공백 포함 문자열 입력 ==========
    
    // cin >> 는 공백을 만나면 입력이 끝남
    // 공백 포함 문자열을 입력받으려면 getline() 사용
    
    cin.ignore();  // 이전 입력의 개행 문자 제거
    
    string fullName;
    cout << "전체 이름을 입력하세요 (공백 포함): ";
    std::getline(cin, fullName);  // std:: 네임스페이스 명시
    cout << "전체 이름: " << fullName << endl;
    
    // ========== 네임스페이스 사용 방법 비교 ==========
    
    // 방법 1: 네임스페이스 전체 지정
    std::cout << "std:: 네임스페이스 직접 사용" << std::endl;
    
    // 방법 2: using 선언 사용 (위에서 선언함)
    cout << "using 선언으로 간단히 사용" << endl;
    
    // ========== 여러 데이터 타입 입출력 ==========
    
    int integer;
    float decimal;
    char character;
    bool boolean;
    
    cout << "\n정수 입력: ";
    cin >> integer;
    
    cout << "실수 입력: ";
    cin >> decimal;
    
    cout << "문자 입력: ";
    cin >> character;
    
    cout << "불리언 입력 (0 또는 1): ";
    cin >> boolean;
    
    cout << "\n입력된 값들:" << endl;
    cout << "정수: " << integer << endl;
    cout << "실수: " << decimal << endl;
    cout << "문자: " << character << endl;
    cout << "불리언: " << std::boolalpha << boolean << endl;  // true/false로 출력
    
    return 0;
}

/*
 * 네임스페이스 (Namespace)란?
 * 
 * 1. 목적: 이름 충돌 방지
 *    - 같은 이름의 함수나 변수를 다른 네임스페이스에서 사용 가능
 * 
 * 2. 사용 방법:
 *    - std::cout: 네임스페이스 직접 지정 (가장 명확)
 *    - using std::cout: 특정 요소만 가져오기 (권장)
 *    - using namespace std: 전체 네임스페이스 가져오기 (비권장)
 * 
 * 3. 왜 using namespace std를 피해야 하나?
 *    - 이름 충돌 가능성 증가
 *    - 코드의 가독성 저하 (어디서 온 것인지 불명확)
 *    - 대규모 프로젝트에서 문제 발생 가능
 * 
 * 4. 입출력 스트림:
 *    - cout: 표준 출력 (console output)
 *    - cin: 표준 입력 (console input)
 *    - endl: 줄바꿈 + 버퍼 플러시
 *    - << : 출력 연산자 (insertion operator)
 *    - >> : 입력 연산자 (extraction operator)
 */

