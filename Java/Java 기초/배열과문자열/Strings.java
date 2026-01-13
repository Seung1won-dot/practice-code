/*
 * 07_strings.java
 * 
 * Java 문자열 (String)
 * - String 클래스
 * - 문자열 생성 방법
 * - 문자열 메서드
 * - StringBuilder와 StringBuffer
 */

public class Strings {
    public static void main(String[] args) {
        // ========== 문자열 생성 ==========
        
        System.out.println("=== 문자열 생성 ===");
        
        // 방법 1: 문자열 리터럴
        String str1 = "Hello";
        String str2 = "Hello";  // 같은 리터럴은 같은 객체 참조
        
        // 방법 2: new 연산자
        String str3 = new String("Hello");
        String str4 = new String("Hello");  // 새로운 객체 생성
        
        System.out.println("str1 == str2: " + (str1 == str2));  // true (같은 참조)
        System.out.println("str3 == str4: " + (str3 == str4));  // false (다른 객체)
        System.out.println("str1.equals(str3): " + str1.equals(str3));  // true (내용 같음)
        
        // ========== 문자열 길이 ==========
        
        System.out.println("\n=== 문자열 길이 ===");
        String text = "안녕하세요";
        System.out.println("문자열: " + text);
        System.out.println("길이: " + text.length());
        
        // ========== 문자열 연결 ==========
        
        System.out.println("\n=== 문자열 연결 ===");
        String firstName = "홍";
        String lastName = "길동";
        
        // + 연산자 사용
        String fullName = firstName + lastName;
        System.out.println("이름: " + fullName);
        
        // concat() 메서드 사용
        String name = firstName.concat(lastName);
        System.out.println("이름: " + name);
        
        // ========== 문자열 비교 ==========
        
        System.out.println("\n=== 문자열 비교 ===");
        String s1 = "Java";
        String s2 = "Java";
        String s3 = new String("Java");
        
        // == 연산자: 참조 비교
        System.out.println("s1 == s2: " + (s1 == s2));  // true
        System.out.println("s1 == s3: " + (s1 == s3));  // false
        
        // equals(): 내용 비교
        System.out.println("s1.equals(s2): " + s1.equals(s2));  // true
        System.out.println("s1.equals(s3): " + s1.equals(s3));  // true
        
        // equalsIgnoreCase(): 대소문자 무시 비교
        String s4 = "JAVA";
        System.out.println("s1.equals(s4): " + s1.equals(s4));  // false
        System.out.println("s1.equalsIgnoreCase(s4): " + s1.equalsIgnoreCase(s4));  // true
        
        // compareTo(): 사전식 비교
        System.out.println("\"apple\".compareTo(\"banana\"): " + "apple".compareTo("banana"));  // 음수
        System.out.println("\"banana\".compareTo(\"apple\"): " + "banana".compareTo("apple"));  // 양수
        System.out.println("\"apple\".compareTo(\"apple\"): " + "apple".compareTo("apple"));  // 0
        
        // ========== 문자열 검색 ==========
        
        System.out.println("\n=== 문자열 검색 ===");
        String text2 = "Hello, World!";
        
        // indexOf(): 첫 번째 위치 찾기
        System.out.println("'o'의 첫 번째 위치: " + text2.indexOf('o'));
        System.out.println("\"World\"의 위치: " + text2.indexOf("World"));
        
        // lastIndexOf(): 마지막 위치 찾기
        System.out.println("'o'의 마지막 위치: " + text2.lastIndexOf('o'));
        
        // contains(): 포함 여부 확인
        System.out.println("\"World\" 포함 여부: " + text2.contains("World"));
        System.out.println("\"Java\" 포함 여부: " + text2.contains("Java"));
        
        // startsWith(), endsWith()
        System.out.println("\"Hello\"로 시작: " + text2.startsWith("Hello"));
        System.out.println("\"!\"로 끝남: " + text2.endsWith("!"));
        
        // ========== 문자열 추출 ==========
        
        System.out.println("\n=== 문자열 추출 ===");
        String text3 = "Hello, World!";
        
        // charAt(): 특정 위치의 문자
        System.out.println("인덱스 0의 문자: " + text3.charAt(0));
        System.out.println("인덱스 7의 문자: " + text3.charAt(7));
        
        // substring(): 부분 문자열 추출
        System.out.println("0~5: " + text3.substring(0, 5));  // "Hello"
        System.out.println("7부터 끝까지: " + text3.substring(7));  // "World!"
        
        // ========== 문자열 변환 ==========
        
        System.out.println("\n=== 문자열 변환 ===");
        String text4 = "Hello, World!";
        
        // toUpperCase(): 대문자로
        System.out.println("대문자: " + text4.toUpperCase());
        
        // toLowerCase(): 소문자로
        System.out.println("소문자: " + text4.toLowerCase());
        
        // trim(): 앞뒤 공백 제거
        String text5 = "  Hello, World!  ";
        System.out.println("원본: \"" + text5 + "\"");
        System.out.println("trim: \"" + text5.trim() + "\"");
        
        // replace(): 문자/문자열 치환
        String text6 = "Hello, World!";
        System.out.println("replace: " + text6.replace("World", "Java"));
        System.out.println("replace: " + text6.replace('o', 'O'));
        
        // ========== 문자열 분할 ==========
        
        System.out.println("\n=== 문자열 분할 ===");
        String text7 = "apple,banana,orange";
        String[] fruits = text7.split(",");
        
        System.out.println("분할 결과:");
        for (String fruit : fruits) {
            System.out.println("- " + fruit);
        }
        
        // 여러 구분자 사용
        String text8 = "apple,banana;orange:grape";
        String[] fruits2 = text8.split("[,;:]");
        for (String fruit : fruits2) {
            System.out.println("- " + fruit);
        }
        
        // ========== 문자열 포맷팅 ==========
        
        System.out.println("\n=== 문자열 포맷팅 ===");
        String name2 = "홍길동";
        int age = 25;
        double height = 175.5;
        
        // String.format()
        String info = String.format("이름: %s, 나이: %d, 키: %.1f", name2, age, height);
        System.out.println(info);
        
        // printf() 스타일
        System.out.printf("이름: %s, 나이: %d, 키: %.1f\n", name2, age, height);
        
        // ========== StringBuilder ==========
        
        System.out.println("\n=== StringBuilder ===");
        // 문자열을 여러 번 수정할 때 효율적
        
        StringBuilder sb = new StringBuilder();
        sb.append("Hello");
        sb.append(", ");
        sb.append("World");
        sb.append("!");
        
        String result = sb.toString();
        System.out.println("결과: " + result);
        
        // 메서드 체이닝
        StringBuilder sb2 = new StringBuilder();
        String result2 = sb2.append("Java")
                            .append(" ")
                            .append("Programming")
                            .toString();
        System.out.println("결과: " + result2);
        
        // insert(), delete(), reverse()
        StringBuilder sb3 = new StringBuilder("Hello");
        sb3.insert(5, ", World");
        System.out.println("insert: " + sb3);
        
        sb3.delete(5, 12);
        System.out.println("delete: " + sb3);
        
        sb3.reverse();
        System.out.println("reverse: " + sb3);
        
        // ========== StringBuffer ==========
        
        System.out.println("\n=== StringBuffer ===");
        // StringBuilder와 유사하지만 스레드 안전 (동기화됨)
        // 단일 스레드에서는 StringBuilder가 더 빠름
        
        StringBuffer sbf = new StringBuffer();
        sbf.append("Thread-safe");
        sbf.append(" string");
        sbf.append(" builder");
        
        System.out.println("결과: " + sbf.toString());
        
        // ========== 문자열과 숫자 변환 ==========
        
        System.out.println("\n=== 문자열과 숫자 변환 ===");
        
        // 문자열 → 숫자
        String numStr = "123";
        int num = Integer.parseInt(numStr);
        System.out.println("문자열 \"" + numStr + "\" → int: " + num);
        
        String doubleStr = "3.14";
        double d = Double.parseDouble(doubleStr);
        System.out.println("문자열 \"" + doubleStr + "\" → double: " + d);
        
        // 숫자 → 문자열
        int number = 456;
        String str = String.valueOf(number);
        System.out.println("int " + number + " → 문자열: \"" + str + "\"");
        
        String str2 = number + "";  // 빈 문자열과 연결
        System.out.println("int " + number + " → 문자열: \"" + str2 + "\"");
        
        // ========== 실용 예제 ==========
        
        System.out.println("\n=== 실용 예제 ===");
        
        // 이메일 검증
        String email = "user@example.com";
        boolean isValid = email.contains("@") && email.contains(".");
        System.out.println("이메일 유효성: " + isValid);
        
        // 파일 확장자 추출
        String filename = "document.pdf";
        String extension = filename.substring(filename.lastIndexOf('.') + 1);
        System.out.println("파일 확장자: " + extension);
        
        // 단어 개수 세기
        String sentence = "Hello World Java Programming";
        String[] words = sentence.split(" ");
        System.out.println("단어 개수: " + words.length);
    }
}

