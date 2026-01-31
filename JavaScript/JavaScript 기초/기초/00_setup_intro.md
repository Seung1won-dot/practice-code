# JavaScript 환경 설정

## 실행 환경

### 1. 브라우저
- Chrome, Firefox, Safari, Edge 등
- F12 → Console 탭에서 실행
- HTML에 `<script>` 태그로 포함

### 2. Node.js
- 서버 사이드 JavaScript
- 터미널: `node script.js`

## HTML에 연결

```html
<!-- 인라인 -->
<script>console.log("hello");</script>

<!-- 외부 파일 (권장) -->
<script src="script.js"></script>

<!-- body 끝에 넣으면 DOM 로드 후 실행 -->
<body>
  ...
  <script src="script.js"></script>
</body>
```

## 개발 도구

- **Chrome DevTools**: F12, Console, Sources
- **VS Code**: Live Server, Code Runner
- **Node.js**: `node --version` 으로 확인
