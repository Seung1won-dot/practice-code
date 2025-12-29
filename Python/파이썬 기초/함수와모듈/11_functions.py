# 함수 (Functions)

def greet():
    print("안녕하세요!")

greet()

def greet_name(name):
    print(f"안녕하세요, {name}님!")

greet_name("홍길동")
greet_name("김철수")

def introduce(name, age):
    print(f"이름: {name}, 나이: {age}세")

introduce("홍길동", 25)
introduce("김철수", 30)

def greet_with_default(name, greeting="안녕하세요"):
    print(f"{greeting}, {name}님!")

greet_with_default("홍길동")  # 기본값 사용
greet_with_default("김철수", "반갑습니다")  # 기본값 덮어쓰기

def create_profile(name, age, city, job):
    print(f"이름: {name}, 나이: {age}, 도시: {city}, 직업: {job}")

# 위치 인수
create_profile("홍길동", 25, "서울", "개발자")

# 키워드 인수
create_profile(name="김철수", age=30, city="부산", job="디자이너")

# 혼합 사용 (위치 인수 먼저, 키워드 인수 나중)
create_profile("이영희", 28, city="인천", job="교사")

def add(a, b):
    return a + b

result = add(3, 5)
print(f"add(3, 5) = {result}")

# 여러 값 반환 (실제로는 튜플 반환)
def get_name_age():
    return "홍길동", 25

name, age = get_name_age()
print(f"이름: {name}, 나이: {age}")

def sum_numbers(*args):
    total = 0
    for num in args:
        total += num
    return total

print(f"sum_numbers(1, 2, 3): {sum_numbers(1, 2, 3)}")
print(f"sum_numbers(1, 2, 3, 4, 5): {sum_numbers(1, 2, 3, 4, 5)}")

# *args와 일반 매개변수 함께 사용
def greet_many(greeting, *names):
    for name in names:
        print(f"{greeting}, {name}님!")

greet_many("안녕하세요", "홍길동", "김철수", "이영희")

def print_info(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}: {value}")

print_info(name="홍길동", age=25, city="서울")

# 일반 매개변수와 함께 사용
def create_student(name, **info):
    print(f"이름: {name}")
    for key, value in info.items():
        print(f"  {key}: {value}")

create_student("홍길동", age=25, grade="A", city="서울")

def flexible_function(*args, **kwargs):
    print(f"위치 인수: {args}")
    print(f"키워드 인수: {kwargs}")

flexible_function(1, 2, 3, name="홍길동", age=25)

x = 10  # 전역 변수

def test_scope():
    x = 20  # 지역 변수
    print(f"함수 내부 x: {x}")

test_scope()
print(f"함수 외부 x: {x}")

# global 키워드
def modify_global():
    global x
    x = 30
    print(f"함수 내부에서 수정한 x: {x}")

modify_global()
print(f"함수 외부 x: {x}")

# 일반 함수
def square(x):
    return x ** 2

# 람다 함수
square_lambda = lambda x: x ** 2

print(f"square(5): {square(5)}")
print(f"square_lambda(5): {square_lambda(5)}")

def apply_operation(x, y, operation):
    return operation(x, y)

def add(a, b):
    return a + b

def multiply(a, b):
    return a * b

print(f"apply_operation(5, 3, add): {apply_operation(5, 3, add)}")
print(f"apply_operation(5, 3, multiply): {apply_operation(5, 3, multiply)}")

# 람다로 전달
print(f"apply_operation(5, 3, lambda a, b: a - b): {apply_operation(5, 3, lambda a, b: a - b)}")

def factorial(n):
    if n <= 1:
        return 1
    return n * factorial(n - 1)

print(f"factorial(5): {factorial(5)}")

# 피보나치 수열
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

print(f"fibonacci(7): {fibonacci(7)}")

def calculate_area(width, height):
    """
    사각형의 넓이를 계산합니다.
    
    매개변수:
        width (float): 너비
        height (float): 높이
    
    반환값:
        float: 사각형의 넓이
    """
    return width * height

print(f"calculate_area(5, 3): {calculate_area(5, 3)}")
print(f"함수 도움말:\n{calculate_area.__doc__}")

def add_numbers(a: int, b: int) -> int:
    """두 정수를 더합니다."""
    return a + b

def greet_person(name: str, age: int = 20) -> str:
    """인사말을 반환합니다."""
    return f"{name}님, 안녕하세요! (나이: {age}세)"

result = add_numbers(3, 5)
print(f"add_numbers(3, 5): {result}")

greeting = greet_person("홍길동", 25)
print(greeting)

def outer_function(x):
    def inner_function(y):
        return y * 2
    return inner_function(x) + 10

result = outer_function(5)
print(f"outer_function(5): {result}")

def make_multiplier(n):
    def multiplier(x):
        return x * n
    return multiplier

double = make_multiplier(2)
triple = make_multiplier(3)

print(f"double(5): {double(5)}")
print(f"triple(5): {triple(5)}")

def my_decorator(func):
    def wrapper():
        print("함수 실행 전")
        func()
        print("함수 실행 후")
    return wrapper

@my_decorator
def say_hello():
    print("안녕하세요!")

say_hello()

def calculator(operation, *numbers):
    """여러 숫자에 대해 연산을 수행합니다."""
    if not numbers:
        return 0
    
    if operation == "add":
        return sum(numbers)
    elif operation == "multiply":
        result = 1
        for num in numbers:
            result *= num
        return result
    elif operation == "max":
        return max(numbers)
    elif operation == "min":
        return min(numbers)
    else:
        return "알 수 없는 연산입니다."

print(f"add(1, 2, 3, 4): {calculator('add', 1, 2, 3, 4)}")
print(f"multiply(2, 3, 4): {calculator('multiply', 2, 3, 4)}")
print(f"max(5, 2, 8, 1): {calculator('max', 5, 2, 8, 1)}")

def validate_email(email):
    """이메일 형식을 검증합니다."""
    return "@" in email and "." in email.split("@")[1]

def validate_age(age):
    """나이를 검증합니다."""
    return isinstance(age, int) and 0 <= age <= 150

def create_user(name, email, age):
    """사용자를 생성합니다."""
    if not validate_email(email):
        return "잘못된 이메일 형식입니다."
    if not validate_age(age):
        return "잘못된 나이입니다."
    return f"사용자 {name}이(가) 생성되었습니다."

print(create_user("홍길동", "hong@example.com", 25))
print(create_user("김철수", "invalid-email", 25))
print(create_user("이영희", "lee@example.com", 200))
