# 리디렉션과 파이프

## 표준 입출력

- **stdin** (0): 표준 입력 (키보드)
- **stdout** (1): 표준 출력 (화면)
- **stderr** (2): 표준 에러 (화면)

## 출력 리디렉션

```bash
# stdout을 파일로 (덮어쓰기)
ls > output.txt
ls 1> output.txt

# stdout을 파일로 (추가)
echo "추가" >> output.txt

# stderr를 파일로
command 2> error.txt

# stdout과 stderr를 각각
command > output.txt 2> error.txt

# stdout과 stderr를 같은 파일로
command > all.txt 2>&1
command &> all.txt
```

## 입력 리디렉션

```bash
# 파일 내용을 stdin으로
cat < input.txt
sort < data.txt

# 히어독 (Here Document)
cat << EOF
여러 줄 입력
EOF 끝날 때까지
EOF
```

## 파이프

```bash
# 명령의 출력을 다음 명령의 입력으로
ls -l | grep "\.txt"
cat file.txt | sort | uniq
ps aux | grep nginx
```

## 자주 쓰는 파이프 조합

```bash
# 특정 문자열이 있는 줄만
grep "error" log.txt

# 정렬 후 중복 제거
sort file.txt | uniq

# 줄 수 세기
cat file.txt | wc -l

# 페이지 단위로 보기
ls -l | less

# 한 줄에 하나씩
cat file.txt | tr ' ' '\n'
```
