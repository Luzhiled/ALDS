#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using edge = std::pair<int, int>;
using Graph = std::vector<std::vector<edge>>;

std::vector<int> dijkstra(int s, const Graph& G) {
    constexpr int inf = 1001001001;
    std::vector<int> ds(G.size(), inf);
    ds[s] = 0;

    std::priority_queue<edge, std::vector<edge>, std::greater<edge>> pq;
    pq.emplace(ds[s], s);

    while (!pq.empty()) {
        int v, cost;
        std::tie(cost, v) = pq.top();
        pq.pop();

        if (cost > ds[v]) continue;

        for (const auto& e : G[v]) {
            int u, c;
            std::tie(u, c) = e;
            if (ds[u] > cost + c) {
                ds[u] = cost + c;
                pq.emplace(ds[u], u);
            }
        }
    }

    return ds;
}

int main() {
    int n;
    std::cin >> n;

    Graph G(n);
    for (int i = 0; i < n; ++i) {
        int u;
        std::cin >> u;

        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int v, cost;
            std::cin >> v >> cost;

            G[u].emplace_back(v, cost);
        }
    }

    std::vector<int> ds = dijkstra(0, G);

    for (int v = 0; v < n; ++v) {
        std::cout << v << " " << ds[v] << std::endl;
    }
}
