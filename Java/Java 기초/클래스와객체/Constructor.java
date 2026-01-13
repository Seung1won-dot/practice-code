/*
 * 09_constructor.java
 * 
 * Java 생성자
 * - 기본 생성자
 * - 매개변수가 있는 생성자
 * - 생성자 오버로딩
 * - this()를 이용한 생성자 호출
 */

class Student {
    private String name;
    private int age;
    private String major;
    
    // 기본 생성자 (매개변수 없음)
    public Student() {
        this.name = "미정";
        this.age = 0;
        this.major = "미정";
        System.out.println("기본 생성자 호출");
    }
    
    // 매개변수가 있는 생성자
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
        this.major = "미정";
        System.out.println("생성자 (이름, 나이) 호출");
    }
    
    // 생성자 오버로딩
    public Student(String name, int age, String major) {
        this.name = name;
        this.age = age;
        this.major = major;
        System.out.println("생성자 (이름, 나이, 전공) 호출");
    }
    
    // this()를 이용한 생성자 호출
    public Student(String name) {
        this(name, 0, "미정");  // 다른 생성자 호출
        System.out.println("생성자 (이름) 호출");
    }
    
    // Getter 메서드
    public String getName() {
        return name;
    }
    
    public int getAge() {
        return age;
    }
    
    public String getMajor() {
        return major;
    }
    
    // Setter 메서드
    public void setName(String name) {
        this.name = name;
    }
    
    public void setAge(int age) {
        this.age = age;
    }
    
    public void setMajor(String major) {
        this.major = major;
    }
    
    public void display() {
        System.out.println("이름: " + name + ", 나이: " + age + ", 전공: " + major);
    }
}

public class Constructor {
    public static void main(String[] args) {
        // ========== 기본 생성자 ==========
        
        System.out.println("=== 기본 생성자 ===");
        Student student1 = new Student();
        student1.display();
        
        // ========== 매개변수가 있는 생성자 ==========
        
        System.out.println("\n=== 매개변수가 있는 생성자 ===");
        Student student2 = new Student("홍길동", 20);
        student2.display();
        
        // ========== 생성자 오버로딩 ==========
        
        System.out.println("\n=== 생성자 오버로딩 ===");
        Student student3 = new Student("김철수", 22, "컴퓨터공학");
        student3.display();
        
        // ========== this()를 이용한 생성자 호출 ==========
        
        System.out.println("\n=== this()를 이용한 생성자 호출 ===");
        Student student4 = new Student("이영희");
        student4.display();
        
        // ========== 생성자와 Setter 비교 ==========
        
        System.out.println("\n=== 생성자 vs Setter ===");
        
        // 생성자 사용
        Student student5 = new Student("박민수", 25, "전자공학");
        student5.display();
        
        // Setter 사용
        Student student6 = new Student();
        student6.setName("최지영");
        student6.setAge(23);
        student6.setMajor("경영학");
        student6.display();
        
        // ========== 객체 배열과 생성자 ==========
        
        System.out.println("\n=== 객체 배열과 생성자 ===");
        Student[] students = {
            new Student("홍길동", 20, "컴퓨터공학"),
            new Student("김철수", 21, "전자공학"),
            new Student("이영희", 22, "경영학")
        };
        
        for (Student student : students) {
            student.display();
        }
    }
}

/*
 * Java 생성자 핵심 정리
 * 
 * 1. 생성자란?
 *    - 객체 생성 시 자동으로 호출되는 특별한 메서드
 *    - 클래스명과 동일한 이름
 *    - 반환 타입 없음
 * 
 * 2. 기본 생성자
 *    - 매개변수가 없는 생성자
 *    - 생성자를 정의하지 않으면 자동 생성
 *    - 하나라도 정의하면 기본 생성자 자동 생성 안 됨
 * 
 * 3. 생성자 오버로딩
 *    - 같은 이름의 생성자를 여러 개 정의
 *    - 매개변수의 개수나 타입이 달라야 함
 * 
 * 4. this()
 *    - 같은 클래스의 다른 생성자 호출
 *    - 생성자의 첫 줄에만 사용 가능
 *    - 코드 중복 제거
 * 
 * 5. 생성자 vs Setter
 *    - 생성자: 객체 생성 시 초기화
 *    - Setter: 객체 생성 후 값 변경
 * 
 * 6. 주의사항
 *    - 생성자는 상속되지 않음
 *    - private 생성자도 가능 (싱글톤 패턴 등)
 *    - 생성자에서 예외 처리 가능
 */

