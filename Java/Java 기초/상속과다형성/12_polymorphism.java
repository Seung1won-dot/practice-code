/*
 * 12_polymorphism.java
 * 
 * Java 다형성
 * - 메서드 오버라이딩
 * - 업캐스팅과 다운캐스팅
 * - instanceof 연산자
 * - 추상 클래스
 */

// 부모 클래스
class Shape {
    protected String name;
    
    public Shape(String name) {
        this.name = name;
    }
    
    public void draw() {
        System.out.println(name + "을(를) 그립니다.");
    }
    
    public double getArea() {
        return 0;  // 기본 구현
    }
}

// 자식 클래스들
class Circle extends Shape {
    private double radius;
    
    public Circle(double radius) {
        super("원");
        this.radius = radius;
    }
    
    @Override
    public void draw() {
        System.out.println("원을 그립니다. (반지름: " + radius + ")");
    }
    
    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    private double width;
    private double height;
    
    public Rectangle(double width, double height) {
        super("사각형");
        this.width = width;
        this.height = height;
    }
    
    @Override
    public void draw() {
        System.out.println("사각형을 그립니다. (가로: " + width + ", 세로: " + height + ")");
    }
    
    @Override
    public double getArea() {
        return width * height;
    }
}

class Triangle extends Shape {
    private double base;
    private double height;
    
    public Triangle(double base, double height) {
        super("삼각형");
        this.base = base;
        this.height = height;
    }
    
    @Override
    public void draw() {
        System.out.println("삼각형을 그립니다. (밑변: " + base + ", 높이: " + height + ")");
    }
    
    @Override
    public double getArea() {
        return 0.5 * base * height;
    }
}

public class Polymorphism {
    public static void main(String[] args) {
        // ========== 다형성 예제 ==========
        
        System.out.println("=== 다형성 예제 ===");
        
        // 부모 클래스 타입으로 자식 객체 참조 (업캐스팅)
        Shape shape1 = new Circle(5.0);
        Shape shape2 = new Rectangle(4.0, 6.0);
        Shape shape3 = new Triangle(3.0, 4.0);
        
        // 같은 메서드 호출이지만 다른 동작 (다형성)
        shape1.draw();
        System.out.println("면적: " + shape1.getArea());
        System.out.println();
        
        shape2.draw();
        System.out.println("면적: " + shape2.getArea());
        System.out.println();
        
        shape3.draw();
        System.out.println("면적: " + shape3.getArea());
        System.out.println();
        
        // ========== 배열을 이용한 다형성 ==========
        
        System.out.println("=== 배열을 이용한 다형성 ===");
        Shape[] shapes = {
            new Circle(3.0),
            new Rectangle(5.0, 4.0),
            new Triangle(6.0, 8.0),
            new Circle(2.5)
        };
        
        double totalArea = 0;
        for (Shape shape : shapes) {
            shape.draw();
            double area = shape.getArea();
            totalArea += area;
            System.out.println("면적: " + area);
            System.out.println();
        }
        System.out.println("전체 면적: " + totalArea);
        
        // ========== instanceof 연산자 ==========
        
        System.out.println("\n=== instanceof 연산자 ===");
        
        for (Shape shape : shapes) {
            if (shape instanceof Circle) {
                System.out.println("이것은 원입니다.");
            } else if (shape instanceof Rectangle) {
                System.out.println("이것은 사각형입니다.");
            } else if (shape instanceof Triangle) {
                System.out.println("이것은 삼각형입니다.");
            }
        }
        
        // ========== 다운캐스팅 ==========
        
        System.out.println("\n=== 다운캐스팅 ===");
        
        Shape shape = new Circle(5.0);
        
        // instanceof로 확인 후 다운캐스팅
        if (shape instanceof Circle) {
            Circle circle = (Circle)shape;  // 다운캐스팅
            System.out.println("원의 반지름: " + circle.radius);
        }
        
        // ========== 메서드 매개변수로 다형성 활용 ==========
        
        System.out.println("\n=== 메서드 매개변수로 다형성 활용 ===");
        
        printShapeInfo(new Circle(4.0));
        printShapeInfo(new Rectangle(3.0, 5.0));
        printShapeInfo(new Triangle(4.0, 6.0));
        
        // ========== 반환값으로 다형성 활용 ==========
        
        System.out.println("\n=== 반환값으로 다형성 활용 ===");
        
        Shape shape4 = createShape("circle", 5.0);
        shape4.draw();
        System.out.println("면적: " + shape4.getArea());
    }
    
    // 다형성을 활용한 메서드
    public static void printShapeInfo(Shape shape) {
        System.out.println("=== 도형 정보 ===");
        shape.draw();
        System.out.println("면적: " + shape.getArea());
        System.out.println();
    }
    
    // 다형성을 활용한 팩토리 메서드
    public static Shape createShape(String type, double... params) {
        switch (type.toLowerCase()) {
            case "circle":
                return new Circle(params[0]);
            case "rectangle":
                return new Rectangle(params[0], params[1]);
            case "triangle":
                return new Triangle(params[0], params[1]);
            default:
                return null;
        }
    }
}

/*
 * Java 다형성 핵심 정리
 * 
 * 1. 다형성이란?
 *    - 하나의 인터페이스로 여러 형태의 객체를 다룸
 *    - 같은 메서드 호출이 객체에 따라 다른 동작
 * 
 * 2. 업캐스팅 (Upcasting)
 *    - 자식 객체를 부모 타입으로 참조
 *    - 자동 변환
 *    - 부모 클래스의 멤버만 접근 가능
 * 
 * 3. 다운캐스팅 (Downcasting)
 *    - 부모 타입을 자식 타입으로 변환
 *    - 명시적 변환 필요
 *    - instanceof로 확인 후 사용 권장
 * 
 * 4. instanceof 연산자
 *    - 객체가 특정 클래스의 인스턴스인지 확인
 *    - 다운캐스팅 전에 확인 필수
 * 
 * 5. 메서드 오버라이딩
 *    - 부모 클래스 메서드를 자식 클래스에서 재정의
 *    - 런타임에 실제 객체의 메서드 호출 (동적 바인딩)
 * 
 * 6. 다형성의 장점
 *    - 코드 재사용성 향상
 *    - 유지보수 용이
 *    - 확장성 증가
 * 
 * 7. 주의사항
 *    - 오버라이딩된 메서드만 다형성 적용
 *    - 멤버 변수는 다형성 적용 안 됨
 *    - static 메서드는 오버라이딩 불가
 */

