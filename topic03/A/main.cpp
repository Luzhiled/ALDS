#include <array>
#include <iostream>
#include <cstddef>
#include <string>

template< typename T >
class stack {
  std::size_t n;
  std::array< T, 200000 > as;

public:
  stack() : n(0) {}

  void push(T val) {
    as[n] = val;
    n++;
  }

  int pop() {
    n--;
    return as[n];
  }
};

int main() {
  std::string buf;

  stack< int > st;
  while (std::cin >> buf) {
    if (buf == "+") {
      int val = st.pop();
      val += st.pop();
      st.push(val);
      continue;
    }
    if (buf == "-") {
      int val = -st.pop();
      val += st.pop();
      st.push(val);
      continue;
    }
    if (buf == "*") {
      int val = st.pop();
      val *= st.pop();
      st.push(val);
      continue;
    }

    int val = std::stoi(buf);
    st.push(val);
  }

  std::cout << st.pop() << std::endl;
}
