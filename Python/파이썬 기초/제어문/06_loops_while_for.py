# 반복문 (while, for)

count = 0
while count < 5:
    print(f"카운트: {count}")
    count += 1

total = 0
num = 1

while num <= 10:
    total += num
    num += 1

print(f"1부터 10까지의 합: {total}")

count = 0
while True:
    count += 1
    print(f"반복 횟수: {count}")
    if count >= 3:
        break  # 루프 탈출

num = 0
while num < 10:
    num += 1
    if num % 2 == 0:  # 짝수면 건너뛰기
        continue
    print(f"홀수: {num}")

fruits = ["apple", "banana", "orange"]

for fruit in fruits:
    print(f"과일: {fruit}")

# range(stop): 0부터 stop-1까지
for i in range(5):
    print(f"i = {i}")

# range(start, stop): start부터 stop-1까지
print("\nrange(2, 6):")
for i in range(2, 6):
    print(f"i = {i}")

# range(start, stop, step): start부터 stop-1까지 step씩 증가
print("\nrange(0, 10, 2):")
for i in range(0, 10, 2):
    print(f"i = {i}")

# 역순
print("\nrange(10, 0, -1):")
for i in range(10, 0, -1):
    print(f"i = {i}")

total = 0
for i in range(1, 11):
    total += i
print(f"1부터 10까지의 합: {total}")

fruits = ["apple", "banana", "orange"]

for index, fruit in enumerate(fruits):
    print(f"인덱스 {index}: {fruit}")

# 시작 인덱스 지정
print("\nenumerate(fruits, start=1):")
for index, fruit in enumerate(fruits, start=1):
    print(f"인덱스 {index}: {fruit}")

names = ["홍길동", "김철수", "이영희"]
ages = [25, 30, 28]

for name, age in zip(names, ages):
    print(f"{name}님의 나이는 {age}세입니다.")

student = {
    "name": "홍길동",
    "age": 20,
    "grade": "A"
}

# 키만 순회
print("키만 순회:")
for key in student:
    print(f"키: {key}")

# 키와 값 순회
print("\n키와 값 순회:")
for key, value in student.items():
    print(f"{key}: {value}")

# 값만 순회
print("\n값만 순회:")
for value in student.values():
    print(f"값: {value}")

# 구구단 출력
for i in range(2, 4):  # 2단, 3단만
    print(f"\n{i}단:")
    for j in range(1, 10):
        print(f"{i} x {j} = {i * j}")

# for 문 사용
squares = []
for i in range(5):
    squares.append(i ** 2)
print(f"for 문: {squares}")

# 리스트 컴프리헨션 사용 (더 간결)
squares = [i ** 2 for i in range(5)]
print(f"컴프리헨션: {squares}")

text = "Python"

for char in text:
    print(char)

# 인덱스와 함께
for index, char in enumerate(text):
    print(f"인덱스 {index}: {char}")

# for 문의 else는 break 없이 완료되면 실행
for i in range(5):
    print(i)
else:
    print("반복문이 정상적으로 완료되었습니다.")

# break로 중단되면 else 실행 안 됨
for i in range(5):
    if i == 3:
        break
    print(i)
else:
    print("이 메시지는 출력되지 않습니다.")

import random

target = random.randint(1, 10)
attempts = 0
max_attempts = 3

# 실제 게임은 input()을 사용하지만, 여기서는 시뮬레이션
guesses = [5, 7, 3]  # 예시 추측값

for guess in guesses:
    attempts += 1
    if guess == target:
        print(f"정답입니다! {attempts}번 만에 맞췄습니다.")
        break
    elif guess < target:
        print(f"{guess}보다 큽니다.")
    else:
        print(f"{guess}보다 작습니다.")
    
    if attempts >= max_attempts:
        print(f"기회를 모두 사용했습니다. 정답은 {target}이었습니다.")
        break

def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

print(f"5! = {factorial(5)}")
print(f"10! = {factorial(10)}")

numbers = [3, 7, 2, 9, 1, 5]

max_value = numbers[0]
for num in numbers:
    if num > max_value:
        max_value = num

print(f"리스트: {numbers}")
print(f"최대값: {max_value}")

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 짝수만 필터링
even_numbers = []
for num in numbers:
    if num % 2 == 0:
        even_numbers.append(num)

print(f"원본: {numbers}")
print(f"짝수: {even_numbers}")

# while: 조건이 만족될 때까지 반복 (횟수를 모를 때)
# for: 정해진 횟수나 시퀀스를 순회할 때

# while True:
#     user_input = input("1부터 10 사이의 숫자를 입력하세요: ")
#     if user_input.isdigit() and 1 <= int(user_input) <= 10:
#         break
#     print("잘못된 입력입니다.")

for i in range(3):
    print(f"반복 {i + 1}")
