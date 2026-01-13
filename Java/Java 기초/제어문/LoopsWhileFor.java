/*
 * 05_loops_while_for.java
 * 
 * Java 반복문
 * - while 문
 * - do-while 문
 * - for 문
 * - 향상된 for 문 (for-each)
 * - 중첩 반복문
 * - break와 continue
 */

public class LoopsWhileFor {
    public static void main(String[] args) {
        // ========== while 문 ==========
        
        System.out.println("=== while 문 ===");
        int count = 0;
        while (count < 5) {
            System.out.println("카운트: " + count);
            count++;
        }
        
        // ========== do-while 문 ==========
        
        System.out.println("\n=== do-while 문 ===");
        int num = 0;
        do {
            System.out.println("num: " + num);
            num++;
        } while (num < 3);
        
        // do-while은 최소 한 번은 실행됨
        num = 10;
        do {
            System.out.println("num: " + num);
            num++;
        } while (num < 3);  // 조건이 false지만 한 번 실행됨
        
        // ========== for 문 ==========
        
        System.out.println("\n=== for 문 ===");
        for (int i = 0; i < 5; i++) {
            System.out.println("i = " + i);
        }
        
        // for 문의 다양한 형태
        System.out.println("\n=== for 문 (다양한 형태) ===");
        
        // 초기값 생략 (이미 선언된 변수 사용)
        int j = 0;
        for (; j < 3; j++) {
            System.out.println("j = " + j);
        }
        
        // 증감식 생략
        for (int k = 0; k < 3; ) {
            System.out.println("k = " + k);
            k++;
        }
        
        // 모든 요소 생략 (무한 루프)
        // for (;;) { ... }
        
        // ========== 중첩 반복문 ==========
        
        System.out.println("\n=== 중첩 반복문 ===");
        for (int i = 1; i <= 3; i++) {
            for (int k = 1; k <= 3; k++) {
                System.out.println(i + " x " + k + " = " + (i * k));
            }
        }
        
        // 별 찍기 예제
        System.out.println("\n=== 별 찍기 ===");
        for (int i = 1; i <= 5; i++) {
            for (int k = 1; k <= i; k++) {
                System.out.print("*");
            }
            System.out.println();
        }
        
        // ========== 향상된 for 문 (for-each) ==========
        
        System.out.println("\n=== 향상된 for 문 (for-each) ===");
        int[] arr = {10, 20, 30, 40, 50};
        
        // 전통적인 for 문
        System.out.println("전통적인 for 문:");
        for (int i = 0; i < arr.length; i++) {
            System.out.println("arr[" + i + "] = " + arr[i]);
        }
        
        // 향상된 for 문
        System.out.println("\n향상된 for 문:");
        for (int value : arr) {
            System.out.println("값: " + value);
        }
        
        // 문자열 배열
        String[] names = {"홍길동", "김철수", "이영희"};
        for (String name : names) {
            System.out.println("이름: " + name);
        }
        
        // ========== break 문 ==========
        
        System.out.println("\n=== break 문 ===");
        for (int i = 0; i < 10; i++) {
            if (i == 5) {
                break;  // 반복문 종료
            }
            System.out.print(i + " ");
        }
        System.out.println();
        
        // 중첩 반복문에서 break
        System.out.println("\n=== 중첩 반복문에서 break ===");
        outer:  // 레이블 사용
        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 3; k++) {
                if (i == 1 && k == 1) {
                    break outer;  // 외부 반복문까지 종료
                }
                System.out.println("i=" + i + ", k=" + k);
            }
        }
        
        // ========== continue 문 ==========
        
        System.out.println("\n=== continue 문 ===");
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                continue;  // 다음 반복으로 건너뛰기
            }
            System.out.print(i + " ");  // 홀수만 출력
        }
        System.out.println();
        
        // ========== 무한 루프 ==========
        
        System.out.println("\n=== 무한 루프 (제어된) ===");
        int sum = 0;
        int n = 1;
        while (true) {
            sum += n;
            n++;
            if (n > 10) {
                break;  // 무한 루프 탈출
            }
        }
        System.out.println("1부터 10까지의 합: " + sum);
        
        // ========== 배열 순회 ==========
        
        System.out.println("\n=== 배열 순회 ===");
        int[] numbers = {10, 20, 30, 40, 50};
        
        // 전통적인 방법
        System.out.println("전통적인 방법:");
        for (int i = 0; i < numbers.length; i++) {
            System.out.println("numbers[" + i + "] = " + numbers[i]);
        }
        
        // 향상된 for 문
        System.out.println("\n향상된 for 문:");
        for (int number : numbers) {
            System.out.println("값: " + number);
        }
        
        // ========== 실용 예제: 최대값 찾기 ==========
        
        System.out.println("\n=== 최대값 찾기 ===");
        int[] scores = {85, 92, 78, 96, 88};
        int max = scores[0];
        
        for (int i = 1; i < scores.length; i++) {
            if (scores[i] > max) {
                max = scores[i];
            }
        }
        System.out.println("최대값: " + max);
        
        // ========== 실용 예제: 합계와 평균 ==========
        
        System.out.println("\n=== 합계와 평균 ===");
        int[] data = {10, 20, 30, 40, 50};
        int total = 0;
        
        for (int value : data) {
            total += value;
        }
        
        double average = (double)total / data.length;
        System.out.println("합계: " + total);
        System.out.println("평균: " + average);
        
        // ========== 실용 예제: 구구단 ==========
        
        System.out.println("\n=== 구구단 ===");
        for (int i = 2; i <= 9; i++) {
            System.out.println("=== " + i + "단 ===");
            for (int k = 1; k <= 9; k++) {
                System.out.println(i + " x " + k + " = " + (i * k));
            }
            System.out.println();
        }
    }
}

/*
 * Java 반복문 핵심 정리
 * 
 * 1. while 문
 *    while (조건) {
 *        // 조건이 true인 동안 반복
 *    }
 * 
 * 2. do-while 문
 *    do {
 *        // 최소 한 번은 실행
 *    } while (조건);
 * 
 * 3. for 문
 *    for (초기값; 조건; 증감식) {
 *        // 반복 실행
 *    }
 * 
 * 4. 향상된 for 문 (for-each)
 *    for (자료형 변수 : 배열/컬렉션) {
 *        // 각 요소에 대해 실행
 *    }
 * 
 * 5. break
 *    - 현재 반복문 종료
 *    - 레이블과 함께 사용하면 외부 반복문도 종료 가능
 * 
 * 6. continue
 *    - 현재 반복 건너뛰고 다음 반복으로
 *    - 레이블과 함께 사용 가능
 * 
 * 7. 중첩 반복문
 *    - 반복문 안에 반복문
 *    - 외부 반복문과 내부 반복문의 변수명 주의
 * 
 * 8. 무한 루프
 *    while (true) { ... }
 *    for (;;) { ... }
 *    - break로 탈출 필요
 * 
 * 9. 배열 순회
 *    - 전통적: for (int i = 0; i < arr.length; i++)
 *    - 향상된: for (int value : arr)
 *    - 향상된 for 문은 인덱스가 필요 없을 때 유용
 */

