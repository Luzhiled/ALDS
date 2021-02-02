#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  int n;
  std::cin >> n;

  std::vector< i64 > dp(n + 1);
  dp[0] = dp[1] = 1;
  for (int i = 2; i < (int)dp.size(); i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  std::cout << dp.back() << std::endl;
}
