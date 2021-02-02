#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector< int > ls(n), rs(n), pars(n, -1), sibs(n, -1), degs(n);
    for (int i = 0; i < n; ++i) {
        int id, l, r;
        std::cin >> id >> l >> r;

        ls[id] = l;
        rs[id] = r;
        if (l != -1) {
            degs[id]++;
            sibs[l] = r;
            pars[l] = id;
        }
        if (r != -1) {
            degs[id]++;
            sibs[r] = l;
            pars[r] = id;
        }
    }

    int root = -1;
    for (int v = 0; v < n; ++v) {
        if (pars[v] == -1) {
            root = v;
            break;
        }
    }

    std::vector< int > deps(n), hs(n);
    std::function< int(int, int) > dfs = [&](int v, int dep) {
        deps[v] = dep;
        if (ls[v] != -1) hs[v] = std::max(hs[v], dfs(ls[v], dep + 1) + 1);
        if (rs[v] != -1) hs[v] = std::max(hs[v], dfs(rs[v], dep + 1) + 1);
        return hs[v];
    };

    dfs(root, 0);

    auto node_type = [&](int id) {
        if (pars[id] == -1) return "root";
        if (degs[id] == 0) return "leaf";
        return "internal node";
    };

    for (int id = 0; id < n; ++id) {
        std::cout << "node " << id << ": ";
        std::cout << "parent = " << pars[id] << ", ";
        std::cout << "sibling = " << sibs[id] << ", ";
        std::cout << "degree = " << degs[id] << ", ";
        std::cout << "depth = " << deps[id] << ", ";
        std::cout << "height = " << hs[id] << ", ";
        std::cout << node_type(id) << std::endl;
    }
}


