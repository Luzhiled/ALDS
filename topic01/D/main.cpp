#include <iostream>
#include <algorithm>

constexpr int inf = 1001001001;

int main() {
    int n;
    std::cin >> n;

    int Rmin = inf;
    int ans = -inf;
    for (int i = 0; i < n; ++i) {
        int R;
        std::cin >> R;

        ans = std::max(ans, R - Rmin);
        Rmin = std::min(Rmin, R);
    }

    std::cout << ans << std::endl;
}

