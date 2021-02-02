#include <iostream>
#include <vector>
#include <algorithm>

int bubble_sort(std::vector< int > &as) {
  int n = as.size();
  int res = 0;
  for (int r = n; r >= 0; r--) {
    for (int i = 1; i < r; i++) {
      if (as[i - 1] > as[i]) {
        std::swap(as[i - 1], as[i]);
        res++;
      }
    }
  }

  return res;
}

int main() {
    int N;
    std::cin >> N;

    std::vector< int > As(N);
    for (auto &A: As) std::cin >> A;

    int ans = bubble_sort(As);
    for (int i = 0; i < N; i++) {
      std::cout << As[i] << (i + 1 == N ? "\n" : " ");
    }

    std::cout << ans << std::endl;
}
