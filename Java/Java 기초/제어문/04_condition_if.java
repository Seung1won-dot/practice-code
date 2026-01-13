/*
 * 04_condition_if.java
 * 
 * Java 조건문
 * - if 문
 * - if-else 문
 * - if-else if-else 문
 * - switch 문
 * - 중첩 조건문
 */

public class ConditionIf {
    public static void main(String[] args) {
        // ========== if 문 ==========
        
        System.out.println("=== if 문 ===");
        int age = 20;
        
        if (age >= 18) {
            System.out.println("성인입니다.");
        }
        
        int score = 85;
        if (score >= 60) {
            System.out.println("합격입니다!");
        }
        
        // ========== if-else 문 ==========
        
        System.out.println("\n=== if-else 문 ===");
        score = 50;
        
        if (score >= 60) {
            System.out.println("합격입니다!");
        } else {
            System.out.println("불합격입니다.");
        }
        
        // ========== if-else if-else 문 ==========
        
        System.out.println("\n=== if-else if-else 문 ===");
        int grade = 92;
        
        if (grade >= 90) {
            System.out.println("등급: A");
        } else if (grade >= 80) {
            System.out.println("등급: B");
        } else if (grade >= 70) {
            System.out.println("등급: C");
        } else if (grade >= 60) {
            System.out.println("등급: D");
        } else {
            System.out.println("등급: F");
        }
        
        // ========== 중첩 조건문 ==========
        
        System.out.println("\n=== 중첩 조건문 ===");
        int num = 5;
        
        if (num > 0) {
            if (num % 2 == 0) {
                System.out.println("양수이면서 짝수");
            } else {
                System.out.println("양수이면서 홀수");
            }
        } else {
            System.out.println("0 이하의 수");
        }
        
        // ========== 논리 연산자를 이용한 조건 ==========
        
        System.out.println("\n=== 논리 연산자 활용 ===");
        int a = 10, b = 20;
        
        if (a > 0 && b > 0) {
            System.out.println("둘 다 양수");
        }
        
        if (a > 0 || b < 0) {
            System.out.println("적어도 하나는 양수");
        }
        
        if (!(a < 0)) {
            System.out.println("a는 음수가 아님");
        }
        
        // ========== switch 문 (전통적 방식) ==========
        
        System.out.println("\n=== switch 문 (전통적) ===");
        int day = 3;
        
        switch (day) {
            case 1:
                System.out.println("월요일");
                break;
            case 2:
                System.out.println("화요일");
                break;
            case 3:
                System.out.println("수요일");
                break;
            case 4:
                System.out.println("목요일");
                break;
            case 5:
                System.out.println("금요일");
                break;
            default:
                System.out.println("주말");
        }
        
        // ========== switch 문 (계산기 예제) ==========
        
        System.out.println("\n=== switch 문 (계산기) ===");
        char op = '+';
        int x = 10, y = 5, result = 0;
        
        switch (op) {
            case '+':
                result = x + y;
                break;
            case '-':
                result = x - y;
                break;
            case '*':
                result = x * y;
                break;
            case '/':
                result = x / y;
                break;
            default:
                result = 0;
                System.out.println("지원하지 않는 연산자");
        }
        System.out.println(x + " " + op + " " + y + " = " + result);
        
        // ========== switch 문 (fall-through) ==========
        
        System.out.println("\n=== switch 문 (fall-through) ===");
        int month = 2;
        
        switch (month) {
            case 12:
            case 1:
            case 2:
                System.out.println("겨울");
                break;
            case 3:
            case 4:
            case 5:
                System.out.println("봄");
                break;
            case 6:
            case 7:
            case 8:
                System.out.println("여름");
                break;
            case 9:
            case 10:
            case 11:
                System.out.println("가을");
                break;
            default:
                System.out.println("잘못된 월");
        }
        
        // ========== switch 표현식 (Java 14+) ==========
        
        System.out.println("\n=== switch 표현식 (Java 14+) ===");
        String season = switch (month) {
            case 12, 1, 2 -> "겨울";
            case 3, 4, 5 -> "봄";
            case 6, 7, 8 -> "여름";
            case 9, 10, 11 -> "가을";
            default -> "잘못된 월";
        };
        System.out.println("계절: " + season);
        
        // ========== 문자열 switch 문 ==========
        
        System.out.println("\n=== 문자열 switch 문 ===");
        String language = "Java";
        
        switch (language) {
            case "Java":
                System.out.println("객체지향 프로그래밍 언어");
                break;
            case "Python":
                System.out.println("인터프리터 언어");
                break;
            case "C++":
                System.out.println("컴파일 언어");
                break;
            default:
                System.out.println("알 수 없는 언어");
        }
        
        // ========== 삼항 연산자 ==========
        
        System.out.println("\n=== 삼항 연산자 ===");
        int value = 10;
        String message = (value > 0) ? "양수" : "0 또는 음수";
        System.out.println("value: " + value + " → " + message);
        
        // 중첩 삼항 연산자
        int number = 5;
        String result2 = (number > 0) ? "양수" : (number < 0) ? "음수" : "영";
        System.out.println("number: " + number + " → " + result2);
    }
}

/*
 * Java 조건문 핵심 정리
 * 
 * 1. if 문
 *    if (조건) {
 *        // 조건이 true일 때 실행
 *    }
 * 
 * 2. if-else 문
 *    if (조건) {
 *        // 조건이 true일 때
 *    } else {
 *        // 조건이 false일 때
 *    }
 * 
 * 3. if-else if-else 문
 *    if (조건1) {
 *        // 조건1이 true일 때
 *    } else if (조건2) {
 *        // 조건2가 true일 때
 *    } else {
 *        // 모든 조건이 false일 때
 *    }
 * 
 * 4. switch 문
 *    switch (변수) {
 *        case 값1:
 *            // 실행 코드
 *            break;
 *        case 값2:
 *            // 실행 코드
 *            break;
 *        default:
 *            // 기본 실행 코드
 *    }
 * 
 * 5. switch 표현식 (Java 14+)
 *    String result = switch (변수) {
 *        case 값1 -> "결과1";
 *        case 값2 -> "결과2";
 *        default -> "기본값";
 *    };
 * 
 * 6. 삼항 연산자
 *    변수 = (조건) ? 값1 : 값2;
 * 
 * 7. 주의사항
 *    - switch에서 break를 빼면 fall-through 발생
 *    - switch는 정수, 문자, 문자열, enum만 사용 가능
 *    - 문자열 비교는 == 대신 equals() 사용 권장
 */

