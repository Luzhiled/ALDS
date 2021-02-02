#include <iostream>
#include <string>
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

void insert(std::vector< int > &as, int key) {
    int idx = as.size();
    as.emplace_back(key);

    do {
        idx = (idx - 1) / 2;
        max_heapify(as, idx);
    } while (idx);
}

int extract_max(std::vector< int > &as) {
    int res = as.front();
    as.front() = -1;
    std::swap(as.front(), as.back());
    as.pop_back();
    max_heapify(as, 0);
    return res;
}

int main() {
    std::string s;

    std::vector< int > as;

    while (std::cin >> s) {
        if (s == "end") break;

        if (s[0] == 'i') {
            int key;
            std::cin >> key;

            insert(as, key);
        } else {
            std::cout << extract_max(as) << std::endl;
        }
    }
}

