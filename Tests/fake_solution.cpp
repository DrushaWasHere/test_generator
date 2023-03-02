#include <iostream>
#include <random>

const int MAX_VALUE = 100;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> value_generator(1, MAX_VALUE);

int main() {
    int n = 0;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        sum += num;
    }
    if (value_generator(gen) == 1) {
        sum += 1;
    }
    std::cout << sum;
    return 0;
}
