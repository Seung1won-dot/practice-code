name = "홍길동"
age = 25
height = 175.5
is_student = True

print("이름:", name)
print("나이:", age)
print("키:", height)
print("학생 여부:", is_student)

num1 = 10
num2 = -5
num3 = 0
print(f"정수형: {num1}, {num2}, {num3}")
print(f"num1의 자료형: {type(num1)}")

pi = 3.14159
temperature = -10.5
print(f"실수형: {pi}, {temperature}")
print(f"pi의 자료형: {type(pi)}")

text1 = "안녕하세요"
text2 = 'Python'
text3 = """여러 줄
문자열도
가능합니다"""
print(f"문자열: {text1}, {text2}")
print(text3)

is_true = True
is_false = False
print(f"불리언: {is_true}, {is_false}")
print(f"is_true의 자료형: {type(is_true)}")

empty_value = None
print(f"None 값: {empty_value}")
print(f"None의 자료형: {type(empty_value)}")

str_num = "123"
int_num = int(str_num)
print(f"문자열 '{str_num}'를 정수로 변환: {int_num}, 타입: {type(int_num)}")

str_float = "3.14"
float_num = float(str_float)
print(f"문자열 '{str_float}'를 실수로 변환: {float_num}, 타입: {type(float_num)}")

number = 456
str_number = str(number)
print(f"정수 {number}를 문자열로 변환: '{str_number}', 타입: {type(str_number)}")

int_to_float = float(42)
print(f"정수 42를 실수로 변환: {int_to_float}, 타입: {type(int_to_float)}")

float_to_int = int(3.9)
print(f"실수 3.9를 정수로 변환: {float_to_int}")

print(f"bool(1): {bool(1)}")
print(f"bool(0): {bool(0)}")
print(f"bool(''): {bool('')}")
print(f"bool('text'): {bool('text')}")

my_variable = 10
user_name = "홍길동"
count2 = 5
_private = "비공개"

x, y, z = 1, 2, 3
print(f"x={x}, y={y}, z={z}")

a = b = c = 0
print(f"a={a}, b={b}, c={c}")

temp = 100
print(f"temp: {temp}")
del temp
