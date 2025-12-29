# 개발 도구 소개

## Cursor (AI IDE)

Cursor는 AI 기능이 통합된 코드 에디터입니다.

### 주요 기능

- AI 코드 자동 완성
- 코드 리팩토링 지원
- 버그 수정 제안
- 코드 설명 생성

### 사용법

1. Cursor 설치 후 프로젝트 폴더 열기
2. AI 기능은 자동으로 활성화됨
3. 코드 작성 시 AI 제안 확인

## uv (가상환경 관리 도구)

uv는 빠른 Python 패키지 관리자입니다.

### 설치

```bash
pip install uv
```

### 가상환경 생성

```bash
uv venv
```

### 가상환경 활성화

Windows:
```bash
.venv\Scripts\activate
```

macOS/Linux:
```bash
source .venv/bin/activate
```

### 패키지 설치

```bash
uv pip install 패키지명
```

### requirements.txt로 설치

```bash
uv pip install -r requirements.txt
```

### 장점

- 매우 빠른 속도
- 간단한 명령어
- 효율적인 의존성 관리

