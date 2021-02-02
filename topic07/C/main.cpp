#include <iostream>
#include <functional>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector< int > ls(n), rs(n), pars(n, -1);
    for (int i = 0; i < n; ++i) {
        int id, l, r;
        std::cin >> id >> l >> r;

        ls[id] = l;
        rs[id] = r;

        if (l != -1) pars[l] = id;
        if (r != -1) pars[r] = id;
    }

    int root = -1;
    for (int v = 0; v < n; ++v) {
        if (pars[v] == -1) root = v;
    }

    std::vector< int > pre, in, post;
    std::function< void(int) > dfs = [&](int v) {
        pre.emplace_back(v);
        if (ls[v] != -1) dfs(ls[v]);
        in.emplace_back(v);
        if (rs[v] != -1) dfs(rs[v]);
        post.emplace_back(v);
    };

    dfs(root);

    std::cout << "Preorder" << std::endl;
    for (auto &v: pre) std::cout << " " << v;
    std::cout << std::endl;

    std::cout << "Inorder" << std::endl;
    for (auto &v: in) std::cout << " " << v;
    std::cout << std::endl;

    std::cout << "Postorder" << std::endl;
    for (auto &v: post) std::cout << " " << v;
    std::cout << std::endl;
}
