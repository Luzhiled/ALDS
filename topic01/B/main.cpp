#include <iostream>

int gcd(int x, int y) {
    if (x < y) std::swap(x, y);
    while (y) {
        x = x % y;
        std::swap(x, y);
    }

    return x;
}

int main() {
    int x, y;
    std::cin >> x >> y;

    std::cout << gcd(x, y) << std::endl;
}
