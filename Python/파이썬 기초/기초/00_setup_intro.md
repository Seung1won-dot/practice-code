# 파이썬 설치 및 환경 설정

## 파이썬 설치

### Windows
1. 공식 웹사이트(https://www.python.org/downloads/)에서 최신 버전 다운로드
2. 설치 시 "Add Python to PATH" 옵션 체크 필수
3. 설치 완료 후 명령 프롬프트에서 `python --version`으로 확인

### macOS
- Homebrew 사용: `brew install python3`
- 또는 공식 웹사이트에서 설치 파일 다운로드

### Linux
- Ubuntu/Debian: `sudo apt update && sudo apt install python3`
- CentOS/RHEL: `sudo yum install python3`

## 가상환경 (venv) 개념

가상환경은 프로젝트별로 독립적인 Python 환경을 만들어주는 도구입니다.

### 왜 가상환경을 사용하나요?
- 프로젝트마다 다른 버전의 패키지를 사용할 수 있음
- 시스템 Python 환경을 깨끗하게 유지
- 다른 프로젝트와의 의존성 충돌 방지

### 가상환경 생성 및 사용

```bash
# 가상환경 생성
python -m venv myenv

# Windows에서 활성화
myenv\Scripts\activate

# macOS/Linux에서 활성화
source myenv/bin/activate

# 비활성화
deactivate
```

## .py와 .ipynb 차이점

### .py 파일 (Python Script)
- 일반적인 Python 스크립트 파일
- 텍스트 에디터나 IDE에서 작성
- 터미널에서 `python script.py`로 실행
- 전체 코드가 순차적으로 실행됨
- 프로덕션 코드, 모듈, 스크립트 작성에 적합

### .ipynb 파일 (Jupyter Notebook)
- Jupyter Notebook 형식의 파일 (JSON 기반)
- 셀(cell) 단위로 코드를 작성하고 실행
- 각 셀을 독립적으로 실행 가능
- 마크다운과 코드를 함께 사용 가능
- 데이터 분석, 실험, 교육용으로 적합
- 시각화 결과를 바로 확인 가능

### 언제 무엇을 사용할까?
- **.py**: 애플리케이션 개발, 라이브러리 작성, 프로덕션 코드
- **.ipynb**: 데이터 분석, 프로토타이핑, 학습, 문서화가 필요한 경우

