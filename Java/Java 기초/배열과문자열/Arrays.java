/*
 * 06_arrays.java
 * 
 * Java 배열
 * - 1차원 배열
 * - 2차원 배열
 * - 배열 초기화
 * - 배열 복사
 * - 배열 메서드
 */

public class Arrays {
    public static void main(String[] args) {
        // ========== 1차원 배열 선언과 초기화 ==========
        
        System.out.println("=== 1차원 배열 ===");
        
        // 방법 1: 선언 후 초기화
        int[] arr1 = new int[5];
        arr1[0] = 10;
        arr1[1] = 20;
        arr1[2] = 30;
        arr1[3] = 40;
        arr1[4] = 50;
        
        // 방법 2: 선언과 동시에 초기화
        int[] arr2 = {1, 2, 3, 4, 5};
        
        // 방법 3: new와 함께 초기화
        int[] arr3 = new int[]{10, 20, 30};
        
        System.out.println("arr1 요소:");
        for (int i = 0; i < arr1.length; i++) {
            System.out.println("arr1[" + i + "] = " + arr1[i]);
        }
        
        System.out.println("\narr2 요소:");
        for (int value : arr2) {
            System.out.println("값: " + value);
        }
        
        // ========== 배열 길이 ==========
        
        System.out.println("\n=== 배열 길이 ===");
        int[] numbers = {10, 20, 30, 40, 50};
        System.out.println("배열 길이: " + numbers.length);
        
        // ========== 배열 순회 ==========
        
        System.out.println("\n=== 배열 순회 ===");
        String[] names = {"홍길동", "김철수", "이영희"};
        
        // 전통적인 for 문
        for (int i = 0; i < names.length; i++) {
            System.out.println("names[" + i + "] = " + names[i]);
        }
        
        // 향상된 for 문
        System.out.println("\n향상된 for 문:");
        for (String name : names) {
            System.out.println("이름: " + name);
        }
        
        // ========== 2차원 배열 ==========
        
        System.out.println("\n=== 2차원 배열 ===");
        
        // 방법 1: 선언 후 초기화
        int[][] matrix1 = new int[3][3];
        matrix1[0][0] = 1;
        matrix1[0][1] = 2;
        matrix1[0][2] = 3;
        matrix1[1][0] = 4;
        matrix1[1][1] = 5;
        matrix1[1][2] = 6;
        matrix1[2][0] = 7;
        matrix1[2][1] = 8;
        matrix1[2][2] = 9;
        
        // 방법 2: 선언과 동시에 초기화
        int[][] matrix2 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        System.out.println("matrix2:");
        for (int i = 0; i < matrix2.length; i++) {
            for (int j = 0; j < matrix2[i].length; j++) {
                System.out.print(matrix2[i][j] + " ");
            }
            System.out.println();
        }
        
        // 향상된 for 문으로 2차원 배열 순회
        System.out.println("\n향상된 for 문:");
        for (int[] row : matrix2) {
            for (int value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
        
        // ========== 가변 배열 (Jagged Array) ==========
        
        System.out.println("\n=== 가변 배열 ===");
        int[][] jagged = new int[3][];
        jagged[0] = new int[]{1, 2};
        jagged[1] = new int[]{3, 4, 5};
        jagged[2] = new int[]{6, 7, 8, 9};
        
        for (int i = 0; i < jagged.length; i++) {
            for (int j = 0; j < jagged[i].length; j++) {
                System.out.print(jagged[i][j] + " ");
            }
            System.out.println();
        }
        
        // ========== 배열 복사 ==========
        
        System.out.println("\n=== 배열 복사 ===");
        int[] original = {1, 2, 3, 4, 5};
        
        // 방법 1: 얕은 복사 (참조 복사)
        int[] shallowCopy = original;
        shallowCopy[0] = 100;
        System.out.println("원본[0]: " + original[0]);  // 100으로 변경됨
        
        // 방법 2: 깊은 복사 (값 복사)
        int[] deepCopy = new int[original.length];
        for (int i = 0; i < original.length; i++) {
            deepCopy[i] = original[i];
        }
        deepCopy[0] = 200;
        System.out.println("원본[0]: " + original[0]);  // 여전히 100
        System.out.println("복사본[0]: " + deepCopy[0]);  // 200
        
        // 방법 3: System.arraycopy() 사용
        int[] copy3 = new int[original.length];
        System.arraycopy(original, 0, copy3, 0, original.length);
        
        // 방법 4: clone() 사용
        int[] copy4 = original.clone();
        
        // ========== 배열 최대값, 최소값 찾기 ==========
        
        System.out.println("\n=== 배열 최대값, 최소값 ===");
        int[] scores = {85, 92, 78, 96, 88};
        
        int max = scores[0];
        int min = scores[0];
        
        for (int i = 1; i < scores.length; i++) {
            if (scores[i] > max) {
                max = scores[i];
            }
            if (scores[i] < min) {
                min = scores[i];
            }
        }
        
        System.out.println("최대값: " + max);
        System.out.println("최소값: " + min);
        
        // ========== 배열 합계와 평균 ==========
        
        System.out.println("\n=== 배열 합계와 평균 ===");
        int[] data = {10, 20, 30, 40, 50};
        int sum = 0;
        
        for (int value : data) {
            sum += value;
        }
        
        double average = (double)sum / data.length;
        System.out.println("합계: " + sum);
        System.out.println("평균: " + average);
        
        // ========== 배열 검색 ==========
        
        System.out.println("\n=== 배열 검색 ===");
        int[] numbers2 = {10, 20, 30, 40, 50};
        int target = 30;
        boolean found = false;
        int index = -1;
        
        for (int i = 0; i < numbers2.length; i++) {
            if (numbers2[i] == target) {
                found = true;
                index = i;
                break;
            }
        }
        
        if (found) {
            System.out.println(target + "을(를) 찾았습니다. 인덱스: " + index);
        } else {
            System.out.println(target + "을(를) 찾을 수 없습니다.");
        }
        
        // ========== 배열 정렬 (버블 정렬) ==========
        
        System.out.println("\n=== 배열 정렬 ===");
        int[] unsorted = {64, 34, 25, 12, 22, 11, 90};
        
        System.out.println("정렬 전:");
        for (int value : unsorted) {
            System.out.print(value + " ");
        }
        System.out.println();
        
        // 버블 정렬
        for (int i = 0; i < unsorted.length - 1; i++) {
            for (int j = 0; j < unsorted.length - i - 1; j++) {
                if (unsorted[j] > unsorted[j + 1]) {
                    // 교환
                    int temp = unsorted[j];
                    unsorted[j] = unsorted[j + 1];
                    unsorted[j + 1] = temp;
                }
            }
        }
        
        System.out.println("정렬 후:");
        for (int value : unsorted) {
            System.out.print(value + " ");
        }
        System.out.println();
        
        // ========== Arrays 클래스 사용 ==========
        
        System.out.println("\n=== Arrays 클래스 ===");
        int[] arr = {5, 2, 8, 1, 9};
        
        // 정렬
        java.util.Arrays.sort(arr);
        System.out.println("정렬 후: " + java.util.Arrays.toString(arr));
        
        // 검색 (정렬된 배열에서만 정확함)
        int index2 = java.util.Arrays.binarySearch(arr, 8);
        System.out.println("8의 인덱스: " + index2);
        
        // 배열 비교
        int[] arr1_comp = {1, 2, 3};
        int[] arr2_comp = {1, 2, 3};
        boolean equals = java.util.Arrays.equals(arr1_comp, arr2_comp);
        System.out.println("배열 같음: " + equals);
        
        // 배열 채우기
        int[] filled = new int[5];
        java.util.Arrays.fill(filled, 10);
        System.out.println("채운 배열: " + java.util.Arrays.toString(filled));
    }
}

/*
 * Java 배열 핵심 정리
 * 
 * 1. 배열 선언
 *    자료형[] 배열명 = new 자료형[크기];
 *    자료형[] 배열명 = {값1, 값2, ...};
 * 
 * 2. 배열 접근
 *    배열명[인덱스]  // 인덱스는 0부터 시작
 * 
 * 3. 배열 길이
 *    배열명.length  // 배열의 크기
 * 
 * 4. 2차원 배열
 *    자료형[][] 배열명 = new 자료형[행][열];
 *    자료형[][] 배열명 = {{값들}, {값들}, ...};
 * 
 * 5. 배열 복사
 *    - 얕은 복사: 참조만 복사
 *    - 깊은 복사: 값 복사 (for문, System.arraycopy(), clone())
 * 
 * 6. Arrays 클래스
 *    - sort(): 정렬
 *    - binarySearch(): 이진 검색
 *    - equals(): 배열 비교
 *    - fill(): 배열 채우기
 *    - toString(): 문자열로 변환
 * 
 * 7. 주의사항
 *    - 배열 크기는 고정 (동적 크기 변경 불가)
 *    - 인덱스 범위를 벗어나면 ArrayIndexOutOfBoundsException 발생
 *    - 동적 크기가 필요하면 ArrayList 사용
 */

