#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector< int > ss(n);
    for (auto &s: ss) std::cin >> s;

    int q;
    std::cin >> q;

    std::vector< int > ts(q);
    for (auto &t: ts) std::cin >> t;

    int ans = 0;
    for (const auto &t: ts) {
        for (const auto &s: ss) {
            if (t == s) {
                ans += 1;
                break;
            }
        }
    }

    std::cout << ans << std::endl;
}
