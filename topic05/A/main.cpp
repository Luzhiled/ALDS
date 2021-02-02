#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector< int > as(n);
    for (auto &a: as) std::cin >> a;

    int q;
    std::cin >> q;

    bool valid[2001] = {false};
    for (int bit = 0; bit < (1 << (int)as.size()); ++bit) {
        int sum = 0;
        for (int i = 0; i < (int)as.size(); ++i) {
            if (((bit >> i) & 1) == false) continue;
            sum += as[i];
        }

        if (sum > 2000) continue;
        valid[sum] = true;
    }

    auto solve = [valid](int m) {
        return valid[m];
    };
            
    for (int i = 0; i < q; ++i) {
        int m;
        std::cin >> m;

        std::cout << (solve(m) ? "yes" : "no") << std::endl;
    }
}
