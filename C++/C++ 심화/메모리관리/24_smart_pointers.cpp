/*
 * 24_smart_pointers.cpp
 * 
 * 스마트 포인터 (Smart Pointers)
 * - unique_ptr: 단일 소유권
 * - shared_ptr: 공유 소유권
 * - weak_ptr: 약한 참조
 * - RAII 패턴 구현
 */

#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;

// ========== unique_ptr (단일 소유권) ==========

void uniquePtrExample() {
    cout << "=== unique_ptr (단일 소유권) ===" << endl;
    
    // unique_ptr 생성
    std::unique_ptr<int> ptr1(new int(42));
    cout << "*ptr1 = " << *ptr1 << endl;
    
    // make_unique 사용 (C++14, 권장)
    auto ptr2 = std::make_unique<int>(100);
    cout << "*ptr2 = " << *ptr2 << endl;
    
    // 배열 할당
    auto arr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    
    cout << "배열: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 소유권 이전 (이동)
    std::unique_ptr<int> ptr3 = std::move(ptr1);
    // ptr1은 이제 nullptr (사용 불가)
    
    if (ptr1 == nullptr) {
        cout << "ptr1은 nullptr입니다" << endl;
    }
    
    cout << "*ptr3 = " << *ptr3 << endl;
    
    // 자동으로 메모리 해제됨
}

// ========== shared_ptr (공유 소유권) ==========

void sharedPtrExample() {
    cout << "\n=== shared_ptr (공유 소유권) ===" << endl;
    
    // shared_ptr 생성
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "참조 카운트: " << ptr1.use_count() << endl;
    
    {
        // 복사 생성 (참조 카운트 증가)
        std::shared_ptr<int> ptr2 = ptr1;
        cout << "ptr2 생성 후 참조 카운트: " << ptr1.use_count() << endl;
        
        std::shared_ptr<int> ptr3 = ptr1;
        cout << "ptr3 생성 후 참조 카운트: " << ptr1.use_count() << endl;
        
        // ptr2, ptr3가 스코프를 벗어나면 참조 카운트 감소
    }
    
    cout << "스코프 벗어난 후 참조 카운트: " << ptr1.use_count() << endl;
    
    // 참조 카운트가 0이 되면 자동으로 메모리 해제
}

// ========== weak_ptr (약한 참조) ==========

void weakPtrExample() {
    cout << "\n=== weak_ptr (약한 참조) ===" << endl;
    
    std::shared_ptr<int> shared = std::make_shared<int>(100);
    cout << "shared 참조 카운트: " << shared.use_count() << endl;
    
    // weak_ptr 생성 (참조 카운트 증가 안 함)
    std::weak_ptr<int> weak = shared;
    cout << "weak_ptr 생성 후 shared 참조 카운트: " << shared.use_count() << endl;
    
    // weak_ptr로 접근하려면 lock() 사용
    if (auto locked = weak.lock()) {
        cout << "weak_ptr로 접근: " << *locked << endl;
    }
    
    // shared_ptr 해제
    shared.reset();
    cout << "shared_ptr 해제 후 참조 카운트: " << shared.use_count() << endl;
    
    // weak_ptr은 expired()로 확인
    if (weak.expired()) {
        cout << "weak_ptr이 가리키는 객체가 해제되었습니다" << endl;
    }
}

// ========== 순환 참조 문제 ==========

struct Node;

struct Node {
    int data;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;  // 순환 참조 방지
    
    Node(int d) : data(d) {
        cout << "Node 생성: " << data << endl;
    }
    
    ~Node() {
        cout << "Node 소멸: " << data << endl;
    }
};

void circularReferenceExample() {
    cout << "\n=== 순환 참조 문제 해결 ===" << endl;
    
    auto node1 = std::make_shared<Node>(1);
    auto node2 = std::make_shared<Node>(2);
    
    node1->next = node2;
    node2->prev = node1;  // weak_ptr 사용으로 순환 참조 방지
    
    cout << "node1 참조 카운트: " << node1.use_count() << endl;
    cout << "node2 참조 카운트: " << node2.use_count() << endl;
    
    // node1, node2가 해제되면 자동으로 소멸됨
}

// ========== 커스텀 삭제자 ==========

void customDeleter() {
    cout << "\n=== 커스텀 삭제자 ===" << endl;
    
    // 파일 포인터를 위한 커스텀 삭제자
    auto fileDeleter = [](FILE* f) {
        if (f) {
            fclose(f);
            cout << "파일이 닫혔습니다" << endl;
        }
    };
    
    // unique_ptr with custom deleter
    std::unique_ptr<FILE, decltype(fileDeleter)> filePtr(
        fopen("test.txt", "w"), fileDeleter);
    
    if (filePtr) {
        fprintf(filePtr.get(), "Hello, World!");
        // 파일이 자동으로 닫힘
    }
}

// ========== 스마트 포인터와 컨테이너 ==========

