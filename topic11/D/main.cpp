#include <iostream>
#include <vector>

// union find {{{
class union_find {
    using data_type = int_fast32_t;
    std::vector<data_type> data_;

  public:
    union_find(std::size_t size) : data_(size, -1) {}

    std::size_t size() const { return data_.size(); }

    data_type get_root(data_type x) {
        return (data_[x] < 0 ? x : data_[x] = get_root(data_[x]));
    }

    bool is_root(data_type x) { return x == get_root(x); }

    bool is_same(data_type x, data_type y) {
        return get_root(x) == get_root(y);
    }

    void unite(data_type x, data_type y) {
        x = get_root(x);
        y = get_root(y);
        if (x == y) return;

        if (data_[x] > data_[y]) std::swap(x, y);
        data_[x] += data_[y];
        data_[y] = x;
    }

    data_type element_count(data_type x) { return -data_[get_root(x)]; }
};
// }}}

int main() {
    int n, m;
    std::cin >> n >> m;

    union_find uft(n);
    for (int i = 0; i < m; ++i) {
        int s, t;
        std::cin >> s >> t;
        uft.unite(s, t);
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int s, t;
        std::cin >> s >> t;

        if (uft.is_same(s, t)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
}
