# 기본 명령어

## 현재 위치 확인

```bash
pwd
# Print Working Directory - 현재 디렉터리 경로 출력
# 예: /home/user/documents
```

## 디렉터리 내용 보기

```bash
ls              # 현재 디렉터리 파일 목록
ls -l           # 상세 정보 (권한, 소유자, 크기, 날짜)
ls -a           # 숨김 파일 포함 (점으로 시작하는 파일)
ls -la          # -l과 -a 조합
ls -lh          # 크기를 사람이 읽기 쉬운 형태로 (KB, MB)
ls -lt          # 수정 시간순 정렬
ls /etc         # 특정 경로의 내용
ls *.txt        # 와일드카드로 txt 파일만
```

## 디렉터리 이동

```bash
cd /home/user       # 절대 경로로 이동
cd documents        # 상대 경로로 이동
cd ..               # 상위 디렉터리로
cd ~                # 홈 디렉터리로
cd -                # 이전 디렉터리로
cd                  # 홈으로 (cd ~ 와 동일)
```

### 경로 구분
- **절대 경로**: `/`로 시작 (루트부터)
- **상대 경로**: 현재 위치 기준
- `~`: 홈 디렉터리
- `.`: 현재 디렉터리
- `..`: 상위 디렉터리

## 디렉터리 생성

```bash
mkdir mydir         # 디렉터리 생성
mkdir -p a/b/c      # 부모 디렉터리 함께 생성
mkdir dir1 dir2     # 여러 개 한번에 생성
```

## 디렉터리 삭제

```bash
rmdir mydir         # 빈 디렉터리만 삭제
rm -r mydir         # 디렉터리와 내용 삭제 (주의!)
rm -rf mydir        # 확인 없이 강제 삭제 (매우 주의!)
```

## 기타 유용한 명령어

```bash
clear               # 화면 지우기 (Ctrl+L과 동일)
date                # 현재 날짜·시간
cal                 # 달력
whoami              # 현재 사용자명
hostname            # 호스트 이름
echo "hello"        # 문자열 출력
```
