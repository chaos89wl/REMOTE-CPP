#include <cstdio>
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>

#include <cstdio>
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>

void SaveNumbersToFile(const char* filename, const std::vector<double>& numbers) {
    FILE* outFile = fopen(filename, "w");

    if (outFile != nullptr) {
        for (const auto& number : numbers) {
            // Convert to scientific notation
            std::ostringstream oss;
            oss << std::scientific << std::setprecision(16) << number;
            std::string scientificStr = oss.str();

            // Convert to UTF-8
            std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
            std::string utf8Str = converter.to_bytes(scientificStr);

            // Write to file
            fprintf(outFile, "%s\n", utf8Str.c_str());
        }
        fclose(outFile);
        std::cout << "Data has been successfully written to the file." << std::endl;
    } else {
        std::cerr << "Unable to open the file." << std::endl;
    }
}

int main() {
    std::vector<double> numbers = {96.768, 164.608, 232.704};
    SaveNumbersToFile("output.txt", numbers);
    return 0;
}