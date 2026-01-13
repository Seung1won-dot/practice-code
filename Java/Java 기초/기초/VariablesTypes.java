/*
 * 02_variables_types.java
 * 
 * Java 변수와 자료형
 * - 기본 자료형 (Primitive Types)
 * - 참조 자료형 (Reference Types)
 * - 변수 선언과 초기화
 * - 타입 변환
 */

public class VariablesTypes {
    public static void main(String[] args) {
        // ========== 정수형 자료형 ==========
        
        byte byteVar = 127;           // 1 byte, -128 ~ 127
        short shortVar = 32767;       // 2 bytes, -32,768 ~ 32,767
        int intVar = 2147483647;      // 4 bytes, -2^31 ~ 2^31-1
        long longVar = 9223372036854775807L; // 8 bytes, L 접미사 필요
        
        System.out.println("정수형:");
        System.out.println("byte: " + byteVar);
        System.out.println("short: " + shortVar);
        System.out.println("int: " + intVar);
        System.out.println("long: " + longVar);
        
        // ========== 실수형 자료형 ==========
        
        float floatVar = 3.14159f;    // 4 bytes, f 접미사 필요
        double doubleVar = 2.71828;   // 8 bytes, 기본 실수형
        
        System.out.println("\n실수형:");
        System.out.println("float: " + floatVar);
        System.out.println("double: " + doubleVar);
        System.out.printf("float: %.5f\n", floatVar);
        System.out.printf("double: %.5f\n", doubleVar);
        
        // ========== 문자형 자료형 ==========
        
        char charVar = 'A';           // 2 bytes, 유니코드 문자
        char unicodeChar = '\u0041';  // 유니코드로 'A' 표현
        char koreanChar = '가';
        
        System.out.println("\n문자형:");
        System.out.println("char: " + charVar);
        System.out.println("unicode: " + unicodeChar);
        System.out.println("한글: " + koreanChar);
        System.out.println("char의 정수값: " + (int)charVar);
        
        // ========== 불리언 자료형 ==========
        
        boolean boolTrue = true;      // 1 bit (JVM 구현에 따라 다름)
        boolean boolFalse = false;
        
        System.out.println("\n불리언:");
        System.out.println("true: " + boolTrue);
        System.out.println("false: " + boolFalse);
        
        // ========== 참조 자료형 (문자열) ==========
        
        String str1 = "Hello";       // 문자열 리터럴
        String str2 = new String("World"); // String 객체 생성
        String str3 = "안녕하세요";
        
        System.out.println("\n문자열:");
        System.out.println("str1: " + str1);
        System.out.println("str2: " + str2);
        System.out.println("str3: " + str3);
        System.out.println("문자열 연결: " + str1 + " " + str2);
        
        // ========== 변수 선언 방법 ==========
        
        // 방법 1: 선언과 동시에 초기화
        int num1 = 10;
        
        // 방법 2: 선언 후 나중에 초기화
        int num2;
        num2 = 20;
        
        // 방법 3: 여러 변수 동시 선언
        int a = 1, b = 2, c = 3;
        
        System.out.println("\n변수 선언:");
        System.out.println("num1: " + num1 + ", num2: " + num2);
        System.out.println("a: " + a + ", b: " + b + ", c: " + c);
        
        // ========== 상수 (final) ==========
        
        final int MAX_SIZE = 100;     // 상수는 final 키워드 사용
        final double PI = 3.14159;
        // MAX_SIZE = 200; // 오류! 상수는 재할당 불가
        
        System.out.println("\n상수:");
        System.out.println("MAX_SIZE: " + MAX_SIZE);
        System.out.println("PI: " + PI);
        
        // ========== 타입 변환 (Type Casting) ==========
        
        // 자동 타입 변환 (묵시적 변환)
        int intNum = 100;
        long longNum = intNum;        // int → long 자동 변환
        double doubleNum = intNum;   // int → double 자동 변환
        
        System.out.println("\n자동 타입 변환:");
        System.out.println("int: " + intNum + " → long: " + longNum);
        System.out.println("int: " + intNum + " → double: " + doubleNum);
        
        // 강제 타입 변환 (명시적 변환)
        double d = 3.14;
        int i = (int)d;               // double → int 강제 변환 (소수점 손실)
        
        System.out.println("\n강제 타입 변환:");
        System.out.println("double: " + d + " → int: " + i);
        
        // 문자와 숫자 변환
        char ch = 'A';
        int charToInt = ch;           // char → int (ASCII/Unicode 값)
        char intToChar = (char)65;    // int → char
        
        System.out.println("\n문자-숫자 변환:");
        System.out.println("char 'A': " + ch + " → int: " + charToInt);
        System.out.println("int 65: " + 65 + " → char: " + intToChar);
        
        // ========== 문자열과 숫자 변환 ==========
        
        // 문자열 → 숫자
        String strNum = "123";
        int parsedInt = Integer.parseInt(strNum);
        double parsedDouble = Double.parseDouble("3.14");
        
        System.out.println("\n문자열 → 숫자:");
        System.out.println("문자열 \"" + strNum + "\" → int: " + parsedInt);
        System.out.println("문자열 \"3.14\" → double: " + parsedDouble);
        
        // 숫자 → 문자열
        int number = 456;
        String intToString = String.valueOf(number);
        String intToString2 = number + "";  // 빈 문자열과 연결
        
        System.out.println("\n숫자 → 문자열:");
        System.out.println("int " + number + " → 문자열: \"" + intToString + "\"");
        System.out.println("int " + number + " → 문자열: \"" + intToString2 + "\"");
        
        // ========== 자료형 크기 확인 ==========
        
        System.out.println("\n자료형 크기:");
        System.out.println("byte: " + Byte.BYTES + " bytes");
        System.out.println("short: " + Short.BYTES + " bytes");
        System.out.println("int: " + Integer.BYTES + " bytes");
        System.out.println("long: " + Long.BYTES + " bytes");
        System.out.println("float: " + Float.BYTES + " bytes");
        System.out.println("double: " + Double.BYTES + " bytes");
        System.out.println("char: " + Character.BYTES + " bytes");
        
        // ========== 자료형 범위 확인 ==========
        
        System.out.println("\n자료형 범위:");
        System.out.println("byte: " + Byte.MIN_VALUE + " ~ " + Byte.MAX_VALUE);
        System.out.println("short: " + Short.MIN_VALUE + " ~ " + Short.MAX_VALUE);
        System.out.println("int: " + Integer.MIN_VALUE + " ~ " + Integer.MAX_VALUE);
        System.out.println("long: " + Long.MIN_VALUE + " ~ " + Long.MAX_VALUE);
    }
}

/*
 * Java 자료형 핵심 정리
 * 
 * 1. 기본 자료형 (Primitive Types)
 *    - 정수형: byte, short, int, long
 *    - 실수형: float, double
 *    - 문자형: char
 *    - 불리언: boolean
 * 
 * 2. 참조 자료형 (Reference Types)
 *    - String: 문자열
 *    - 배열: int[], String[] 등
 *    - 클래스: 사용자 정의 클래스
 *    - 인터페이스
 * 
 * 3. 변수 선언
 *    자료형 변수명 = 값;
 *    final 자료형 상수명 = 값;  // 상수
 * 
 * 4. 타입 변환
 *    - 자동 변환: 작은 타입 → 큰 타입 (byte → int → long → float → double)
 *    - 강제 변환: (타입)값 형태로 명시적 변환
 * 
 * 5. 문자열 변환
 *    - 문자열 → 숫자: Integer.parseInt(), Double.parseDouble()
 *    - 숫자 → 문자열: String.valueOf(), "" + 숫자
 * 
 * 6. 리터럴 접미사
 *    - long: L (예: 100L)
 *    - float: f (예: 3.14f)
 *    - double: d (생략 가능, 예: 3.14 또는 3.14d)
 */

