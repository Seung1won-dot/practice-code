# 딕셔너리 (Dictionary) - Key-Value 쌍

student = {
    "name": "홍길동",
    "age": 20,
    "grade": "A"
}
print(f"student: {student}")

student2 = dict(name="김철수", age=21, grade="B")
print(f"student2: {student2}")

student3 = dict([("name", "이영희"), ("age", 22), ("grade", "A")])
print(f"student3: {student3}")

# 빈 딕셔너리
empty = {}
empty2 = dict()
print(f"빈 딕셔너리: {empty}")

student = {"name": "홍길동", "age": 20, "grade": "A"}

# 키로 값 접근
print(f"student['name']: {student['name']}")
print(f"student['age']: {student['age']}")

# get() 메서드 (키가 없어도 에러 없음)
print(f"student.get('name'): {student.get('name')}")
print(f"student.get('city', '서울'): {student.get('city', '서울')}")  # 기본값

# 존재하지 않는 키 접근
# print(student['city'])  # KeyError 발생!
print(f"get('city'): {student.get('city')}")

student = {"name": "홍길동", "age": 20}

# 값 변경
student["age"] = 21
print(f"age 변경 후: {student}")

# 새 키-값 추가
student["grade"] = "A"
student["city"] = "서울"
print(f"키-값 추가 후: {student}")

# update() 메서드로 여러 값 업데이트
student.update({"age": 22, "city": "부산"})
print(f"update() 후: {student}")

student = {"name": "홍길동", "age": 20, "grade": "A", "city": "서울"}

# del 키워드
del student["city"]
print(f"del 후: {student}")

# pop() 메서드 (값 반환)
age = student.pop("age")
print(f"pop('age') 후: {student}, 반환값: {age}")

# popitem() 메서드 (마지막 항목 제거, Python 3.7+)
item = student.popitem()
print(f"popitem() 후: {student}, 반환값: {item}")

# clear() 메서드
student.clear()
print(f"clear() 후: {student}")

student = {"name": "홍길동", "age": 20, "grade": "A"}

# keys(): 모든 키
print(f"keys(): {list(student.keys())}")

# values(): 모든 값
print(f"values(): {list(student.values())}")

# items(): 모든 키-값 쌍
print(f"items(): {list(student.items())}")

# in 연산자 (키 확인)
print(f"'name' in student: {'name' in student}")
print(f"'city' in student: {'city' in student}")

student = {"name": "홍길동", "age": 20, "grade": "A"}

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

# 제곱 딕셔너리
squares = {x: x ** 2 for x in range(1, 6)}
print(f"제곱 딕셔너리: {squares}")

# 조건부 컴프리헨션
even_squares = {x: x ** 2 for x in range(1, 10) if x % 2 == 0}
print(f"짝수 제곱: {even_squares}")

# 문자열 길이 딕셔너리
words = ["apple", "banana", "orange"]
lengths = {word: len(word) for word in words}
print(f"단어 길이: {lengths}")

students = {
    "홍길동": {"age": 20, "grade": "A"},
    "김철수": {"age": 21, "grade": "B"},
    "이영희": {"age": 22, "grade": "A"}
}

print(f"전체 학생: {students}")
print(f"홍길동의 나이: {students['홍길동']['age']}")

# 중첩 딕셔너리 수정
students["홍길동"]["grade"] = "A+"
print(f"수정 후: {students['홍길동']}")

original = {"a": 1, "b": 2, "c": 3}

shallow = original
shallow["a"] = 999
print(f"원본: {original}")  # 원본도 변경됨!

original = {"a": 1, "b": 2, "c": 3}

copy1 = original.copy()
copy1["a"] = 999
print(f"\n원본: {original}")
print(f"copy() 복사: {copy1}")

copy2 = dict(original)
copy2["a"] = 888
print(f"dict() 복사: {copy2}")

copy3 = {k: v for k, v in original.items()}
copy3["a"] = 777
print(f"컴프리헨션 복사: {copy3}")

dict1 = {"a": 1, "b": 2}
dict2 = {"c": 3, "d": 4}

merged1 = dict1.copy()
merged1.update(dict2)
print(f"update() 방법: {merged1}")

merged2 = {**dict1, **dict2}
print(f"** 연산자 방법: {merged2}")

merged3 = dict1 | dict2
print(f"| 연산자 방법: {merged3}")

student = {"name": "홍길동", "age": 20}

# 키가 없으면 기본값 설정
city = student.setdefault("city", "서울")
print(f"setdefault('city', '서울') 후: {student}, 반환값: {city}")

# 키가 이미 있으면 기존 값 반환
name = student.setdefault("name", "김철수")
print(f"setdefault('name', '김철수') 후: {student}, 반환값: {name}")

from collections import defaultdict

# 기본값이 0인 딕셔너리
counter = defaultdict(int)
words = ["apple", "banana", "apple", "orange", "banana", "apple"]

for word in words:
    counter[word] += 1

print(f"단어 빈도: {dict(counter)}")

# 기본값이 리스트인 딕셔너리
grouped = defaultdict(list)
numbers = [("a", 1), ("b", 2), ("a", 3), ("b", 4)]

for key, value in numbers:
    grouped[key].append(value)

print(f"그룹화: {dict(grouped)}")

scores = {
    "홍길동": {"수학": 85, "영어": 90, "과학": 88},
    "김철수": {"수학": 92, "영어": 87, "과학": 95},
    "이영희": {"수학": 78, "영어": 95, "과학": 82}
}

# 각 학생의 평균 계산
for name, subjects in scores.items():
    average = sum(subjects.values()) / len(subjects)
    print(f"{name}의 평균: {average:.2f}")

text = "apple banana apple orange banana apple"
words = text.split()

word_count = {}
for word in words:
    word_count[word] = word_count.get(word, 0) + 1

print(f"텍스트: {text}")
print(f"단어 빈도: {word_count}")

phonebook = {
    "홍길동": "010-1234-5678",
    "김철수": "010-2345-6789",
    "이영희": "010-3456-7890"
}

def add_contact(name, phone):
    phonebook[name] = phone
    print(f"{name} 추가됨")

def find_contact(name):
    return phonebook.get(name, "연락처 없음")

def delete_contact(name):
    if name in phonebook:
        del phonebook[name]
        print(f"{name} 삭제됨")
    else:
        print(f"{name}을(를) 찾을 수 없습니다")

add_contact("박민수", "010-4567-8901")
print(f"김철수 찾기: {find_contact('김철수')}")
delete_contact("이영희")
print(f"전화번호부: {phonebook}")
