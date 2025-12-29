import re

text = "연락처: 010-1234-5678, 이메일: test@example.com"

phone_pattern = r'\d{3}-\d{4}-\d{4}'
phone_match = re.search(phone_pattern, text)
if phone_match:
    print(f"전화번호: {phone_match.group()}")

email_pattern = r'[\w\.-]+@[\w\.-]+\.\w+'
email_match = re.search(email_pattern, text)
if email_match:
    print(f"이메일: {email_match.group()}")

text2 = "Python, python, PYTHON, java, Java"
matches = re.findall(r'[Pp]ython', text2)
print(f"매칭된 단어: {matches}")

text3 = "2024-01-15, 2023-12-25, 2022-05-10"
dates = re.findall(r'\d{4}-\d{2}-\d{2}', text3)
print(f"날짜들: {dates}")

text4 = "Hello World 123"
result = re.sub(r'\d+', '숫자', text4)
print(f"치환 결과: {result}")

pattern = r'(\d{3})-(\d{4})-(\d{4})'
text5 = "연락처: 010-1234-5678"
match = re.search(pattern, text5)
if match:
    print(f"전체: {match.group(0)}")
    print(f"첫 번째 그룹: {match.group(1)}")
    print(f"두 번째 그룹: {match.group(2)}")
    print(f"세 번째 그룹: {match.group(3)}")

