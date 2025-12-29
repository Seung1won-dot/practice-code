# 리스트 (List)

# 빈 리스트
empty_list = []
empty_list2 = list()

# 정수 리스트
numbers = [1, 2, 3, 4, 5]

# 다양한 자료형 혼합
mixed = [1, "hello", 3.14, True]

# 리스트 안에 리스트 (중첩 리스트)
nested = [[1, 2], [3, 4], [5, 6]]

print(f"빈 리스트: {empty_list}")
print(f"정수 리스트: {numbers}")
print(f"혼합 리스트: {mixed}")
print(f"중첩 리스트: {nested}")

fruits = ["apple", "banana", "orange", "grape", "kiwi"]

print(f"전체 리스트: {fruits}")
print(f"첫 번째 요소: {fruits[0]}")      # apple
print(f"두 번째 요소: {fruits[1]}")      # banana
print(f"마지막 요소: {fruits[-1]}")      # kiwi (음수 인덱스)
print(f"뒤에서 두 번째: {fruits[-2]}")   # grape

# 중첩 리스트 인덱싱
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(f"\n중첩 리스트: {matrix}")
print(f"matrix[0]: {matrix[0]}")           # [1, 2, 3]
print(f"matrix[0][1]: {matrix[0][1]}")    # 2

numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

print(f"전체: {numbers}")
print(f"numbers[2:5]: {numbers[2:5]}")        # [2, 3, 4] (인덱스 2부터 4까지)
print(f"numbers[:5]: {numbers[:5]}")         # [0, 1, 2, 3, 4] (처음부터 4까지)
print(f"numbers[5:]: {numbers[5:]}")         # [5, 6, 7, 8, 9] (인덱스 5부터 끝까지)
print(f"numbers[:]: {numbers[:]}")           # 전체 복사
print(f"numbers[::2]: {numbers[::2]}")       # [0, 2, 4, 6, 8] (2씩 건너뛰기)
print(f"numbers[::-1]: {numbers[::-1]}")     # 역순: [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

fruits = ["apple", "banana", "orange"]

# 인덱스로 값 변경
fruits[1] = "grape"
print(f"수정 후: {fruits}")

# 슬라이싱으로 여러 값 변경
fruits[0:2] = ["cherry", "mango"]
print(f"슬라이싱 수정 후: {fruits}")

fruits = ["apple", "banana"]

# append(): 끝에 요소 추가
fruits.append("orange")
print(f"append 후: {fruits}")

# insert(): 특정 위치에 삽입
fruits.insert(1, "grape")
print(f"insert(1, 'grape') 후: {fruits}")

# extend(): 여러 요소 추가
fruits.extend(["kiwi", "mango"])
print(f"extend 후: {fruits}")

# + 연산자로 연결
fruits = fruits + ["peach"]
print(f"+ 연산자 후: {fruits}")

fruits = ["apple", "banana", "orange", "banana", "grape"]

# remove(): 값으로 제거 (첫 번째만)
fruits.remove("banana")
print(f"remove('banana') 후: {fruits}")

# pop(): 인덱스로 제거하고 반환
removed = fruits.pop(1)
print(f"pop(1) 후: {fruits}, 제거된 값: {removed}")

# pop(): 인덱스 없으면 마지막 요소 제거
last = fruits.pop()
print(f"pop() 후: {fruits}, 제거된 값: {last}")

# del 키워드
del fruits[0]
print(f"del fruits[0] 후: {fruits}")

# clear(): 모든 요소 제거
fruits.clear()
print(f"clear() 후: {fruits}")

fruits = ["apple", "banana", "orange", "banana"]

# index(): 값의 인덱스 찾기
print(f"fruits.index('banana'): {fruits.index('banana')}")  # 첫 번째 인덱스

# count(): 값의 개수 세기
print(f"fruits.count('banana'): {fruits.count('banana')}")

# in 연산자
print(f"'apple' in fruits: {'apple' in fruits}")
print(f"'grape' in fruits: {'grape' in fruits}")

numbers = [3, 1, 4, 1, 5, 9, 2, 6]

# sort(): 원본 리스트 정렬 (오름차순)
numbers.sort()
print(f"sort() 후: {numbers}")

# sort(reverse=True): 내림차순
numbers.sort(reverse=True)
print(f"sort(reverse=True) 후: {numbers}")

# sorted(): 새 리스트 반환 (원본 유지)
numbers = [3, 1, 4, 1, 5]
sorted_numbers = sorted(numbers)
print(f"원본: {numbers}")
print(f"sorted() 결과: {sorted_numbers}")

# reverse(): 순서 뒤집기
fruits = ["apple", "banana", "orange"]
fruits.reverse()
print(f"reverse() 후: {fruits}")

original = [1, 2, 3]

shallow = original
shallow[0] = 999
print(f"원본: {original}")  # 원본도 변경됨!
print(f"얕은 복사: {shallow}")

original = [1, 2, 3]

copy1 = original[:]
copy1[0] = 999
print(f"\n원본: {original}")
print(f"슬라이싱 복사: {copy1}")

original = [1, 2, 3]
copy2 = original.copy()
copy2[0] = 999
print(f"\n원본: {original}")
print(f"copy() 복사: {copy2}")

original = [1, 2, 3]
copy3 = list(original)
copy3[0] = 999
print(f"\n원본: {original}")
print(f"list() 복사: {copy3}")

numbers = [3, 1, 4, 1, 5, 9, 2, 6]

print(f"리스트: {numbers}")
print(f"길이: {len(numbers)}")
print(f"최대값: {max(numbers)}")
print(f"최소값: {min(numbers)}")
print(f"합계: {sum(numbers)}")

squares = []
for i in range(5):
    squares.append(i ** 2)
print(f"기존 방법: {squares}")

# 컴프리헨션
squares = [i ** 2 for i in range(5)]
print(f"컴프리헨션: {squares}")

fruits = ["apple", "banana", "orange"]

for fruit in fruits:
    print(f"과일: {fruit}")

for index, fruit in enumerate(fruits):
    print(f"인덱스 {index}: {fruit}")

for i in range(len(fruits)):
    print(f"인덱스 {i}: {fruits[i]}")

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 짝수만 필터링
even_numbers = [num for num in numbers if num % 2 == 0]
print(f"원본: {numbers}")
print(f"짝수: {even_numbers}")

scores = [85, 92, 78, 96, 88]

print(f"점수 리스트: {scores}")
print(f"평균: {sum(scores) / len(scores):.2f}")
print(f"최고점: {max(scores)}")
print(f"최저점: {min(scores)}")

# 정렬된 점수
sorted_scores = sorted(scores, reverse=True)
print(f"내림차순 정렬: {sorted_scores}")

list1 = [1, 2, 3]
list2 = [4, 5, 6]

merged1 = list1.copy()
merged1.extend(list2)
print(f"extend() 방법: {merged1}")

merged2 = list1 + list2
print(f"+ 연산자 방법: {merged2}")

merged3 = list1.copy()
merged3[len(merged3):] = list2
print(f"슬라이싱 할당 방법: {merged3}")
