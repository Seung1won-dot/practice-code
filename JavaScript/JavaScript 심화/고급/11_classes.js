// ES6 클래스

class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }
  
  greet() {
    return `Hi, I'm ${this.name}`;
  }
  
  static info() {
    return "Person 클래스";
  }
}

class Student extends Person {
  constructor(name, age, major) {
    super(name, age);  // 부모 생성자 호출
    this.major = major;
  }
  
  greet() {
    return `${super.greet()} (${this.major})`;
  }
}

const s = new Student("Alice", 20, "CS");
console.log(s.greet());  // Hi, I'm Alice (CS)
