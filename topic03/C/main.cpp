#include <array>
#include <iostream>
#include <string>
#include <cstddef>

template< typename T >
class list {
  struct Node {
    T val;
    int prev;
    int next;

    Node () {}
    Node (T val, int prev, int next) : val(val), prev(prev), next(next) {}
  };

  static constexpr std::size_t N = 2000000 + 2;
  std::array< Node, N > as;
  int n;
  const int begin = N - 2;
  const int end = N - 1;

  void insert(int idx, T val) {
    int next = as[idx].next;
    as[n] = Node(val, idx, next); 
    as[next].prev = as[idx].next = n;
    n++;
  }

  void remove(int idx) {
    int prev = as[idx].prev;
    int next = as[idx].next;
    as[prev].next = next;
    as[next].prev = prev;
  }

  public:
  list() : n(0) {
    as[begin] = Node(T(), -1, end);
    as[end] = Node(T(), begin, -1);
  }

  void push_front(T val) {
    insert(begin, val);
  }

  void pop_front() {
    remove(as[begin].next);
  }

  void pop_back() {
    remove(as[end].prev);
  }

  void delete_val(T val) {
    int idx = as[begin].next;
    while (idx != end) {
      if (as[idx].val == val) {
        remove(idx);
        return;
      }

      idx = as[idx].next;
    }
  }

  void print() {
    int idx = as[begin].next;

    while (true) {
      std::cout << as[idx].val;
      idx = as[idx].next;
      if (idx == end) break;
      std::cout << " ";
    }

    std::cout << std::endl;
  }
};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;

  list< int > ls;
  for (int i = 0; i < n; ++i) {
    std::string command;
    std::cin >> command;

    if (command == "insert") {
      int x;
      std::cin >> x;

      ls.push_front(x);
    }

    if (command == "delete") {
      int x;
      std::cin >> x;

      ls.delete_val(x);
    }

    if (command == "deleteFirst") {
      ls.pop_front();
    }

    if (command == "deleteLast") {
      ls.pop_back();
    }
  }

  ls.print();
}
