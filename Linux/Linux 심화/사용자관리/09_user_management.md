# 사용자와 그룹 관리

## 사용자 확인

```bash
whoami              # 현재 사용자
id                  # 사용자 ID, 그룹 ID
who                 # 로그인한 사용자
w                   # 로그인 사용자와 실행 중인 명령
```

## 사용자 추가/삭제

```bash
# 사용자 추가
useradd username
useradd -m -s /bin/bash username   # 홈 생성, 쉘 지정

# 비밀번호 설정
passwd username

# 사용자 삭제
userdel username
userdel -r username    # 홈 디렉터리까지 삭제
```

## 사용자 수정

```bash
usermod -l newname oldname     # 사용자명 변경
usermod -aG groupname user     # 그룹 추가
usermod -s /bin/bash user      # 기본 쉘 변경
usermod -L user                # 비밀번호 잠금
usermod -U user                # 비밀번호 잠금 해제
```

## 그룹 관리

```bash
groups username     # 사용자 그룹 목록
groupadd groupname  # 그룹 생성
groupdel groupname  # 그룹 삭제
gpasswd -a user group  # 그룹에 사용자 추가
gpasswd -d user group  # 그룹에서 사용자 제거
```

## /etc/passwd

```
username:x:1000:1000:User Name:/home/username:/bin/bash
```
- 사용자명:비밀번호(x):UID:GID:설명:홈:쉘

## /etc/shadow

- 암호화된 비밀번호 저장
- root만 읽기 가능

## su와 sudo

```bash
su - username       # 다른 사용자로 전환 (- : 로그인 쉘)
su -                # root로 전환
exit                # 원래 사용자로

sudo command        # root 권한으로 명령 실행
sudo -i             # root 쉘로
sudo -u user cmd    # 특정 사용자 권한으로
```

## sudoers

```bash
visudo              # /etc/sudoers 안전하게 편집
# user ALL=(ALL) ALL    # user가 모든 명령 sudo 가능
```
