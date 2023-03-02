#include <iostream>
#include <vector>
#include <random>

const int MAX_LEN = 10;
const int MAX_VALUE = 10;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> size_generator(1, MAX_LEN);
std::uniform_int_distribution<> value_generator(1, MAX_VALUE);

struct Test {
    int n;
    std::vector<int> vec;

    Test() : n(size_generator(gen)), vec(n) {
        for (int i = 0; i < n; ++i) {
            vec[i] = value_generator(gen);
        }
    }

    void Print() {
        std::cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            std::cout << vec[i] << " ";
        }
    }
};


int main() {
    Test test;
    test.Print();
}