#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    using i64 = long long;
    int n, w;
    std::cin >> n >> w;

    std::vector<std::pair<i64, i64> > vs(n);
    for (auto& v : vs) {
        std::cin >> v.first >> v.second;
    }

    std::sort(vs.begin(), vs.end(), [](auto a, auto b) {
        return a.first * b.second > a.second * b.first;
    });

    double ans = 0;
    for (const auto& v : vs) {
        if (v.second <= w) {
            ans += v.first;
            w -= v.second;
            continue;
        }

        ans += (double)v.first * w / v.second;
        break;
    }

    std::cout << std::fixed << std::setprecision(15);
    std::cout << ans << std::endl;
}
