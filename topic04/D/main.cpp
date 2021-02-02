#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector< int > ws(n);
    for (auto &w: ws) std::cin >> w;

    auto check = [ws, k](int p) {
        if (*max_element(ws.begin(), ws.end()) > p) {
            return false;
        }

        int cnt = 1;
        int now = 0;
        for (const auto &w: ws) {
            if (now + w <= p) {
                now += w;
                continue;
            }

            cnt += 1;
            now = w;
        }

        return cnt <= k;
    };

    int ok = std::accumulate(ws.begin(), ws.end(), 0);
    int ng = 0;

    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        if (check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    std::cout << ok << std::endl;
}

