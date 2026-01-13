/*
 * 08_class_basic.java
 * 
 * Java 클래스와 객체 기초
 * - 클래스 정의
 * - 객체 생성
 * - 멤버 변수와 메서드
 * - 접근 제어자
 */

// 클래스 정의
class Person {
    // 멤버 변수 (인스턴스 변수)
    private String name;  // private: 클래스 내부에서만 접근
    private int age;
    
    // public: 어디서나 접근 가능
    public void setName(String name) {
        this.name = name;  // this: 현재 객체를 가리킴
    }
    
    public void setAge(int age) {
        if (age > 0) {  // 유효성 검사
            this.age = age;
        }
    }
    
    public String getName() {
        return name;
    }
    
    public int getAge() {
        return age;
    }
    
    public void display() {
        System.out.println("이름: " + name + ", 나이: " + age);
    }
}

// 메인 클래스
public class ClassBasic {
    public static void main(String[] args) {
        // ========== 객체 생성 ==========
        
        System.out.println("=== 객체 생성 ===");
        
        // 객체 생성
        Person person1 = new Person();
        person1.setName("홍길동");
        person1.setAge(25);
        person1.display();
        
        // ========== 여러 객체 생성 ==========
        
        System.out.println("\n=== 여러 객체 생성 ===");
        
        Person person2 = new Person();
        person2.setName("김철수");
        person2.setAge(30);
        person2.display();
        
        Person person3 = new Person();
        person3.setName("이영희");
        person3.setAge(28);
        person3.display();
        
        // ========== 접근 제어자 ==========
        
        System.out.println("\n=== 접근 제어자 ===");
        
        // public 메서드는 외부에서 접근 가능
        System.out.println("person1의 이름: " + person1.getName());
        System.out.println("person1의 나이: " + person1.getAge());
        
        // private 멤버는 직접 접근 불가
        // person1.name = "박민수";  // 오류! private 멤버 접근 불가
        
        // ========== this 키워드 ==========
        
        System.out.println("\n=== this 키워드 ===");
        
        Person person4 = new Person();
        person4.setName("최지영");
        person4.setAge(22);
        person4.display();
        
        // ========== 객체 배열 ==========
        
        System.out.println("\n=== 객체 배열 ===");
        
        Person[] people = new Person[3];
        
        people[0] = new Person();
        people[0].setName("홍길동");
        people[0].setAge(25);
        
        people[1] = new Person();
        people[1].setName("김철수");
        people[1].setAge(30);
        
        people[2] = new Person();
        people[2].setName("이영희");
        people[2].setAge(28);
        
        for (Person person : people) {
            person.display();
        }
    }
}

/*
 * Java 클래스와 객체 핵심 정리
 * 
 * 1. 클래스 정의
 *    class 클래스명 {
 *        // 멤버 변수
 *        // 메서드
 *    }
 * 
 * 2. 객체 생성
 *    클래스명 객체명 = new 클래스명();
 * 
 * 3. 접근 제어자
 *    - private: 클래스 내부에서만 접근
 *    - public: 어디서나 접근 가능
 *    - protected: 같은 패키지 또는 상속 관계에서 접근
 *    - (default): 같은 패키지에서만 접근
 * 
 * 4. this 키워드
 *    - 현재 객체를 가리킴
 *    - 멤버 변수와 매개변수 이름이 같을 때 구분
 * 
 * 5. 캡슐화
 *    - 데이터를 private으로 보호
 *    - public 메서드로 접근 제어
 *    - 정보 은닉 구현
 */