void smartPointerWithContainer() {
    cout << "\n=== 스마트 포인터와 컨테이너 ===" << endl;
    
    std::vector<std::unique_ptr<int>> vec;
    
    // unique_ptr을 벡터에 추가 (이동)
    vec.push_back(std::make_unique<int>(10));
    vec.push_back(std::make_unique<int>(20));
    vec.push_back(std::make_unique<int>(30));
    
    cout << "벡터 요소들: ";
    for (const auto& ptr : vec) {
        cout << *ptr << " ";
    }
    cout << endl;
    
    // shared_ptr과 벡터
    std::vector<std::shared_ptr<int>> sharedVec;
    auto shared = std::make_shared<int>(100);
    
    sharedVec.push_back(shared);
    sharedVec.push_back(shared);  // 같은 객체 공유
    
    cout << "shared 참조 카운트: " << shared.use_count() << endl;
}

// ========== 예외 안전성 ==========

void exceptionSafety() {
    cout << "\n=== 예외 안전성 ===" << endl;
    
    try {
        auto ptr = std::make_unique<int[]>(1000);
        
        // 예외 발생 가능한 작업
        throw std::runtime_error("예외 발생!");
        
        // 예외가 발생해도 unique_ptr이 자동으로 메모리 해제
        
    } catch (const std::exception& e) {
        cout << "예외 처리: " << e.what() << endl;
        cout << "메모리는 자동으로 해제되었습니다" << endl;
    }
}

// ========== 성능 비교 ==========

void performanceComparison() {
    cout << "\n=== 성능 비교 ===" << endl;
    cout << "1. unique_ptr: 오버헤드 최소 (raw 포인터와 거의 동일)" << endl;
    cout << "2. shared_ptr: 참조 카운팅 오버헤드 있음" << endl;
    cout << "3. weak_ptr: shared_ptr보다 약간 더 많은 오버헤드" << endl;
    cout << "4. make_unique/make_shared 사용 권장 (예외 안전)" << endl;
}

// ========== 사용 가이드 ==========

void usageGuide() {
    cout << "\n=== 스마트 포인터 사용 가이드 ===" << endl;
    cout << "1. 기본적으로 unique_ptr 사용" << endl;
    cout << "2. 여러 곳에서 공유 필요 시 shared_ptr" << endl;
    cout << "3. 순환 참조 방지를 위해 weak_ptr 사용" << endl;
    cout << "4. make_unique, make_shared 사용 권장" << endl;
    cout << "5. raw 포인터는 스마트 포인터로 변환 불가능할 때만" << endl;
    cout << "6. get()으로 raw 포인터 얻기 (신중하게 사용)" << endl;
    cout << "7. reset()으로 명시적 해제 가능" << endl;
}

int main() {
    uniquePtrExample();
    sharedPtrExample();
    weakPtrExample();
    circularReferenceExample();
    customDeleter();
    smartPointerWithContainer();
    exceptionSafety();
    performanceComparison();
    usageGuide();
    
    return 0;
}

/*
 * 스마트 포인터 핵심 정리
 * 
 * 1. 스마트 포인터의 개념
 *    - 자동 메모리 관리
 *    - RAII 패턴 구현
 *    - 메모리 누수 방지
 *    - 예외 안전성 보장
 * 
 * 2. unique_ptr
 *    - 단일 소유권
 *    - 이동만 가능, 복사 불가
 *    - 오버헤드 최소
 *    - make_unique 사용 권장 (C++14)
 * 
 * 3. shared_ptr
 *    - 공유 소유권
 *    - 참조 카운팅
 *    - 복사 가능
 *    - make_shared 사용 권장
 *    - 순환 참조 주의
 * 
 * 4. weak_ptr
 *    - 약한 참조
 *    - 참조 카운트 증가 안 함
 *    - lock()으로 접근
 *    - expired()로 유효성 확인
 *    - 순환 참조 방지에 사용
 * 
 * 5. make_unique / make_shared
 *    - 예외 안전성 보장
 *    - 효율적인 메모리 할당
 *    - 권장 사용 방법
 * 
 * 6. 커스텀 삭제자
 *    - 기본 delete 대신 다른 함수 사용
 *    - 파일, 리소스 해제 등에 활용
 * 
 * 7. 스마트 포인터와 컨테이너
 *    - unique_ptr은 이동으로 추가
 *    - shared_ptr은 복사로 추가
 *    - 컨테이너가 자동으로 관리
 * 
 * 8. 예외 안전성
 *    - 예외 발생 시에도 자동 해제
 *    - 메모리 누수 방지
 * 
 * 9. 사용 시나리오
 *    - unique_ptr: 단일 소유권 필요
 *    - shared_ptr: 공유 필요
 *    - weak_ptr: 순환 참조 방지
 * 
 * 10. 주의사항
 *     - 순환 참조 (shared_ptr)
 *     - get()으로 얻은 raw 포인터 관리
 *     - this를 shared_ptr로 전달 시 주의
 *     - 성능 고려 (특히 shared_ptr)
 */

