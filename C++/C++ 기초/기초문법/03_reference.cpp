/*
 * 03_reference.cpp
 * 
 * 참조자(Reference)의 개념과 활용
 * - 포인터를 대체하는 강력한 기능
 * - 별칭(alias) 개념
 * - 함수 매개변수로 활용
 */

#include <iostream>

using std::cout;
using std::endl;

// ========== 참조자 기본 개념 ==========

void basicReference() {
    int num = 10;
    int& ref = num;  // ref는 num의 참조자 (별칭)
    
    cout << "=== 참조자 기본 ===" << endl;
    cout << "num의 값: " << num << endl;
    cout << "ref의 값: " << ref << endl;
    cout << "num의 주소: " << &num << endl;
    cout << "ref의 주소: " << &ref << endl;  // 같은 주소!
    
    // ref를 수정하면 num도 변경됨
    ref = 20;
    cout << "\nref = 20 후" << endl;
    cout << "num의 값: " << num << endl;
    cout << "ref의 값: " << ref << endl;
}

// ========== 참조자 vs 포인터 ==========

void referenceVsPointer() {
    int num = 100;
    
    // 포인터 방식
    int* ptr = &num;
    *ptr = 200;
    
    // 참조자 방식
    int& ref = num;
    ref = 300;
    
    cout << "\n=== 참조자 vs 포인터 ===" << endl;
    cout << "포인터로 변경 후 num: " << num << endl;
    cout << "참조자로 변경 후 num: " << num << endl;
    
    // 차이점
    cout << "\n차이점:" << endl;
    cout << "포인터: " << ptr << " (주소를 저장)" << endl;
    cout << "참조자: " << ref << " (값, 별칭)" << endl;
    cout << "포인터 역참조: " << *ptr << endl;
    cout << "참조자는 역참조 불필요: " << ref << endl;
}

// ========== 함수 매개변수로 사용 ==========

// 값 전달 (복사)
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // 원본은 변경되지 않음!
}

// 포인터 전달
void swapByPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 참조자 전달 (가장 깔끔!)
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void functionParameters() {
    int x = 10, y = 20;
    
    cout << "\n=== 함수 매개변수 ===" << endl;
    cout << "원본: x = " << x << ", y = " << y << endl;
    
    // 값 전달 (변경 안됨)
    swapByValue(x, y);
    cout << "값 전달 후: x = " << x << ", y = " << y << endl;
    
    // 포인터 전달
    x = 10; y = 20;
    swapByPointer(&x, &y);
    cout << "포인터 전달 후: x = " << x << ", y = " << y << endl;
    
    // 참조자 전달 (가장 간단!)
    x = 10; y = 20;
    swapByReference(x, y);
    cout << "참조자 전달 후: x = " << x << ", y = " << y << endl;
}

// ========== 참조자 반환 ==========

int& getReference(int arr[], int index) {
    return arr[index];  // 배열 요소의 참조자 반환
}

void returnReference() {
    int arr[] = {10, 20, 30, 40, 50};
    
    cout << "\n=== 참조자 반환 ===" << endl;
    cout << "원본 배열: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 참조자를 통해 배열 요소 수정
    getReference(arr, 2) = 999;
    
    cout << "수정 후 배열: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ========== const 참조자 ==========

void printValue(const int& ref) {
    // ref는 읽기 전용 (수정 불가)
    cout << "값: " << ref << endl;
    // ref = 100;  // 컴파일 오류!
}

void constReference() {
    int num = 42;
    const int& constRef = num;  // const 참조자
    
    cout << "\n=== const 참조자 ===" << endl;
    cout << "num: " << num << endl;
    cout << "constRef: " << constRef << endl;
    
    // constRef를 통해서는 수정 불가
    // constRef = 100;  // 오류!
    
    // 원본은 수정 가능
    num = 100;
    cout << "num 변경 후 constRef: " << constRef << endl;  // 같이 변경됨
    
    printValue(num);
}

// ========== 참조자 주의사항 ==========

void referenceWarning() {
    cout << "\n=== 참조자 주의사항 ===" << endl;
    
    // 1. 참조자는 반드시 초기화되어야 함
    int num = 10;
    int& ref = num;  // OK
    // int& ref2;     // 오류! 초기화 필요
    
    // 2. 참조자는 다른 변수를 참조할 수 없음 (재할당 불가)
    int a = 10, b = 20;
    int& ref3 = a;
    // ref3 = b;  // 이것은 a = b와 같음 (참조 변경이 아님!)
    cout << "ref3 = b 후: a = " << a << ", b = " << b << endl;
    
    // 3. NULL 참조자는 없음 (포인터와의 차이)
    // int& nullRef = nullptr;  // 오류!
    
    // 4. 참조자의 참조자는 없음
    int& ref4 = a;
    // int&& ref5 = ref4;  // 오류! (rvalue reference는 나중에 학습)
}

// ========== 배열 참조자 ==========

void arrayReference() {
    int arr[] = {1, 2, 3, 4, 5};
    int(&arrRef)[5] = arr;  // 배열 참조자
    
    cout << "\n=== 배열 참조자 ===" << endl;
    cout << "원본 배열: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    arrRef[2] = 999;
    
    cout << "참조자로 수정 후: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    basicReference();
    referenceVsPointer();
    functionParameters();
    returnReference();
    constReference();
    referenceWarning();
    arrayReference();
    
    return 0;
}

/*
 * 참조자(Reference) 핵심 정리
 * 
 * 1. 개념
 *    - 변수에 대한 별칭(alias)
 *    - 같은 메모리 공간을 다른 이름으로 접근
 *    - 포인터보다 안전하고 사용하기 쉬움
 * 
 * 2. 선언 방법
 *    - 타입& 참조자명 = 변수명;
 *    - 예: int& ref = num;
 * 
 * 3. 특징
 *    - 반드시 초기화 필요
 *    - 한 번 초기화되면 다른 변수를 참조할 수 없음
 *    - NULL 참조자 없음
 *    - 역참조 연산자(*) 불필요
 * 
 * 4. 포인터 vs 참조자
 *    포인터:
 *    - 주소를 저장하는 변수
 *    - NULL 가능
 *    - 재할당 가능
 *    - 역참조 필요 (*ptr)
 * 
 *    참조자:
 *    - 별칭 (같은 변수)
 *    - NULL 불가
 *    - 재할당 불가
 *    - 역참조 불필요
 * 
 * 5. 사용 시기
 *    - 함수 매개변수로 사용 (값 변경 필요 시)
 *    - 큰 객체를 전달할 때 (복사 비용 절감)
 *    - 반환값으로 사용 (주의해서 사용)
 * 
 * 6. const 참조자
 *    - 읽기 전용 참조자
 *    - 함수 매개변수로 자주 사용
 *    - 불필요한 복사 방지
 */

