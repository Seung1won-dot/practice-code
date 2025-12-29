# 컴프리헨션 (Comprehension) - 리스트, 딕셔너리, 집합, 제너레이터

squares = []
for i in range(5):
    squares.append(i ** 2)
print(f"기존 방법: {squares}")

# 리스트 컴프리헨션
squares = [i ** 2 for i in range(5)]
print(f"컴프리헨션: {squares}")

# 짝수만 필터링
evens = [x for x in range(10) if x % 2 == 0]
print(f"짝수: {evens}")

# 5보다 큰 수만
greater_than_5 = [x for x in range(10) if x > 5]
print(f"5보다 큰 수: {greater_than_5}")

# 짝수는 제곱, 홀수는 0
numbers = [x ** 2 if x % 2 == 0 else 0 for x in range(10)]
print(f"조건부 표현식: {numbers}")

# 양수는 그대로, 음수는 0
values = [-2, -1, 0, 1, 2, 3]
non_negative = [x if x >= 0 else 0 for x in values]
print(f"원본: {values}")
print(f"음수는 0으로: {non_negative}")

# 구구단 2단~4단
multiplication_table = [[i * j for j in range(1, 10)] for i in range(2, 5)]
print("구구단 2단~4단:")
for i, table in enumerate(multiplication_table, 2):
    print(f"  {i}단: {table[:3]}...")

# 평면화 (Flatten)
nested = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
flattened = [item for sublist in nested for item in sublist]
print(f"\n중첩 리스트: {nested}")
print(f"평면화: {flattened}")

# 제곱 딕셔너리
squares_dict = {x: x ** 2 for x in range(1, 6)}
print(f"제곱 딕셔너리: {squares_dict}")

# 문자열 길이 딕셔너리
words = ["apple", "banana", "orange"]
lengths = {word: len(word) for word in words}
print(f"단어 길이: {lengths}")

# 짝수만 제곱
even_squares = {x: x ** 2 for x in range(10) if x % 2 == 0}
print(f"짝수 제곱: {even_squares}")

# 값이 5 이상인 항목만
scores = {"홍길동": 85, "김철수": 92, "이영희": 78, "박민수": 95}
high_scores = {name: score for name, score in scores.items() if score >= 85}
print(f"원본 점수: {scores}")
print(f"85점 이상: {high_scores}")

# 짝수 집합
even_set = {x for x in range(10) if x % 2 == 0}
print(f"짝수 집합: {even_set}")

# 단어의 첫 글자 집합
words = ["apple", "banana", "apricot", "orange"]
first_letters = {word[0] for word in words}
print(f"단어: {words}")
print(f"첫 글자 집합: {first_letters}")

# 리스트 컴프리헨션 (메모리에 모든 값 저장)
squares_list = [x ** 2 for x in range(5)]
print(f"리스트: {squares_list}, 타입: {type(squares_list)}")

# 제너레이터 표현식 (값을 필요할 때 생성)
squares_gen = (x ** 2 for x in range(5))
print(f"제너레이터: {squares_gen}, 타입: {type(squares_gen)}")
print(f"값들: {list(squares_gen)}")

# 메모리 효율적 (큰 데이터 처리 시 유용)
large_gen = (x ** 2 for x in range(1000000))
print(f"큰 제너레이터 생성됨 (메모리 효율적)")

# sum()과 함께 사용
total = sum(x ** 2 for x in range(10))
print(f"0~9 제곱의 합: {total}")

# max(), min()과 함께 사용
numbers = [1, 5, 3, 9, 2, 7]
max_square = max(x ** 2 for x in numbers)
print(f"원본: {numbers}")
print(f"최대 제곱값: {max_square}")

# 반복문 (더 명시적, 복잡한 로직에 적합)
result1 = []
for x in range(10):
    if x % 2 == 0:
        result1.append(x ** 2)
print(f"반복문: {result1}")

