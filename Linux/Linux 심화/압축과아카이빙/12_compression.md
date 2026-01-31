# 압축과 아카이빙

## tar - 아카이브

```bash
# 아카이브 생성
tar -cvf archive.tar dir/      # 디렉터리 묶기
tar -cvf archive.tar file1 file2

# 아카이브 해제
tar -xvf archive.tar
tar -xvf archive.tar -C /dest/ # 특정 경로에

# gzip 압축과 함께
tar -czvf archive.tar.gz dir/
tar -xzvf archive.tar.gz       # 압축 해제 및 풀기

# bzip2
tar -cjvf archive.tar.bz2 dir/
tar -xjvf archive.tar.bz2

# xz
tar -cJvf archive.tar.xz dir/
tar -xJvf archive.tar.xz
```

### tar 옵션

| 옵션 | 설명 |
|------|------|
| -c | 생성 |
| -x | 추출 |
| -v | 과정 출력 |
| -f | 파일명 지정 |
| -z | gzip |
| -j | bzip2 |
| -J | xz |
| -t | 내용 목록만 |

## gzip / gunzip

```bash
gzip file.txt          # file.txt.gz 생성, 원본 삭제
gzip -k file.txt       # 원본 유지 (-k)
gunzip file.gz         # 압축 해제
gzip -d file.gz        # gunzip과 동일
```

## zip / unzip

```bash
zip archive.zip file1 file2    # 압축
zip -r archive.zip dir/        # 디렉터리 재귀
unzip archive.zip              # 압축 해제
unzip -l archive.zip           # 목록만 확인
unzip -d /dest/ archive.zip    # 특정 경로에
```

## 7z (p7zip)

```bash
7z a archive.7z dir/   # 압축
7z x archive.7z        # 압축 해제
7z l archive.7z        # 목록
```
