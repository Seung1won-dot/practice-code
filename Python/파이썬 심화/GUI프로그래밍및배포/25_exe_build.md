# PyInstaller를 사용한 실행 파일 생성

## 설치

```bash
pip install pyinstaller
```

## 기본 사용법

### 단일 파일로 생성

```bash
pyinstaller script.py
```

### 실행 파일만 생성 (폴더 없이)

```bash
pyinstaller --onefile script.py
```

### 창이 나타나지 않게 (GUI 앱)

```bash
pyinstaller --onefile --windowed script.py
```

### 아이콘 추가

```bash
pyinstaller --onefile --icon=icon.ico script.py
```

## 옵션

- `--onefile`: 단일 실행 파일 생성
- `--windowed` 또는 `-w`: 콘솔 창 숨기기
- `--icon=파일.ico`: 아이콘 지정
- `--name=이름`: 실행 파일 이름 지정
- `--add-data`: 추가 파일 포함

## 예시

```bash
pyinstaller --onefile --windowed --icon=app.ico --name=MyApp main.py
```

