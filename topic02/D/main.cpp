#include <iostream>
#include <vector>
#include <algorithm>

void insertion_sort(std::vector< int > &as, int g, int &cnt) {
    int n = as.size();

    for (int i = g; i < n; ++i) {
        int v = as[i];
        int j = i - g;

        while (j >= 0 && as[j] > v) {
            as[j + g] = as[j];
            j = j - g;
            cnt++;
        }

        as[j + g] = v;
    }
}

void shell_sort(std::vector< int > &as) {
    int n = as.size();
    
    std::vector< int > gs;
    for (int g = 1; g <= n; g += std::max(1, g / 7)) {
        gs.emplace_back(g);
    }

    std::reverse(gs.begin(), gs.end());

    int m = gs.size();
    std::cout << m << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << gs[i] << (i + 1 == m ? "" : " ");
    }
    std::cout << std::endl;

    int cnt = 0;
    for (const auto &g: gs) {
        insertion_sort(as, g, cnt);
    }

    std::cout << cnt << std::endl;

    for (const auto &a: as) {
        std::cout << a << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector< int > as(n);
    for (auto &a: as) std::cin >> a;

    shell_sort(as);
}
