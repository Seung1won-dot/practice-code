/*
 * 19_class_template.cpp
 * 
 * 클래스 템플릿 (Class Template)
 * - 제네릭 클래스 정의
 * - 템플릿 매개변수
 * - 템플릿 특수화
 * - 템플릿과 상속
 */

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

// ========== 기본 클래스 템플릿 ==========

template <typename T>
class Stack {
private:
    T* data;
    size_t capacity;
    size_t top;
    
public:
    Stack(size_t cap = 10) : capacity(cap), top(0) {
        data = new T[capacity];
    }
    
    ~Stack() {
        delete[] data;
    }
    
    void push(const T& item) {
        if (top < capacity) {
            data[top++] = item;
        } else {
            cout << "스택이 가득 찼습니다!" << endl;
        }
    }
    
    void pop() {
        if (top > 0) {
            top--;
        } else {
            cout << "스택이 비어있습니다!" << endl;
        }
    }
    
    T peek() const {
        if (top > 0) {
            return data[top - 1];
        }
        throw std::runtime_error("스택이 비어있습니다");
    }
    
    bool isEmpty() const {
        return top == 0;
    }
    
    size_t size() const {
        return top;
    }
};

void basicClassTemplate() {
    cout << "=== 기본 클래스 템플릿 ===" << endl;
    
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    cout << "스택 크기: " << intStack.size() << endl;
    cout << "최상단: " << intStack.peek() << endl;
    intStack.pop();
    cout << "pop 후 최상단: " << intStack.peek() << endl;
    
    Stack<double> doubleStack;
    doubleStack.push(3.14);
    doubleStack.push(2.71);
    cout << "double 스택 최상단: " << doubleStack.peek() << endl;
    
    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    cout << "string 스택 최상단: " << stringStack.peek() << endl;
}

// ========== 여러 템플릿 매개변수 ==========

