// 연산자와 제어문

// 산술 연산자
let a = 10 + 5;   // 15
let b = 10 - 5;
let c = 10 * 5;
let d = 10 / 5;
let e = 10 % 3;   // 나머지 1

// 비교 연산자
console.log(5 == "5");   // true (값만 비교)
console.log(5 === "5");  // false (타입까지 비교, 권장)

// 조건문
if (a > 10) {
  console.log("10보다 큼");
} else if (a === 10) {
  console.log("10과 같음");
} else {
  console.log("10보다 작음");
}

// 삼항 연산자
let result = a > 10 ? "크다" : "작거나 같다";

// switch
switch (a) {
  case 15:
    console.log("15");
    break;
  default:
    console.log("그 외");
}
