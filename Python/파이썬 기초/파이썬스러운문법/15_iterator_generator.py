# 이터레이터와 제너레이터

# 리스트, 튜플, 문자열 등은 이터러블
my_list = [1, 2, 3, 4, 5]

# for 루프로 순회 가능
for item in my_list:
    print(f"항목: {item}")

# iter() 함수로 이터레이터 얻기
iterator = iter(my_list)
print(f"이터레이터: {iterator}")

my_list = [1, 2, 3, 4, 5]
iterator = iter(my_list)

# next() 함수로 다음 값 가져오기
print(f"next(iterator): {next(iterator)}")
print(f"next(iterator): {next(iterator)}")
print(f"next(iterator): {next(iterator)}")

# StopIteration 예외 발생 (더 이상 값이 없을 때)
try:
    while True:
        item = next(iterator)
        print(f"항목: {item}")
except StopIteration:
    print("이터레이터 종료")

# 이터러블: 순회 가능한 객체 (리스트, 튜플, 문자열 등)
# 이터레이터: 실제로 순회를 수행하는 객체

my_list = [1, 2, 3]  # 이터러블

# iter()로 이터레이터 생성
iterator1 = iter(my_list)  # 이터레이터
iterator2 = iter(my_list)  # 새로운 이터레이터

print(f"iterator1의 첫 번째: {next(iterator1)}")
print(f"iterator2의 첫 번째: {next(iterator2)}")  # 독립적

class CountDown:
    def __init__(self, start):
        self.current = start
    
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.current <= 0:
            raise StopIteration
        self.current -= 1
        return self.current + 1

# 사용
counter = CountDown(5)
for num in counter:
    print(f"카운트다운: {num}")

def simple_generator():
    yield 1
    yield 2
    yield 3

gen = simple_generator()
print(f"제너레이터: {gen}")
print(f"타입: {type(gen)}")

# next()로 값 가져오기
print(f"next(gen): {next(gen)}")
print(f"next(gen): {next(gen)}")
print(f"next(gen): {next(gen)}")

# for 루프로 순회
gen2 = simple_generator()
for value in gen2:
    print(f"값: {value}")

def infinite_counter():
    count = 0
    while True:
        yield count
        count += 1

# 무한 제너레이터 생성
counter = infinite_counter()

# 처음 5개만 가져오기
for i in range(5):
    print(f"카운터: {next(counter)}")

def fibonacci():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b

# 피보나치 제너레이터
fib = fibonacci()

# 처음 10개
fib_numbers = [next(fib) for _ in range(10)]
print(f"피보나치 수열 (처음 10개): {fib_numbers}")

# 리스트 컴프리헨션
squares_list = [x ** 2 for x in range(5)]
print(f"리스트: {squares_list}, 타입: {type(squares_list)}")

# 제너레이터 표현식
squares_gen = (x ** 2 for x in range(5))
print(f"제너레이터: {squares_gen}, 타입: {type(squares_gen)}")
print(f"값들: {list(squares_gen)}")

def number_generator():
    value = yield
    while True:
        value = yield value * 2

gen = number_generator()
next(gen)  # 제너레이터 시작

print(f"send(5): {gen.send(5)}")   # 10
print(f"send(10): {gen.send(10)}")  # 20
print(f"send(3): {gen.send(3)}")   # 6

def count_generator():
    try:
        count = 0
        while True:
            yield count
            count += 1
    except GeneratorExit:
        print("제너레이터 종료")

gen = count_generator()
print(f"첫 번째: {next(gen)}")
print(f"두 번째: {next(gen)}")
gen.close()  # 제너레이터 종료

def numbers():
    for i in range(5):
        yield i

def squares(iterable):
    for num in iterable:
        yield num ** 2

def evens(iterable):
    for num in iterable:
        if num % 2 == 0:
            yield num

# 제너레이터 체이닝
chain = evens(squares(numbers()))
print(f"체이닝 결과: {list(chain)}")

def generator1():
    yield 1
    yield 2

def generator2():
    yield 3
    yield 4

def combined_generator():
    yield from generator1()
    yield from generator2()

gen = combined_generator()
print(f"결합된 제너레이터: {list(gen)}")

# 큰 데이터를 처리할 때 제너레이터가 유용

# 리스트 (모든 값을 메모리에 저장)
def squares_list(n):
    return [x ** 2 for x in range(n)]

# 제너레이터 (값을 필요할 때만 생성)
def squares_generator(n):
    for x in range(n):
        yield x ** 2

# 리스트는 메모리를 많이 사용
# squares_list(1000000)  # 메모리에 100만 개 저장

# 제너레이터는 메모리 효율적
gen = squares_generator(1000000)
print(f"제너레이터 생성됨 (메모리 효율적)")
print(f"첫 번째 값: {next(gen)}")

def read_lines(filename):
    """파일을 한 줄씩 읽는 제너레이터"""
    with open(filename, 'r', encoding='utf-8') as f:
        for line in f:
            yield line.strip()

# 사용 예시 (파일이 있다고 가정)
# for line in read_lines('data.txt'):
#     print(line)

def numbers():
    for i in range(10):
        yield i

def filter_evens(iterable):
    for num in iterable:
        if num % 2 == 0:
            yield num

def square(iterable):
    for num in iterable:
        yield num ** 2

# 파이프라인 구성
pipeline = square(filter_evens(numbers()))
print(f"파이프라인 결과: {list(pipeline)}")

# 이터러블 객체는 __iter__() 메서드를 가져야 함
# 이터레이터 객체는 __iter__()와 __next__() 메서드를 가져야 함

class MyRange:
    def __init__(self, start, end):
        self.start = start
        self.end = end
    
    def __iter__(self):
        return MyRangeIterator(self.start, self.end)

class MyRangeIterator:
    def __init__(self, start, end):
        self.current = start
        self.end = end
    
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.current >= self.end:
            raise StopIteration
        value = self.current
        self.current += 1
        return value

# 사용
my_range = MyRange(1, 5)
for num in my_range:
    print(f"MyRange 값: {num}")

def simple_gen():
    yield 1
    yield 2
    yield 3

gen = simple_gen()

# 제너레이터는 이미 이터레이터
print(f"iter(gen) is gen: {iter(gen) is gen}")

# list()로 모든 값 가져오기
values = list(gen)
print(f"모든 값: {values}")

def batch_process(data, batch_size):
    """데이터를 배치 단위로 처리하는 제너레이터"""
    for i in range(0, len(data), batch_size):
        yield data[i:i + batch_size]

data = list(range(20))
batches = batch_process(data, 5)

print(f"원본 데이터: {data}")
print("배치:")
for i, batch in enumerate(batches, 1):
    print(f"  배치 {i}: {batch}")

def safe_generator():
    try:
        yield 1
        yield 2
        yield 3
    except ValueError as e:
        print(f"예외 발생: {e}")
        yield "에러 처리됨"

gen = safe_generator()
print(f"첫 번째: {next(gen)}")
print(f"두 번째: {next(gen)}")
gen.throw(ValueError, "테스트 예외")
print(f"다음: {next(gen)}")

def stateful_generator():
    count = 0
    while count < 5:
        count += 1
        yield count

gen = stateful_generator()

# 제너레이터는 상태를 유지
print(f"첫 번째: {next(gen)}")
print(f"두 번째: {next(gen)}")
print(f"세 번째: {next(gen)}")

# 새로운 제너레이터는 독립적
gen2 = stateful_generator()
print(f"새 제너레이터 첫 번째: {next(gen2)}")
