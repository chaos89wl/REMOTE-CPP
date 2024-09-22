#include <iostream>
#include <fstream>

int main() {
    // Open a file for writing
    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    // 파일에 데이터 쓰기
    outputFile << "Hello, World!" << std::endl;

    // 출력 파일 닫기
    outputFile.close();

    // 파일을 읽기 모드로 열기
    std::ifstream inputFile("output.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    // 파일에서 데이터 읽기
    std::string line;

    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    // 입력 파일 닫기
    inputFile.close();

    return 0;
}

// Compare this snippet from Test-03.cpp:
// #include <iostream>