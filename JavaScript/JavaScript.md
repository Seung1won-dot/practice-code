# JavaScript 프로그래밍 언어

## JavaScript란?

JavaScript는 1995년 넷스케이프(Netscape)의 브렌던 아이크(Brendan Eich)가 개발한 동적 프로그래밍 언어입니다. 웹 브라우저에서 동작하는 유일한 표준 언어로, 현재는 서버 사이드까지 영역을 확장한 범용 언어가 되었습니다.

## JavaScript의 특징

### 1. 동적 타입 언어
- 변수 선언 시 타입을 명시하지 않음
- 런타임에 타입이 결정됨
- 유연한 개발 가능

### 2. 이벤트 기반 프로그래밍
- 비동기 처리 지원
- 콜백 함수와 Promise
- 이벤트 루프 기반 실행 모델

### 3. 함수형 프로그래밍 지원
- 일급 함수 (First-class functions)
- 고차 함수 (Higher-order functions)
- 클로저 (Closure)

### 4. 프로토타입 기반 객체지향
- 클래스 없이도 객체 생성 가능
- 프로토타입 체인을 통한 상속
- ES6에서 클래스 문법 추가

### 5. 크로스 플랫폼
- 모든 주요 웹 브라우저에서 실행
- Node.js로 서버 사이드 실행
- 모바일 앱 개발 (React Native, Ionic)

## JavaScript의 활용 분야

### 프론트엔드 개발
- 웹 페이지 인터랙션
- SPA (Single Page Application)
- React, Vue, Angular 등 프레임워크

### 백엔드 개발
- Node.js 기반 서버
- RESTful API 개발
- 실시간 애플리케이션 (WebSocket)

### 모바일 앱 개발
- React Native
- Ionic
- NativeScript

### 데스크톱 애플리케이션
- Electron (VS Code, Slack 등)
- Tauri
- NW.js

### 게임 개발
- HTML5 게임
- Phaser, Three.js 등 게임 엔진

## JavaScript 버전

### ES5 (ECMAScript 5)
- 2009년 표준화
- 현재도 널리 사용

### ES6/ES2015
- 현대적 JavaScript의 시작
- 화살표 함수, 클래스, 모듈
- let, const 키워드

### ES2017
- async/await 도입
- 비동기 프로그래밍 간소화

### ES2020
- Optional Chaining (?.)
- Nullish Coalescing (??)
- BigInt

### ES2022
- Top-level await
- Private fields
- 최신 표준

## 학습 경로

### 기초 단계
1. 변수와 자료형
2. 연산자와 제어문
3. 함수
4. 객체와 배열
5. DOM 조작

### 중급 단계
1. 이벤트 처리
2. 비동기 프로그래밍 (Promise, async/await)
3. 클로저와 스코프
4. 프로토타입과 상속
5. 모듈 시스템

### 고급 단계
1. 함수형 프로그래밍
2. 디자인 패턴
3. 성능 최적화
4. 테스팅
5. 프레임워크/라이브러리 (React, Vue 등)

## 예제 파일 구조

### JavaScript 기초
- **기초/**: `00_setup_intro.md`, `01_variables_types.js`, `02_operators_condition.js`, `03_loops.js`
- **함수/**: `04_functions.js`
- **객체와배열/**: `05_objects.js`, `06_arrays.js`
- **DOM/**: `07_dom_basic.js`

### JavaScript 심화
- **이벤트/**: `08_events.js`
- **비동기/**: `09_promise_async.js`
- **고급/**: `10_closure_scope.js`, `11_classes.js`, `12_modules.js`

## JavaScript 개발 환경

### 런타임
- **브라우저**: Chrome, Firefox, Safari, Edge
- **Node.js**: 서버 사이드 JavaScript 실행 환경
- **Deno**: 현대적인 JavaScript/TypeScript 런타임

### 패키지 관리자
- **npm**: Node.js 기본 패키지 관리자
- **yarn**: Facebook에서 개발
- **pnpm**: 빠른 패키지 관리자

### 빌드 도구
- **Webpack**: 모듈 번들러
- **Vite**: 빠른 빌드 도구
- **Parcel**: 제로 설정 번들러

### 프레임워크/라이브러리
- **React**: Facebook 개발, 가장 인기 있는 UI 라이브러리
- **Vue.js**: 점진적 프레임워크
- **Angular**: Google 개발, 엔터프라이즈 프레임워크
- **Svelte**: 컴파일 타임 프레임워크

## JavaScript의 핵심 개념

### 비동기 프로그래밍
- 콜백 함수
- Promise
- async/await
- 이벤트 루프

### 클로저 (Closure)
- 함수와 렉시컬 환경의 조합
- 변수 캡슐화
- 모듈 패턴 구현

### 프로토타입
- 프로토타입 체인
- 상속 구현
- 메서드 공유

### 호이스팅 (Hoisting)
- 변수와 함수 선언의 끌어올림
- var, let, const의 차이
- 함수 선언 vs 함수 표현식

## JavaScript의 장점

1. **범용성**: 프론트엔드와 백엔드 모두 개발 가능
2. **유연성**: 동적 타입으로 빠른 개발
3. **생태계**: 방대한 npm 패키지
4. **실행 환경**: 브라우저에서 즉시 실행 가능
5. **커뮤니티**: 활발한 오픈소스 커뮤니티

## JavaScript의 단점

1. **타입 안전성**: 동적 타입으로 런타임 오류 가능
2. **일관성**: 브라우저마다 차이 존재
3. **복잡성**: 비동기 프로그래밍의 복잡성
4. **성능**: 인터프리터 언어로 네이티브보다 느림
5. **호이스팅**: 예상치 못한 동작 가능

## TypeScript

TypeScript는 JavaScript에 정적 타입을 추가한 언어입니다:
- 타입 안전성 향상
- 더 나은 IDE 지원
- JavaScript로 컴파일
- 점진적 도입 가능

## JavaScript와 다른 언어의 관계

### Java
- 이름만 비슷할 뿐 완전히 다른 언어
- Java는 컴파일 언어, JavaScript는 인터프리터 언어

### Python
- 둘 다 동적 타입 언어
- JavaScript는 브라우저에서 실행, Python은 서버 사이드

### HTML/CSS
- HTML: 구조, CSS: 스타일, JavaScript: 동작
- 웹 개발의 세 가지 핵심 기술

## 결론

JavaScript는 웹 개발의 필수 언어입니다. 프론트엔드에서 시작하여 백엔드, 모바일, 데스크톱까지 영역을 확장한 범용 프로그래밍 언어가 되었습니다. 풍부한 생태계와 활발한 커뮤니티를 통해 지속적으로 발전하고 있으며, 현대 웹 개발에서 가장 중요한 언어 중 하나입니다.
