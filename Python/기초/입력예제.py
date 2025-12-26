# 기본 입력 받기
user_input = input()
print("입력받은 값:", user_input)

# 입력 안내 메시지 사용하기
# input() 함수의 소괄호 안에 문자열을 전달하면 해당 내용이 먼저 출력되어 사용자에게 입력할 내용을 안내합니다
name = input("이름을 입력하세요: ")
print("안녕하세요,", name, "님!")

# 숫자 입력 받기 (문자열로 입력 받은 후 형변환)
age_str = input("나이를 입력하세요: ")
age = int(age_str)
print("내년에는", age + 1, "살이 되시네요!")