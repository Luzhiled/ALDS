#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector< int > ws(n);
    for (auto &w: ws) std::cin >> w;

    const int inf = 1001001001;
    int min_w = inf;
    for (auto w: ws) {
        min_w = std::min(min_w, w);
    }

    std::vector< int > ps(n);
    for (int i = 0; i < n; ++i) {
        ps[i] = i;
    }

    std::sort(ps.begin(), ps.end(), [ws](int a, int b) { return ws[a] < ws[b]; });

    int ans = 0;
    std::vector< bool > used(n);
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;

        used[i] = true;
        int min_c = ws[i];
        int sum_c = ws[i]; 
        int cnt = 1;
        for (int j = ps[i]; j != i; j = ps[j]) {
            min_c = std::min(min_c, ws[j]);
            sum_c += ws[j];
            cnt++;
            used[j] = true;
        }

        ans += (sum_c - min_c) + std::min((cnt - 1) * min_c, (cnt + 1) * min_w + 2 * min_c);
    }

    std::cout << ans << std::endl;
}

