#include <algorithm>
#include <iostream>
#include <vector>

using vi = std::vector<int>;
using Graph = std::vector<std::vector<int> >;

void dfs(int v, int& time, vi& ds, vi& fs, const Graph& G) {
    time += 1;
    ds[v] = time;

    for (const auto& u : G[v]) {
        if (ds[u] != -1) continue;
        dfs(u, time, ds, fs, G);
    }

    time += 1;
    fs[v] = time;
}

int main() {
    int n;
    std::cin >> n;

    Graph G(n);
    for (int i = 0; i < n; ++i) {
        int u;
        std::cin >> u;
        u -= 1;

        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            std::cin >> v;
            v -= 1;

            G[u].emplace_back(v);
        }

        std::sort(G[u].begin(), G[u].end());
    }

    vi ds(n, -1), fs(n, -1);

    int time = 0;
    for (int v = 0; v < n; ++v) {
        if (ds[v] != -1) continue;

        dfs(v, time, ds, fs, G);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << (i + 1) << " " << ds[i] << " " << fs[i] << std::endl;
    }
}
