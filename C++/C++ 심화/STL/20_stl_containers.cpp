/*
 * 20_stl_containers.cpp
 * 
 * STL 컨테이너 (Standard Template Library Containers)
 * - 시퀀스 컨테이너 (vector, list, deque)
 * - 연관 컨테이너 (map, set, multimap, multiset)
 * - 컨테이너 어댑터 (stack, queue, priority_queue)
 */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <string>

using std::cout;
using std::endl;
using std::string;

// ========== vector (동적 배열) ==========

void vectorExample() {
    cout << "=== vector (동적 배열) ===" << endl;
    
    std::vector<int> vec;
    
    // 요소 추가
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    
    cout << "크기: " << vec.size() << endl;
    cout << "용량: " << vec.capacity() << endl;
    
    // 인덱스 접근
    cout << "요소들: ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    // 반복자 사용
    cout << "반복자로 접근: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // 범위 기반 for문
    cout << "범위 기반 for문: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // 요소 삭제
    vec.pop_back();
    cout << "pop_back 후 크기: " << vec.size() << endl;
    
    // 중간 삽입
    vec.insert(vec.begin() + 1, 25);
    cout << "삽입 후: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// ========== list (이중 연결 리스트) ==========

void listExample() {
    cout << "\n=== list (이중 연결 리스트) ===" << endl;
    
    std::list<int> lst;
    
    lst.push_back(10);
    lst.push_back(20);
    lst.push_front(5);  // 앞에 추가
    lst.push_back(30);
    
    cout << "요소들: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    // 중간 삽입 (빠름)
    auto it = lst.begin();
    ++it;
    lst.insert(it, 15);
    
    cout << "삽입 후: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    // 요소 제거
    lst.remove(20);
    cout << "remove(20) 후: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;
}

// ========== deque (양방향 큐) ==========

void dequeExample() {
    cout << "\n=== deque (양방향 큐) ===" << endl;
    
    std::deque<int> dq;
    
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);   // 앞에 추가
    dq.push_back(30);
    dq.push_front(1);   // 앞에 추가
    
    cout << "요소들: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "앞 요소: " << dq.front() << endl;
    cout << "뒤 요소: " << dq.back() << endl;
    
    dq.pop_front();
    dq.pop_back();
    
    cout << "pop 후: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;
}

// ========== map (키-값 쌍) ==========

void mapExample() {
    cout << "\n=== map (키-값 쌍) ===" << endl;
    
    std::map<string, int> scores;
    
    // 요소 추가
    scores["홍길동"] = 95;
    scores["김철수"] = 87;
    scores["이영희"] = 92;
    scores["박민수"] = 78;
    
    // 접근
    cout << "홍길동의 점수: " << scores["홍길동"] << endl;
    
    // 순회
    cout << "모든 점수:" << endl;
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // 검색
    auto it = scores.find("이영희");
    if (it != scores.end()) {
        cout << "이영희 찾음: " << it->second << endl;
    }
    
    // 삭제
    scores.erase("박민수");
    cout << "삭제 후 크기: " << scores.size() << endl;
}

// ========== set (정렬된 집합) ==========

void setExample() {
    cout << "\n=== set (정렬된 집합) ===" << endl;
    
    std::set<int> numbers;
    
    numbers.insert(30);
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(10);  // 중복 무시
    
    cout << "요소들 (자동 정렬): ";
    for (int val : numbers) {
        cout << val << " ";
    }
    cout << endl;
    
    // 검색
    if (numbers.find(20) != numbers.end()) {
        cout << "20이 존재합니다" << endl;
    }
    
    // 개수
    cout << "크기: " << numbers.size() << endl;
}

// ========== unordered_map (해시 맵) ==========

void unorderedMapExample() {
    cout << "\n=== unordered_map (해시 맵) ===" << endl;
    
    std::unordered_map<string, string> phonebook;
    
    phonebook["홍길동"] = "010-1234-5678";
    phonebook["김철수"] = "010-2345-6789";
    phonebook["이영희"] = "010-3456-7890";
    
    cout << "전화번호부:" << endl;
    for (const auto& pair : phonebook) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // 검색 (평균 O(1))
    auto it = phonebook.find("김철수");
    if (it != phonebook.end()) {
        cout << "김철수 찾음: " << it->second << endl;
    }
}

// ========== stack (스택) ==========

