/*
 * 14_collections.java
 * 
 * Java 컬렉션 프레임워크
 * - List (ArrayList, LinkedList)
 * - Set (HashSet, TreeSet)
 * - Map (HashMap, TreeMap)
 * - Iterator
 */

import java.util.*;

public class Collections {
    public static void main(String[] args) {
        // ========== ArrayList ==========
        
        System.out.println("=== ArrayList ===");
        
        // ArrayList 생성
        ArrayList<String> list = new ArrayList<>();
        
        // 요소 추가
        list.add("사과");
        list.add("바나나");
        list.add("오렌지");
        list.add("사과");  // 중복 허용
        
        System.out.println("리스트: " + list);
        System.out.println("크기: " + list.size());
        
        // 요소 접근
        System.out.println("첫 번째 요소: " + list.get(0));
        
        // 요소 수정
        list.set(1, "포도");
        System.out.println("수정 후: " + list);
        
        // 요소 삭제
        list.remove(2);
        System.out.println("삭제 후: " + list);
        
        // 요소 검색
        System.out.println("'사과' 포함 여부: " + list.contains("사과"));
        System.out.println("'사과' 인덱스: " + list.indexOf("사과"));
        
        // 순회
        System.out.println("\n순회:");
        for (String fruit : list) {
            System.out.println("- " + fruit);
        }
        
        // ========== LinkedList ==========
        
        System.out.println("\n=== LinkedList ===");
        
        LinkedList<Integer> linkedList = new LinkedList<>();
        
        linkedList.add(10);
        linkedList.add(20);
        linkedList.add(30);
        
        System.out.println("리스트: " + linkedList);
        
        // 앞뒤로 추가
        linkedList.addFirst(5);
        linkedList.addLast(40);
        System.out.println("추가 후: " + linkedList);
        
        // 앞뒤 요소 제거
        linkedList.removeFirst();
        linkedList.removeLast();
        System.out.println("제거 후: " + linkedList);
        
        // ========== HashSet ==========
        
        System.out.println("\n=== HashSet ===");
        
        HashSet<String> set = new HashSet<>();
        
        // 요소 추가
        set.add("Java");
        set.add("Python");
        set.add("C++");
        set.add("Java");  // 중복은 무시됨
        
        System.out.println("셋: " + set);
        System.out.println("크기: " + set.size());
        
        // 요소 검색
        System.out.println("'Java' 포함 여부: " + set.contains("Java"));
        
        // 요소 삭제
        set.remove("Python");
        System.out.println("삭제 후: " + set);
        
        // 순회
        System.out.println("\n순회:");
        for (String lang : set) {
            System.out.println("- " + lang);
        }
        
        // ========== TreeSet ==========
        
        System.out.println("\n=== TreeSet ===");
        
        TreeSet<Integer> treeSet = new TreeSet<>();
        
        treeSet.add(30);
        treeSet.add(10);
        treeSet.add(20);
        treeSet.add(50);
        treeSet.add(40);
        
        System.out.println("트리셋 (자동 정렬): " + treeSet);
        System.out.println("최소값: " + treeSet.first());
        System.out.println("최대값: " + treeSet.last());
        
        // ========== HashMap ==========
        
        System.out.println("\n=== HashMap ===");
        
        HashMap<String, Integer> map = new HashMap<>();
        
        // 키-값 쌍 추가
        map.put("홍길동", 25);
        map.put("김철수", 30);
        map.put("이영희", 28);
        map.put("홍길동", 26);  // 기존 키의 값 업데이트
        
        System.out.println("맵: " + map);
        System.out.println("크기: " + map.size());
        
        // 값 접근
        System.out.println("홍길동의 나이: " + map.get("홍길동"));
        
        // 키 존재 여부
        System.out.println("'김철수' 키 존재: " + map.containsKey("김철수"));
        System.out.println("25 값 존재: " + map.containsValue(25));
        
        // 키-값 쌍 삭제
        map.remove("이영희");
        System.out.println("삭제 후: " + map);
        
        // 순회
        System.out.println("\n순회:");
        for (String key : map.keySet()) {
            System.out.println(key + ": " + map.get(key));
        }
        
        // ========== TreeMap ==========
        
        System.out.println("\n=== TreeMap ===");
        
        TreeMap<String, Integer> treeMap = new TreeMap<>();
        
        treeMap.put("사과", 1000);
        treeMap.put("바나나", 2000);
        treeMap.put("오렌지", 1500);
        
        System.out.println("트리맵 (키 자동 정렬): " + treeMap);
        
        // ========== Iterator ==========
        
        System.out.println("\n=== Iterator ===");
        
        ArrayList<String> fruits = new ArrayList<>();
        fruits.add("사과");
        fruits.add("바나나");
        fruits.add("오렌지");
        
        Iterator<String> iterator = fruits.iterator();
        while (iterator.hasNext()) {
            String fruit = iterator.next();
            System.out.println("- " + fruit);
        }
        
        // ========== 컬렉션 변환 ==========
        
        System.out.println("\n=== 컬렉션 변환 ===");
        
        // List → Set (중복 제거)
        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(2);
        numbers.add(3);
        
        HashSet<Integer> numberSet = new HashSet<>(numbers);
        System.out.println("리스트: " + numbers);
        System.out.println("셋 (중복 제거): " + numberSet);
        
        // ========== 실용 예제 ==========
        
        System.out.println("\n=== 실용 예제 ===");
        
        // 학생 점수 관리
        HashMap<String, Integer> scores = new HashMap<>();
        scores.put("홍길동", 85);
        scores.put("김철수", 92);
        scores.put("이영희", 78);
        scores.put("박민수", 96);
        
        // 평균 계산
        int sum = 0;
        for (int score : scores.values()) {
            sum += score;
        }
        double average = (double)sum / scores.size();
        System.out.println("평균 점수: " + average);
        
        // 최고 점수 찾기
        int maxScore = Collections.max(scores.values());
        System.out.println("최고 점수: " + maxScore);
    }
}

/*
 * Java 컬렉션 프레임워크 핵심 정리
 * 
 * 1. List (순서 있음, 중복 허용)
 *    - ArrayList: 배열 기반, 빠른 접근
 *    - LinkedList: 연결 리스트, 빠른 삽입/삭제
 * 
 * 2. Set (순서 없음, 중복 불가)
 *    - HashSet: 해시 테이블, 빠른 검색
 *    - TreeSet: 트리 구조, 자동 정렬
 * 
 * 3. Map (키-값 쌍)
 *    - HashMap: 해시 테이블, 빠른 검색
 *    - TreeMap: 트리 구조, 키 자동 정렬
 * 
 * 4. 주요 메서드
 *    - List: add(), get(), set(), remove(), size()
 *    - Set: add(), remove(), contains(), size()
 *    - Map: put(), get(), remove(), containsKey(), size()
 * 
 * 5. 제네릭
 *    - 타입 안정성 제공
 *    - ArrayList<String>, HashMap<Integer, String> 등
 * 
 * 6. Iterator
 *    - 컬렉션 순회
 *    - hasNext(), next() 메서드
 * 
 * 7. 주의사항
 *    - null 값 허용 여부 확인
 *    - equals()와 hashCode() 구현 필요 (Set, Map)
 *    - 동기화가 필요하면 Collections.synchronizedXXX() 사용
 */

