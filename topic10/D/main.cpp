#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<double> ps(n), qs(n + 1);
    for (auto& p : ps) std::cin >> p;
    for (auto& q : qs) std::cin >> q;

    std::vector<double> rs(n + 2);
    for (int i = 0; i <= n; ++i) {
        rs[i + 1] += qs[i];
    }

    for (int i = 0; i < n; ++i) {
        rs[i + 2] += ps[i];
    }

    for (int i = 1; i < (int)rs.size(); ++i) {
        rs[i] += rs[i - 1];
    }

    auto calc = [ps, rs](int l, int r) {
        double res = rs[r] - rs[l];
        if (l - 1 >= 0) res -= ps[l - 1];
        return res;
    };

    constexpr int inf = 1001001001;
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(n + 2, inf));
    for (int i = 0; i <= n; i++) {
        dp[i][i + 1] = qs[i];
    }

    for (int d = 2; d <= n + 1; ++d) {
        for (int l = 0; l + d <= n + 1; ++l) {
            // (l, r]
            int r = l + d;

            for (int mid = l + 1; mid < r; ++mid) {
                // (l, r] <- (l, mid] + (mid, r]

                double cost = dp[l][mid] + dp[mid][r] + calc(l, r);
                dp[l][r] = std::min(dp[l][r], cost);
            }
        }
    }

    std::cout << std::fixed << std::setprecision(15);
    std::cout << dp[0][n + 1] << std::endl;
}
