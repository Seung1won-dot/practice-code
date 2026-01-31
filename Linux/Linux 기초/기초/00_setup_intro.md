# Linux 환경 설정

## Linux 설치 방법

### 가상 머신 (권장)
- **VirtualBox**: 무료, 오라클 제공
- **VMware Workstation Player**: 개인용 무료
- **Hyper-V**: Windows Pro/Enterprise 내장

### WSL (Windows Subsystem for Linux)
```bash
# Windows PowerShell (관리자)에서
wsl --install
```
- Windows 10/11에서 Linux 터미널 사용
- Ubuntu, Debian 등 배포판 선택 가능

### 듀얼 부팅
- Windows와 Linux를 동일 PC에서 선택 부팅
- 디스크 파티션 분할 필요

### 클라우드
- AWS EC2, Google Cloud, Azure VM
- Ubuntu 등 AMI/이미지로 즉시 생성

## 터미널과 쉘

### 터미널 (Terminal)
- CLI(Command Line Interface)를 제공하는 프로그램
- 터미널 에뮬레이터: GNOME Terminal, Konsole, xterm 등

### 쉘 (Shell)
- 사용자 명령을 해석해 커널에 전달
- **Bash**: 가장 널리 사용 (기본 쉘)
- **Zsh**: 확장 기능 많음 (macOS 기본)
- **Fish**: 사용자 친화적

### 프롬프트
```
user@hostname:~$
```
- `user`: 현재 사용자
- `hostname`: 컴퓨터 이름
- `~`: 홈 디렉터리
- `$`: 일반 사용자, `#`: root

## 기본 단축키

| 단축키 | 설명 |
|--------|------|
| Ctrl + C | 실행 중단 |
| Ctrl + Z | 작업 일시정지 (bg, fg로 복귀) |
| Ctrl + D | 로그아웃 / EOF |
| Ctrl + L | 화면 지우기 (clear) |
| Tab | 명령/경로 자동완성 |
| ↑ / ↓ | 명령어 이력 탐색 |
| Ctrl + R | 역방향 검색 |

## 명령어 형식

```
명령어 [옵션] [인자]
```
- 옵션: `-l`, `--long` 형식
- 인자: 파일명, 경로 등

## 도움말 보기

```bash
man ls          # 매뉴얼 (manual)
ls --help       # 도움말
info ls         # 상세 정보
```
