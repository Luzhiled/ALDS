#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int solve(const std::string &s, const std::string &t) {
    std::vector< std::vector< int > > dp(s.size() + 1, std::vector< int >(t.size() + 1));

    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            dp[i + 1][j + 1] = std::max({dp[i + 1][j], dp[i][j + 1], dp[i][j] + (s[i] == t[j])});
        }
    }

    return dp.back().back();
}

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        std::string s, t;
        std::cin >> s >> t;

        std::cout << solve(s, t) << std::endl;
    }
}
