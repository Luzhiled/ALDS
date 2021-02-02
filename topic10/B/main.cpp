#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector< int > rs(n), cs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> rs[i] >> cs[i];
    }

    rs.emplace_back(cs.back());

    const int inf = 1001001001;
    std::vector< std::vector< int > > dp(n + 1, std::vector< int >(n + 1, inf));

    for (int i = 0; i < n; ++i) dp[i][i + 1] = 0;

    for (int d = 2; d <= n; ++d) {
        for (int l = 0; l + d <= n; ++l) {
            int r = l + d;
            for (int m = l + 1; m < r; ++m) {
                dp[l][r] = std::min(dp[l][r], dp[l][m] + dp[m][r] + rs[l] * rs[m] * rs[r]);
            }
        }
    }

    std::cout << dp[0][n] << std::endl;
}
