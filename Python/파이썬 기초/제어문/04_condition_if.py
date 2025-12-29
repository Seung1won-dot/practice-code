# 조건문 (if, elif, else)

age = 20

if age >= 18:
    print("성인입니다.")
    print("투표가 가능합니다.")

score = 85

if score >= 60:
    print("합격입니다!")
else:
    print("불합격입니다.")

score = 92

if score >= 90:
    grade = "A"
    print(f"점수: {score}, 등급: {grade}")
elif score >= 80:
    grade = "B"
    print(f"점수: {score}, 등급: {grade}")
elif score >= 70:
    grade = "C"
    print(f"점수: {score}, 등급: {grade}")
elif score >= 60:
    grade = "D"
    print(f"점수: {score}, 등급: {grade}")
else:
    grade = "F"
    print(f"점수: {score}, 등급: {grade}")

age = 25
has_license = True

if age >= 18:
    print("성인입니다.")
    if has_license:
        print("운전이 가능합니다.")
    else:
        print("면허가 필요합니다.")
else:
    print("미성년자입니다.")

age = 20
has_license = True
has_car = False

# and 연산자
if age >= 18 and has_license:
    print("운전 자격이 있습니다.")

# or 연산자
if has_license or has_car:
    print("운전 관련 자격이 있습니다.")

# not 연산자
if not has_car:
    print("차가 없습니다.")

# 복합 조건
if age >= 18 and has_license and not has_car:
    print("운전은 가능하지만 차가 없습니다.")

temperature = 25

if temperature > 30:
    print("날씨가 덥습니다.")
elif temperature > 20:
    print("날씨가 따뜻합니다.")
elif temperature > 10:
    print("날씨가 시원합니다.")
else:
    print("날씨가 춥습니다.")

fruits = ["apple", "banana", "orange"]
user_input = "apple"

if user_input in fruits:
    print(f"{user_input}는 과일 목록에 있습니다.")
else:
    print(f"{user_input}는 과일 목록에 없습니다.")

username = "admin"

if username == "admin":
    print("관리자로 로그인했습니다.")
elif username == "guest":
    print("게스트로 로그인했습니다.")
else:
    print("일반 사용자로 로그인했습니다.")

age = 20
status = "성인" if age >= 18 else "미성년자"
print(f"나이: {age}, 상태: {status}")

score = 85
result = "합격" if score >= 60 else "불합격"
print(f"점수: {score}, 결과: {result}")

# 중첩 삼항 연산자
score = 92
grade = "A" if score >= 90 else ("B" if score >= 80 else "C")
print(f"점수: {score}, 등급: {grade}")

username = "user123"
password = "pass456"
correct_username = "user123"
correct_password = "pass456"

if username == correct_username:
    if password == correct_password:
        print("로그인 성공!")
    else:
        print("비밀번호가 틀렸습니다.")
else:
    print("사용자 이름이 틀렸습니다.")

if username == correct_username and password == correct_password:
    print("로그인 성공!")
elif username == correct_username:
    print("비밀번호가 틀렸습니다.")
else:
    print("사용자 이름이 틀렸습니다.")

korean = 85
english = 90
math = 78

average = (korean + english + math) / 3

if average >= 90:
    grade = "A"
    comment = "우수"
elif average >= 80:
    grade = "B"
    comment = "양호"
elif average >= 70:
    grade = "C"
    comment = "보통"
elif average >= 60:
    grade = "D"
    comment = "미흡"
else:
    grade = "F"
    comment = "불량"

print(f"평균: {average:.2f}")
print(f"등급: {grade}")
print(f"평가: {comment}")

# pass는 아무것도 하지 않지만 문법적으로 필요할 때 사용
age = 20

if age >= 18:
    pass  # 나중에 구현할 코드
else:
    print("미성년자입니다.")

# 빈 값들은 False로 평가됨
empty_list = []
empty_string = ""
zero = 0
none_value = None

if empty_list:
    print("리스트에 값이 있습니다.")
else:
    print("리스트가 비어있습니다.")

if empty_string:
    print("문자열에 값이 있습니다.")
else:
    print("문자열이 비어있습니다.")

if zero:
    print("0이 아닙니다.")
else:
    print("0입니다.")

if none_value:
    print("None이 아닙니다.")
else:
    print("None입니다.")
