/*
 * 11_inheritance.java
 * 
 * Java 상속
 * - 클래스 상속
 * - super 키워드
 * - 메서드 오버라이딩
 * - 접근 제어자와 상속
 */

// 부모 클래스 (상위 클래스)
class Animal {
    protected String name;  // protected: 상속 관계에서 접근 가능
    protected int age;
    
    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    public void eat() {
        System.out.println(name + "이(가) 먹고 있습니다.");
    }
    
    public void sleep() {
        System.out.println(name + "이(가) 잠을 자고 있습니다.");
    }
    
    public void makeSound() {
        System.out.println(name + "이(가) 소리를 냅니다.");
    }
    
    public void display() {
        System.out.println("이름: " + name + ", 나이: " + age);
    }
}

// 자식 클래스 (하위 클래스) - extends로 상속
class Dog extends Animal {
    private String breed;  // 개만의 특별한 속성
    
    public Dog(String name, int age, String breed) {
        super(name, age);  // 부모 클래스 생성자 호출
        this.breed = breed;
    }
    
    // 메서드 오버라이딩 (재정의)
    @Override
    public void makeSound() {
        System.out.println(name + "이(가) 멍멍 짖습니다.");
    }
    
    // 자식 클래스만의 메서드
    public void bark() {
        System.out.println(name + "이(가) 크게 짖습니다!");
    }
    
    @Override
    public void display() {
        super.display();  // 부모 클래스 메서드 호출
        System.out.println("품종: " + breed);
    }
}

class Cat extends Animal {
    private boolean isIndoor;
    
    public Cat(String name, int age, boolean isIndoor) {
        super(name, age);
        this.isIndoor = isIndoor;
    }
    
    @Override
    public void makeSound() {
        System.out.println(name + "이(가) 야옹 웁니다.");
    }
    
    public void scratch() {
        System.out.println(name + "이(가) 할퀴고 있습니다.");
    }
    
    @Override
    public void display() {
        super.display();
        System.out.println("실내 고양이: " + (isIndoor ? "예" : "아니오"));
    }
}

public class Inheritance {
    public static void main(String[] args) {
        // ========== 상속 확인 ==========
        
        System.out.println("=== 상속 확인 ===");
        
        Dog dog = new Dog("뽀삐", 3, "골든 리트리버");
        dog.display();
        dog.eat();        // 부모 클래스 메서드
        dog.sleep();      // 부모 클래스 메서드
        dog.makeSound();  // 오버라이딩된 메서드
        dog.bark();       // 자식 클래스만의 메서드
        
        System.out.println();
        
        Cat cat = new Cat("나비", 2, true);
        cat.display();
        cat.eat();
        cat.sleep();
        cat.makeSound();  // 오버라이딩된 메서드
        cat.scratch();    // 자식 클래스만의 메서드
        
        // ========== 부모 클래스 참조 ==========
        
        System.out.println("\n=== 부모 클래스 참조 ===");
        
        // 부모 클래스 타입으로 자식 객체 참조 가능
        Animal animal1 = new Dog("멍멍이", 4, "비글");
        Animal animal2 = new Cat("야옹이", 1, false);
        
        animal1.makeSound();  // 오버라이딩된 메서드 호출
        animal2.makeSound();
        
        // animal1.bark();  // 오류! 부모 클래스에 없는 메서드
        
        // ========== super 키워드 ==========
        
        System.out.println("\n=== super 키워드 ===");
        
        Dog dog2 = new Dog("초코", 5, "푸들");
        dog2.display();  // super.display() 호출됨
        
        // ========== 상속 체인 ==========
        
        System.out.println("\n=== 상속 체인 ===");
        
        // 모든 동물을 배열로 관리
        Animal[] animals = {
            new Dog("뽀삐", 3, "골든 리트리버"),
            new Cat("나비", 2, true),
            new Dog("멍멍이", 4, "비글")
        };
        
        for (Animal animal : animals) {
            animal.display();
            animal.makeSound();  // 각각의 오버라이딩된 메서드 호출
            System.out.println();
        }
    }
}

/*
 * Java 상속 핵심 정리
 * 
 * 1. 상속 정의
 *    class 자식클래스 extends 부모클래스 {
 *        // 자식 클래스 내용
 *    }
 * 
 * 2. 상속의 장점
 *    - 코드 재사용
 *    - 유지보수 용이
 *    - 다형성 구현
 * 
 * 3. super 키워드
 *    - super: 부모 클래스 참조
 *    - super(): 부모 클래스 생성자 호출
 *    - super.메서드(): 부모 클래스 메서드 호출
 * 
 * 4. 메서드 오버라이딩
 *    - 부모 클래스 메서드를 자식 클래스에서 재정의
 *    - @Override 어노테이션 사용 권장
 *    - 접근 제어자는 같거나 더 넓어야 함
 * 
 * 5. 접근 제어자와 상속
 *    - private: 상속 불가
 *    - protected: 상속 관계에서 접근 가능
 *    - public: 어디서나 접근 가능
 * 
 * 6. 상속 제한
 *    - Java는 단일 상속만 지원 (하나의 부모만)
 *    - 모든 클래스는 Object 클래스를 상속
 * 
 * 7. 주의사항
 *    - 생성자는 상속되지 않음
 *    - private 멤버는 상속되지 않음
 *    - final 클래스는 상속 불가
 *    - final 메서드는 오버라이딩 불가
 */

