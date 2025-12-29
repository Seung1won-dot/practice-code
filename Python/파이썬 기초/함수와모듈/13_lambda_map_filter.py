# 람다 함수, map, filter, reduce

# 일반 함수
def square(x):
    return x ** 2

# 람다 함수
square_lambda = lambda x: x ** 2

print(f"square(5): {square(5)}")
print(f"square_lambda(5): {square_lambda(5)}")

# 람다 함수는 이름 없이 바로 사용 가능
result = (lambda x: x ** 2)(5)
print(f"(lambda x: x ** 2)(5): {result}")

add = lambda a, b: a + b
multiply = lambda x, y, z: x * y * z

print(f"add(3, 5): {add(3, 5)}")
print(f"multiply(2, 3, 4): {multiply(2, 3, 4)}")

# 절댓값
abs_value = lambda x: x if x >= 0 else -x
print(f"abs_value(-5): {abs_value(-5)}")
print(f"abs_value(5): {abs_value(5)}")

# 최대값
max_value = lambda a, b: a if a > b else b
print(f"max_value(10, 20): {max_value(10, 20)}")

numbers = [1, 2, 3, 4, 5]

# 각 요소를 제곱
squares = list(map(lambda x: x ** 2, numbers))
print(f"원본: {numbers}")
print(f"제곱: {squares}")

# 일반 함수와 함께 사용
def double(x):
    return x * 2

doubled = list(map(double, numbers))
print(f"2배: {doubled}")

numbers1 = [1, 2, 3]
numbers2 = [4, 5, 6]

# 두 리스트의 요소를 더하기
sums = list(map(lambda x, y: x + y, numbers1, numbers2))
print(f"numbers1: {numbers1}")
print(f"numbers2: {numbers2}")
print(f"합: {sums}")

words = ["apple", "banana", "orange"]

# 대문자로 변환
uppercase = list(map(str.upper, words))
print(f"원본: {words}")
print(f"대문자: {uppercase}")

# 길이 구하기
lengths = list(map(len, words))
print(f"길이: {lengths}")

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 짝수만 필터링
evens = list(filter(lambda x: x % 2 == 0, numbers))
print(f"원본: {numbers}")
print(f"짝수: {evens}")

# 5보다 큰 수만 필터링
greater_than_5 = list(filter(lambda x: x > 5, numbers))
print(f"5보다 큰 수: {greater_than_5}")

words = ["apple", "banana", "orange", "kiwi", "grape"]

# 길이가 5 이상인 단어만
long_words = list(filter(lambda w: len(w) >= 5, words))
print(f"원본: {words}")
print(f"길이 5 이상: {long_words}")

# 'a'로 시작하는 단어만
starts_with_a = list(filter(lambda w: w.startswith('a'), words))
print(f"'a'로 시작: {starts_with_a}")

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 짝수를 제곱하기
even_squares = list(map(lambda x: x ** 2, filter(lambda x: x % 2 == 0, numbers)))
print(f"원본: {numbers}")
print(f"짝수 제곱: {even_squares}")

# 또는 리스트 컴프리헨션으로 (더 읽기 쉬움)
even_squares2 = [x ** 2 for x in numbers if x % 2 == 0]
print(f"컴프리헨션: {even_squares2}")

from functools import reduce

numbers = [1, 2, 3, 4, 5]

# 합계 구하기
total = reduce(lambda x, y: x + y, numbers)
print(f"원본: {numbers}")
print(f"합계: {total}")

# 곱 구하기
product = reduce(lambda x, y: x * y, numbers)
print(f"곱: {product}")

# 최대값 구하기
maximum = reduce(lambda x, y: x if x > y else y, numbers)
print(f"최대값: {maximum}")

numbers = [1, 2, 3, 4, 5]

# 초기값 10과 함께 합계
total_with_init = reduce(lambda x, y: x + y, numbers, 10)
print(f"원본: {numbers}")
print(f"합계 (초기값 10): {total_with_init}")

students = [
    {"name": "홍길동", "age": 25},
    {"name": "김철수", "age": 20},
    {"name": "이영희", "age": 30}
]

# 나이로 정렬
sorted_by_age = sorted(students, key=lambda s: s["age"])
print("나이로 정렬:")
for student in sorted_by_age:
    print(f"  {student}")

# 이름으로 정렬
sorted_by_name = sorted(students, key=lambda s: s["name"])
print("\n이름으로 정렬:")
for student in sorted_by_name:
    print(f"  {student}")

students = [
    {"name": "홍길동", "score": 85},
    {"name": "김철수", "score": 92},
    {"name": "이영희", "score": 78}
]

# 최고 점수 학생
top_student = max(students, key=lambda s: s["score"])
print(f"최고 점수 학생: {top_student}")

# 최저 점수 학생
lowest_student = min(students, key=lambda s: s["score"])
print(f"최저 점수 학생: {lowest_student}")

prices = [100, 200, 300, 400, 500]

# 가격에 세금(10%) 추가
prices_with_tax = list(map(lambda p: p * 1.1, prices))
print(f"원본 가격: {prices}")
print(f"세금 포함: {[round(p, 2) for p in prices_with_tax]}")

# 200 이상인 가격만
expensive = list(filter(lambda p: p >= 200, prices))
print(f"200 이상: {expensive}")

sentences = [
    "Python is great",
    "I love programming",
    "Code is fun"
]

# 각 문장의 단어 수
word_counts = list(map(lambda s: len(s.split()), sentences))
print(f"문장: {sentences}")
print(f"단어 수: {word_counts}")

# 3단어 이상인 문장만
long_sentences = list(filter(lambda s: len(s.split()) >= 3, sentences))
print(f"3단어 이상: {long_sentences}")

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 짝수를 필터링하고 제곱한 후 합계
result = reduce(
    lambda x, y: x + y,
    map(lambda x: x ** 2, filter(lambda x: x % 2 == 0, numbers))
)
print(f"원본: {numbers}")
print(f"짝수 제곱의 합: {result}")

# 람다는 간단한 한 줄 함수에 적합
# 복잡한 로직은 일반 함수가 더 읽기 쉬움

# 람다 사용 (간단한 경우)
numbers = [1, 2, 3, 4, 5]
squares = list(map(lambda x: x ** 2, numbers))

# 일반 함수 사용 (복잡한 경우)
def complex_calculation(x):
    if x < 0:
        return 0
    elif x < 10:
        return x ** 2
    else:
        return x ** 3

results = list(map(complex_calculation, numbers))
print(f"복잡한 계산 결과: {results}")

# 함수형 프로그래밍은 데이터를 변환하는 함수들을 조합하는 방식

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 파이프라인: 필터 -> 변환 -> 집계
pipeline = (
    numbers
    | (lambda nums: filter(lambda x: x % 2 == 0, nums))
    | (lambda evens: map(lambda x: x ** 2, evens))
    | (lambda squares: list(squares))
)

# Python에서는 위 방식이 복잡하므로, 단계별로 나누는 것이 좋음
evens = filter(lambda x: x % 2 == 0, numbers)
squares = map(lambda x: x ** 2, evens)
result = list(squares)
print(f"파이프라인 결과: {result}")

# 또는 리스트 컴프리헨션 (더 Pythonic)
result2 = [x ** 2 for x in numbers if x % 2 == 0]
print(f"컴프리헨션 결과: {result2}")
