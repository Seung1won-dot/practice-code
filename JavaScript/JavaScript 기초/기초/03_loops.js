// 반복문

// for
for (let i = 0; i < 5; i++) {
  console.log(i);  // 0, 1, 2, 3, 4
}

// for...of (배열 순회)
const arr = [1, 2, 3];
for (const item of arr) {
  console.log(item);  // 1, 2, 3
}

// for...in (객체 키 순회)
const obj = { a: 1, b: 2 };
for (const key in obj) {
  console.log(key, obj[key]);
}

// while
let i = 0;
while (i < 3) {
  console.log(i);
  i++;
}

// do-while
let j = 0;
do {
  console.log(j);
  j++;
} while (j < 3);
