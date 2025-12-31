/*
 * 05_range_based_for.cpp
 * 
 * 범위 기반 for문 (Range-based for loop)
 * - C++11에서 도입
 * - 배열과 컨테이너를 쉽게 순회
 * - 코드 가독성 향상
 */

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>

using std::cout;
using std::endl;

// ========== 기본 배열 순회 ==========

void basicArray() {
    cout << "=== 기본 배열 순회 ===" << endl;
    
    int arr[] = {10, 20, 30, 40, 50};
    
    // 전통적인 방법
    cout << "전통적인 for문: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 범위 기반 for문 (값 복사)
    cout << "범위 기반 for문 (값): ";
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
    
    // 범위 기반 for문 (참조자)
    cout << "범위 기반 for문 (참조자): ";
    for (int& element : arr) {
        element *= 2;  // 원본 배열 수정 가능
        cout << element << " ";
    }
    cout << endl;
    
    // 수정된 배열 확인
    cout << "수정된 배열: ";
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

// ========== std::array 사용 ==========

void stdArray() {
    cout << "\n=== std::array 사용 ===" << endl;
    
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    
    // 범위 기반 for문
    cout << "std::array 순회: ";
    for (auto element : arr) {
        cout << element << " ";
    }
    cout << endl;
    
    // auto와 함께 사용 (타입 자동 추론)
    cout << "auto 사용: ";
    for (auto& element : arr) {
        element += 10;
        cout << element << " ";
    }
    cout << endl;
}

// ========== std::vector 사용 ==========

void stdVector() {
    cout << "\n=== std::vector 사용 ===" << endl;
    
    std::vector<int> vec = {100, 200, 300, 400, 500};
    
    // 범위 기반 for문
    cout << "vector 순회: ";
    for (const auto& element : vec) {
        cout << element << " ";
    }
    cout << endl;
    
    // 인덱스가 필요한 경우 (C++20 이전)
    int index = 0;
    cout << "인덱스와 함께: ";
    for (const auto& element : vec) {
        cout << "[" << index++ << "]=" << element << " ";
    }
    cout << endl;
}

// ========== 문자열 순회 ==========

void stringIteration() {
    cout << "\n=== 문자열 순회 ===" << endl;
    
    std::string str = "Hello";
    
    // 문자 단위로 순회
    cout << "문자 단위: ";
    for (char c : str) {
        cout << c << " ";
    }
    cout << endl;
    
    // 참조자로 수정
    std::string str2 = "hello";
    cout << "원본: " << str2 << endl;
    for (char& c : str2) {
        c = std::toupper(c);  // 대문자로 변환
    }
    cout << "수정 후: " << str2 << endl;
}

// ========== std::map 순회 ==========

void mapIteration() {
    cout << "\n=== std::map 순회 ===" << endl;
    
    std::map<std::string, int> scores = {
        {"Alice", 95},
        {"Bob", 87},
        {"Charlie", 92}
    };
    
    // 키-값 쌍으로 순회
    cout << "점수표:" << endl;
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // C++17 구조화된 바인딩 (더 깔끔!)
    cout << "\n구조화된 바인딩 (C++17):" << endl;
    for (const auto& [name, score] : scores) {
        cout << name << ": " << score << endl;
    }
}

// ========== 초기화 리스트 순회 ==========

void initializerList() {
    cout << "\n=== 초기화 리스트 순회 ===" << endl;
    
    // 직접 초기화 리스트 사용
    cout << "초기화 리스트: ";
    for (int x : {1, 2, 3, 4, 5}) {
        cout << x << " ";
    }
    cout << endl;
}

// ========== 2차원 배열/벡터 순회 ==========

void twoDimensional() {
    cout << "\n=== 2차원 구조 순회 ===" << endl;
    
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // 중첩 범위 기반 for문
    cout << "2차원 벡터:" << endl;
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << "\t";
        }
        cout << endl;
    }
}

// ========== 값 vs 참조자 vs const 참조자 ==========

void valueReferenceConst() {
    cout << "\n=== 값 vs 참조자 ===" << endl;
    
    std::vector<int> vec = {10, 20, 30};
    
    // 1. 값으로 복사 (비효율적, 큰 객체의 경우)
    cout << "값으로 복사: ";
    for (int element : vec) {
        // element는 복사본
        cout << element << " ";
    }
    cout << endl;
    
    // 2. 참조자 (수정 가능)
    cout << "참조자 (수정 가능): ";
    for (int& element : vec) {
        element *= 2;
        cout << element << " ";
    }
    cout << endl;
    
    // 3. const 참조자 (읽기 전용, 효율적) - 권장!
    cout << "const 참조자 (읽기 전용): ";
    for (const int& element : vec) {
        // element는 읽기 전용
        cout << element << " ";
    }
    cout << endl;
    
    // 4. auto와 함께 (가장 간단)
    cout << "auto const 참조자: ";
    for (const auto& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

// ========== 사용자 정의 타입 순회 ==========

class MyContainer {
private:
    int data[5] = {1, 2, 3, 4, 5};
    
public:
    // begin(), end() 메서드 제공
    int* begin() { return data; }
    int* end() { return data + 5; }
    const int* begin() const { return data; }
    const int* end() const { return data + 5; }
};

void customType() {
    cout << "\n=== 사용자 정의 타입 ===" << endl;
    
    MyContainer container;
    
    cout << "사용자 정의 컨테이너: ";
    for (const auto& element : container) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    basicArray();
    stdArray();
    stdVector();
    stringIteration();
    mapIteration();
    initializerList();
    twoDimensional();
    valueReferenceConst();
    customType();
    
    return 0;
}

/*
 * 범위 기반 for문 핵심 정리
 * 
 * 1. 기본 문법
 *    for (타입 변수 : 범위) {
 *        // 코드
 *    }
 * 
 * 2. 사용 가능한 타입
 *    - 배열 (C 스타일)
 *    - std::array
 *    - std::vector, std::list 등 STL 컨테이너
 *    - std::string
 *    - std::map, std::set 등
 *    - begin(), end()를 제공하는 모든 타입
 * 
 * 3. 값 vs 참조자
 *    - 값: for (int x : arr) - 복사본 생성
 *    - 참조자: for (int& x : arr) - 원본 수정 가능
 *    - const 참조자: for (const int& x : arr) - 읽기 전용, 효율적 (권장)
 * 
 * 4. auto 키워드와 함께
 *    - for (auto x : arr) - 타입 자동 추론
 *    - for (const auto& x : arr) - 가장 일반적인 패턴
 * 
 * 5. 장점
 *    - 코드가 간결하고 읽기 쉬움
 *    - 인덱스 오류 방지
 *    - 모든 요소를 자동으로 순회
 * 
 * 6. 제한사항
 *    - 인덱스 정보가 필요 없을 때만 사용
 *    - 역순 순회 불가 (역방향 반복자 필요)
 *    - 일부 요소만 건너뛰기 어려움
 * 
 * 7. C++17 구조화된 바인딩
 *    for (const auto& [key, value] : map) {
 *        // 키와 값을 분리해서 사용
 *    }
 */

