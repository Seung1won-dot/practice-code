# 파일 조작 명령어

## 파일 내용 보기

```bash
cat file.txt        # 전체 내용 출력
cat -n file.txt     # 줄 번호와 함께 출력
cat file1 file2     # 여러 파일 연결 출력

head file.txt       # 앞 10줄만
head -n 5 file.txt  # 앞 5줄만

tail file.txt       # 뒤 10줄만
tail -n 20 file.txt # 뒤 20줄만
tail -f log.txt     # 실시간 추가 내용 감시 (로그 모니터링)
```

## 파일 복사

```bash
cp source.txt dest.txt          # 파일 복사
cp file.txt /backup/            # 다른 경로로 복사
cp -r mydir /backup/            # 디렉터리 전체 복사 (-r: 재귀)
cp -i file.txt dest.txt         # 덮어쓸 때 확인 (-i: 대화형)
cp -p file.txt dest.txt         # 속성 유지 (-p: preserve)
cp file*.txt backup/            # 와일드카드 사용
```

## 파일 이동/이름 변경

```bash
mv old.txt new.txt              # 이름 변경
mv file.txt /backup/            # 다른 경로로 이동
mv -i file.txt dest.txt         # 덮어쓸 때 확인
```

## 파일 삭제

```bash
rm file.txt         # 파일 삭제
rm -i file.txt      # 삭제 전 확인
rm -f file.txt      # 강제 삭제 (확인 없음)
rm -r dir           # 디렉터리와 내용 삭제
rm -rf dir          # 강제 재귀 삭제 (주의: 복구 불가)
```

> **경고**: `rm -rf /` 는 절대 실행하지 말 것. 시스템 전체가 삭제됨.

## 파일 검색

```bash
find /home -name "*.txt"        # 이름으로 검색
find . -type f -name "*.log"    # 현재 디렉터리에서 .log 파일
find /var -mtime -7             # 7일 이내 수정된 파일
find . -size +100M              # 100MB 이상 파일
find . -empty                   # 빈 파일/디렉터리

locate filename     # 인덱스 기반 빠른 검색 (updatedb 필요)
which python        # 명령어 경로 확인
whereis ls          # 실행파일, 소스, 매뉴얼 경로
```

## 파일 비교·정렬

```bash
diff file1.txt file2.txt        # 두 파일 차이
sort file.txt                   # 알파벳순 정렬
sort -n numbers.txt             # 숫자순 정렬
sort -r file.txt                # 역순 정렬
uniq file.txt                   # 연속 중복 제거 (sort 후 사용)
```
