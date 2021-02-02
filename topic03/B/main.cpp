#include <array>
#include <iostream>
#include <cstddef>
#include <utility>
#include <string>

template< typename T >
class queue {
  static constexpr std::size_t N = 200000;
  std::array< T, N > as;
  int n;
  int l, r;

public:
  queue() : n(0), l(0), r(0) {}

  void enqueue(T val) {
    as[r] = val;
    r++;
    n++;
    if (r == N) r = 0;
  }

  T dequeue() {
    T res = as[l];
    l++;
    n--;
    if (l == N) l = 0;
    return res;
  }

  bool empty() {
    return n == 0;
  }
};

int main() {
    int n, q;
    std::cin >> n >> q;

    using T = std::pair< std::string, int >;
    queue< T > que;
    for (int i = 0; i < n; ++i) {
        std::string name;
        int time;
        std::cin >> name >> time;

        que.enqueue(T(name, time));
    }

    int now = 0;
    while (!que.empty()) {
        T p = que.dequeue();

        if (p.second <= q) {
            now += p.second;
            std::cout << p.first << " " << now << std::endl;
        } else {
            now += q;
            p.second -= q;
            que.enqueue(p);
        }
    }
}
