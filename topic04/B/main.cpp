#include <iostream>
#include <vector>

int binary_search(std::vector< int > &as, int x) {
  int ok = 0;
  int ng = as.size();
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (as[mid] <= x) ok = mid;
    else ng = mid;
  }

  return as[ok];
}

int main() {
    int n;
    std::cin >> n;

    std::vector< int > ss(n);
    for (auto &s: ss) std::cin >> s;

    int q;
    std::cin >> q;

    int ans = 0;
    for (int i = 0; i < q; ++i) {
        int t;
        std::cin >> t;

        int s = binary_search(ss, t);
        if (s == t) {
            ans += 1;
        }
    }

    std::cout << ans << std::endl;
}
