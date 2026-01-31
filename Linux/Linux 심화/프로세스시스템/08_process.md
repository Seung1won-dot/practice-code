# 프로세스 관리

## 프로세스 확인

```bash
ps                  # 현재 터미널 프로세스
ps aux              # 전체 프로세스 상세
ps -ef              # 전체 프로세스 (다른 형식)
ps aux | grep nginx # 특정 프로세스만

top                 # 실시간 모니터링 (q로 종료)
htop                # top 개선 버전 (설치 필요)
```

## 프로세스 종료

```bash
kill PID            # SIGTERM 전송 (정상 종료 요청)
kill -9 PID         # SIGKILL (강제 종료)
kill -15 PID        # SIGTERM (기본값)

killall processname # 이름으로 종료
pkill nginx         # 패턴으로 종료
```

## 백그라운드 실행

```bash
command &           # 백그라운드로 실행
Ctrl+Z              # 현재 작업 일시정지
bg                  # 일시정지 작업을 백그라운드로
fg                  # 백그라운드 작업을 포그라운드로
jobs                # 백그라운드 작업 목록
```

## nice와 renice

```bash
nice -n 10 command  # 낮은 우선순위로 실행
renice 5 -p PID     # 실행 중인 프로세스 우선순위 변경
```

## 시스템 모니터링

```bash
free -h             # 메모리 사용량
df -h               # 디스크 사용량
uptime              # 시스템 가동 시간, 부하
```
