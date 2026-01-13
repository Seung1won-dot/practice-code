/*
 * 03_operators.java
 * 
 * Java 연산자
 * - 산술 연산자
 * - 비교 연산자
 * - 논리 연산자
 * - 대입 연산자
 * - 증감 연산자
 * - 삼항 연산자
 */

public class Operators {
    public static void main(String[] args) {
        // ========== 산술 연산자 ==========
        
        int a = 10, b = 3;
        
        System.out.println("=== 산술 연산자 ===");
        System.out.println("a = " + a + ", b = " + b);
        System.out.println("a + b = " + (a + b));  // 덧셈: 13
        System.out.println("a - b = " + (a - b));  // 뺄셈: 7
        System.out.println("a * b = " + (a * b));  // 곱셈: 30
        System.out.println("a / b = " + (a / b));  // 나눗셈: 3 (정수 나눗셈)
        System.out.println("a % b = " + (a % b));  // 나머지: 1
        
        // 실수 나눗셈
        double x = 10.0, y = 3.0;
        System.out.println("x / y = " + (x / y));  // 3.333...
        
        // ========== 증감 연산자 ==========
        
        System.out.println("\n=== 증감 연산자 ===");
        int num = 5;
        
        System.out.println("초기값: " + num);
        System.out.println("num++: " + (num++));  // 후위 증가: 5 (출력 후 증가)
        System.out.println("현재값: " + num);      // 6
        
        num = 5;
        System.out.println("초기값: " + num);
        System.out.println("++num: " + (++num));  // 전위 증가: 6 (증가 후 출력)
        System.out.println("현재값: " + num);      // 6
        
        num = 5;
        System.out.println("초기값: " + num);
        System.out.println("num--: " + (num--));  // 후위 감소: 5
        System.out.println("현재값: " + num);      // 4
        
        num = 5;
        System.out.println("초기값: " + num);
        System.out.println("--num: " + (--num));  // 전위 감소: 4
        System.out.println("현재값: " + num);      // 4
        
        // ========== 비교 연산자 ==========
        
        System.out.println("\n=== 비교 연산자 ===");
        int p = 10, q = 20;
        
        System.out.println("p = " + p + ", q = " + q);
        System.out.println("p == q: " + (p == q));  // 같음: false
        System.out.println("p != q: " + (p != q));  // 다름: true
        System.out.println("p < q: " + (p < q));    // 작음: true
        System.out.println("p > q: " + (p > q));    // 큼: false
        System.out.println("p <= q: " + (p <= q));  // 작거나 같음: true
        System.out.println("p >= q: " + (p >= q));  // 크거나 같음: false
        
        // 문자열 비교 (주의!)
        String str1 = "Hello";
        String str2 = "Hello";
        String str3 = new String("Hello");
        
        System.out.println("\n문자열 비교:");
        System.out.println("str1 == str2: " + (str1 == str2));        // true (리터럴은 같은 참조)
        System.out.println("str1 == str3: " + (str1 == str3));        // false (다른 객체)
        System.out.println("str1.equals(str3): " + str1.equals(str3)); // true (내용 비교)
        
        // ========== 논리 연산자 ==========
        
        System.out.println("\n=== 논리 연산자 ===");
        boolean bool1 = true, bool2 = false;
        
        System.out.println("bool1 = " + bool1 + ", bool2 = " + bool2);
        System.out.println("bool1 && bool2: " + (bool1 && bool2));  // AND: false
        System.out.println("bool1 || bool2: " + (bool1 || bool2));   // OR: true
        System.out.println("!bool1: " + (!bool1));                  // NOT: false
        System.out.println("!bool2: " + (!bool2));                  // NOT: true
        
        // 단락 평가 (Short-circuit evaluation)
        int value = 5;
        if (value > 0 && value < 10) {
            System.out.println("value는 0과 10 사이입니다.");
        }
        
        // &&는 첫 번째가 false면 두 번째 평가 안 함
        if (value < 0 && (value = 10) > 0) {
            // 실행 안 됨
        }
        System.out.println("value: " + value);  // 여전히 5
        
        // ||는 첫 번째가 true면 두 번째 평가 안 함
        if (value > 0 || (value = 20) > 0) {
            // 실행됨
        }
        System.out.println("value: " + value);  // 여전히 5
        
        // ========== 대입 연산자 ==========
        
        System.out.println("\n=== 대입 연산자 ===");
        int result = 10;
        
        System.out.println("초기값: " + result);
        result += 5;  // result = result + 5
        System.out.println("result += 5: " + result);  // 15
        
        result -= 3;  // result = result - 3
        System.out.println("result -= 3: " + result);   // 12
        
        result *= 2;  // result = result * 2
        System.out.println("result *= 2: " + result);   // 24
        
        result /= 4;  // result = result / 4
        System.out.println("result /= 4: " + result);   // 6
        
        result %= 4;  // result = result % 4
        System.out.println("result %= 4: " + result);   // 2
        
        // ========== 삼항 연산자 ==========
        
        System.out.println("\n=== 삼항 연산자 ===");
        int score = 85;
        
        String grade = (score >= 90) ? "A" : (score >= 80) ? "B" : "C";
        System.out.println("점수: " + score + ", 등급: " + grade);
        
        int max = (a > b) ? a : b;
        System.out.println("a와 b 중 큰 값: " + max);
        
        // ========== 비트 연산자 ==========
        
        System.out.println("\n=== 비트 연산자 ===");
        int bit1 = 5;   // 0101 (이진수)
        int bit2 = 3;   // 0011 (이진수)
        
        System.out.println("bit1 = " + bit1 + " (이진수: " + Integer.toBinaryString(bit1) + ")");
        System.out.println("bit2 = " + bit2 + " (이진수: " + Integer.toBinaryString(bit2) + ")");
        System.out.println("bit1 & bit2: " + (bit1 & bit2));  // AND: 1 (0001)
        System.out.println("bit1 | bit2: " + (bit1 | bit2));  // OR: 7 (0111)
        System.out.println("bit1 ^ bit2: " + (bit1 ^ bit2));  // XOR: 6 (0110)
        System.out.println("~bit1: " + (~bit1));              // NOT: -6
        System.out.println("bit1 << 1: " + (bit1 << 1));      // 왼쪽 시프트: 10
        System.out.println("bit1 >> 1: " + (bit1 >> 1));      // 오른쪽 시프트: 2
        
        // ========== 연산자 우선순위 ==========
        
        System.out.println("\n=== 연산자 우선순위 ===");
        int calc = 2 + 3 * 4;  // 곱셈이 먼저: 14
        System.out.println("2 + 3 * 4 = " + calc);
        
        calc = (2 + 3) * 4;     // 괄호가 먼저: 20
        System.out.println("(2 + 3) * 4 = " + calc);
        
        boolean logic = true || false && false;  // &&가 먼저: true
        System.out.println("true || false && false = " + logic);
        
        logic = (true || false) && false;        // 괄호가 먼저: false
        System.out.println("(true || false) && false = " + logic);
    }
}

