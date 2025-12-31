/*
 * 04_new_delete.cpp
 * 
 * 동적 메모리 할당: new와 delete 연산자
 * - C의 malloc/free를 대체
 * - 생성자/소멸자 자동 호출
 * - 타입 안전성 향상
 */

#include <iostream>
#include <cstring>  // strcpy 사용

using std::cout;
using std::endl;

// ========== 기본 사용법 ==========

void basicNewDelete() {
    cout << "=== 기본 new/delete ===" << endl;
    
    // 단일 변수 동적 할당
    int* ptr = new int;  // 메모리 할당
    *ptr = 42;
    cout << "할당된 값: " << *ptr << endl;
    delete ptr;  // 메모리 해제
    ptr = nullptr;  // 안전을 위해 nullptr로 설정
    
    // 초기화와 함께 할당
    int* ptr2 = new int(100);  // 100으로 초기화
    cout << "초기화된 값: " << *ptr2 << endl;
    delete ptr2;
    
    // 배열 동적 할당
    int* arr = new int[5];  // 5개 정수 배열
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    
    cout << "배열: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;  // 배열은 delete[] 사용!
    arr = nullptr;
}

// ========== new vs malloc 비교 ==========

void newVsMalloc() {
    cout << "\n=== new vs malloc ===" << endl;
    
    // C 스타일 (malloc/free)
    int* cPtr = (int*)malloc(sizeof(int));
    *cPtr = 50;
    cout << "malloc으로 할당: " << *cPtr << endl;
    free(cPtr);
    
    // C++ 스타일 (new/delete)
    int* cppPtr = new int(50);
    cout << "new로 할당: " << *cppPtr << endl;
    delete cppPtr;
    
    // 차이점:
    // 1. new는 타입을 알고 있어서 캐스팅 불필요
    // 2. new는 생성자를 호출 (객체의 경우)
    // 3. new는 예외를 던질 수 있음 (메모리 부족 시)
}

// ========== 객체 동적 할당 ==========

class MyClass {
private:
    int value;
    char* name;
    
public:
    MyClass(int v, const char* n) : value(v) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cout << "생성자 호출: " << name << endl;
    }
    
    ~MyClass() {
        cout << "소멸자 호출: " << name << endl;
        delete[] name;  // 동적 할당된 메모리 해제
    }
    
    void display() {
        cout << "값: " << value << ", 이름: " << name << endl;
    }
};

void objectAllocation() {
    cout << "\n=== 객체 동적 할당 ===" << endl;
    
    // 스택에 할당 (자동 해제)
    {
        MyClass obj1(10, "스택 객체");
        obj1.display();
    }  // 여기서 자동으로 소멸자 호출
    
    // 힙에 할당 (수동 해제 필요)
    MyClass* obj2 = new MyClass(20, "힙 객체");
    obj2->display();
    delete obj2;  // 소멸자 호출됨
}

// ========== 2차원 배열 동적 할당 ==========

void twoDimensionalArray() {
    cout << "\n=== 2차원 배열 동적 할당 ===" << endl;
    
    int rows = 3, cols = 4;
    
    // 방법 1: 1차원 배열로 시뮬레이션
    int* arr1D = new int[rows * cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr1D[i * cols + j] = i * cols + j;
        }
    }
    
    cout << "1차원 배열 시뮬레이션:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr1D[i * cols + j] << "\t";
        }
        cout << endl;
    }
    delete[] arr1D;
    
    // 방법 2: 포인터 배열 사용
    int** arr2D = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr2D[i] = new int[cols];
    }
    
    // 값 할당
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr2D[i][j] = count++;
        }
    }
    
    cout << "\n2차원 배열:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr2D[i][j] << "\t";
        }
        cout << endl;
    }
    
    // 메모리 해제 (역순으로!)
    for (int i = 0; i < rows; i++) {
        delete[] arr2D[i];
    }
    delete[] arr2D;
}

// ========== new의 예외 처리 ==========

void exceptionHandling() {
    cout << "\n=== 예외 처리 ===" << endl;
    
    try {
        // 매우 큰 메모리 할당 시도
        int* huge = new int[10000000000LL];  // 메모리 부족 가능
        delete[] huge;
    }
    catch (std::bad_alloc& e) {
        cout << "메모리 할당 실패: " << e.what() << endl;
    }
    
    // nothrow 버전 (예외 대신 nullptr 반환)
    int* ptr = new(std::nothrow) int[10000000000LL];
    if (ptr == nullptr) {
        cout << "메모리 할당 실패 (nothrow)" << endl;
    }
    else {
        delete[] ptr;
    }
}

// ========== 메모리 누수 방지 ==========

void memoryLeakExample() {
    cout << "\n=== 메모리 누수 주의 ===" << endl;
    
    // 올바른 사용
    int* ptr1 = new int(100);
    delete ptr1;  // 반드시 해제!
    ptr1 = nullptr;  // 이중 해제 방지
    
    // 잘못된 사용 예시 (주석 처리)
    /*
    int* ptr2 = new int(200);
    // delete를 안 하면 메모리 누수!
    
    int* ptr3 = new int[10];
    delete ptr3;  // 오류! delete[]를 사용해야 함
    
    int* ptr4 = new int(300);
    delete ptr4;
    delete ptr4;  // 오류! 이중 해제
    */
    
    cout << "메모리 누수 예시는 주석 처리되어 있습니다." << endl;
}

// ========== placement new ==========

void placementNew() {
    cout << "\n=== placement new ===" << endl;
    
    // 미리 할당된 메모리에 객체 생성
    char buffer[sizeof(MyClass)];
    MyClass* obj = new(buffer) MyClass(30, "Placement");
    obj->display();
    
    // 소멸자만 명시적으로 호출 (delete 사용 안 함)
    obj->~MyClass();
}

int main() {
    basicNewDelete();
    newVsMalloc();
    objectAllocation();
    twoDimensionalArray();
    exceptionHandling();
    memoryLeakExample();
    placementNew();
    
    return 0;
}

/*
 * new와 delete 핵심 정리
 * 
 * 1. 기본 사용법
 *    - new 타입: 단일 변수 할당
 *    - new 타입[크기]: 배열 할당
 *    - delete 포인터: 단일 변수 해제
 *    - delete[] 포인터: 배열 해제
 * 
 * 2. malloc/free vs new/delete
 *    malloc/free:
 *    - C 스타일
 *    - 타입을 모름 (캐스팅 필요)
 *    - 생성자/소멸자 호출 안 됨
 *    - NULL 반환 (실패 시)
 * 
 *    new/delete:
 *    - C++ 스타일
 *    - 타입을 알고 있음
 *    - 생성자/소멸자 자동 호출
 *    - 예외 발생 (실패 시)
 * 
 * 3. 주의사항
 *    - new로 할당한 것은 반드시 delete로 해제
 *    - new[]로 할당한 것은 반드시 delete[]로 해제
 *    - 이중 해제 금지
 *    - 해제 후 포인터를 nullptr로 설정 (권장)
 * 
 * 4. 메모리 누수 방지
 *    - 할당과 해제를 짝을 맞춤
 *    - RAII 패턴 사용 (나중에 학습)
 *    - 스마트 포인터 사용 (나중에 학습)
 * 
 * 5. 예외 처리
 *    - new는 메모리 부족 시 std::bad_alloc 예외 발생
 *    - new(std::nothrow)는 예외 대신 nullptr 반환
 * 
 * 6. 초기화
 *    - new int(값): 초기화와 함께 할당
 *    - new int[크기]{}: 배열을 0으로 초기화
 */

