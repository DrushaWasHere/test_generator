#include <cstdlib>
#include <iostream>
#include <fstream>

void printFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

bool areFilesEqual(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1), f2(file2);
    char c1, c2;
    while (f1.get(c1) && f2.get(c2)) {
        if (c1 != c2) {
            return false;
        }
    }
    return !f1.eof() || !f2.eof(); // Check if one file is longer than the other
}

int main() {
    std::system("g++ true_solution.cpp -o true_solution");
    std::system("g++ fake_solution.cpp -o fake_solution");
    std::system("g++ test_generator.cpp -o test_generator");
    std::system("chmod uog+rwx in.txt");
    std::system("chmod uog+rwx true_solution_out.txt");
    std::system("chmod uog+rwx fake_solution_out.txt");

    int k_tests = 100;
    for (int q = 1; q <= k_tests; ++q) {
        std::system("./test_generator > in.txt");
        std::system("./true_solution < in.txt > true_solution_out.txt");
        std::system("./fake_solution < in.txt > fake_solution_out.txt");
        if (areFilesEqual("true_solution_out.txt", "fake_solution_out.txt")) {
            std::cout << "TEST " << q << ": OK\n";
        } else {
            std::cout << "YOU WAS WRONG! MUAHAHAHAHA\nTEST " << q << ":\n";
            printFile("in.txt");
            std::cout << "WRONG ANSWER:\n";
            printFile("fake_solution_out.txt");
            std::cout << "TRUE ANSWER:\n";
            printFile("true_solution_out.txt");
            break;
        }
    }

    return 0;
}