#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
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
    int n;
    std::cin >> n;

    using edge = std::tuple<int, int, int>;
    std::vector<edge> edges;

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            int cost;
            std::cin >> cost;

            if (cost == -1) continue;
            edges.emplace_back(cost, u, v);
        }
    }

    std::sort(edges.begin(), edges.end());

    int ans = 0;
    union_find uf(n);
    for (const auto& e : edges) {
        int cost, u, v;
        std::tie(cost, u, v) = e;

        if (uf.is_same(u, v)) continue;

        uf.unite(u, v);
        ans += cost;
    }

    std::cout << ans << std::endl;
}
