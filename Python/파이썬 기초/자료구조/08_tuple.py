# 튜플 (Tuple) - 불변(immutable) 자료구조

tuple1 = (1, 2, 3)
print(f"tuple1: {tuple1}")

tuple2 = 1, 2, 3
print(f"tuple2: {tuple2}")

# 단일 요소 튜플 (쉼표 필수!)
single = (1,)  # 쉼표 없으면 정수로 인식
not_tuple = (1)  # 이것은 정수
print(f"single: {single}, 타입: {type(single)}")
print(f"not_tuple: {not_tuple}, 타입: {type(not_tuple)}")

# 빈 튜플
empty = ()
print(f"빈 튜플: {empty}")

# tuple() 생성자
tuple3 = tuple([1, 2, 3])
print(f"tuple([1, 2, 3]): {tuple3}")

my_tuple = (1, 2, 3)
print(f"원본 튜플: {my_tuple}")

# 튜플은 수정 불가능
# my_tuple[0] = 10  # TypeError 발생!

# 하지만 튜플 전체를 재할당은 가능
my_tuple = (10, 20, 30)
print(f"재할당 후: {my_tuple}")

fruits = ("apple", "banana", "orange", "grape", "kiwi")

print(f"전체 튜플: {fruits}")
print(f"첫 번째: {fruits[0]}")
print(f"마지막: {fruits[-1]}")
print(f"슬라이싱: {fruits[1:4]}")
print(f"역순: {fruits[::-1]}")

# 여러 값을 하나의 튜플로 묶기
packed = 1, 2, 3
print(f"패킹: {packed}, 타입: {type(packed)}")

# 함수에서 여러 값 반환 (실제로는 튜플 반환)
def get_name_age():
    return "홍길동", 25

result = get_name_age()
print(f"함수 반환값: {result}, 타입: {type(result)}")

# 튜플의 값을 여러 변수에 할당
person = ("홍길동", 25, "서울")
name, age, city = person
print(f"이름: {name}, 나이: {age}, 도시: {city}")

# 함수에서 반환된 튜플 언패킹
name, age = get_name_age()
print(f"언패킹 - 이름: {name}, 나이: {age}")

# 일부만 언패킹 (나머지는 *로 처리)
numbers = (1, 2, 3, 4, 5)
first, *rest, last = numbers
print(f"first: {first}, rest: {rest}, last: {last}")

numbers = (1, 2, 3, 2, 4, 2)

# count(): 값의 개수
print(f"numbers.count(2): {numbers.count(2)}")

# index(): 값의 첫 번째 인덱스
print(f"numbers.index(2): {numbers.index(2)}")

# len(): 길이
print(f"len(numbers): {len(numbers)}")

# in 연산자
print(f"3 in numbers: {3 in numbers}")

tuple1 = (1, 2, 3)
tuple2 = (4, 5, 6)

# 연결
combined = tuple1 + tuple2
print(f"연결: {combined}")

# 반복
repeated = tuple1 * 3
print(f"반복: {repeated}")

# 튜플: 불변, 메모리 효율적, 딕셔너리 키로 사용 가능
# 리스트: 가변, 다양한 메서드 제공

my_list = [1, 2, 3]
my_tuple = (1, 2, 3)

# 리스트는 수정 가능
my_list[0] = 10
print(f"리스트 수정 후: {my_list}")

# 튜플은 수정 불가
# my_tuple[0] = 10  # TypeError!

point1 = (3, 4)
point2 = (1, 2)

def distance(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5

dist = distance(point1, point2)
print(f"점1: {point1}, 점2: {point2}")
print(f"거리: {dist:.2f}")

# 튜플은 불변이라 딕셔너리 키로 사용 가능
coordinates = {
    (0, 0): "원점",
    (1, 0): "X축 위",
    (0, 1): "Y축 위"
}

print(f"좌표 딕셔너리: {coordinates}")
print(f"(0, 0)의 값: {coordinates[(0, 0)]}")

# 리스트는 딕셔너리 키로 사용 불가 (가변이므로)
# coordinates[[1, 2]] = "에러"  # TypeError!

a = 10
b = 20

print(f"교환 전: a={a}, b={b}")

# 튜플 언패킹으로 간단하게 교환
a, b = b, a
print(f"교환 후: a={a}, b={b}")

def greet(name, age, city):
    print(f"{name}님({age}세)은 {city}에 살고 있습니다.")

person = ("홍길동", 25, "서울")

# * 연산자로 언패킹하여 전달
greet(*person)

matrix = ((1, 2, 3), (4, 5, 6), (7, 8, 9))

print(f"중첩 튜플: {matrix}")
print(f"matrix[0]: {matrix[0]}")
print(f"matrix[0][1]: {matrix[0][1]}")

fruits = ("apple", "banana", "orange")

for fruit in fruits:
    print(f"과일: {fruit}")

for index, fruit in enumerate(fruits):
    print(f"인덱스 {index}: {fruit}")

colors = {
    "red": (255, 0, 0),
    "green": (0, 255, 0),
    "blue": (0, 0, 255),
    "white": (255, 255, 255),
    "black": (0, 0, 0)
}

def mix_colors(color1, color2):
    r1, g1, b1 = color1
    r2, g2, b2 = color2
    return ((r1 + r2) // 2, (g1 + g2) // 2, (b1 + b2) // 2)

red = colors["red"]
blue = colors["blue"]
purple = mix_colors(red, blue)

print(f"빨강: {red}")
print(f"파랑: {blue}")
print(f"혼합: {purple}")

def sum_numbers(*args):
    return sum(args)

numbers = (1, 2, 3, 4, 5)
result = sum_numbers(*numbers)
print(f"튜플 언패킹: {result}")

# 직접 전달
result2 = sum_numbers(1, 2, 3, 4, 5)
print(f"직접 전달: {result2}")
