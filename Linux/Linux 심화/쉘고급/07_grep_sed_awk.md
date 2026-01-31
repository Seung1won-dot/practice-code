# grep, sed, awk

## grep - 패턴 검색

```bash
grep "pattern" file.txt       # 패턴이 있는 줄 출력
grep -i "pattern" file.txt    # 대소문자 무시
grep -v "pattern" file.txt    # 매칭되지 않는 줄만
grep -n "pattern" file.txt    # 줄 번호 함께 출력
grep -r "pattern" ./dir       # 디렉터리 재귀 검색
grep -l "pattern" *.txt       # 매칭되는 파일명만
grep -c "pattern" file.txt    # 매칭 개수만

# 정규표현식
grep "^start" file.txt        # 줄 처음이 start
grep "end$" file.txt          # 줄 끝이 end
grep -E "a|b" file.txt        # a 또는 b (확장 정규식)
```

## sed - 스트림 편집

```bash
# 치환 (첫 번째만)
sed 's/old/new/' file.txt

# 치환 (전역)
sed 's/old/new/g' file.txt

# 특정 줄만
sed '3s/old/new/' file.txt

# 파일 수정 (-i)
sed -i 's/old/new/g' file.txt

# 줄 삭제
sed '3d' file.txt             # 3번째 줄 삭제
sed '/pattern/d' file.txt     # pattern 있는 줄 삭제

# 여러 명령
sed -e 's/a/A/g' -e 's/b/B/g' file.txt
```

## awk - 텍스트 처리

```bash
# 기본: 공백으로 구분된 필드
awk '{print $1}' file.txt     # 첫 번째 필드
awk '{print $1, $3}' file.txt # 1번째, 3번째 필드
awk '{print $NF}' file.txt    # 마지막 필드

# 구분자 지정
awk -F: '{print $1}' /etc/passwd

# 조건
awk '$3 > 100 {print $1}' file.txt
awk '/pattern/ {print}' file.txt

# BEGIN, END
awk 'BEGIN{sum=0} {sum+=$1} END{print sum}' file.txt
```
