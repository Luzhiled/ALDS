#include <iostream>
#include <vector>
#include <functional>

int main() {
    int n;
    std::cin >> n;

    std::vector< int > pre(n), in(n);
    for (auto &v: pre) std::cin >> v;
    for (auto &v: in ) std::cin >> v;

    int idx = 0;
    std::vector< int > post;
    std::function< void(int, int) > dfs = [&](int l, int r) {
        if (l == r) return;

        int nidx;
        for (int i = l; i < r; ++i) {
            if (in[i] == pre[idx]) {
                nidx = i;
            }
        }

        idx++;
        dfs(l, nidx);
        dfs(nidx + 1, r);

        post.emplace_back(in[nidx]);
    };

    dfs(0, n);

    for (int i = 0; i < n; ++i) {
        std::cout << post[i] << (i + 1 == n ? "\n" : " ");
    }
}