# 컴프리헨션 (간결, 간단한 변환에 적합)
result2 = [x ** 2 for x in range(10) if x % 2 == 0]
print(f"컴프리헨션: {result2}")

# 가격 리스트에 세금 추가
prices = [100, 200, 300, 400, 500]
prices_with_tax = [p * 1.1 for p in prices]
print(f"원본 가격: {prices}")
print(f"세금 포함: {[round(p, 2) for p in prices_with_tax]}")

# 학생 점수에서 합격자만 추출
scores = {"홍길동": 85, "김철수": 92, "이영희": 78, "박민수": 65}
passing = {name: score for name, score in scores.items() if score >= 70}
print(f"원본 점수: {scores}")
print(f"합격자 (70점 이상): {passing}")

words = ["apple", "banana", "orange", "kiwi", "grape"]

# 대문자로 변환
uppercase = [word.upper() for word in words]
print(f"원본: {words}")
print(f"대문자: {uppercase}")

# 길이가 5 이상인 단어만
long_words = [word for word in words if len(word) >= 5]
print(f"길이 5 이상: {long_words}")

students = [
    {"name": "홍길동", "scores": [85, 90, 88]},
    {"name": "김철수", "scores": [92, 87, 95]},
    {"name": "이영희", "scores": [78, 85, 82]}
]

# 각 학생의 평균 점수
averages = {
    student["name"]: sum(student["scores"]) / len(student["scores"])
    for student in students
}
print(f"학생 평균: {averages}")

# 너무 복잡한 컴프리헨션은 가독성이 떨어짐
# 간단한 경우에만 사용하는 것이 좋음

# 좋은 예: 간단하고 명확
good = [x ** 2 for x in range(10) if x % 2 == 0]
print(f"좋은 예: {good}")

# 나쁜 예: 너무 복잡 (반복문이 더 나음)
# bad = [x ** 2 if x % 2 == 0 else x ** 3 if x % 3 == 0 else 0 for x in range(10) if x > 5]

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

# 소수만 필터링
primes = [x for x in range(2, 20) if is_prime(x)]
print(f"2~19 사이의 소수: {primes}")

original = {"a": 1, "b": 2, "c": 3}

# 키와 값을 바꾸기
swapped = {value: key for key, value in original.items()}
print(f"원본: {original}")
print(f"키-값 교환: {swapped}")

# 값에 10 곱하기
multiplied = {key: value * 10 for key, value in original.items()}
print(f"값 10배: {multiplied}")

# 리스트 -> 딕셔너리
words = ["apple", "banana", "orange"]
word_dict = {word: len(word) for word in words}
print(f"단어 딕셔너리: {word_dict}")

# 딕셔너리 -> 리스트
scores = {"홍길동": 85, "김철수": 92, "이영희": 78}
names = [name for name in scores.keys()]
high_scorers = [name for name, score in scores.items() if score >= 85]
print(f"이름 리스트: {names}")
print(f"고득점자: {high_scorers}")

# 큰 데이터를 처리할 때 제너레이터가 유용

# 리스트 컴프리헨션 (모든 값을 메모리에 저장)
large_list = [x ** 2 for x in range(1000000)]
print(f"리스트 크기: {len(large_list)} (메모리 많이 사용)")

# 제너레이터 표현식 (값을 필요할 때만 생성)
large_gen = (x ** 2 for x in range(1000000))
print(f"제너레이터 생성됨 (메모리 효율적)")

# sum()과 함께 사용하면 메모리 효율적
total = sum(x ** 2 for x in range(1000000))
print(f"합계: {total}")

# 원시 데이터
raw_data = ["  apple  ", "BANANA", "  Orange  ", "kiwi", "  GRAPE  "]

# 공백 제거, 소문자 변환
cleaned = [word.strip().lower() for word in raw_data]
print(f"원본: {raw_data}")
print(f"정제 후: {cleaned}")

# 길이가 5 이상인 것만
filtered = [word for word in cleaned if len(word) >= 5]
print(f"길이 5 이상: {filtered}")
