#include <iostream>
#include <queue>
#include <vector>

using Graph = std::vector<std::vector<int> >;

void bfs(int v, std::vector<int>& ds, const Graph& G) {
    std::queue<int> que;
    ds[v] = 0;
    que.push(v);

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (const auto& to : G[u]) {
            if (ds[to] != -1) continue;
            ds[to] = ds[u] + 1;
            que.push(to);
        }
    }
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
    }

    int st = 0;
    std::vector<int> ds(n, -1);

    bfs(st, ds, G);

    for (int v = 0; v < n; ++v) {
        std::cout << (v + 1) << " " << ds[v] << std::endl;
    }
}
