#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int ans = 0;
    constexpr int coin[] = {25, 10, 5, 1};

    for (int i = 0; i < 4; ++i) {
        ans += n / coin[i];
        n %= coin[i];
    }

    std::cout << ans << std::endl;
}
