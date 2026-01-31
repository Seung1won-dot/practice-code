// ES6 모듈

// export (utils.js)
export const PI = 3.14;
export function add(a, b) { return a + b; }
export default class Calculator {}

// export 기본 + 이름
// export { add, PI };
// export { add as sum };

// import (main.js)
import Calculator from "./utils.js";       // default
import { add, PI } from "./utils.js";     // 이름 지정
import * as utils from "./utils.js";      // 전체

// HTML에서 사용 시
// <script type="module" src="main.js"></script>
