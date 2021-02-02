#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26);
    for (const auto& c : s) {
        cnt[c - 'a']++;
    }

    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    for (int c = 'a'; c <= 'z'; ++c) {
        if (cnt[c - 'a'] == 0) continue;
        pq.emplace(cnt[c - 'a'], c - 'a');
    }

    if (pq.size() == 1) {
        pq.emplace(0, 51);
    }

    int idx = 25;
    std::vector<std::vector<int>> G(52);

    while (pq.size() >= 2) {
        auto a = pq.top();
        pq.pop();

        auto b = pq.top();
        pq.pop();

        idx++;
        G[idx].emplace_back(a.second);
        G[idx].emplace_back(b.second);
        pq.emplace(a.first + b.first, idx);
    }

    std::vector<int> ds(52);
    ds[idx] = 0;

    auto dfs = [&](auto self, int v, int pre) -> void {
        for (const int& u : G[v]) {
            if (u == pre) continue;
            ds[u] = ds[v] + 1;
            self(self, u, v);
        }
    };

    dfs(dfs, idx, -1);

    int ans = 0;
    for (const auto& c : s) {
        ans += ds[c - 'a'];
    }

    std::cout << ans << std::endl;
}
