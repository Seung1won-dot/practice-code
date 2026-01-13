/*
 * 01_hello_world.java
 * 
 * Java 입출력과 클래스 기초
 * - System.out.println을 이용한 출력
 * - System.in, Scanner를 이용한 입력
 * - 클래스와 main 메서드 구조
 */

// 클래스 선언
public class HelloWorld {
    // main 메서드: 프로그램의 진입점
    public static void main(String[] args) {
        // ========== 출력 (System.out) ==========
        
        // println: 출력 후 줄바꿈
        System.out.println("Hello, World!");
        
        // print: 출력 후 줄바꿈 없음
        System.out.print("안녕하세요, ");
        System.out.print("Java입니다!");
        System.out.println(); // 줄바꿈만
        
        // printf: 포맷 지정 출력
        String name = "홍길동";
        int age = 25;
        System.out.printf("이름: %s, 나이: %d\n", name, age);
        
        // 여러 값 출력
        System.out.println("이름: " + name + ", 나이: " + age);
        
        // ========== 입력 (Scanner 사용) ==========
        
        // Scanner 클래스 import 필요 (파일 상단에 추가)
        // import java.util.Scanner;
        
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        System.out.print("이름을 입력하세요: ");
        String userName = scanner.next(); // 공백 전까지만 입력받음
        
        System.out.print("나이를 입력하세요: ");
        int userAge = scanner.nextInt();
        
        System.out.println("입력하신 정보: " + userName + ", " + userAge + "세");
        
        // ========== 공백 포함 문자열 입력 ==========
        
        scanner.nextLine(); // 이전 입력의 개행 문자 제거
        
        System.out.print("전체 이름을 입력하세요 (공백 포함): ");
        String fullName = scanner.nextLine(); // 공백 포함 문자열 입력
        System.out.println("전체 이름: " + fullName);
        
        // ========== 여러 데이터 타입 입출력 ==========
        
        System.out.print("\n정수 입력: ");
        int integer = scanner.nextInt();
        
        System.out.print("실수 입력: ");
        double decimal = scanner.nextDouble();
        
        System.out.print("문자 입력: ");
        char character = scanner.next().charAt(0); // 첫 번째 문자만
        
        System.out.print("불리언 입력 (true 또는 false): ");
        boolean bool = scanner.nextBoolean();
        
        System.out.println("\n입력된 값들:");
        System.out.println("정수: " + integer);
        System.out.println("실수: " + decimal);
        System.out.println("문자: " + character);
        System.out.println("불리언: " + bool);
        
        scanner.close(); // Scanner 닫기
    }
}

/*
 * Java 프로그램 구조 핵심 정리
 * 
 * 1. 클래스 선언
 *    public class 클래스명 {
 *        // 클래스 내용
 *    }
 * 
 * 2. main 메서드
 *    - 프로그램의 진입점
 *    - 반드시 public static void main(String[] args) 형식
 *    - String[] args: 명령줄 인자
 * 
 * 3. 출력 방법
 *    - System.out.println(): 출력 후 줄바꿈
 *    - System.out.print(): 출력 후 줄바꿈 없음
 *    - System.out.printf(): 포맷 지정 출력 (C 스타일)
 * 
 * 4. 입력 방법
 *    - Scanner 클래스 사용
 *    - import java.util.Scanner; 필요
 *    - scanner.next(): 단어 입력 (공백 전까지)
 *    - scanner.nextLine(): 줄 전체 입력 (공백 포함)
 *    - scanner.nextInt(): 정수 입력
 *    - scanner.nextDouble(): 실수 입력
 *    - scanner.nextBoolean(): 불리언 입력
 * 
 * 5. 문자열 연결
 *    - + 연산자로 문자열 연결
 *    - "문자열" + 변수 + "문자열"
 * 
 * 6. 주석
 *    - // : 한 줄 주석
 *    - /* */ : 여러 줄 주석
 *    - /** */ : 문서 주석 (JavaDoc)
 */