template <typename T, size_t N>
class Array {
private:
    T arr[N];
    
public:
    T& operator[](size_t index) {
        if (index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    
    const T& operator[](size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    
    size_t size() const {
        return N;
    }
    
    void fill(const T& value) {
        for (size_t i = 0; i < N; i++) {
            arr[i] = value;
        }
    }
};

void multipleTemplateParams() {
    cout << "\n=== 여러 템플릿 매개변수 ===" << endl;
    
    Array<int, 5> intArray;
    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;
    
    cout << "배열 크기: " << intArray.size() << endl;
    for (size_t i = 0; i < intArray.size(); i++) {
        cout << "intArray[" << i << "] = " << intArray[i] << endl;
    }
    
    Array<double, 3> doubleArray;
    doubleArray.fill(3.14);
    for (size_t i = 0; i < doubleArray.size(); i++) {
        cout << "doubleArray[" << i << "] = " << doubleArray[i] << endl;
    }
}

// ========== 템플릿 특수화 ==========

// 일반 템플릿
template <typename T>
class Calculator {
public:
    T add(T a, T b) {
        return a + b;
    }
    
    T multiply(T a, T b) {
        return a * b;
    }
};

// 특수화: bool 타입에 대한 특별한 처리
template <>
class Calculator<bool> {
public:
    bool add(bool a, bool b) {
        return a || b;  // 논리 OR
    }
    
    bool multiply(bool a, bool b) {
        return a && b;  // 논리 AND
    }
};

void templateSpecialization() {
    cout << "\n=== 템플릿 특수화 ===" << endl;
    
    Calculator<int> intCalc;
    cout << "int: 5 + 3 = " << intCalc.add(5, 3) << endl;
    cout << "int: 5 * 3 = " << intCalc.multiply(5, 3) << endl;
    
    Calculator<bool> boolCalc;
    cout << "bool: true + false = " << boolCalc.add(true, false) << endl;
    cout << "bool: true * false = " << boolCalc.multiply(true, false) << endl;
}

// ========== 템플릿과 상속 ==========

template <typename T>
class Container {
protected:
    T* data;
    size_t size;
    
public:
    Container(size_t s = 10) : size(s) {
        data = new T[size];
    }
    
    virtual ~Container() {
        delete[] data;
    }
    
    virtual void add(const T& item) = 0;
    virtual T get(size_t index) const = 0;
    virtual size_t getSize() const = 0;
};

template <typename T>
class Vector : public Container<T> {
private:
    size_t count;
    
public:
    Vector(size_t s = 10) : Container<T>(s), count(0) {}
    
    void add(const T& item) override {
        if (count < this->size) {
            this->data[count++] = item;
        }
    }
    
    T get(size_t index) const override {
        if (index < count) {
            return this->data[index];
        }
        throw std::out_of_range("Index out of range");
    }
    
    size_t getSize() const override {
        return count;
    }
};

void templateInheritance() {
    cout << "\n=== 템플릿과 상속 ===" << endl;
    
    Vector<int> vec(5);
    vec.add(10);
    vec.add(20);
    vec.add(30);
    
    cout << "벡터 크기: " << vec.getSize() << endl;
    for (size_t i = 0; i < vec.getSize(); i++) {
        cout << "vec[" << i << "] = " << vec.get(i) << endl;
    }
}

// ========== 템플릿 메서드 정의 분리 ==========

template <typename T>
class Pair {
private:
    T first, second;
    
public:
    Pair(const T& f = T(), const T& s = T()) : first(f), second(s) {}
    
    T getFirst() const;
    T getSecond() const;
    void setFirst(const T& f);
    void setSecond(const T& s);
    
    void display() const;
};

// 템플릿 메서드 외부 정의
template <typename T>
T Pair<T>::getFirst() const {
    return first;
}

template <typename T>
T Pair<T>::getSecond() const {
    return second;
}

template <typename T>
void Pair<T>::setFirst(const T& f) {
    first = f;
}

template <typename T>
void Pair<T>::setSecond(const T& s) {
    second = s;
}

template <typename T>
void Pair<T>::display() const {
    cout << "(" << first << ", " << second << ")" << endl;
}

void templateMethodDefinition() {
    cout << "\n=== 템플릿 메서드 정의 분리 ===" << endl;
    
    Pair<int> intPair(10, 20);
    intPair.display();
    
    Pair<std::string> stringPair("Hello", "World");
    stringPair.display();
}

// ========== 기본 템플릿 인수 ==========

template <typename T = int, size_t N = 10>
class Buffer {
private:
    T buffer[N];
    size_t index;
    
public:
    Buffer() : index(0) {}
    
    void add(const T& item) {
        if (index < N) {
            buffer[index++] = item;
        }
    }
    
    void display() const {
        for (size_t i = 0; i < index; i++) {
            cout << buffer[i] << " ";
        }
        cout << endl;
    }
};

void defaultTemplateArgs() {
    cout << "\n=== 기본 템플릿 인수 ===" << endl;
    
    Buffer<> defaultBuffer;  // Buffer<int, 10>과 동일
    defaultBuffer.add(1);
    defaultBuffer.add(2);
    defaultBuffer.add(3);
    defaultBuffer.display();
    
    Buffer<double, 5> customBuffer;
    customBuffer.add(1.1);
    customBuffer.add(2.2);
    customBuffer.display();
}

int main() {
    basicClassTemplate();
    multipleTemplateParams();
    templateSpecialization();
    templateInheritance();
    templateMethodDefinition();
    defaultTemplateArgs();
    
    return 0;
}

/*
 * 클래스 템플릿 핵심 정리
 * 
 * 1. 클래스 템플릿의 개념
 *    - 타입에 독립적인 클래스 정의
 *    - 제네릭 프로그래밍 구현
 *    - 코드 재사용성 극대화
 * 
 * 2. 템플릿 선언
 *    template <typename T>
 *    class 클래스명 {
 *        // ...
 *    };
 * 
 * 3. 템플릿 인스턴스화
 *    클래스명<타입> 객체명;
 *    예: Stack<int> stack;
 * 
 * 4. 여러 템플릿 매개변수
 *    template <typename T, size_t N>
 *    - 타입 매개변수와 비타입 매개변수 혼용 가능
 * 
 * 5. 템플릿 특수화
 *    - 특정 타입에 대한 특별한 구현
 *    - template <> class 클래스명<특정타입>
 *    - 성능 최적화나 특별한 동작 필요 시 사용
 * 
 * 6. 템플릿과 상속
 *    - 템플릿 클래스도 상속 가능
 *    - 파생 클래스도 템플릿일 수 있음
 *    - this-> 사용 주의 (템플릿 의존 이름)
 * 
 * 7. 템플릿 메서드 외부 정의
 *    - 헤더 파일에 정의하는 것이 일반적
 *    - 외부 정의 시 template 키워드 필요
 *    - 모든 정의가 헤더에 있어야 함 (링크 오류 방지)
 * 
 * 8. 기본 템플릿 인수
 *    - 함수의 기본 인수와 유사
 *    - 타입과 비타입 매개변수 모두 가능
 * 
 * 9. 템플릿의 장점
 *    - 타입 안전성
 *    - 코드 중복 제거
 *    - 컴파일 타임 최적화
 *    - 유연한 코드 작성
 * 
 * 10. 템플릿의 단점
 *     - 컴파일 시간 증가
 *     - 코드 크기 증가
 *     - 디버깅 어려움
 *     - 모든 정의가 헤더에 필요
 */

