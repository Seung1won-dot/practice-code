/*
 * 13_exception_handling.java
 * 
 * Java 예외 처리
 * - try-catch 문
 * - finally 블록
 * - 여러 예외 처리
 * - throw와 throws
 * - 사용자 정의 예외
 */

public class ExceptionHandling {
    public static void main(String[] args) {
        // ========== 기본 예외 처리 ==========
        
        System.out.println("=== 기본 예외 처리 ===");
        
        try {
            int result = 10 / 0;  // ArithmeticException 발생
            System.out.println("결과: " + result);
        } catch (ArithmeticException e) {
            System.out.println("예외 발생: " + e.getMessage());
            System.out.println("0으로 나눌 수 없습니다.");
        }
        
        System.out.println("프로그램 계속 실행");
        
        // ========== 여러 예외 처리 ==========
        
        System.out.println("\n=== 여러 예외 처리 ===");
        
        try {
            int[] arr = {1, 2, 3};
            System.out.println(arr[5]);  // ArrayIndexOutOfBoundsException
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("배열 인덱스 오류: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("일반 예외: " + e.getMessage());
        }
        
        // ========== 다중 catch 블록 ==========
        
        System.out.println("\n=== 다중 catch 블록 ===");
        
        try {
            String str = null;
            System.out.println(str.length());  // NullPointerException
        } catch (NullPointerException e) {
            System.out.println("널 포인터 예외: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("일반 예외: " + e.getMessage());
        }
        
        // ========== finally 블록 ==========
        
        System.out.println("\n=== finally 블록 ===");
        
        try {
            int[] numbers = {1, 2, 3};
            System.out.println(numbers[1]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("배열 인덱스 오류");
        } finally {
            System.out.println("finally 블록은 항상 실행됩니다.");
        }
        
        // ========== 예외 정보 출력 ==========
        
        System.out.println("\n=== 예외 정보 출력 ===");
        
        try {
            int result = 10 / 0;
        } catch (ArithmeticException e) {
            System.out.println("예외 메시지: " + e.getMessage());
            System.out.println("예외 클래스: " + e.getClass().getName());
            e.printStackTrace();  // 스택 트레이스 출력
        }
        
        // ========== throw로 예외 발생시키기 ==========
        
        System.out.println("\n=== throw로 예외 발생 ===");
        
        try {
            checkAge(15);
        } catch (IllegalArgumentException e) {
            System.out.println("예외 처리: " + e.getMessage());
        }
        
        // ========== throws로 예외 전달 ==========
        
        System.out.println("\n=== throws로 예외 전달 ===");
        
        try {
            divide(10, 0);
        } catch (ArithmeticException e) {
            System.out.println("예외 처리: " + e.getMessage());
        }
        
        // ========== 사용자 정의 예외 ==========
        
        System.out.println("\n=== 사용자 정의 예외 ===");
        
        try {
            withdraw(1000, 2000);
        } catch (InsufficientBalanceException e) {
            System.out.println("예외 처리: " + e.getMessage());
        }
        
        // ========== try-with-resources (Java 7+) ==========
        
        System.out.println("\n=== try-with-resources ===");
        
        // 자동으로 리소스 닫기
        try (MyResource resource = new MyResource()) {
            resource.use();
        } catch (Exception e) {
            System.out.println("예외: " + e.getMessage());
        }
        // resource.close() 자동 호출됨
    }
    
    // throw로 예외 발생
    public static void checkAge(int age) {
        if (age < 18) {
            throw new IllegalArgumentException("나이는 18세 이상이어야 합니다.");
        }
        System.out.println("나이 확인 완료: " + age);
    }
    
    // throws로 예외 전달
    public static int divide(int a, int b) throws ArithmeticException {
        if (b == 0) {
            throw new ArithmeticException("0으로 나눌 수 없습니다.");
        }
        return a / b;
    }
    
    // 사용자 정의 예외 사용
    public static void withdraw(double balance, double amount) throws InsufficientBalanceException {
        if (amount > balance) {
            throw new InsufficientBalanceException("잔액이 부족합니다. 현재 잔액: " + balance);
        }
        System.out.println("출금 성공: " + amount);
    }
}

// 사용자 정의 예외 클래스
class InsufficientBalanceException extends Exception {
    public InsufficientBalanceException(String message) {
        super(message);
    }
}

// 리소스 클래스 (AutoCloseable 구현)
class MyResource implements AutoCloseable {
    public void use() {
        System.out.println("리소스 사용 중...");
    }
    
    @Override
    public void close() {
        System.out.println("리소스 닫기");
    }
}

/*
 * Java 예외 처리 핵심 정리
 * 
 * 1. 예외 처리 구조
 *    try {
 *        // 예외가 발생할 수 있는 코드
 *    } catch (예외타입 e) {
 *        // 예외 처리
 *    } finally {
 *        // 항상 실행되는 코드
 *    }
 * 
 * 2. 예외 클래스 계층
 *    Throwable
 *    ├── Error (시스템 오류, 처리 불가)
 *    └── Exception
 *        ├── RuntimeException (실행 시 예외)
 *        └── Checked Exception (컴파일 시 체크)
 * 
 * 3. 주요 예외
 *    - ArithmeticException: 산술 연산 오류
 *    - NullPointerException: null 참조
 *    - ArrayIndexOutOfBoundsException: 배열 인덱스 오류
 *    - IllegalArgumentException: 잘못된 인자
 *    - IOException: 입출력 오류
 * 
 * 4. throw
 *    - 예외를 명시적으로 발생시킴
 *    - throw new 예외타입("메시지");
 * 
 * 5. throws
 *    - 메서드에서 예외를 호출자에게 전달
 *    - public void method() throws Exception
 * 
 * 6. 사용자 정의 예외
 *    - Exception을 상속받아 생성
 *    - 필요에 따라 RuntimeException 상속 가능
 * 
 * 7. try-with-resources
 *    - AutoCloseable 구현한 리소스 자동 닫기
 *    - Java 7부터 지원
 *    - finally에서 close() 호출 불필요
 * 
 * 8. 주의사항
 *    - catch 블록은 구체적인 예외부터 작성
 *    - Exception은 마지막에 catch
 *    - 예외를 무시하지 말고 처리하거나 로깅
 */

