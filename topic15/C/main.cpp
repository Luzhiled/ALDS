#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> vs(n);
    for (auto& v : vs) std::cin >> v.second >> v.first;

    std::sort(vs.begin(), vs.end());

    int t = 0;
    int ans = 0;
    for (const auto& v : vs) {
        if (t > v.second) continue;
        ans++;
        t = v.first + 1;
    }

    std::cout << ans << std::endl;
}
