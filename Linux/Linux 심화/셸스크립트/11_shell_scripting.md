# 셸 스크립트

## 기본 구조

```bash
#!/bin/bash
# shebang - 이 스크립트를 bash로 실행

echo "Hello, World!"
```

## 실행

```bash
chmod +x script.sh
./script.sh

# 또는
bash script.sh
```

## 변수

```bash
name="Alice"
echo $name
echo ${name}

# 읽기 전용
readonly PI=3.14

# 명령 실행 결과
files=$(ls)
today=$(date +%Y-%m-%d)
```

## 인자

```bash
# $0: 스크립트명, $1, $2...: 인자
echo "첫 번째 인자: $1"
echo "인자 개수: $#"
echo "모든 인자: $@"
```

## 조건문

```bash
if [ -f file.txt ]; then
    echo "파일 존재"
elif [ -d dir ]; then
    echo "디렉터리 존재"
else
    echo "없음"
fi
```

### 조건 테스트

```bash
[ -f file ]    # 일반 파일
[ -d dir ]     # 디렉터리
[ -e path ]    # 존재
[ -r file ]    # 읽기 가능
[ -w file ]    # 쓰기 가능
[ -x file ]    # 실행 가능
[ -z "$var" ]  # 빈 문자열
[ -n "$var" ]  # 비어있지 않음
[ $a -eq $b ]  # 같음
[ $a -ne $b ]  # 다름
[ $a -lt $b ]  # 미만
[ $a -le $b ]  # 이하
[ $a -gt $b ]  # 초과
[ $a -ge $b ]  # 이상
```

## 반복문

```bash
# for
for i in 1 2 3; do
    echo $i
done

for file in *.txt; do
    echo $file
done

# while
while [ $i -lt 10 ]; do
    echo $i
    ((i++))
done
```

## 함수

```bash
myfunc() {
    echo "인자: $1, $2"
    return 0
}
myfunc "hello" "world"
```
