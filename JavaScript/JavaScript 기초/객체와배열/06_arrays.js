// 배열

const fruits = ["apple", "banana", "cherry"];

// 접근
console.log(fruits[0]);   // apple
console.log(fruits.length);  // 3

// 메서드
fruits.push("date");      // 끝에 추가
fruits.pop();             // 끝 제거
fruits.unshift("apricot");  // 앞에 추가
fruits.shift();           // 앞 제거

// map, filter, reduce
const nums = [1, 2, 3, 4, 5];
const doubled = nums.map(n => n * 2);      // [2, 4, 6, 8, 10]
const evens = nums.filter(n => n % 2 === 0);  // [2, 4]
const sum = nums.reduce((acc, n) => acc + n, 0);  // 15

// 구조 분해
const [first, second, ...rest] = nums;
console.log(first, second, rest);  // 1, 2, [3, 4, 5]
