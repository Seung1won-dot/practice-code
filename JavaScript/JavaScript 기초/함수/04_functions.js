// 함수

// 함수 선언
function greet(name) {
  return `Hello, ${name}!`;
}
console.log(greet("Alice"));  // Hello, Alice!

// 함수 표현식
const add = function(a, b) {
  return a + b;
};

// 화살표 함수
const multiply = (a, b) => a * b;
const square = x => x * x;

// 기본값 매개변수
function log(msg = "기본 메시지") {
  console.log(msg);
}

// 나머지 매개변수
function sum(...numbers) {
  return numbers.reduce((acc, n) => acc + n, 0);
}
console.log(sum(1, 2, 3, 4, 5));  // 15
