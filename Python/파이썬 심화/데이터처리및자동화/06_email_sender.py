import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

smtp_server = "smtp.gmail.com"
smtp_port = 587
sender_email = "your_email@gmail.com"
sender_password = "your_app_password"
receiver_email = "receiver@gmail.com"

msg = MIMEMultipart()
msg['From'] = sender_email
msg['To'] = receiver_email
msg['Subject'] = "테스트 이메일"

body = "이것은 파이썬으로 보낸 테스트 이메일입니다."
msg.attach(MIMEText(body, 'plain', 'utf-8'))

try:
    server = smtplib.SMTP(smtp_server, smtp_port)
    server.starttls()
    server.login(sender_email, sender_password)
    text = msg.as_string()
    server.sendmail(sender_email, receiver_email, text)
    server.quit()
    print("이메일이 성공적으로 전송되었습니다.")
except Exception as e:
    print(f"이메일 전송 실패: {e}")