/*
 * Java 연산자 핵심 정리
 * 
 * 1. 산술 연산자
 *    + : 덧셈
 *    - : 뺄셈
 *    * : 곱셈
 *    / : 나눗셈
 *    % : 나머지
 * 
 * 2. 증감 연산자
 *    ++ : 증가 (전위/후위)
 *    -- : 감소 (전위/후위)
 * 
 * 3. 비교 연산자
 *    == : 같음
 *    != : 다름
 *    <, >, <=, >= : 대소 비교
 * 
 * 4. 논리 연산자
 *    && : AND (단락 평가)
 *    || : OR (단락 평가)
 *    !  : NOT
 * 
 * 5. 대입 연산자
 *    =, +=, -=, *=, /=, %=
 * 
 * 6. 삼항 연산자
 *    조건 ? 값1 : 값2
 * 
 * 7. 비트 연산자
 *    &, |, ^, ~, <<, >>
 * 
 * 8. 연산자 우선순위
 *    1. 괄호 ()
 *    2. 단항 연산자 (++, --, !, ~)
 *    3. 산술 연산자 (*, /, %, +, -)
 *    4. 비교 연산자 (<, >, <=, >=, ==, !=)
 *    5. 논리 연산자 (&&, ||)
 *    6. 대입 연산자 (=, +=, -= 등)
 * 
 * 9. 문자열 비교
 *    == : 참조 비교 (같은 객체인지)
 *    equals() : 내용 비교 (문자열 내용이 같은지)
 */

