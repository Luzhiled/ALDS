#include <iostream>
#include <vector>
#include <functional>

int main() {
    int n;
    std::cin >> n;

    std::vector< std::vector< int > > G(n);
    std::vector< int > pars(n, -1);
    for (int i = 0; i < n; ++i) {
        int id, k;
        std::cin >> id >> k;
        
        for (int j = 0; j < k; ++j) {
            int c;
            std::cin >> c;

            pars[c] = id;
            G[id].emplace_back(c);
        }
    }

    int root = -1;
    for (int v = 0; v < n; ++v) {
        if (pars[v] == -1) {
            root = v;
            break;
        }
    }

    std::vector< int > deps(n, -1);
    std::function< void(int, int) > dfs = [&](int v, int dep) {
        deps[v] = dep;

        for (auto &to: G[v]) {
            if (deps[to] == -1) {
                dfs(to, dep + 1);
            }
        }
    };

    dfs(root, 0);

    auto node_type = [G, pars](int id) {
        if (pars[id] == -1) return "root";
        if (G[id].size() == 0) return "leaf";
        return "internal node";
    };

    for (int id = 0; id < n; ++id) {
        std::cout << "node " << id << ": parent = " << pars[id] << ", ";
        std::cout << "depth = " << deps[id] << ", " << node_type(id) << ", ";

        std::cout << "[";
        for (int i = 0; i < G[id].size(); ++i) {
            if (i) std::cout << ", ";
            std::cout << G[id][i];
        }
        std::cout << "]" << std::endl;
    }
}
