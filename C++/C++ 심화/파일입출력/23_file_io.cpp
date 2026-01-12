/*
 * 23_file_io.cpp
 * 
 * 파일 입출력 (File I/O)
 * - 파일 스트림 (ifstream, ofstream, fstream)
 * - 텍스트 파일 읽기/쓰기
 * - 바이너리 파일 읽기/쓰기
 * - 파일 위치 제어
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

// ========== 텍스트 파일 쓰기 ==========

void textFileWrite() {
    cout << "=== 텍스트 파일 쓰기 ===" << endl;
    
    std::ofstream outFile("example.txt");
    
    if (!outFile.is_open()) {
        cout << "파일 열기 실패!" << endl;
        return;
    }
    
    // 파일에 쓰기
    outFile << "Hello, C++!" << endl;
    outFile << "파일 입출력 예제입니다." << endl;
    outFile << 123 << " " << 3.14 << endl;
    
    outFile.close();
    cout << "파일 쓰기 완료: example.txt" << endl;
}

// ========== 텍스트 파일 읽기 ==========

void textFileRead() {
    cout << "\n=== 텍스트 파일 읽기 ===" << endl;
    
    std::ifstream inFile("example.txt");
    
    if (!inFile.is_open()) {
        cout << "파일 열기 실패!" << endl;
        return;
    }
    
    string line;
    
    // 한 줄씩 읽기
    cout << "--- 한 줄씩 읽기 ---" << endl;
    while (std::getline(inFile, line)) {
        cout << line << endl;
    }
    
    inFile.close();
    
    // 다시 열기
    inFile.open("example.txt");
    
    // 단어씩 읽기
    cout << "\n--- 단어씩 읽기 ---" << endl;
    string word;
    while (inFile >> word) {
        cout << word << " ";
    }
    cout << endl;
    
    inFile.close();
}

// ========== 파일 모드 ==========

void fileModes() {
    cout << "\n=== 파일 모드 ===" << endl;
    
    // ios::out: 쓰기 모드 (기본)
    std::ofstream out1("file1.txt", std::ios::out);
    out1 << "쓰기 모드" << endl;
    out1.close();
    
    // ios::app: 추가 모드 (파일 끝에 추가)
    std::ofstream out2("file2.txt", std::ios::app);
    out2 << "첫 번째 줄" << endl;
    out2 << "두 번째 줄" << endl;
    out2.close();
    
    // ios::trunc: 기존 내용 삭제 (기본)
    std::ofstream out3("file3.txt", std::ios::trunc);
    out3 << "기존 내용 삭제 후 쓰기" << endl;
    out3.close();
    
    // ios::in: 읽기 모드
    std::ifstream in1("file1.txt", std::ios::in);
    string content;
    std::getline(in1, content);
    cout << "읽은 내용: " << content << endl;
    in1.close();
    
    // ios::binary: 바이너리 모드
    std::ofstream out4("binary.bin", std::ios::binary);
    out4.close();
}

// ========== fstream (읽기/쓰기 모두) ==========

void fstreamExample() {
    cout << "\n=== fstream (읽기/쓰기) ===" << endl;
    
    std::fstream file("data.txt", std::ios::in | std::ios::out | std::ios::trunc);
    
    if (!file.is_open()) {
        cout << "파일 열기 실패!" << endl;
        return;
    }
    
    // 쓰기
    file << "첫 번째 줄" << endl;
    file << "두 번째 줄" << endl;
    file << "세 번째 줄" << endl;
    
    // 파일 위치를 처음으로 이동
    file.seekg(0, std::ios::beg);
    
    // 읽기
    string line;
    cout << "파일 내용:" << endl;
    while (std::getline(file, line)) {
        cout << line << endl;
    }
    
    file.close();
}

// ========== 바이너리 파일 ==========

void binaryFileWrite() {
    cout << "\n=== 바이너리 파일 쓰기 ===" << endl;
    
    std::ofstream outFile("data.bin", std::ios::binary);
    
    if (!outFile.is_open()) {
        cout << "파일 열기 실패!" << endl;
        return;
    }
    
    int numbers[] = {10, 20, 30, 40, 50};
    double pi = 3.14159;
    
    // 바이너리로 쓰기
    outFile.write(reinterpret_cast<const char*>(numbers), sizeof(numbers));
    outFile.write(reinterpret_cast<const char*>(&pi), sizeof(pi));
    
    outFile.close();
    cout << "바이너리 파일 쓰기 완료" << endl;
}

void binaryFileRead() {
    cout << "\n=== 바이너리 파일 읽기 ===" << endl;
    
    std::ifstream inFile("data.bin", std::ios::binary);
    
    if (!inFile.is_open()) {
        cout << "파일 열기 실패!" << endl;
        return;
    }
    
    int numbers[5];
    double pi;
    
    // 바이너리로 읽기
    inFile.read(reinterpret_cast<char*>(numbers), sizeof(numbers));
    inFile.read(reinterpret_cast<char*>(&pi), sizeof(pi));
    
    cout << "읽은 정수들: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    cout << "읽은 실수: " << pi << endl;
    
    inFile.close();
}

// ========== 파일 위치 제어 ==========

void filePositionControl() {
    cout << "\n=== 파일 위치 제어 ===" << endl;
    
    std::fstream file("position.txt", std::ios::in | std::ios::out | std::ios::trunc);
    
    // 파일에 데이터 쓰기
    for (int i = 1; i <= 10; i++) {
        file << "Line " << i << endl;
    }
    
    // 파일 위치 확인
    cout << "현재 위치: " << file.tellg() << " 바이트" << endl;
    
    // 파일 시작으로 이동
    file.seekg(0, std::ios::beg);
    cout << "시작으로 이동 후 위치: " << file.tellg() << " 바이트" << endl;
    
    // 10바이트 앞으로 이동
    file.seekg(10, std::ios::cur);
    cout << "10바이트 앞으로 이동 후 위치: " << file.tellg() << " 바이트" << endl;
    
    // 파일 끝으로 이동
    file.seekg(0, std::ios::end);
    cout << "끝으로 이동 후 위치: " << file.tellg() << " 바이트" << endl;
    
    // 파일 크기 계산
    size_t fileSize = file.tellg();
    cout << "파일 크기: " << fileSize << " 바이트" << endl;
    
    file.close();
}

// ========== 파일 존재 확인 ==========

void checkFileExists() {
    cout << "\n=== 파일 존재 확인 ===" << endl;
    
    std::ifstream file("example.txt");
    
    if (file.good()) {
        cout << "파일이 존재합니다" << endl;
        
        // 파일 크기 확인
        file.seekg(0, std::ios::end);
        size_t size = file.tellg();
        cout << "파일 크기: " << size << " 바이트" << endl;
        
    } else {
        cout << "파일이 존재하지 않습니다" << endl;
    }
    
    file.close();
}

// ========== 구조체를 파일에 저장 ==========

struct Student {
    char name[50];
    int age;
    double score;
};

void structFileIO() {
    cout << "\n=== 구조체 파일 입출력 ===" << endl;
    
    // 구조체 배열 쓰기
    std::ofstream outFile("students.bin", std::ios::binary);
    
    Student students[] = {
        {"홍길동", 20, 95.5},
        {"김철수", 21, 87.0},
        {"이영희", 19, 92.5}
    };
    
    int count = 3;
    outFile.write(reinterpret_cast<const char*>(&count), sizeof(count));
    outFile.write(reinterpret_cast<const char*>(students), 
                  sizeof(Student) * count);
    outFile.close();
    
    // 구조체 배열 읽기
    std::ifstream inFile("students.bin", std::ios::binary);
    
    int readCount;
    inFile.read(reinterpret_cast<char*>(&readCount), sizeof(readCount));
    
    Student* readStudents = new Student[readCount];
    inFile.read(reinterpret_cast<char*>(readStudents), 
                sizeof(Student) * readCount);
    
    cout << "학생 정보:" << endl;
    for (int i = 0; i < readCount; i++) {
        cout << "이름: " << readStudents[i].name 
             << ", 나이: " << readStudents[i].age
             << ", 점수: " << readStudents[i].score << endl;
    }
    
    delete[] readStudents;
    inFile.close();
}

// ========== CSV 파일 읽기 ==========

void csvFileRead() {
    cout << "\n=== CSV 파일 읽기 ===" << endl;
    
    // CSV 파일 생성
    std::ofstream csvOut("data.csv");
    csvOut << "이름,나이,도시" << endl;
    csvOut << "홍길동,25,서울" << endl;
    csvOut << "김철수,30,부산" << endl;
    csvOut << "이영희,28,대구" << endl;
    csvOut.close();
    
    // CSV 파일 읽기
    std::ifstream csvIn("data.csv");
    string line;
    
    // 헤더 읽기
    std::getline(csvIn, line);
    cout << "헤더: " << line << endl;
    
    // 데이터 읽기
    cout << "\n데이터:" << endl;
    while (std::getline(csvIn, line)) {
        size_t pos = 0;
        int field = 0;
        
        while ((pos = line.find(',')) != string::npos) {
            string token = line.substr(0, pos);
            cout << "필드 " << field++ << ": " << token << " | ";
            line.erase(0, pos + 1);
        }
        cout << "필드 " << field << ": " << line << endl;
    }
    
    csvIn.close();
}

int main() {
    textFileWrite();
    textFileRead();
    fileModes();
    fstreamExample();
    binaryFileWrite();
    binaryFileRead();
    filePositionControl();
    checkFileExists();
    structFileIO();
    csvFileRead();
    
    return 0;
}

/*
 * 파일 입출력 핵심 정리
 * 
 * 1. 파일 스트림 클래스
 *    - ifstream: 입력 파일 스트림 (읽기)
 *    - ofstream: 출력 파일 스트림 (쓰기)
 *    - fstream: 입출력 파일 스트림 (읽기/쓰기)
 * 
 * 2. 파일 열기
 *    파일스트림 객체명("파일명", 모드);
 *    - 모드 생략 시 기본 모드 사용
 * 
 * 3. 파일 모드
 *    - ios::in: 읽기 모드
 *    - ios::out: 쓰기 모드 (기본)
 *    - ios::app: 추가 모드 (파일 끝에 추가)
 *    - ios::trunc: 기존 내용 삭제
 *    - ios::binary: 바이너리 모드
 *    - 여러 모드 조합: ios::in | ios::out
 * 
 * 4. 텍스트 파일 입출력
 *    - << 연산자로 쓰기
 *    - >> 연산자로 읽기 (공백 단위)
 *    - getline()으로 한 줄씩 읽기
 * 
 * 5. 바이너리 파일 입출력
 *    - write(): 바이너리 쓰기
 *    - read(): 바이너리 읽기
 *    - reinterpret_cast 사용
 * 
 * 6. 파일 위치 제어
 *    - tellg(): 현재 읽기 위치
 *    - tellp(): 현재 쓰기 위치
 *    - seekg(): 읽기 위치 이동
 *    - seekp(): 쓰기 위치 이동
 *    - ios::beg: 파일 시작
 *    - ios::cur: 현재 위치
 *    - ios::end: 파일 끝
 * 
 * 7. 파일 상태 확인
 *    - is_open(): 파일이 열려있는지
 *    - good(): 스트림 상태가 좋은지
 *    - eof(): 파일 끝인지
 *    - fail(): 오류 발생했는지
 * 
 * 8. 파일 닫기
 *    - close(): 파일 닫기
 *    - 소멸자에서 자동으로 닫힘
 * 
 * 9. 예외 처리
 *    - 파일 열기 실패 가능성 고려
 *    - 파일 읽기/쓰기 오류 처리
 * 
 * 10. 모범 사례
 *     - 파일 열기 후 is_open() 확인
 *     - 사용 후 close() 호출
 *     - 예외 처리 포함
 *     - 바이너리 파일은 binary 모드 사용
 */

