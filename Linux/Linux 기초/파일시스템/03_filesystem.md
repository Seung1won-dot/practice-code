# Linux 파일시스템

## 디렉터리 구조 (FHS)

```
/
├── bin      실행 가능한 필수 명령어 (ls, cp 등)
├── boot    부트 로더, 커널
├── dev     장치 파일 (하드디스크, 터미널 등)
├── etc     설정 파일
├── home    사용자 홈 디렉터리
├── lib     필수 공유 라이브러리
├── media   이동식 미디어 마운트점 (USB, CD)
├── mnt     임시 마운트점
├── opt     추가 소프트웨어
├── proc    가상 파일시스템 (프로세스 정보)
├── root    root 사용자 홈
├── run     런타임 데이터
├── sbin    시스템 관리용 명령어
├── tmp     임시 파일 (재부팅 시 삭제 가능)
├── usr     사용자 프로그램, 라이브러리
└── var     로그, 캐시 등 가변 데이터
```

## 주요 디렉터리 설명

| 경로 | 용도 |
|------|------|
| /etc | 시스템·서비스 설정 |
| /home | 일반 사용자 홈 |
| /tmp | 임시 파일 (누구나 쓰기 가능) |
| /var/log | 로그 파일 |
| /usr/bin | 사용자 명령어 |
| /proc | 프로세스·시스템 정보 (가상) |

## 파일 종류

```bash
ls -l
# 첫 글자로 구분
# - : 일반 파일
# d : 디렉터리
# l : 심볼릭 링크
# c : 문자 장치
# b : 블록 장치
```

## 마운트

```bash
mount                  # 마운트된 파일시스템 목록
mount /dev/sdb1 /mnt   # 장치를 /mnt에 마운트
umount /mnt            # 마운트 해제
df -h                  # 디스크 사용량 (사람이 읽기 쉬운 형태)
du -sh /home           # 디렉터리 크기
du -h --max-depth=1    # 1단계 하위만
```

## 심볼릭 링크

```bash
ln -s /path/to/target linkname   # 심볼릭 링크 생성
ln target hardlink               # 하드 링크 생성
ls -l                            # l로 시작하고 -> 표시
```

## inode

- 파일 메타데이터 저장
- `ls -i` : inode 번호 확인
- 파일명은 inode에 대한 참조
