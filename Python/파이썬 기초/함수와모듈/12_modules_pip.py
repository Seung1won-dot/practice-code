# 모듈과 패키지, pip

# 표준 라이브러리 모듈 import
import math
import random
import datetime

# 모듈의 함수/변수 사용
print(f"math.pi: {math.pi}")
print(f"math.sqrt(16): {math.sqrt(16)}")

print(f"random.randint(1, 10): {random.randint(1, 10)}")

now = datetime.datetime.now()
print(f"현재 시간: {now}")

from math import sqrt, pi
from random import randint, choice

# 모듈 이름 없이 직접 사용
print(f"sqrt(25): {sqrt(25)}")
print(f"pi: {pi}")
print(f"randint(1, 10): {randint(1, 10)}")
print(f"choice(['apple', 'banana', 'orange']): {choice(['apple', 'banana', 'orange'])}")

import datetime as dt
import math as m

today = dt.date.today()
print(f"오늘 날짜: {today}")
print(f"m.pi: {m.pi}")

# my_module.py 파일을 만든다고 가정
# my_module.py 내용:
"""
# my_module.py
def greet(name):
    return f"안녕하세요, {name}님!"

def add(a, b):
    return a + b

PI = 3.14159
"""

# 사용 예시 (실제로는 my_module.py 파일이 있어야 함)
# import my_module
# print(my_module.greet("홍길동"))
# print(my_module.add(3, 5))

# 이 코드는 현재 파일이 직접 실행될 때만 실행됨
# 다른 파일에서 import될 때는 실행되지 않음

def main():
    print("이 파일이 직접 실행되었습니다.")
    print("다른 파일에서 import되면 이 부분은 실행되지 않습니다.")

# 현재 파일이 직접 실행될 때만 main() 호출
if __name__ == "__main__":
    main()

# 예시:
# my_utils.py 파일:
"""
def add(a, b):
    return a + b

def multiply(a, b):
    return a * b

if __name__ == "__main__":
    # 테스트 코드
    print(add(3, 5))
    print(multiply(2, 4))
"""

# 다른 파일에서:
# import my_utils
# print(my_utils.add(10, 20))  # if __name__ == "__main__": 부분은 실행 안 됨

# os 모듈
import os
print(f"현재 작업 디렉토리: {os.getcwd()}")

# sys 모듈
import sys
print(f"Python 버전: {sys.version}")

# json 모듈
import json
data = {"name": "홍길동", "age": 25}
json_str = json.dumps(data, ensure_ascii=False)
print(f"JSON 문자열: {json_str}")

# collections 모듈
from collections import Counter
words = ["apple", "banana", "apple", "orange", "banana", "apple"]
counter = Counter(words)
print(f"단어 빈도: {counter}")

# 패키지는 여러 모듈을 담는 디렉토리
# 예시 구조:
"""
my_package/
    __init__.py
    module1.py
    module2.py
    subpackage/
        __init__.py
        module3.py
"""

# 사용 예시:
# from my_package import module1
# from my_package.subpackage import module3
# import my_package.module1

# pip는 Python 패키지 관리자입니다

# 패키지 설치
# pip install 패키지명
# 예: pip install requests
# 예: pip install numpy pandas

# 패키지 업그레이드
# pip install --upgrade 패키지명
# 예: pip install --upgrade requests

# 패키지 제거
# pip uninstall 패키지명
# 예: pip uninstall requests

# 설치된 패키지 목록
# pip list

# 패키지 정보 확인
# pip show 패키지명
# 예: pip show requests

# requirements.txt로 설치
# pip install -r requirements.txt

# requirements.txt 생성
# pip freeze > requirements.txt

# 가상환경 생성
# python -m venv myenv

# 가상환경 활성화
# Windows: myenv\Scripts\activate
# macOS/Linux: source myenv/bin/activate

# 가상환경 활성화 후 pip install 사용
# pip install 패키지명

# 가상환경 비활성화
# deactivate

# requests (HTTP 라이브러리)
# 설치: pip install requests
"""
import requests
response = requests.get("https://api.github.com")
print(response.status_code)
"""

# numpy (수치 계산)
# 설치: pip install numpy
"""
import numpy as np
arr = np.array([1, 2, 3, 4, 5])
print(arr.mean())
"""

# pandas (데이터 분석)
# 설치: pip install pandas
"""
import pandas as pd
df = pd.DataFrame({"name": ["홍길동", "김철수"], "age": [25, 30]})
print(df)
"""

import sys
print("Python이 모듈을 찾는 경로:")
for path in sys.path:
    print(f"  {path}")

# __init__.py는 패키지 디렉토리를 Python 패키지로 만드는 파일
# Python 3.3+에서는 없어도 되지만, 명시적으로 만드는 것이 좋음

# __init__.py 예시:
"""
# my_package/__init__.py
from .module1 import function1
from .module2 import function2

__version__ = "1.0.0"
"""

# 절대 import
# from my_package.module1 import function1

# 상대 import (같은 패키지 내에서)
# from .module1 import function1  # 같은 디렉토리
# from ..parent_package.module2 import function2  # 상위 디렉토리
# from .subpackage.module3 import function3  # 하위 디렉토리

# importlib을 사용하여 모듈 재로드
import importlib

# 모듈을 수정한 후 재로드
# import my_module
# importlib.reload(my_module)

# utils.py 파일 예시:
"""
# utils.py
def format_currency(amount):
    return f"${amount:,.2f}"

def format_date(date):
    return date.strftime("%Y-%m-%d")

if __name__ == "__main__":
    # 테스트 코드
    print(format_currency(1234.56))
"""

# 사용:
# import utils
# print(utils.format_currency(1234.56))

# requirements.txt 파일 내용 예시:
"""
requests==2.31.0
numpy>=1.24.0
pandas==2.0.0
matplotlib>=3.7.0
"""

# 설치:
# pip install -r requirements.txt

# 특정 버전 설치
# pip install 패키지명==버전
# 예: pip install requests==2.31.0

# 버전 범위 지정
# pip install "패키지명>=버전"
# 예: pip install "requests>=2.30.0"

# 버전 확인
# pip show 패키지명 | findstr Version  # Windows
# pip show 패키지명 | grep Version     # macOS/Linux
