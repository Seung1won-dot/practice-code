# C 언어 개발 환경 설정

## C 컴파일러 설치

### Windows
1. **MinGW-w64** 설치
   - 공식 웹사이트에서 다운로드
   - 또는 MSYS2를 통해 설치
   - 환경 변수 PATH에 추가

2. **Visual Studio** 설치
   - Visual Studio Community 버전 다운로드
   - "C++를 사용한 데스크톱 개발" 워크로드 선택
   - MSVC 컴파일러 포함

### macOS
- **Xcode Command Line Tools** 설치
```bash
xcode-select --install
```

- **Homebrew**를 통한 설치
```bash
brew install gcc
```

### Linux
- **Ubuntu/Debian**
```bash
sudo apt update
sudo apt install build-essential
```

- **CentOS/RHEL**
```bash
sudo yum groupinstall "Development Tools"
```

## 개발 도구

### 통합 개발 환경 (IDE)
- **Code::Blocks**: 크로스 플랫폼 C/C++ IDE
- **Dev-C++**: Windows용 경량 IDE
- **Visual Studio**: Microsoft 통합 개발 환경
- **CLion**: JetBrains의 C/C++ IDE

### 텍스트 에디터
- **VS Code**: 확장 기능으로 C 개발 지원
- **Vim/Neovim**: 터미널 기반 에디터
- **Sublime Text**: 가벼운 텍스트 에디터

## 첫 번째 C 프로그램

### Hello World 예제
```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

### 컴파일 및 실행
```bash
# 컴파일
gcc hello.c -o hello

# 실행 (Windows)
hello.exe

# 실행 (macOS/Linux)
./hello
```

## C 프로그램 구조

### 기본 구조
- `#include`: 헤더 파일 포함
- `main()`: 프로그램 진입점
- 함수 정의: 사용자 정의 함수
- 주석: `//` 또는 `/* */`

### 컴파일 과정
1. 전처리 (Preprocessing): `#include`, `#define` 처리
2. 컴파일 (Compiling): 소스 코드를 어셈블리 코드로 변환
3. 어셈블 (Assembling): 어셈블리 코드를 오브젝트 파일로 변환
4. 링킹 (Linking): 오브젝트 파일들을 연결하여 실행 파일 생성

## 디버깅

### GDB (GNU Debugger)
```bash
# 컴파일 시 디버그 정보 포함
gcc -g program.c -o program

# GDB 실행
gdb program
```

### 주요 GDB 명령어
- `break`: 중단점 설정
- `run`: 프로그램 실행
- `next`: 다음 줄 실행
- `print`: 변수 값 출력
- `quit`: GDB 종료

