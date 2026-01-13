# Java 개발 환경 설정

## Java란?

Java는 1995년 썬 마이크로시스템즈(Sun Microsystems)에서 개발한 객체지향 프로그래밍 언어입니다. "한 번 작성하면 어디서든 실행된다(Write Once, Run Anywhere)"는 철학을 가진 크로스 플랫폼 언어입니다.

## Java의 특징

### 1. 플랫폼 독립성
- **JVM (Java Virtual Machine)**: Java 바이트코드를 실행하는 가상 머신
- 컴파일된 `.class` 파일은 어떤 운영체제에서도 실행 가능
- JVM만 설치되어 있으면 동일한 코드 실행

### 2. 객체지향 프로그래밍
- 모든 것이 클래스와 객체로 구성
- 상속, 다형성, 캡슐화, 추상화 지원
- 재사용성과 유지보수성 향상

### 3. 자동 메모리 관리
- **가비지 컬렉션(GC)**: 자동으로 메모리 관리
- 개발자가 직접 메모리를 해제할 필요 없음
- 메모리 누수 위험 감소

### 4. 풍부한 표준 라이브러리
- Java API: 수천 개의 클래스 제공
- 컬렉션 프레임워크, 입출력, 네트워킹, GUI 등

### 5. 멀티스레딩 지원
- 동시에 여러 작업 수행 가능
- 스레드 생성 및 관리가 상대적으로 쉬움

## JDK 설치

### Windows
1. **Oracle JDK** 또는 **OpenJDK** 다운로드
   - 공식 웹사이트: https://www.oracle.com/java/technologies/downloads/
   - 또는 OpenJDK: https://adoptium.net/
2. 설치 프로그램 실행
3. 환경 변수 설정
   - `JAVA_HOME`: JDK 설치 경로 설정
   - `PATH`: `%JAVA_HOME%\bin` 추가

### macOS
```bash
# Homebrew 사용
brew install openjdk

# 또는 Oracle JDK 다운로드
```

### Linux
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install default-jdk

# CentOS/RHEL
sudo yum install java-11-openjdk-devel
```

## 설치 확인

```bash
# Java 버전 확인
java -version

# Java 컴파일러 버전 확인
javac -version
```

## 개발 도구

### 통합 개발 환경 (IDE)
- **IntelliJ IDEA**: JetBrains의 강력한 Java IDE (추천)
- **Eclipse**: 오픈소스 Java IDE
- **NetBeans**: Oracle의 Java IDE
- **VS Code**: 확장 기능으로 Java 개발 지원

### 텍스트 에디터
- **VS Code**: Java Extension Pack 설치
- **Sublime Text**: Java 개발 지원
- **Vim/Neovim**: 터미널 기반 에디터

## 첫 번째 Java 프로그램

### Hello World 예제

```java
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

### 컴파일 및 실행

```bash
# 컴파일 (.java → .class)
javac HelloWorld.java

# 실행
java HelloWorld
```

## Java 프로그램 구조

### 기본 구조
- **클래스**: 모든 코드는 클래스 안에 작성
- **메서드**: 클래스 내부의 함수
- **main 메서드**: 프로그램의 진입점
- **패키지**: 관련 클래스들을 그룹화

### 컴파일 과정
1. **소스 코드 작성**: `.java` 파일
2. **컴파일**: `javac`로 바이트코드 생성 (`.class` 파일)
3. **실행**: `java`로 JVM에서 실행

### JVM 동작 원리
1. 클래스 로더가 `.class` 파일 로드
2. 바이트코드 검증
3. 인터프리터 또는 JIT 컴파일러로 실행
4. 가비지 컬렉터가 메모리 관리

## Java 버전

### 주요 버전
- **Java 8 (LTS)**: 람다, 스트림 API 도입
- **Java 11 (LTS)**: 모듈 시스템, var 키워드
- **Java 17 (LTS)**: 현재 권장 버전
- **Java 21 (LTS)**: 최신 LTS 버전

### LTS (Long Term Support)
- 장기 지원 버전
- 기업 환경에서 주로 사용
- 보안 업데이트 제공 기간이 길음

## 패키지와 디렉토리 구조

### 패키지 선언
```java
package com.example.myapp;

public class MyClass {
    // ...
}
```

### 디렉토리 구조
```
project/
├── src/
│   └── com/
│       └── example/
│           └── myapp/
│               └── MyClass.java
└── bin/
    └── com/
        └── example/
            └── myapp/
                └── MyClass.class
```

## 다음 단계

1. **Hello World 프로그램**: 입출력과 클래스 구조 학습
2. **변수와 자료형**: Java의 기본 자료형과 변수 선언
3. **연산자**: 산술, 비교, 논리 연산자
4. **제어문**: 조건문과 반복문
5. **배열과 문자열**: 데이터 구조 기초
6. **클래스와 객체**: 객체지향 프로그래밍 시작

