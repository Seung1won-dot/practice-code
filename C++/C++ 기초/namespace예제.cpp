#include <iostream>
#include <string>
using namespace std; // std 네임스페이스 사용 선언

int main() {
    string name = "홍길동";
    int age = 20;
    
    // std:: 접두어 없이 사용 가능
    cout << "이름: " << name << endl;
    cout << "나이: " << age << "세" << endl;
    
    return 0;
}