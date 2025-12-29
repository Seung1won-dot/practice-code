# 연산자 (Operators)

a = 10
b = 3

print(f"a = {a}, b = {b}")
print(f"a + b = {a + b}")   # 덧셈: 13
print(f"a - b = {a - b}")   # 뺄셈: 7
print(f"a * b = {a * b}")   # 곱셈: 30
print(f"a / b = {a / b}")   # 나눗셈: 3.333...
print(f"a // b = {a // b}") # 몫: 3
print(f"a % b = {a % b}")   # 나머지: 1
print(f"a ** b = {a ** b}") # 거듭제곱: 1000

# 문자열 연산
str1 = "Hello"
str2 = "World"
print(f"str1 + str2 = {str1 + str2}")  # 연결: HelloWorld
print(f"str1 * 3 = {str1 * 3}")        # 반복: HelloHelloHello

x = 5
y = 8

print(f"x = {x}, y = {y}")
print(f"x == y: {x == y}")  # 같음: False
print(f"x != y: {x != y}")  # 다름: True
print(f"x < y: {x < y}")    # 작음: True
print(f"x > y: {x > y}")    # 큼: False
print(f"x <= y: {x <= y}")  # 작거나 같음: True
print(f"x >= y: {x >= y}")  # 크거나 같음: False

# 문자열 비교 (사전식 순서)
print(f"'apple' < 'banana': {'apple' < 'banana'}")  # True
print(f"'cat' > 'dog': {'cat' > 'dog'}")            # False

p = True
q = False

print(f"p = {p}, q = {q}")
print(f"p and q: {p and q}")  # AND: False
print(f"p or q: {p or q}")    # OR: True
print(f"not p: {not p}")      # NOT: False

age = 20
has_license = True

can_drive = age >= 18 and has_license
print(f"\n나이: {age}, 면허: {has_license}")
print(f"운전 가능: {can_drive}")

num = 10
print(f"초기값: {num}")

num += 5   # num = num + 5
print(f"num += 5: {num}")  # 15

num -= 3   # num = num - 3
print(f"num -= 3: {num}")  # 12

num *= 2   # num = num * 2
print(f"num *= 2: {num}")  # 24

num /= 4   # num = num / 4
print(f"num /= 4: {num}")  # 6.0

num //= 2  # num = num // 2
print(f"num //= 2: {num}")  # 3.0

num %= 2   # num = num % 2
print(f"num %= 2: {num}")   # 1.0

num = 8
num **= 2  # num = num ** 2
print(f"num **= 2: {num}")  # 64

fruits = ["apple", "banana", "orange"]

print(f"fruits = {fruits}")
print(f"'apple' in fruits: {'apple' in fruits}")      # True
print(f"'grape' in fruits: {'grape' in fruits}")      # False
print(f"'grape' not in fruits: {'grape' not in fruits}")  # True

# 문자열에서도 사용 가능
text = "Hello World"
print(f"\ntext = '{text}'")
print(f"'World' in text: {'World' in text}")  # True
print(f"'Python' in text: {'Python' in text}")  # False

a = [1, 2, 3]
b = [1, 2, 3]
c = a

print(f"a = {a}")
print(f"b = {b}")
print(f"c = a")

print(f"a == b: {a == b}")    # True (값이 같음)
print(f"a is b: {a is b}")    # False (다른 객체)
print(f"a is c: {a is c}")    # True (같은 객체)

# 정수는 작은 값들은 같은 객체를 참조 (최적화)
x = 256
y = 256
print(f"\nx = 256, y = 256")
print(f"x is y: {x is y}")    # True (작은 정수는 캐시됨)

x = 257
y = 257
print(f"x = 257, y = 257")
print(f"x is y: {x is y}")    # False (큰 정수는 다른 객체)

a = 5   # 0101 (이진수)
b = 3   # 0011 (이진수)

print(f"a = {a} (이진수: {bin(a)})")
print(f"b = {b} (이진수: {bin(b)})")
print(f"a & b = {a & b} (AND: {bin(a & b)})")      # 0001 = 1
print(f"a | b = {a | b} (OR: {bin(a | b)})")       # 0111 = 7
print(f"a ^ b = {a ^ b} (XOR: {bin(a ^ b)})")      # 0110 = 6
print(f"~a = {~a} (NOT)")                          # -6
print(f"a << 1 = {a << 1} (왼쪽 시프트: {bin(a << 1)})")  # 1010 = 10
print(f"a >> 1 = {a >> 1} (오른쪽 시프트: {bin(a >> 1)})")  # 0010 = 2

result = 2 + 3 * 4
print(f"2 + 3 * 4 = {result}")  # 14 (곱셈이 먼저)

result = (2 + 3) * 4
print(f"(2 + 3) * 4 = {result}")  # 20 (괄호가 먼저)

result = 2 ** 3 ** 2
print(f"2 ** 3 ** 2 = {result}")  # 512 (오른쪽부터)

age = 20
status = "성인" if age >= 18 else "미성년자"
print(f"나이: {age}, 상태: {status}")

score = 85
grade = "합격" if score >= 60 else "불합격"
print(f"점수: {score}, 결과: {grade}")
