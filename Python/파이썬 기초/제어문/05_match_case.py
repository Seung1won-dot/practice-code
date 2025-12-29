# match-case 문 (Python 3.10+)
# switch-case 문의 파이썬 버전

status = "success"

match status:
    case "success":
        print("작업이 성공했습니다.")
    case "error":
        print("오류가 발생했습니다.")
    case "pending":
        print("작업이 대기 중입니다.")
    case _:  # default case (와일드카드)
        print("알 수 없는 상태입니다.")

day = "월요일"

match day:
    case "월요일" | "화요일" | "수요일" | "목요일" | "금요일":
        print("평일입니다.")
    case "토요일" | "일요일":
        print("주말입니다.")
    case _:
        print("알 수 없는 요일입니다.")

point = (3, 4)

match point:
    case (0, 0):
        print("원점입니다.")
    case (0, y):
        print(f"Y축 위의 점입니다. y={y}")
    case (x, 0):
        print(f"X축 위의 점입니다. x={x}")
    case (x, y):
        print(f"일반 점입니다. ({x}, {y})")

def process_list(items):
    match items:
        case []:
            print("빈 리스트입니다.")
        case [x]:
            print(f"요소가 하나입니다: {x}")
        case [x, y]:
            print(f"요소가 두 개입니다: {x}, {y}")
        case [x, y, *rest]:
            print(f"첫 두 요소: {x}, {y}, 나머지: {rest}")

process_list([])
process_list([1])
process_list([1, 2])
process_list([1, 2, 3, 4, 5])

def process_dict(data):
    match data:
        case {"type": "user", "name": name}:
            print(f"사용자: {name}")
        case {"type": "admin", "name": name, "level": level}:
            print(f"관리자: {name}, 레벨: {level}")
        case {"type": "guest"}:
            print("게스트입니다.")
        case _:
            print("알 수 없는 타입입니다.")

process_dict({"type": "user", "name": "홍길동"})
process_dict({"type": "admin", "name": "관리자", "level": 5})
process_dict({"type": "guest"})

def check_number(num):
    match num:
        case n if n < 0:
            print(f"{n}은(는) 음수입니다.")
        case n if n == 0:
            print("0입니다.")
        case n if n > 0 and n < 10:
            print(f"{n}은(는) 한 자리 양수입니다.")
        case n if n >= 10:
            print(f"{n}은(는) 두 자리 이상의 양수입니다.")

check_number(-5)
check_number(0)
check_number(5)
check_number(25)

from dataclasses import dataclass

@dataclass
class Point:
    x: int
    y: int

@dataclass
class Circle:
    radius: float

def process_shape(shape):
    match shape:
        case Point(x=0, y=0):
            print("원점입니다.")
        case Point(x=x, y=y):
            print(f"점: ({x}, {y})")
        case Circle(radius=r) if r > 0:
            print(f"원의 반지름: {r}")
        case _:
            print("알 수 없는 도형입니다.")

process_shape(Point(0, 0))
process_shape(Point(3, 4))
process_shape(Circle(5.0))

def handle_http_status(code):
    match code:
        case 200:
            return "OK - 요청 성공"
        case 201:
            return "Created - 리소스 생성됨"
        case 400:
            return "Bad Request - 잘못된 요청"
        case 401:
            return "Unauthorized - 인증 필요"
        case 404:
            return "Not Found - 리소스를 찾을 수 없음"
        case 500:
            return "Internal Server Error - 서버 오류"
        case code if 200 <= code < 300:
            return f"성공 응답 ({code})"
        case code if 400 <= code < 500:
            return f"클라이언트 오류 ({code})"
        case code if 500 <= code < 600:
            return f"서버 오류 ({code})"
        case _:
            return f"알 수 없는 상태 코드 ({code})"

print(handle_http_status(200))
print(handle_http_status(404))
print(handle_http_status(503))

def calculate(operator, a, b):
    match operator:
        case "+":
            return a + b
        case "-":
            return a - b
        case "*":
            return a * b
        case "/":
            if b != 0:
                return a / b
            else:
                return "0으로 나눌 수 없습니다."
        case "**" | "^":
            return a ** b
        case _:
            return "알 수 없는 연산자입니다."

print(f"10 + 5 = {calculate('+', 10, 5)}")
print(f"10 - 5 = {calculate('-', 10, 5)}")
print(f"10 * 5 = {calculate('*', 10, 5)}")
print(f"10 / 5 = {calculate('/', 10, 5)}")
print(f"10 ** 5 = {calculate('**', 10, 5)}")

# match-case는 패턴 매칭에 더 적합
# if-elif-else는 복잡한 조건에 더 적합

# match-case 사용 (간단한 값 비교)
command = "start"
match command:
    case "start":
        print("시작합니다.")
    case "stop":
        print("중지합니다.")
    case _:
        print("알 수 없는 명령입니다.")

# if-elif-else 사용 (복잡한 조건)
score = 85
if score >= 90:
    grade = "A"
elif score >= 80:
    grade = "B"
elif score >= 70:
    grade = "C"
else:
    grade = "F"
print(f"점수: {score}, 등급: {grade}")

def process_nested(data):
    match data:
        case {"type": "user", "action": action}:
            match action:
                case "login":
                    print("사용자 로그인")
                case "logout":
                    print("사용자 로그아웃")
                case _:
                    print(f"알 수 없는 액션: {action}")
        case {"type": "admin", "action": action}:
            match action:
                case "delete":
                    print("관리자 삭제 작업")
                case "modify":
                    print("관리자 수정 작업")
                case _:
                    print(f"알 수 없는 액션: {action}")
        case _:
            print("알 수 없는 타입입니다.")

process_nested({"type": "user", "action": "login"})
process_nested({"type": "admin", "action": "delete"})