void stackExample() {
    cout << "\n=== stack (스택) ===" << endl;
    
    std::stack<int> stk;
    
    stk.push(10);
    stk.push(20);
    stk.push(30);
    
    cout << "스택 크기: " << stk.size() << endl;
    cout << "최상단: " << stk.top() << endl;
    
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

// ========== queue (큐) ==========

void queueExample() {
    cout << "\n=== queue (큐) ===" << endl;
    
    std::queue<int> q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "큐 크기: " << q.size() << endl;
    cout << "앞 요소: " << q.front() << endl;
    cout << "뒤 요소: " << q.back() << endl;
    
    cout << "큐에서 제거: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// ========== priority_queue (우선순위 큐) ==========

void priorityQueueExample() {
    cout << "\n=== priority_queue (우선순위 큐) ===" << endl;
    
    std::priority_queue<int> pq;
    
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);
    
    cout << "우선순위 큐 (최대값 우선): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    // 최소값 우선 (greater 사용)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minPq;
    minPq.push(30);
    minPq.push(10);
    minPq.push(50);
    minPq.push(20);
    
    cout << "최소값 우선: ";
    while (!minPq.empty()) {
        cout << minPq.top() << " ";
        minPq.pop();
    }
    cout << endl;
}

// ========== 컨테이너 선택 가이드 ==========

void containerSelectionGuide() {
    cout << "\n=== 컨테이너 선택 가이드 ===" << endl;
    cout << "1. vector: 임의 접근, 끝에서 삽입/삭제가 많을 때" << endl;
    cout << "2. list: 중간 삽입/삭제가 많을 때" << endl;
    cout << "3. deque: 앞뒤 삽입/삭제가 많을 때" << endl;
    cout << "4. map: 키-값 쌍, 정렬 필요" << endl;
    cout << "5. set: 중복 제거, 정렬 필요" << endl;
    cout << "6. unordered_map: 키-값 쌍, 빠른 검색 필요" << endl;
    cout << "7. stack: LIFO 구조" << endl;
    cout << "8. queue: FIFO 구조" << endl;
    cout << "9. priority_queue: 우선순위 기반" << endl;
}

int main() {
    vectorExample();
    listExample();
    dequeExample();
    mapExample();
    setExample();
    unorderedMapExample();
    stackExample();
    queueExample();
    priorityQueueExample();
    containerSelectionGuide();
    
    return 0;
}

/*
 * STL 컨테이너 핵심 정리
 * 
 * 1. 시퀀스 컨테이너
 *    - vector: 동적 배열, 임의 접근 O(1)
 *    - list: 이중 연결 리스트, 삽입/삭제 O(1)
 *    - deque: 양방향 큐, 앞뒤 삽입/삭제 O(1)
 * 
 * 2. 연관 컨테이너
 *    - map: 키-값 쌍, 정렬됨, 검색 O(log n)
 *    - set: 정렬된 집합, 중복 없음
 *    - multimap: 중복 키 허용
 *    - multiset: 중복 값 허용
 * 
 * 3. 비정렬 연관 컨테이너 (C++11)
 *    - unordered_map: 해시 맵, 검색 평균 O(1)
 *    - unordered_set: 해시 집합
 * 
 * 4. 컨테이너 어댑터
 *    - stack: LIFO (Last In First Out)
 *    - queue: FIFO (First In First Out)
 *    - priority_queue: 우선순위 기반
 * 
 * 5. 공통 메서드
 *    - size(): 크기
 *    - empty(): 비어있는지 확인
 *    - clear(): 모든 요소 제거
 *    - begin(), end(): 반복자
 * 
 * 6. 반복자 (Iterator)
 *    - 컨테이너 요소 순회
 *    - begin(): 첫 요소
 *    - end(): 마지막 다음 요소
 *    - 역방향: rbegin(), rend()
 * 
 * 7. 범위 기반 for문 (C++11)
 *    for (auto val : container) {
 *        // ...
 *    }
 * 
 * 8. 성능 고려사항
 *    - 접근 패턴에 따라 적절한 컨테이너 선택
 *    - vector: 캐시 친화적, 빠른 순차 접근
 *    - list: 삽입/삭제 빠름, 순차 접근 느림
 *    - map: 정렬 필요 시
 *    - unordered_map: 빠른 검색 필요 시
 */

