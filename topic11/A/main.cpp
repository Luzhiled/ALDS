#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int> > as(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        int u, k;
        std::cin >> u >> k;

        u -= 1;

        for (int j = 0; j < k; ++j) {
            int v;
            std::cin >> v;

            v -= 1;

            as[u][v] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << as[i][j] << (j + 1 == n ? '\n' : ' ');
        }
    }
}
