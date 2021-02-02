#include <iostream>
#include <vector>
#include <algorithm>

void max_heapify(std::vector< int > &as, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int idx = i;
    if (l < as.size() && as[l] > as[idx]) idx = l;
    if (r < as.size() && as[r] > as[idx]) idx = r;

    if (idx == i) return;

    std::swap(as[i], as[idx]);
    max_heapify(as, idx);
}

void build(std::vector< int > &as) {
    for (int i = as.size(); i >= 0; --i) {
        max_heapify(as, i);
    }
}

int main() {
    int h;
    std::cin >> h;

    std::vector< int > as(h);
    for (auto &a: as) std::cin >> a;

    build(as);

    for (const auto &a: as) std::cout << " " << a;
    std::cout << std::endl;
}
