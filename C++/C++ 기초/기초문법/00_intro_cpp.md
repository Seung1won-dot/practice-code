# C++ 언어 소개

## C++란?

C++는 1979년 비야네 스트롭스트룹(Bjarne Stroustrup)이 개발한 범용 프로그래밍 언어입니다. C 언어를 기반으로 객체지향 프로그래밍과 일반화 프로그래밍 기능을 추가하여 개발되었습니다.

## C++의 특징

### 1. 멀티 패러다임 언어
- **절차지향 프로그래밍**: C 스타일의 함수 기반 프로그래밍
- **객체지향 프로그래밍**: 클래스, 상속, 다형성 지원
- **일반화 프로그래밍**: 템플릿을 통한 제네릭 프로그래밍
- **함수형 프로그래밍 요소**: 람다 함수, 함수 객체

### 2. 높은 성능
- 컴파일 언어로 실행 속도가 매우 빠름
- 메모리 사용량을 정밀하게 제어 가능
- 하드웨어에 가까운 수준의 성능 제공

### 3. 풍부한 표준 라이브러리
- STL (Standard Template Library)
- 컨테이너, 알고리즘, 반복자 제공
- 파일 시스템, 스레드, 네트워킹 지원

## C 언어와의 차이점

### 1. 객체지향 프로그래밍
- **C**: 구조체와 함수만 제공
- **C++**: 클래스, 상속, 다형성, 캡슐화 지원

### 2. 네임스페이스
- **C**: 전역 네임스페이스만 존재
- **C++**: 네임스페이스를 통한 이름 충돌 방지

### 3. 참조자(Reference)
- **C**: 포인터만 사용
- **C++**: 참조자(&)를 통한 안전한 별칭 제공

### 4. 함수 오버로딩
- **C**: 같은 이름의 함수 불가능
- **C++**: 매개변수에 따라 같은 이름의 함수 다중 정의 가능

### 5. 기본 매개변수
- **C**: 지원하지 않음
- **C++**: 함수 매개변수에 기본값 지정 가능

### 6. 동적 메모리 할당
- **C**: malloc(), free() 사용
- **C++**: new, delete 연산자 사용 (생성자/소멸자 호출)

### 7. bool 타입
- **C**: int를 사용하여 0/1로 표현
- **C++**: bool 타입 직접 지원 (true/false)

### 8. 범위 기반 for문
- **C**: 지원하지 않음
- **C++**: 배열과 컨테이너를 쉽게 순회하는 for문 제공

## 컴파일러 설정

### 주요 컴파일러

#### 1. GCC (GNU Compiler Collection)
```bash
# 컴파일
g++ -o program program.cpp

# C++11 이상 표준 사용
g++ -std=c++11 -o program program.cpp

# 디버그 정보 포함
g++ -g -o program program.cpp
```

#### 2. MSVC (Microsoft Visual C++)
```bash
# Visual Studio Developer Command Prompt
cl /EHsc program.cpp

# C++11 이상 표준 사용
cl /std:c++11 /EHsc program.cpp
```

#### 3. Clang
```bash
# 컴파일
clang++ -o program program.cpp

# C++11 이상 표준 사용
clang++ -std=c++11 -o program program.cpp
```

### 컴파일 옵션

#### 표준 버전 지정
- `-std=c++98`: C++98 표준
- `-std=c++11`: C++11 표준 (현대적 C++의 시작)
- `-std=c++14`: C++14 표준
- `-std=c++17`: C++17 표준
- `-std=c++20`: C++20 표준

#### 최적화 옵션
- `-O0`: 최적화 없음 (디버깅용)
- `-O1`: 기본 최적화
- `-O2`: 높은 수준의 최적화 (권장)
- `-O3`: 최대 최적화

#### 경고 옵션
- `-Wall`: 모든 주요 경고 활성화
- `-Wextra`: 추가 경고 활성화
- `-Werror`: 경고를 오류로 처리

### 예제 컴파일 명령어
```bash
# 기본 컴파일
g++ -o hello hello.cpp

# 최적화 및 경고 포함
g++ -O2 -Wall -Wextra -std=c++11 -o hello hello.cpp

# 디버그 빌드
g++ -g -O0 -Wall -std=c++11 -o hello_debug hello.cpp
```

## C++ 표준 버전

### C++98/03
- 첫 번째 공식 표준
- STL 도입
- 기본 객체지향 기능

### C++11
- 현대적 C++의 시작
- auto 키워드
- 범위 기반 for문
- 스마트 포인터
- 람다 함수
- nullptr

### C++14
- C++11의 개선
- 일반화된 람다
- 변수 템플릿

### C++17
- 파일 시스템 라이브러리
- 구조화된 바인딩
- if constexpr

### C++20
- 코루틴
- 개념(Concepts)
- 모듈 시스템
- ranges 라이브러리

## 개발 환경 설정

### Visual Studio (Windows)
1. Visual Studio 설치
2. C++ 개발 워크로드 선택
3. 프로젝트 생성: "빈 프로젝트" 또는 "콘솔 애플리케이션"

### Code::Blocks (크로스 플랫폼)
1. Code::Blocks 설치
2. File → New → Project → Console Application
3. C++ 선택

### VS Code + 확장 프로그램
1. VS Code 설치
2. C/C++ 확장 프로그램 설치
3. tasks.json 설정 (빌드 작업)
4. launch.json 설정 (디버깅)

## 첫 번째 C++ 프로그램

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, C++!" << std::endl;
    return 0;
}
```

### 프로그램 구조 설명
- `#include <iostream>`: 입출력 스트림 라이브러리 포함
- `int main()`: 프로그램의 진입점
- `std::cout`: 표준 출력 스트림
- `<<`: 출력 연산자
- `std::endl`: 줄바꿈 및 버퍼 플러시
- `return 0`: 프로그램 정상 종료

## 다음 단계

1. **Hello World 프로그램**: 입출력과 네임스페이스 학습
2. **변수와 자료형**: C++의 자료형과 초기화 방식
3. **참조자**: 포인터를 대체하는 참조자 개념
4. **동적 메모리**: new/delete 연산자
5. **범위 기반 for문**: 현대적 C++의 순회 방법

