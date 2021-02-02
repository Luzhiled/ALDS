#include <algorithm>
#include <iostream>
#include <vector>

int partition(std::vector<int>& as, int p, int r) {
    int x = as[r - 1];

    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (as[j] <= x) {
            i++;
            std::swap(as[i], as[j]);
        }
    }

    return i;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> as(n);
    for (auto& a : as) std::cin >> a;

    int p = partition(as, 0, n);
    for (int i = 0; i < n; ++i) {
        if (i == p) std::cout << "[";
        std::cout << as[i];
        if (i == p) std::cout << "]";
        std::cout << (i + 1 == n ? '\n' : ' ');
    }
}
