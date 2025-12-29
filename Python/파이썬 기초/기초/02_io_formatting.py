# 입출력과 문자열 포맷팅

# 기본 출력
print("Hello, World!")
print(123)
print(3.14)

# 여러 값 출력 (자동으로 공백으로 구분)
name = "홍길동"
age = 25
print("이름:", name, "나이:", age)

# sep 매개변수로 구분자 지정
print("2024", "01", "15", sep="-")  # 2024-01-15

# end 매개변수로 끝 문자 지정 (기본값: '\n')
print("첫 번째 줄", end=" ")
print("두 번째 줄")  # 첫 번째 줄 두 번째 줄

# 기본 입력 (프로그램 실행 시 사용자 입력 대기)
# user_name = input("이름을 입력하세요: ")
# print(f"안녕하세요, {user_name}님!")

# 숫자 입력 받기 (문자열로 받아서 형변환 필요)
# age_str = input("나이를 입력하세요: ")
# age = int(age_str)
# print(f"내년에는 {age + 1}살이 되시네요!")

# 한 줄에 여러 입력 받기
# x, y = input("두 숫자를 입력하세요 (공백으로 구분): ").split()
# x, y = int(x), int(y)
# print(f"합계: {x + y}")

name = "김철수"
age = 30
score = 95.5

print(f"이름: {name}, 나이: {age}세")
print(f"점수: {score:.2f}")  # 소수점 둘째 자리까지
print(f"나이 + 10 = {age + 10}")  # 표현식 사용 가능

# f-string에서 중괄호 출력하기
print(f"{{중괄호}} 출력: {{name}}")

print("이름: {}, 나이: {}세".format(name, age))
print("이름: {0}, 나이: {1}세, 이름 다시: {0}".format(name, age))  # 인덱스 사용
print("이름: {n}, 나이: {a}세".format(n=name, a=age))  # 키워드 인수

# format()에서 숫자 서식 지정
print("점수: {:.2f}".format(score))
print("정수: {:05d}".format(42))  # 5자리, 앞에 0으로 채움: 00042

print("이름: %s, 나이: %d세" % (name, age))
print("점수: %.2f" % score)

# % 서식 문자 종류
# %s: 문자열
# %d: 정수
# %f: 실수
# %x: 16진수
# %o: 8진수

result = "이름: " + name + ", 나이: " + str(age) + "세"
print(result)

# 정렬
text = "Python"
print(f"|{text:10}|")      # 왼쪽 정렬 (기본): |Python    |
print(f"|{text:>10}|")     # 오른쪽 정렬: |    Python|
print(f"|{text:^10}|")     # 가운데 정렬: |  Python  |

# 숫자 포맷팅
number = 1234.5678
print(f"기본: {number}")
print(f"소수점 2자리: {number:.2f}")
print(f"천 단위 구분: {number:,.2f}")
print(f"퍼센트: {0.85:.1%}")  # 85.0%

# 0으로 채우기
num = 42
print(f"5자리 0 채움: {num:05d}")  # 00042

print("첫 번째 줄")
print("두 번째 줄")
print("세 번째 줄")

print("첫 번째 줄\n두 번째 줄\n세 번째 줄")

print("""첫 번째 줄
두 번째 줄
세 번째 줄""")

# 파일 쓰기
with open("example.txt", "w", encoding="utf-8") as f:
    f.write("안녕하세요!\n")
    f.write("파이썬 파일 입출력 예제입니다.\n")

# 파일 읽기
with open("example.txt", "r", encoding="utf-8") as f:
    content = f.read()
    print("파일 내용:")
    print(content)