/*
 * Java 문자열 핵심 정리
 * 
 * 1. 문자열 생성
 *    String str = "리터럴";  // 문자열 풀 사용
 *    String str = new String("문자열");  // 새 객체 생성
 * 
 * 2. 문자열 비교
 *    == : 참조 비교
 *    equals() : 내용 비교 (권장)
 *    equalsIgnoreCase() : 대소문자 무시 비교
 * 
 * 3. 주요 메서드
 *    - length(): 길이
 *    - charAt(): 특정 위치 문자
 *    - substring(): 부분 문자열
 *    - indexOf(), lastIndexOf(): 검색
 *    - contains(), startsWith(), endsWith(): 포함 여부
 *    - toUpperCase(), toLowerCase(): 대소문자 변환
 *    - trim(): 공백 제거
 *    - replace(): 치환
 *    - split(): 분할
 * 
 * 4. StringBuilder
 *    - 가변 문자열
 *    - append(), insert(), delete(), reverse()
 *    - 단일 스레드에서 사용 (빠름)
 * 
 * 5. StringBuffer
 *    - StringBuilder와 유사
 *    - 스레드 안전 (동기화됨)
 *    - 멀티 스레드에서 사용
 * 
 * 6. 문자열과 숫자 변환
 *    - 문자열 → 숫자: Integer.parseInt(), Double.parseDouble()
 *    - 숫자 → 문자열: String.valueOf(), "" + 숫자
 * 
 * 7. 주의사항
 *    - String은 불변(immutable) 객체
 *    - 문자열 수정 시 새 객체 생성
 *    - 많은 수정이 필요하면 StringBuilder 사용
 */

