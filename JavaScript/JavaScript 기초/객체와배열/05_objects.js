// 객체

const person = {
  name: "Alice",
  age: 30,
  greet: function() {
    return `Hi, I'm ${this.name}`;
  }
};

// 접근
console.log(person.name);      // Alice
console.log(person["age"]);    // 30

// 추가·수정
person.email = "alice@email.com";
person.age = 31;

// 삭제
delete person.email;

// shorthand
const name = "Bob";
const age = 25;
const user = { name, age };  // { name: "Bob", age: 25 }

// 구조 분해
const { name: userName, age: userAge } = person;
