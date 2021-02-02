#include <iostream>

bool is_prime(int val) {
    using i64 = long long;
    if (val <= 1) return false;
    for (i64 d = 2; d * d <= val; ++d) {
        if (val % d == 0) return false;
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;

        ans += is_prime(val);
    }

    std::cout << ans << std::endl;
}
