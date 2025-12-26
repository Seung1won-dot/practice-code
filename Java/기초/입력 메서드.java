package 기초;
Scanner sc = new Scanner(System.in);
String inputValue = sc.next(); // 사용자가 입력한 문자열 값
// 사용자가 입력한 값 중 공백 또는 줄바꿈 문자를 구분점으로 각 문자열을 분리한다.
String inputValue = sc.nextLine(); // 사용자가 입력한 값
// 위의 next()와 다르게 Enter 전까지 입력한 모든 내용을 문자열 형태로 받는다

int num1 = sc.nextInt();


sc.close(); // 수돗물 사용 후 수도꼭지를 닫는 것과 같이 스캐너도 닫아준다.