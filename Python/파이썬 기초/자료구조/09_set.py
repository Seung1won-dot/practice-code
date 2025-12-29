# 집합 (Set) - 중복 없음, 순서 없음

set1 = {1, 2, 3, 4, 5}
print(f"set1: {set1}")

set2 = set([1, 2, 3, 4, 5])
print(f"set2: {set2}")

empty_dict = {}  # 딕셔너리
empty_set = set()  # 집합
print(f"빈 딕셔너리 타입: {type(empty_dict)}")
print(f"빈 집합 타입: {type(empty_set)}")

# 문자열로부터 집합 생성
set3 = set("hello")
print(f"set('hello'): {set3}")  # {'h', 'e', 'l', 'o'} (중복 제거)

numbers = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]
unique_numbers = set(numbers)
print(f"원본 리스트: {numbers}")
print(f"집합으로 변환: {unique_numbers}")

# 리스트의 중복 제거 (집합 활용)
unique_list = list(set(numbers))
print(f"중복 제거된 리스트: {unique_list}")

# 집합은 순서가 없으므로 인덱싱 불가
my_set = {3, 1, 4, 1, 5, 9, 2, 6}
print(f"집합: {my_set}")

# print(my_set[0])  # TypeError! 인덱싱 불가

fruits = {"apple", "banana"}

# add(): 요소 하나 추가
fruits.add("orange")
print(f"add('orange') 후: {fruits}")

# update(): 여러 요소 추가
fruits.update(["grape", "kiwi"])
print(f"update(['grape', 'kiwi']) 후: {fruits}")

# remove(): 요소 제거 (없으면 KeyError)
fruits.remove("banana")
print(f"remove('banana') 후: {fruits}")

# discard(): 요소 제거 (없어도 에러 없음)
fruits.discard("mango")  # 없어도 에러 없음
fruits.discard("grape")
print(f"discard('grape') 후: {fruits}")

# pop(): 임의의 요소 제거하고 반환
removed = fruits.pop()
print(f"pop() 후: {fruits}, 제거된 값: {removed}")

# clear(): 모든 요소 제거
fruits.clear()
print(f"clear() 후: {fruits}")

set1 = {1, 2, 3, 4}
set2 = {3, 4, 5, 6}

union1 = set1 | set2
print(f"set1 | set2: {union1}")

union2 = set1.union(set2)
print(f"set1.union(set2): {union2}")

set1 = {1, 2, 3, 4}
set2 = {3, 4, 5, 6}

intersection1 = set1 & set2
print(f"set1 & set2: {intersection1}")

intersection2 = set1.intersection(set2)
print(f"set1.intersection(set2): {intersection2}")

set1 = {1, 2, 3, 4}
set2 = {3, 4, 5, 6}

difference1 = set1 - set2
print(f"set1 - set2: {difference1}")  # set1에만 있는 요소

difference2 = set2 - set1
print(f"set2 - set1: {difference2}")  # set2에만 있는 요소

difference3 = set1.difference(set2)
print(f"set1.difference(set2): {difference3}")

set1 = {1, 2, 3, 4}
set2 = {3, 4, 5, 6}

symmetric1 = set1 ^ set2
print(f"set1 ^ set2: {symmetric1}")  # 양쪽에만 있는 요소

symmetric2 = set1.symmetric_difference(set2)
print(f"set1.symmetric_difference(set2): {symmetric2}")

set1 = {1, 2, 3}
set2 = {1, 2, 3, 4, 5}
set3 = {1, 2, 3}

# 부분집합 (Subset)
print(f"set1 <= set2: {set1 <= set2}")  # True
print(f"set1.issubset(set2): {set1.issubset(set2)}")  # True

# 진부분집합 (Proper Subset)
print(f"set1 < set2: {set1 < set2}")  # True
print(f"set1 < set3: {set1 < set3}")  # False (같으면 False)

# 상위집합 (Superset)
print(f"set2 >= set1: {set2 >= set1}")  # True
print(f"set2.issuperset(set1): {set2.issuperset(set1)}")  # True

# 교집합 없음 확인
set4 = {6, 7, 8}
print(f"set1.isdisjoint(set4): {set1.isdisjoint(set4)}")  # True

my_set = {1, 2, 3, 4, 5}

print(f"집합: {my_set}")
print(f"길이: {len(my_set)}")
print(f"3 in my_set: {3 in my_set}")
print(f"6 in my_set: {6 in my_set}")

# 짝수 집합
even_set = {x for x in range(10) if x % 2 == 0}
print(f"짝수 집합: {even_set}")

# 제곱 집합
squares_set = {x ** 2 for x in range(5)}
print(f"제곱 집합: {squares_set}")

fruits = {"apple", "banana", "orange"}

for fruit in fruits:
    print(f"과일: {fruit}")

# 정렬된 순서로 순회
for fruit in sorted(fruits):
    print(f"정렬된 과일: {fruit}")

# 리스트에서 중복 제거
numbers = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5]
unique = list(set(numbers))
print(f"원본: {numbers}")
print(f"중복 제거: {unique}")

# 순서 유지하면서 중복 제거
def remove_duplicates_preserve_order(lst):
    seen = set()
    result = []
    for item in lst:
        if item not in seen:
            seen.add(item)
            result.append(item)
    return result

ordered_unique = remove_duplicates_preserve_order(numbers)
print(f"순서 유지 중복 제거: {ordered_unique}")

students_math = {"홍길동", "김철수", "이영희", "박민수"}
students_english = {"홍길동", "이영희", "최지영", "박민수"}

# 두 과목 모두 수강하는 학생
both = students_math & students_english
print(f"수학 수강: {students_math}")
print(f"영어 수강: {students_english}")
print(f"두 과목 모두: {both}")

# 수학만 수강하는 학생
only_math = students_math - students_english
print(f"수학만: {only_math}")

article1_tags = {"python", "programming", "tutorial"}
article2_tags = {"python", "data-science", "tutorial"}
article3_tags = {"javascript", "web", "tutorial"}

# 모든 기사의 태그
all_tags = article1_tags | article2_tags | article3_tags
print(f"모든 태그: {all_tags}")

# 모든 기사에 공통인 태그
common_tags = article1_tags & article2_tags & article3_tags
print(f"공통 태그: {common_tags}")

# 특정 태그를 가진 기사 찾기 (시뮬레이션)
python_articles = []
if "python" in article1_tags:
    python_articles.append("기사1")
if "python" in article2_tags:
    python_articles.append("기사2")
if "python" in article3_tags:
    python_articles.append("기사3")

print(f"'python' 태그 기사: {python_articles}")
