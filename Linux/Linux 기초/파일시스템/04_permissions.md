# 권한과 소유자

## 권한 표기

```bash
ls -l
# -rwxr-xr-x 1 user group 1024 Jan 31 10:00 file.txt
# │││││││││
# │└┴┴┴┴┴┴┴─ 다른 사용자 (other)
# │ └┴┴┴─── 그룹 (group)
# │  └┴┴─── 소유자 (owner)
# └──────── 파일 타입 (-, d, l 등)
```

- **r** (4): 읽기
- **w** (2): 쓰기
- **x** (1): 실행 (디렉터리면 진입)

## 권한 변경 (chmod)

```bash
# 숫자 모드
chmod 755 file.txt     # rwxr-xr-x
chmod 644 file.txt     # rw-r--r--
chmod 600 file.txt     # rw------- (소유자만 읽기/쓰기)

# 문자 모드
chmod u+x file.txt     # 소유자에 실행 권한 추가
chmod g-w file.txt     # 그룹에서 쓰기 권한 제거
chmod o=r file.txt     # 다른 사용자를 읽기만
chmod a+x script.sh    # 모든 사용자에 실행 권한

# 재귀 적용
chmod -R 755 mydir/
```

### 자주 쓰는 권한

| 모드 | 의미 |
|------|------|
| 755 | 실행 파일, 디렉터리 (rwxr-xr-x) |
| 644 | 일반 파일 (rw-r--r--) |
| 600 | 비밀키 등 (소유자만) |
| 700 | 홈 디렉터리 |

## 소유자 변경 (chown)

```bash
chown user file.txt            # 소유자 변경
chown user:group file.txt      # 소유자와 그룹
chown -R user:group mydir/     # 재귀 적용
```

## 그룹 변경 (chgrp)

```bash
chgrp groupname file.txt
chgrp -R groupname mydir/
```

## 특수 권한

```bash
# SetUID (4): 실행 시 소유자 권한으로
chmod 4755 program
# SetGID (2): 실행 시 그룹 권한으로
chmod 2755 program
# Sticky bit (1): /tmp처럼 소유자만 삭제 가능
chmod 1777 dir
```

## umask

- 새로 생성되는 파일의 기본 권한
- `umask 022` : 기본 755 (디렉터리), 644 (파일)
- `umask` : 현재 값 확인
