import requests
from bs4 import BeautifulSoup

url = "https://example.com"
response = requests.get(url)

if response.status_code == 200:
    soup = BeautifulSoup(response.text, 'html.parser')
    title = soup.find('title')
    if title:
        print(f"페이지 제목: {title.text}")

url2 = "https://httpbin.org/json"
response2 = requests.get(url2)
if response2.status_code == 200:
    data = response2.json()
    print(f"JSON 데이터: {data}")

html = """
<html>
<body>
    <div class="content">
        <h1>제목</h1>
        <p>첫 번째 문단</p>
        <p>두 번째 문단</p>
    </div>
</body>
</html>
"""

soup = BeautifulSoup(html, 'html.parser')
paragraphs = soup.find_all('p')
for p in paragraphs:
    print(p.text)

div = soup.find('div', class_='content')
if div:
    h1 = div.find('h1')
    print(f"제목: {h1.text}")

