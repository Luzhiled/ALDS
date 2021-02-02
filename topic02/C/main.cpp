#include <iostream>
#include <algorithm>
#include <vector>

using data_type = std::pair<char, int >;

std::vector< data_type > bubble_sort(std::vector< data_type > cs) {
    int n = cs.size();

    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (cs[j].second < cs[j - 1].second) {
                std::swap(cs[j], cs[j - 1]);
            }
        }
    }

    return cs;
}

std::vector< data_type > selection_sort(std::vector< data_type > cs) {
    int n = cs.size();

    for (int i = 0; i < n; ++i) {
        int minj = i;

        for (int j = i; j < n; ++j) {
            if (cs[j].second < cs[minj].second) {
                minj = j;
            }
        }

        std::swap(cs[i], cs[minj]);
    }

    return cs;
}

bool is_stable(const std::vector< data_type > &cs, const std::vector< data_type > &vs) {
    int n = cs.size();
    for (int i = 1; i <= 36; ++i) {
        std::vector< char > as;
        for (const auto &c: cs) {
            if (c.second == i) as.emplace_back(c.first);
        }
        
        std::vector< char > bs;
        for (const auto &v: vs) {
            if (v.second == i) bs.emplace_back(v.first);
        }

        if (as != bs) return false;
    }

    return true;
}

std::ostream &operator<<(std::ostream &os, std::vector< data_type > &vs) {
    int n = vs.size();
    for (int i = 0; i < n; ++i) {
        os << vs[i].first << vs[i].second << (i + 1 == n ? "" : " ");
    }
    return os;
}

int main() {
    int n;
    std::cin >> n;

    std::vector< data_type > cs(n);
    for (auto &c: cs) std::cin >> c.first >> c.second;

    auto bs_c = bubble_sort(cs);
    std::cout << bs_c << std::endl;
    std::cout << (is_stable(cs, bs_c) ? "Stable" : "Not stable") << std::endl;

    auto ss_c = selection_sort(cs);
    std::cout << ss_c << std::endl;
    std::cout << (is_stable(cs, ss_c) ? "Stable" : "Not stable") << std::endl;
}
