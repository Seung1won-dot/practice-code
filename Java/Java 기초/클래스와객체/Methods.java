/*
 * 10_methods.java
 * 
 * Java 메서드
 * - 메서드 정의와 호출
 * - 매개변수와 반환값
 * - 메서드 오버로딩
 * - static 메서드
 * - 재귀 메서드
 */

class Calculator {
    // 인스턴스 메서드
    public int add(int a, int b) {
        return a + b;
    }
    
    public int subtract(int a, int b) {
        return a - b;
    }
    
    public int multiply(int a, int b) {
        return a * b;
    }
    
    public double divide(int a, int b) {
        if (b == 0) {
            System.out.println("0으로 나눌 수 없습니다.");
            return 0;
        }
        return (double)a / b;
    }
    
    // 메서드 오버로딩
    public int add(int a, int b, int c) {
        return a + b + c;
    }
    
    public double add(double a, double b) {
        return a + b;
    }
    
    // static 메서드 (클래스 메서드)
    public static int multiplyStatic(int a, int b) {
        return a * b;
    }
    
    // 재귀 메서드
    public int factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }
    
    // void 메서드 (반환값 없음)
    public void printResult(int result) {
        System.out.println("결과: " + result);
    }
    
    // 매개변수가 없는 메서드
    public String getGreeting() {
        return "안녕하세요!";
    }
}

public class Methods {
    public static void main(String[] args) {
        // ========== 메서드 호출 ==========
        
        System.out.println("=== 메서드 호출 ===");
        Calculator calc = new Calculator();
        
        int sum = calc.add(10, 20);
        System.out.println("10 + 20 = " + sum);
        
        int diff = calc.subtract(30, 15);
        System.out.println("30 - 15 = " + diff);
        
        int product = calc.multiply(5, 6);
        System.out.println("5 * 6 = " + product);
        
        double quotient = calc.divide(10, 3);
        System.out.println("10 / 3 = " + quotient);
        
        // ========== 메서드 오버로딩 ==========
        
        System.out.println("\n=== 메서드 오버로딩 ===");
        
        // 같은 이름, 다른 매개변수 개수
        int sum1 = calc.add(10, 20);
        int sum2 = calc.add(10, 20, 30);
        System.out.println("add(10, 20) = " + sum1);
        System.out.println("add(10, 20, 30) = " + sum2);
        
        // 같은 이름, 다른 매개변수 타입
        double sum3 = calc.add(10.5, 20.3);
        System.out.println("add(10.5, 20.3) = " + sum3);
        
        // ========== static 메서드 ==========
        
        System.out.println("\n=== static 메서드 ===");
        
        // 객체 없이 호출 가능
        int result = Calculator.multiplyStatic(5, 6);
        System.out.println("multiplyStatic(5, 6) = " + result);
        
        // 객체를 통해서도 호출 가능 (권장하지 않음)
        int result2 = calc.multiplyStatic(3, 4);
        System.out.println("multiplyStatic(3, 4) = " + result2);
        
        // ========== void 메서드 ==========
        
        System.out.println("\n=== void 메서드 ===");
        calc.printResult(100);
        
        // ========== 매개변수가 없는 메서드 ==========
        
        System.out.println("\n=== 매개변수가 없는 메서드 ===");
        String greeting = calc.getGreeting();
        System.out.println(greeting);
        
        // ========== 재귀 메서드 ==========
        
        System.out.println("\n=== 재귀 메서드 ===");
        int fact = calc.factorial(5);
        System.out.println("5! = " + fact);
        
        // ========== 메서드 체이닝 (불가능한 예) ==========
        
        System.out.println("\n=== 메서드 활용 ===");
        
        // 여러 메서드 연속 호출
        int a = 10, b = 5;
        int result3 = calc.add(a, b);
        int result4 = calc.multiply(result3, 2);
        calc.printResult(result4);
        
        // ========== 실용 예제 ==========
        
        System.out.println("\n=== 실용 예제 ===");
        
        // 최대값 찾기
        int max = findMax(10, 20, 15);
        System.out.println("최대값: " + max);
        
        // 짝수 판별
        boolean isEven = isEven(10);
        System.out.println("10은 짝수인가? " + isEven);
        
        // 문자열 반복
        String repeated = repeatString("Hello", 3);
        System.out.println("반복된 문자열: " + repeated);
    }
    
    // 클래스 메서드 (static)
    public static int findMax(int a, int b, int c) {
        int max = a;
        if (b > max) max = b;
        if (c > max) max = c;
        return max;
    }
    
    public static boolean isEven(int num) {
        return num % 2 == 0;
    }
    
    public static String repeatString(String str, int count) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < count; i++) {
            sb.append(str);
        }
        return sb.toString();
    }
}

/*
 * Java 메서드 핵심 정리
 * 
 * 1. 메서드 정의
 *    접근제어자 반환타입 메서드명(매개변수) {
 *        // 코드
 *        return 값;
 *    }
 * 
 * 2. 메서드 종류
 *    - 인스턴스 메서드: 객체를 통해서 호출
 *    - static 메서드: 클래스를 통해서 호출 (객체 없이도 가능)
 * 
 * 3. 메서드 오버로딩
 *    - 같은 이름의 메서드를 여러 개 정의
 *    - 매개변수의 개수나 타입이 달라야 함
 *    - 반환 타입만 다르면 오버로딩 불가
 * 
 * 4. 매개변수 전달
 *    - 기본형: 값 전달 (복사)
 *    - 참조형: 참조 전달 (주소)
 * 
 * 5. 재귀 메서드
 *    - 메서드가 자기 자신을 호출
 *    - 종료 조건 필요
 *    - 스택 오버플로우 주의
 * 
 * 6. void 메서드
 *    - 반환값이 없는 메서드
 *    - return; 만 사용하거나 생략 가능
 * 
 * 7. static 메서드
 *    - 클래스 메서드
 *    - 인스턴스 변수 접근 불가
 *    - 객체 없이 호출 가능
 */

