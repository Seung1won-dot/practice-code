/*
 * 21_stl_algorithms.cpp
 * 
 * STL 알고리즘 (Standard Template Library Algorithms)
 * - 검색 알고리즘 (find, count, search)
 * - 정렬 알고리즘 (sort, partial_sort)
 * - 변환 알고리즘 (transform, for_each)
 * - 수치 알고리즘 (accumulate, inner_product)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <functional>

using std::cout;
using std::endl;
using std::string;

// ========== 검색 알고리즘 ==========

void searchAlgorithms() {
    cout << "=== 검색 알고리즘 ===" << endl;
    
    std::vector<int> vec = {10, 20, 30, 40, 50, 30, 60};
    
    // find: 값 찾기
    auto it = std::find(vec.begin(), vec.end(), 30);
    if (it != vec.end()) {
        cout << "30을 찾았습니다. 위치: " << (it - vec.begin()) << endl;
    }
    
    // count: 개수 세기
    int count = std::count(vec.begin(), vec.end(), 30);
    cout << "30의 개수: " << count << endl;
    
    // find_if: 조건에 맞는 요소 찾기
    auto it2 = std::find_if(vec.begin(), vec.end(), 
                            [](int n) { return n > 40; });
    if (it2 != vec.end()) {
        cout << "40보다 큰 첫 번째 값: " << *it2 << endl;
    }
    
    // count_if: 조건에 맞는 요소 개수
    int count2 = std::count_if(vec.begin(), vec.end(),
                               [](int n) { return n > 30; });
    cout << "30보다 큰 값의 개수: " << count2 << endl;
    
    // binary_search: 이진 탐색 (정렬된 컨테이너)
    std::vector<int> sorted = {10, 20, 30, 40, 50};
    bool found = std::binary_search(sorted.begin(), sorted.end(), 30);
    cout << "30 검색 결과: " << (found ? "찾음" : "없음") << endl;
}

// ========== 정렬 알고리즘 ==========

void sortAlgorithms() {
    cout << "\n=== 정렬 알고리즘 ===" << endl;
    
    std::vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "정렬 전: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // sort: 정렬
    std::sort(vec.begin(), vec.end());
    cout << "오름차순 정렬: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // 내림차순 정렬
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    cout << "내림차순 정렬: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // 람다로 정렬
    std::vector<string> words = {"apple", "banana", "cherry", "date"};
    std::sort(words.begin(), words.end(), 
              [](const string& a, const string& b) {
                  return a.length() < b.length();
              });
    cout << "길이순 정렬: ";
    for (const string& w : words) {
        cout << w << " ";
    }
    cout << endl;
    
    // partial_sort: 일부만 정렬
    std::vector<int> vec2 = {64, 34, 25, 12, 22, 11, 90};
    std::partial_sort(vec2.begin(), vec2.begin() + 3, vec2.end());
    cout << "상위 3개만 정렬: ";
    for (int val : vec2) {
        cout << val << " ";
    }
    cout << endl;
}

// ========== 변환 알고리즘 ==========

void transformAlgorithms() {
    cout << "\n=== 변환 알고리즘 ===" << endl;
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> result(vec.size());
    
    // transform: 각 요소에 함수 적용
    std::transform(vec.begin(), vec.end(), result.begin(),
                   [](int n) { return n * n; });
    
    cout << "원본: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "제곱: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    // for_each: 각 요소에 함수 적용 (변환 없음)
    cout << "for_each로 출력: ";
    std::for_each(vec.begin(), vec.end(),
                  [](int n) { cout << n * 2 << " "; });
    cout << endl;
    
    // 두 컨테이너를 결합
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    std::vector<int> sum(3);
    
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), sum.begin(),
                   std::plus<int>());
    
    cout << "벡터 합: ";
    for (int val : sum) {
        cout << val << " ";
    }
    cout << endl;
}

// ========== 수치 알고리즘 ==========

void numericAlgorithms() {
    cout << "\n=== 수치 알고리즘 ===" << endl;
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // accumulate: 합계
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    cout << "합계: " << sum << endl;
    
    // 곱셈
    int product = std::accumulate(vec.begin(), vec.end(), 1,
                                  std::multiplies<int>());
    cout << "곱셈: " << product << endl;
    
    // inner_product: 내적
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    int dot = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);
    cout << "내적: " << dot << endl;
    
    // partial_sum: 부분합
    std::vector<int> vec3 = {1, 2, 3, 4, 5};
    std::vector<int> partial(5);
    std::partial_sum(vec3.begin(), vec3.end(), partial.begin());
    
    cout << "부분합: ";
    for (int val : partial) {
        cout << val << " ";
    }
    cout << endl;
}

// ========== 제거 알고리즘 ==========

void removeAlgorithms() {
    cout << "\n=== 제거 알고리즘 ===" << endl;
    
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    
    cout << "원본: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // remove: 실제로 제거하지 않고 뒤로 이동 (erase와 함께 사용)
    auto newEnd = std::remove(vec.begin(), vec.end(), 2);
    vec.erase(newEnd, vec.end());
    
    cout << "2 제거 후: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // unique: 연속된 중복 제거
    std::vector<int> vec2 = {1, 1, 2, 2, 3, 3, 4};
    auto newEnd2 = std::unique(vec2.begin(), vec2.end());
    vec2.erase(newEnd2, vec2.end());
    
    cout << "연속 중복 제거: ";
    for (int val : vec2) {
        cout << val << " ";
    }
    cout << endl;
}

// ========== 복사 알고리즘 ==========

void copyAlgorithms() {
    cout << "\n=== 복사 알고리즘 ===" << endl;
    
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> dest(5);
    
    // copy: 복사
    std::copy(source.begin(), source.end(), dest.begin());
    
    cout << "복사 결과: ";
    for (int val : dest) {
        cout << val << " ";
    }
    cout << endl;
    
    // copy_if: 조건에 맞는 것만 복사
    std::vector<int> source2 = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> even;
    
    std::copy_if(source2.begin(), source2.end(), std::back_inserter(even),
                 [](int n) { return n % 2 == 0; });
    
    cout << "짝수만 복사: ";
    for (int val : even) {
        cout << val << " ";
    }
    cout << endl;
}

// ========== 비교 알고리즘 ==========

void comparisonAlgorithms() {
    cout << "\n=== 비교 알고리즘 ===" << endl;
    
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::vector<int> vec3 = {1, 2, 3, 4, 6};
    
    // equal: 두 범위가 같은지 확인
    bool isEqual = std::equal(vec1.begin(), vec1.end(), vec2.begin());
    cout << "vec1 == vec2: " << (isEqual ? "true" : "false") << endl;
    
    isEqual = std::equal(vec1.begin(), vec1.end(), vec3.begin());
    cout << "vec1 == vec3: " << (isEqual ? "true" : "false") << endl;
    
    // lexicographical_compare: 사전식 비교
    bool isLess = std::lexicographical_compare(vec1.begin(), vec1.end(),
                                                vec3.begin(), vec3.end());
    cout << "vec1 < vec3: " << (isLess ? "true" : "false") << endl;
}

// ========== 최대/최소 알고리즘 ==========

void minMaxAlgorithms() {
    cout << "\n=== 최대/최소 알고리즘 ===" << endl;
    
    std::vector<int> vec = {3, 7, 2, 9, 1, 5};
    
    // min_element, max_element: 최소/최대 요소 반복자
    auto minIt = std::min_element(vec.begin(), vec.end());
    auto maxIt = std::max_element(vec.begin(), vec.end());
    
    cout << "최소값: " << *minIt << " (위치: " << (minIt - vec.begin()) << ")" << endl;
    cout << "최대값: " << *maxIt << " (위치: " << (maxIt - vec.begin()) << ")" << endl;
    
    // minmax_element: 최소와 최대 동시에
    auto minmax = std::minmax_element(vec.begin(), vec.end());
    cout << "최소: " << *minmax.first << ", 최대: " << *minmax.second << endl;
}

int main() {
    searchAlgorithms();
    sortAlgorithms();
    transformAlgorithms();
    numericAlgorithms();
    removeAlgorithms();
    copyAlgorithms();
    comparisonAlgorithms();
    minMaxAlgorithms();
    
    return 0;
}

/*
 * STL 알고리즘 핵심 정리
 * 
 * 1. 알고리즘의 특징
 *    - 컨테이너와 독립적
 *    - 반복자를 통해 작동
 *    - <algorithm> 헤더에 정의
 * 
 * 2. 검색 알고리즘
 *    - find: 값 찾기
 *    - find_if: 조건에 맞는 요소 찾기
 *    - count: 개수 세기
 *    - count_if: 조건에 맞는 개수
 *    - binary_search: 이진 탐색 (정렬 필요)
 * 
 * 3. 정렬 알고리즘
 *    - sort: 정렬
 *    - partial_sort: 일부만 정렬
 *    - stable_sort: 안정 정렬
 *    - nth_element: n번째 요소만 제자리에
 * 
 * 4. 변환 알고리즘
 *    - transform: 각 요소 변환
 *    - for_each: 각 요소에 함수 적용
 *    - replace: 값 교체
 *    - replace_if: 조건에 맞는 값 교체
 * 
 * 5. 수치 알고리즘
 *    - accumulate: 누적 합/곱
 *    - inner_product: 내적
 *    - partial_sum: 부분합
 *    - adjacent_difference: 인접 차이
 * 
 * 6. 제거 알고리즘
 *    - remove: 값 제거 (erase와 함께 사용)
 *    - remove_if: 조건에 맞는 것 제거
 *    - unique: 연속 중복 제거
 * 
 * 7. 복사 알고리즘
 *    - copy: 복사
 *    - copy_if: 조건에 맞는 것만 복사
 *    - copy_n: n개 복사
 * 
 * 8. 람다 함수 활용
 *    - 알고리즘과 함께 람다 사용
 *    - 간결한 코드 작성
 *    - 예: [](int n) { return n * 2; }
 * 
 * 9. 함수 객체 (Functor)
 *    - std::plus, std::minus 등
 *    - 알고리즘에 전달 가능
 * 
 * 10. 성능 고려사항
 *     - 알고리즘 선택에 따라 성능 차이
 *     - 정렬된 컨테이너는 binary_search 사용
 *     - remove는 실제로 제거하지 않음 (erase 필요)
 */

