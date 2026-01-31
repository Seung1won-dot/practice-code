# CSS 환경 설정

## CSS 적용 방법

### 1. 인라인 스타일
```html
<p style="color: red;">인라인 스타일</p>
```
- 해당 요소에만 적용
- 우선순위 가장 높음
- 유지보수 어려움

### 2. 내부 스타일시트
```html
<head>
  <style>
    p { color: blue; }
  </style>
</head>
```
- HTML 문서 내 `<style>` 태그
- 작은 프로젝트에 적합

### 3. 외부 스타일시트 (권장)
```html
<head>
  <link rel="stylesheet" href="style.css">
</head>
```
- 별도 .css 파일로 분리
- 캐싱 가능, 재사용 용이
- 가장 권장되는 방식

## CSS 파일 확장자

- `.css` - 일반 CSS 파일

## 개발 도구

- **Chrome DevTools**: F12, 요소 검사로 스타일 확인·수정
- **VS Code**: Live Server로 실시간 미리보기
- **W3C CSS Validator**: 문법 검증
