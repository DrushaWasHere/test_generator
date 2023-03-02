#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        sum += num;
    }
    std::cout << sum;
    return 0;
}
