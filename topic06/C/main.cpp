#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using type = std::pair<char, int>;
int partition(std::vector<type>& as, int p, int r) {
    type x = as[r - 1];

    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (as[j].second <= x.second) {
            i++;
            std::swap(as[i], as[j]);
        }
    }

    return i;
}

void quick_sort(std::vector<type>& as, int p, int r) {
    if (r - p > 1) {
        int q = partition(as, p, r);
        quick_sort(as, p, q);
        quick_sort(as, q, r);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<type> cs(n);
    for (auto& c : cs) std::cin >> c.first >> c.second;

    std::map<int, std::vector<char>> mpf;
    for (auto& c : cs) {
        mpf[c.second].emplace_back(c.first);
    }

    quick_sort(cs, 0, n);

    bool is_stable = true;
    std::map<int, std::vector<char>> mps;
    for (auto& c : cs) {
        mps[c.second].emplace_back(c.first);
    }

    for (auto& p : mps) {
        int m;
        std::vector<char> as, bs;
        tie(m, as) = p;

        bs = mpf[m];

        if (as != bs) is_stable = false;
    }

    std::cout << (is_stable ? "Stable" : "Not stable") << std::endl;
    for (auto& c : cs) {
        std::cout << c.first << " " << c.second << std::endl;
    }
}
