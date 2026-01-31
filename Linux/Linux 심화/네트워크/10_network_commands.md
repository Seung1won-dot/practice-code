# 네트워크 명령어

## 연결 확인

```bash
ping 8.8.8.8           # ICMP 응답 확인
ping -c 4 google.com   # 4번만
ping -i 2 host         # 2초 간격

traceroute google.com  # 경로 추적
```

## IP 및 네트워크 설정

```bash
ip addr               # IP 주소 (ip a)
ip link               # 네트워크 인터페이스
ip route              # 라우팅 테이블

ifconfig              # 구버전 (일부 배포판)
```

## DNS

```bash
nslookup domain.com   # DNS 조회
dig domain.com        # 상세 DNS 정보
host domain.com       # 호스트 조회
```

## 네트워크 연결

```bash
# SSH 접속
ssh user@host
ssh -p 2222 user@host
ssh -i key.pem user@host

# SCP (파일 복사)
scp file user@host:/path/
scp -r dir user@host:/path/
scp user@host:/path/file ./

# SFTP
sftp user@host
```

## 포트 확인

```bash
netstat -tuln         # 리스닝 포트
ss -tuln              # netstat 대체 (더 빠름)
lsof -i :80           # 80번 포트 사용 프로세스
```

## 기타

```bash
curl https://example.com     # HTTP 요청
wget https://example.com/file  # 파일 다운로드
telnet host port             # 포트 연결 테스트
nc -zv host port             # netcat으로 포트 확인
```
