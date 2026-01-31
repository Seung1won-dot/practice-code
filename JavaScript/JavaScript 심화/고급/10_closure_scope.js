// 클로저와 스코프

// 스코프
let global = "전역";
function outer() {
  let outerVar = "외부";
  function inner() {
    let innerVar = "내부";
    console.log(outerVar);  // 클로저: outer 스코프 접근 가능
  }
  return inner;
}

// 클로저: 함수가 자신이 정의된 스코프를 기억
function createCounter() {
  let count = 0;
  return function() {
    count++;
    return count;
  };
}
const counter = createCounter();
console.log(counter());  // 1
console.log(counter());  // 2
