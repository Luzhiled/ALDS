#include <iostream>
#include <vector>

constexpr int MIN_A = 0;
constexpr int MAX_A = 10000;
void counting_sort(std::vector<int>& as, int l = MIN_A, int r = MAX_A + 1) {
    int n = as.size();
    int k = r - l;
    std::vector<int> bs = as;
    std::vector<int> cs(k);

    for (const auto& a : as) {
        cs[a - l]++;
    }

    for (int i = 1; i < k; ++i) {
        cs[i] += cs[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        as[cs[bs[i] - l] - 1] = bs[i];
        cs[bs[i] - l]--;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> as(n);
    for (auto& a : as) std::cin >> a;

    counting_sort(as);
    for (int i = 0; i < n; ++i) {
        std::cout << as[i] << (i + 1 == n ? '\n' : ' ');
    }
}
